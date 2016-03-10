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

// externals
#include <iostream>
#include <fstream>
#include <ctime>
#include <thread>
#include <sys/socket.h>// netwrk
#include <arpa/inet.h>

#include <cppconn/driver.h>// mysql
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

// internals
#include "exception.h"
#include "logger.h"
#include "VFS_connector.h"


//defines
#ifndef _GLOBALS_DEFINED_
#define _GLOBALS_DEFINED_

    const int MAX_TCP_MSG_LEN = 2048; // Maximum length of a packet
    const int VALUES_NB_PER_MODIF = 2; // Nomber of values for each repport from the vfs module
    const int VFS_TCP_PORT = 8888;
    const int VALUE_1_FILENAME = 0;
    const int VALUE_2_HOSTNAME = 1;
    #define MYSQL_USER "cryptosaverd"
    #define MYSQL_PASSORD "password"
    #define MYSQL_BASE "cryptosaver"

#endif