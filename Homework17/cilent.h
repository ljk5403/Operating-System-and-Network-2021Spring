#include "my.h"
#define MAXDATASIZE 100
//#define PORT 1234

int main(int argc,char *argv[])
{
  unsigned short PORT = (unsigned short)argv[2];
  struct sockaddr_in server;
  int fd;
  struct hostent *he;
  if(argc!=3){
    cout<<argv[0]<<" <IPaddress Port>\n";
    exit(0);
  }
  if((he=gethostbyname(argv[1]))==NULL){
    cout<<"gethostname() error\n";
    exit(1);
  }
  fd=socket(AF_INET,SOCK_STREAM,0);
  if(fd<0){
    cout<<"socket creating error!\n";
    exit(1);
  }

  memset(&server,0,sizeof(struct sockaddr_in));
  server.sin_family=AF_INET;
  server.sin_port=htons(PORT);
  server.sin_addr=*((struct in_addr *)he->h_addr);

  if(connect(fd,(struct sockaddr *)(&server),sizeof(struct sockaddr_in))<0){
    cout<<"connect failed\n";
    exit(2);
  }

  recviver(fd);

  close(fd);
  return 0;
}

int recviver(int fd){
  if(recv(fd,buf,len,0)==-1){
    return -1;
  }
  else{
    //Do something
    return 0;
  }
}
