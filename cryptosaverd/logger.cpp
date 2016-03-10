#include "cryptosaverd.h"

namespace cryptosaver
{

Logger Logger::m_instance=Logger();
	
void Logger::Log(const std::string tolog)
{
	if(!m_initialised) throw new exception(ex_logger_not_initialised, "Please specify a log filename before using it." );
	std::ofstream file;
	file.open(m_filename.c_str(), std::fstream::app);
	if(!file.is_open()) throw new exception(ex_log_file_not_writable, "Cannot write the log file... are you admin?");
	
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

	file << now->tm_mday << "-" << now->tm_mon << "-"  << now->tm_year << "_" << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "=" << tolog << std::endl;
	
	file.close();
}
	
void Logger::Init(const std::string filename)
{
	m_filename = filename;
	m_initialised = true;
}
	
Logger::Logger():m_initialised(false)
{
}

Logger::~Logger()
{
}

}