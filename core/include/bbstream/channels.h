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

#include <string>

namespace bbstream {
	namespace core {
		enum CHANNELS {
			BBC_ONE, // bbc_one_hd
			BBC_TWO, // bbc_two_hd
			BBC_FOUR, // bbc_four
			BBC_NEWS, //bbc_news24, bbc_news_channel_hd
			BBC_PARLIAMENT, // bbc_parliament
			UNKNOWN // Used in case the parsing fails.
		};

		class Channel {
			std::string name;
			std::string id;

		public:
			Channel() {
				name = "";
			}

			Channel(CHANNELS channel) {
				switch (channel) {
				case BBC_NEWS:
					this->name = "BBC News";
					this->id = "bbc_news24";
					break;
				case BBC_ONE:
					this->name = "BBC One";
					this->id = "bbc_one_hd";
					break;
				case BBC_TWO:
					this->name = "BBC Two";
					this->id = "bbc_two_hd";
					break;
				case BBC_FOUR:
					this->name = "BBC Four";
					this->id = "bbc_four";
					break;
				case BBC_PARLIAMENT:
					this->name = "BBC Parliament";
					this->id = "bbc_parliament";
				}
			}

			std::string getName() {
				return this->name;
			};

			static CHANNELS parseChannelName(std::string value);

			void getOutput();
		};
	}
}