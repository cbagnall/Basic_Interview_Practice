#include <sys/stat.h>   //mkfifo()
#include <stdio.h>		//all the I/O
#include <unistd.h>		//fork() Unix
#include <stdlib.h> 	//exit()
#include <string.h> 	//strlen()

#define MAX_BUFF_SIZE 256

void Write2Queue(const char* data, const char* FIFO)
{
 	FILE* fd = fopen(FIFO, "w+");
	if(fd < 0){
		perror("Could not open file for writing.\n");
		exit(-1);
	}
	fprintf(fd, "%s", data);
	fclose(fd);

}

void ReadFromQueue(char* data, const char* FIFO)
{
	FILE* fd = fopen(FIFO, "r+");
	if(fd < 0){
		perror("Could not open file for reading.\n");
		exit(-1);
	}
	fgets(data, MAX_BUFF_SIZE, fd); //will block until some data is available
	data[strlen(data)-1] = '\0'; //ensures that there is no newline
	fclose(fd);

}

int main(int argc, char* argv[])
{
 	const char* FIFO = "./FIFO"; 
	mkfifo(FIFO, 0666); //create fifo
	char read_buffer[MAX_BUFF_SIZE]{0};
	char write_buffer[MAX_BUFF_SIZE]{0};
	
	pid_t child = fork();


	if (child == 0){ //child process
		ReadFromQueue(read_buffer, FIFO);
		printf("Child read '%s' from FIFO.\n\n", read_buffer);
		unlink(FIFO);	
	}

	else {		//parent process
		printf("\nPlease enter an input phrase:\n\n");
		fgets(write_buffer, MAX_BUFF_SIZE, stdin);
		printf("\n");
		Write2Queue(write_buffer, FIFO);
	}
}
