#include <iostream>
#include <fstream>
#include <ctime>
#include <thread>
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr

#include "exception.h"
#include "logger.h"
#include "VFS_connector.h"

#define MAX_TCP_MSG_LEN 2048 // Maximum length of a packet
#define VALUES_NB_PER_MODIF 2 // Nomber of values for each repport from the vfs module
#define VFS_TCP_PORT 8888