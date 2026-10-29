#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main(){
void *shared_memory;
char buffer[100];
int shmid;
shmid=shmget((key_t)2706,1024,0666|IPC_CREAT);
if(shmid==-1){
perror("shmget failed");
exit(1);
}
printf("Key of shared memory: %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
if(shared_memory==(void *)-1){
perror("shmat failed");
exit(1);
}
printf("Process attached at: %p\n",shared_memory);
printf("Enter data to write shared memory:\n");
read(0,buffer,99);
buffer[strcspn(buffer,"\n")]='\0';
strcpy((char *)shared_memory,buffer);
printf("Data written is %s\n",(char *)shared_memory);
printf("Received data: %s\n",(char *)shared_memory);
shmdt(shared_memory);
return 0;
}
