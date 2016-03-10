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