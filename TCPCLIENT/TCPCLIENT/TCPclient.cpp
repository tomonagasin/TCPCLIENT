#include<winsock2.h>						
#include<stdio.h>
#include<windows.h>
#pragma comment(lib,"WS2_32.lib")	

int main()								
{
	WSADATA data;						
	WORD w=MAKEWORD(2,0);				
	::WSAStartup(w,&data);	
	//Define a socket variable
	SOCKET s;							
	char sztext[255]={0};
	//Create a socket of stream
	s=::socket(AF_INET,SOCK_STREAM,0);	
	//Give the ip and port of server
	sockaddr_in addr;					
	addr.sin_family=AF_INET;				
	addr.sin_port=htons(75);
	addr.sin_addr.S_un.S_addr=inet_addr("192.168.43.175");
	printf("¥¯¥é¥¤¥¢¥ó¥È¤Ï¤¹¤Ç¤ËÆð„Ó¤·¤Æ¤¤¤Þ¤¹\r\n");					

	//connect to server
	::connect(s,(sockaddr*)&addr,sizeof(addr));
	//receive data from server
	::recv(s,sztext,sizeof(sztext),0);
	printf("%s\r\n",sztext);
	//Close socket after connection
	::closesocket(s);	
	//Release the library of socket
	::WSACleanup();
	//Any input over
	if(getchar())
	{
		return 0;						
					
	}
	else
	{
		::Sleep(100);						
	}
}
