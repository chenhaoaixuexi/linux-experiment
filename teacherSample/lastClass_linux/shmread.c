#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

main(){
	int seg_id=shmget(99, 128, 0777);

	char *p;
	p=shmat(seg_id, NULL, 0);

	printf("%s", p);
}
