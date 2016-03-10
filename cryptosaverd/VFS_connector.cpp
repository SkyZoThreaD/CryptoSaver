#include "cryptosaverd.h"

namespace cryptosaver
{

void vfs_mysql_connector_thread()
{
	int socket_desc , client_sock , c , read_size;
	struct sockaddr_in server , client;
	char client_message[MAX_TCP_MSG_LEN];
		
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1) throw new exception(ex_socket_error, "Could not create socket");
		
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( VFS_TCP_PORT );
		
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) throw new exception(ex_socket_error, "bind socket failed");
		
	//Listen
	listen(socket_desc , 3);
		
	//Accept and incoming connection
	c = sizeof(struct sockaddr_in);
		
	while(1)
	{
		//accept connection from an incoming client
		client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
		if (client_sock < 0) throw new exception(ex_socket_error, "accept socket failed");
		
		//Receive a message from client
		for(int curread = 0; curread < VALUES_NB_PER_MODIF; curread ++)
		{
			read_size = recv(client_sock , client_message , MAX_TCP_MSG_LEN , 0);	 
			if(read_size == 0) throw new exception(ex_socket_error, "socket disconected before sending all data");
			else if(read_size == -1) throw new exception(ex_socket_error, "recv socket failed");
		}
	}
}

vfs_connector::vfs_connector():connector_thread(vfs_mysql_connector_thread)
{
}

vfs_connector::~vfs_connector()
{
}

}