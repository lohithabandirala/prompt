
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main()
{
int pid;
char *value;
struct stat s;

printf("\n1. FORK SYSTEM CALL\n");

pid=fork();

if(pid==0)
{
printf("Child Process\n");
printf("Child PID: %d\n",getpid());
exit(0);
}
else if(pid>0)
{
wait(NULL);
printf("Parent Process\n");
printf("Parent PID: %d\n",getpid());
}

printf("\n2. EXECVP SYSTEM CALL\n");

pid=fork();

if(pid==0)
{
char *args[]={"ls","-l",NULL};
execvp("ls",args);
printf("Execvp Failed\n");
exit(1);
}
else
{
wait(NULL);
}

printf("\n3. SETENV AND GETENV\n");

setenv("NAME","Lohitha",1);
setenv("COLLEGE","CBIT",1);

value=getenv("NAME");
printf("Name: %s\n",value);

value=getenv("COLLEGE");
printf("College: %s\n",value);

printf("\n4. STAT SYSTEM CALL\n");

if(stat("file.txt",&s)==0)
{
printf("File Size: %ld bytes\n",(long)s.st_size);
printf("Inode Number: %ld\n",(long)s.st_ino);
printf("Number of Links: %ld\n",(long)s.st_nlink);
}
else
{
printf("File Not Found\n");
}

return 0;
}
