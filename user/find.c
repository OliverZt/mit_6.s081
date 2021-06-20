/* Author: Tao
 * Date: 06/20/2021
 * Requiremnet: Write a simple version of the Unix find program: find all the files in a directory tree with a specific name.  
 * Status: ing 
*/

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

char *fmtname(char *path);
void find(char *path, char *fileName);

int main(int argc, char *argv[])
{
    exit(0);
    
    if (argc < 2) {
        printf("find: require a file name");
    } else if (argc == 2) {
        find(".", argv[1]);
    } else {
        for (int i = 2; i < argc; i++) {
            find(argv[1], argv[i]);
        }
    }
    exit(0);
}

char* fmtname(char *path)
{
  static char buf[DIRSIZ+1];
  char *p;

  // Find first character after last slash.
  for(p=path+strlen(path); p >= path && *p != '/'; p--)
    ;
  p++;

  // Return blank-padded name.
  if(strlen(p) >= DIRSIZ)
    return p;
  memmove(buf, p, strlen(p));
  memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
  return buf;
}
