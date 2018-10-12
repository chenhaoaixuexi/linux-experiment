#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>

main(){
	int seg_id=shmget(99, 128, IPC_CREAT|0777);

	char *p;
	p=shmat(seg_id, NULL, 0);

	strcpy(p, "Hello shm!\n");
}
