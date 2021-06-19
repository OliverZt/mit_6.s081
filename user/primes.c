/* Author: Tao
 * Date: 04/15/2021
 * Requiremnet: Write a concurrent version of prime sieve using pipes. 
 * This idea is due to Doug McIlroy, inventor of Unix pipes. 
 * The picture halfway down this page and the surrounding text explain how to do it. 
 * Your solution should be in the file user/primes.c.
 * Status: pass but waiting for <make grade>. -- 06/20/2021
 * 
*/


#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define R 0
#define W 1
#define TAIL 35

void nextProcess (int inputFd);

int main (int argc, char const *argv[])
{
    int pp[2];
    pipe(pp);
    if (fork() == 0) { // 子进程
        close(pp[W]);
        nextProcess(pp[R]);
        close(pp[R]);
    } else {
        close(pp[R]);
        for (int i = 2; i <= TAIL; i++) {
            write(pp[W], &i, sizeof(int));
        }
        close(pp[W]);
    }
    wait(0);
    exit(0);
}

void nextProcess (int inputFd)
{
    int base;
    if (read(inputFd, &base, sizeof(int)) == 0) {
        printf("End\n");
        exit(0);
    }
    printf("%d\n", base);
    
    int pp[2];
    pipe(pp);
    
    if(fork() == 0) {
        close(pp[W]);
        nextProcess(pp[R]);
        close(pp[R]);
    } else {
        close(pp[R]);
        int readNum;
        while (read(inputFd, &readNum, sizeof(int)) != 0) {
            if (readNum % base != 0) {
                write(pp[W], &readNum, sizeof(int));
            }
        }
        close(pp[W]);
    }

    wait(0);
    exit(0);
}

