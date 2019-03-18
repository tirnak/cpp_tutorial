#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("Started a process with PID of %ld\n", (long)getpid());
	printf("Wait 30 seconds and allocate 1 Gb\n");
	
	sleep(30);
	
	void* address = malloc(1024 * 1024 * 1024);
	
	if (address != NULL) 
	{
		printf("Successfully allocated at %p\n", address);
		exit(0);
	}
	else 
	{
		printf("Failed to allocate\n"); 
		exit(1);
	}

	exit(0);
}
