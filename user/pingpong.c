/* Author: Tao
 * Date: 04/15/2021
 * Requiremnet: Write a program uses UNIX system calls to "ping-pong" a byte between 
 * two processes over a pair of pipes, one for each direction. 
 * The parent should send a byte to the child; the child should print "<pid>:received ping", 
 * write the byte on the pipe to the parent, and exit; the parent should read the byte from the child, 
 * print "<pid>: received pong", and exit. Your solution should be in the file user/pingpong.c.
 * Status: pass but waiting for <make grade>. -- 04/15/2021 
*/

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define R 0 // standard input; process read
#define W 1 // standard output; process write

int main(int argc, char *argv[])
{
    char pingpong;
    int n;
    int child2parent[2];
    int parent2child[2];
    
    pingpong = 'B'; // ball
    pipe(child2parent);
    pipe(parent2child);

    if (fork() == 0) { // child
        close(child2parent[R]);
        close(parent2child[W]);

        n = read(parent2child[R], &pingpong, 1);
        if (n != 1) {
            fprintf(2, "child process failed to read ball\n");
            exit(1);
        }
        fprintf(2, "%d: reveived ping %c\n", getpid(), pingpong);
        write(child2parent[1], &pingpong, 1);

        close(child2parent[W]);
        close(parent2child[R]);
        exit(0);
    } else { // parent
        close(child2parent[W]);
        close(parent2child[R]);

        write(parent2child[W], &pingpong, 1);
        n = read(child2parent[R], &pingpong, 1);
        if (n != 1) {
            fprintf(1, "parent process failed to read ball\n");
            exit(1);
        }
        fprintf(1, "%d: received pong %c\n", getpid(), pingpong);
        wait(0);
        close(child2parent[R]);
        close(parent2child[W]);
        exit(0);
    }

}