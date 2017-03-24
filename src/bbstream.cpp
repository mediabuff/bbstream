/*
bbstream
Copyright (C) 2017  Emil Hummel Clausen

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program(LICENSE in root directory).  If not, see <http://www.gnu.org/licenses/>.

Email: emil@hummel.yt
*/

#include <iostream>
#include <bbstream/core.h>
#include <bbstream/channels.h>


#ifdef WIN32
#define DEFAULT_LOCALE L"en-US"
#else
#define DEFAULT_LOCALE en_US.UTF-8
#endif // WIN32

int main(int argc, char *argv[]) {
#ifdef WIN32
	_wsetlocale(LC_ALL, DEFAULT_LOCALE);
#else
	std::cin.imbue(std::locale(DEFAULT_LOCALE));
	std::cout.imbue(std::locale(DEFAULT_LOCALE));
#endif // WIN32

	std::cout << "bbstream @sequoiia\n";

	if (argc > 1) {
		bbstream::core::Channel * bbcnews = new bbstream::core::Channel(bbstream::core::Channel::parseChannelName(argv[1]));
		std::cout << "Channel: " << bbcnews->getName() << '\n';
		bbcnews->getOutput();
	}

	return 1;
}