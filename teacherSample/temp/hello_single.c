#include <stdio.h>

void print_msg(void *msg){
	int i;
	for(i=0;i<5;i++){
		printf("%s\n", (char *)msg);
		sleep(1);
	}
}

main(){
	print_msg("hello");
	print_msg("world");
}
