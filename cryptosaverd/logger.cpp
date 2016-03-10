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

Logger Logger::m_instance=Logger();
	
void Logger::Log(const std::string tolog)
{
	if(!m_initialised) throw new exception(ex_logger_not_initialised, "Please specify a log filename before using it." );
	std::ofstream file;
	file.open(m_filename.c_str(), std::fstream::app);
	if(!file.is_open()) throw new exception(ex_log_file_not_writable, "Cannot write the log file... are you admin?");
	
	time_t t = time(0); // get time now
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