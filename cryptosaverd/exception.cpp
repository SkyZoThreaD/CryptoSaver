#include "cryptosaverd.h"

namespace cryptosaver
{

exception::exception(const exception_type type, const std::string message):m_type(type),m_message(message)
{
}

exception::~exception()
{
}

}