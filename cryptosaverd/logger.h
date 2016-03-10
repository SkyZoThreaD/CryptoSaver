#ifndef _LOGGER_H
#define _LOGGER_H

#include "cryptosaverd.h"

namespace cryptosaver
{

class Logger
{
public:
	static Logger& Get();
	
	void Init(const std::string filename);
	void Log(const std::string tolog);
	Logger();
	~Logger();
	
private:
	static Logger m_instance;
	std::string m_filename;
	bool m_initialised;
};

}

#endif