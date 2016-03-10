#ifndef _VFS_CONNECTOR_H
#define _VFS_CONNECTOR_H

#include "cryptosaverd.h"

namespace cryptosaver
{

void vfs_mysql_connector_thread();

class vfs_connector
{
public:
	std::thread connector_thread;

	
	vfs_connector();
	~vfs_connector();
};

}

#endif