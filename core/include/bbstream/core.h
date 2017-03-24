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
#include <sstream>
#include <vector>
#include <string>

namespace bbstream {
	namespace core {
		static std::string BBC_DASH_LLNW_ENDPOINT = "http://a.files.bbci.co.uk/media/live/manifesto/audio_video/simulcast/dash/uk/dash_pc/llnw/";
		static std::string BBC_DASH_AK_ENDPOINT = "http://a.files.bbci.co.uk/media/live/manifesto/audio_video/simulcast/dash/uk/dash_pc/ak/";
		void test();

		std::string replaceArgs(std::string value, std::vector<std::string> args);
	}
}