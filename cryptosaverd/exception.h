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

#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include "cryptosaverd.h"

namespace cryptosaver
{

typedef enum{
	ex_logger_not_initialised = 0x8001,
	ex_log_file_not_writable  = 0x8002,
	ex_socket_error			  = 0x8003,
} exception_type;

class exception
{
public:
	exception(const exception_type, const std::string message);
	~exception();
private:
	exception_type m_type;
	std::string m_message;
};

}

#endif