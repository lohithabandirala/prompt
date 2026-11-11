
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd,n;
char msg[]="Hello World";
char buf[50];

fd=open("file.txt",O_CREAT|O_RDWR,0644);

write(fd,msg,sizeof(msg)-1);
lseek(fd,0,SEEK_SET);

n=read(fd,buf,49);
buf[n]='\0';

printf("File Content: %s",buf);

close(fd);
return 0;
}
