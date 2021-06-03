#include<sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc,char *argv[]){
  //string ipAddress = argv[1];
  //unsigned short port = (short)argv[2];
  char ipAddress[] = "192.168.1.2";
  unsigned short port = 8080;
  struct sockaddr_in server;
  memset(&server,0,sizeof(server));
  server.sin_family=AF_INET;
  server.sin_port=htons(port);
  server.sin_addr.s_addr=inet_addr(ipAddress);
  cout<<"网络字节顺序的IP地址为："<<server.sin_addr.s_addr<<endl;
  cout<<"网络字节顺序的端口号为："<<server.sin_port<<endl;
  cout<<"本机字节顺序的IP地址为："<<ntohl(server.sin_addr.s_addr)<<endl;
  cout<<"本机字节顺序的端口号为："<<ntohs(server.sin_port)<<endl;
  return 0;
}

