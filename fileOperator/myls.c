/*
 * =====================================================================================
 *
 *       Filename:  myls.c
 *
 *    Description:  simulate cmd ls -l
 *
 *    algorithm :
 *    	#
 *
 *        Version:  1.0
 *        Created:  09/10/18 21:30:31
 *       Revision:  none
 *       Compiler:  gcc
 *       knowledge:
 *       		opendir
 *       		readdir
 *       		closedir
 *		   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
// opendir , closedir readir
#include <sys/types.h>
#include <dirent.h>
int main(int argc, char *argv[])
{
		char *dir_name ;
		DIR * dir;
		//      struct dirent *readdir(DIR *dirp);
		struct	dirent * dire;

		if (argc != 1 ) {
				dir_name = argv[1];
		}else{
				dir_name = ".";
		}

		dir = opendir(dir_name);
	//	dir = opendir (".");
		while ((dire = readdir(dir))!=NULL ) {
				printf("%ld %s\n",dire->d_ino, dire->d_name);
		}
		closedir(dir);
		return 0;
}
