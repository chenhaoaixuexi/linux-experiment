#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

main(){
	DIR *dp;
	struct dirent *p;
	dp=opendir(".");

	while((p=readdir(dp))!=NULL){
		printf("%d %s\n", p->d_ino,p->d_name);
	}

	closedir(dp);	
}
