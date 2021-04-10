#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int mian(int argc, char *argv[])
{
   /* test */
   if (argc <= 1) {
   	fprintf(2, "usage: sleep NUMBER...\n");
	exit(1);
   }

   sleep(atoi(argv[1]));
   exit(0);
}
