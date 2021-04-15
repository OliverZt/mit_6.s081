/* Author: Tao
 * Date: 04/14/2021
 * Requirement: Implement the UNIX program sleep for xv6; 
 * your sleep should pause for a user-specified number of ticks. 
 * A tick is a notion of time defined by the xv6 kernel, namely the time between two interrupts from the timer chip. 
 * Your solution should be in the file user/sleep.c.
 * Status: PASS!  -- 04/14/2021 
*/

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int mian(int argc, char *argv[])
{
   /* test */
   if (argc <= 1) {
   	fprintf(2, "Usage: sleep numbers...\n");
	   exit(1);
   }

   sleep(atoi(argv[1]));
   exit(0);
}
