#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

main(){
	DIR *dp;
	struct dirent *p;
	struct stat buf;
	dp=opendir(".");

	while((p=readdir(dp))!=NULL){
		stat(p->d_name, &buf);
		printf("%d %s\n", buf.st_uid, p->d_name);
	}

	closedir(dp);	
}
