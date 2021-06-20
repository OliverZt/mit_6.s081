/* Author: Tao
 * Date: 06/20/2021
*/

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int pid;
    int status;
    if (fork() == 0) {
        pid = getpid();
        status = 0;
    } else {
        pid = getpid();
        status = 1;
    }
    wait(0); // wait()放在printf()之前，输出结果是正确的；
    printf("pid: %d; status: %d\n", pid, status);
    // wait(0); // wait()放在printf()之后，可以发现，父子进程在争抢shell的写操作；
    exit(0);
}