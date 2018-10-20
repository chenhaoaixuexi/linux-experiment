/*
 * =====================================================================================
 *
 *       Filename:  process.h
 *
 *    Description:  process web server request
 *
 *        Version:  1.0
 *        Created:  10/18/18 22:05:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

static int header(FILE *fp, char *content_type)
{
	fprintf(fp,"HTTP/1.0 200 OK\r\n");
	if(content_type)
		fprintf(fp, "Content-type:%s\r\n",content_type);
}


static char * file_type(char *f)
{
	char * cp;
	/** char *strrchr(const char *s, int c); */
	/** strchr, strrchr, strchrnul - locate character in string */
	if (NULL != (cp = strrchr(f,'.')))
		return cp+1;
	return "";

}
static int isadir(char * f)
{
	struct stat info;
	/** int stat(const char *restrict path, struct stat *restrict buf); */
	return (-1 != stat(f,&info)&&S_ISDIR(info.st_mode));
}

static int cannot_do(int fd)
{
	FILE *fp = fdopen(fd,"w");

	fprintf(fp,"HTTP/1.0 501 NOT Implemented\r\n");
	fprintf(fp,"ConTent-type: text/plain\r\n");
	fprintf(fp,"\r\n");
	fprintf(fp,"That command is not yet implement\r\n");

	fclose(fp);
}

static int not_exist(char *f)
{
	struct stat info;
	/** int stat(const char *restrict path, struct stat *restrict buf); */
	return(-1 == stat(f,&info));
}

static int do_404(char * item , int fd)
{
	FILE *fp = fdopen(fd,"w");

	fprintf(fp,"HTTP/1.0 404 NOT found\r\n");
	fprintf(fp,"ConTent-type: text/plain\r\n");
	fprintf(fp,"\r\n");
	fprintf(fp, "The item you requested: %s\r\nis not found\r\n", item);
	fclose(fp);

}


static int do_cat(char *f, int fd)	
{
	char * extension = file_type(f);
	char * content = "text/plain";
	FILE* fpsock ,*fpfile;
	int c;

	if ( strcmp(extension,"html") == 0 )
		content = "text/html";
	else if ( strcmp(extension, "gif") == 0 )
		content = "image/gif";
	else if ( strcmp(extension, "jpg") == 0 )
		content = "image/jpeg";
	else if ( strcmp(extension, "jpeg") == 0 )
		content = "image/jpeg";

	fpsock = fdopen(fd,"w");
	fpfile = fopen(f,"r");
	if (fpsock != NULL && NULL != fpfile)
	{
		header(fpsock,content)	;
		fprintf(fpsock,"\r\n");
		while(EOF != (c = getc(fpfile)))
			putc(c,fpsock);
		fclose(fpfile);
		fclose(fpsock);
	}
	exit(0);
}

static int do_exec(char * prog, int fd)
{
	FILE *fp;
	fp = fdopen(fd,"w");
	header(fp,NULL);
	fflush(fp);
	dup2(fd,1);
	dup2(fd,2);
	close(fd);
	//	   int execl(const char *path, const char *arg, ...  /* (char  *) NULL */);
	execl(prog,prog,NULL);
	perror(prog);
}


static int do_ls(char *dir , int fd)
{
	FILE *fp;

	fp = fdopen(fd,"text/plain");
	header(fp,"text/plain");
	fprintf(fp,"\r\n");
	fflush(fp);

	dup2(fd,1);
	dup2(fd,2);
	close(fd);
	//	   int execlp(const char *file, const char *arg, ...  /* (char  *) NULL */);
	execlp("ls","ls","-l",dir,NULL);
	perror(dir);
	exit(1);
}

static int ends_in_cgi(char *f) 
{
	return (0 == strcmp(file_type(f),"cgi"));
}



int myprocess(char *rq, int fd)
{
	char cmd[BUFSIZ],arg[BUFSIZ];
	char temp[BUFSIZ];

	if(0 != fork())// in parent process
		return 127;

	strcpy(arg,"./");
	// if(2 != sscanf(rq,"%s%s%s",temp,cmd,arg))
	if(2 != sscanf(rq,"%s%s",cmd,arg+2))
		return 128;

	if(0 != strcmp(cmd,"GET"))
		cannot_do(fd);
	else if(not_exist(arg))
		do_404(arg,fd);
	else if(isadir(arg))
		do_ls(arg,fd);
	else if(ends_in_cgi(arg))
		do_exec(arg,fd);
	else 
		do_cat(arg,fd);
}
