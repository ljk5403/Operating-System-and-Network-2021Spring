#include "my.h"

int main(int argc, char *argv[]){
  char ipAddress[] = argv[1];
  unsigned short port = (unsigned short)argv[2];
  struct sockaddr_in server,client;
  int listenfd,connectfd;
  int sin_size;
  int opt;
  listenfd=socket(AF_INET,SOCK_STREAM,0);
  if(listenfd<0){
    cout<<"socket creating error!\n";
    exit(1);
  }
  opt=SO_REUSEADDR;
  setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
  memset(&server,0,sizeof(struct sockaddr_in));
  server.sin_family=AF_INET;
  server.sin_port=htons(port);
  server.sin_addr.s_addr=inet_addr(ipAddress);
  if(bind(listenfd,(struct sockaddr *)&server,sizeof(struct sockaddr))==-1){
    cout<<"bind failed\n";
    exit(2);
  }
#define BACKLOG 1
  if(listen(listenfd,BACKLOG)==-1){
    cout<<"listen() failed\n";
    exit(3);
  }
  sin_size=sizeof(struct sockaddr_in);
  if((connectfd=accept(listenfd,(struct sockaddr *)&client,(socklen_t *)&sin_size))==-1){
    cout<<"accept() failed\n";
    exit(4);
  }
  cout<<"you got a connection from  "<<inet_ntoa(client.sin_addr)<<endl;

  sender(connectfd);

  close(connectfd);
  close(listenfd);
  return 0;
}

int sender(int fd){
  if(send(fd,message,sizeof(message),0)==-1){
    return -1;
  }
  else{
    //Do something
    return 0;
  }
}
