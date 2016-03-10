// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// copyright 2016 SkyZoThreaD skyzothread@gmail.com

#include "cryptosaverd.h"

namespace cryptosaver
{
    
void vfs_mysql_connector_thread()
{
	int socket_desc , client_sock , c , read_size;
	struct sockaddr_in server , client;
	char client_message[MAX_TCP_MSG_LEN];
    
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", MYSQL_USER, MYSQL_PASSORD);
    con->setSchema(MYSQL_BASE);
    stmt = con->createStatement();
		
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1) throw new exception(ex_socket_error, "Could not create socket");
		
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( VFS_TCP_PORT );
		
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) throw new exception(ex_socket_error, "bind socket failed");
		
	listen(socket_desc , 3);
		
	c = sizeof(struct sockaddr_in);
    
    std::string value1, value2;
    
	while(1)
	{
		//accept connection from the vfs module
		client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
		if (client_sock < 0) throw new exception(ex_socket_error, "accept socket failed");
		
		//Receive values
		for(int curread = 0; curread < VALUES_NB_PER_MODIF; curread ++)
		{
			read_size = recv(client_sock , client_message , MAX_TCP_MSG_LEN , 0);	 
			if(read_size == 0) throw new exception(ex_socket_error, "socket disconected before sending all data");
			else if(read_size == -1) throw new exception(ex_socket_error, "recv socket failed");
            
            switch(curread)
            {
                case VALUE_1_FILENAME: value1 = client_message; break;
                case VALUE_2_HOSTNAME: value2 = client_message; break;
                default: break;
            }
		}
        
        // send to mysql table
        std::string query = "INSERT INTO `modifs_incoming` (`filename`, `hostname`) VALUES ('";
        query += VALUE_1_FILENAME;
        query += "', '";
        query += VALUE_2_HOSTNAME + "');";
        stmt->executeQuery(query);
	}
}

vfs_connector::vfs_connector():connector_thread(vfs_mysql_connector_thread)
{
}

vfs_connector::~vfs_connector()
{
}

}