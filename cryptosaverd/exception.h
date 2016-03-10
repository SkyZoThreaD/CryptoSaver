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