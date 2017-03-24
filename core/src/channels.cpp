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
#include <bbstream/channels.h>
#include <bbstream/core.h>
#include <bbstream/protocols/dash.h>
#include <sstream>
#include <locale>
#include <algorithm>
#include <cpr\cpr.h>

namespace bbstream {
	namespace core {
		CHANNELS Channel::parseChannelName(std::string value) {
			std::string lowerCasedValue = value;
			std::transform(lowerCasedValue.begin(), lowerCasedValue.end(), lowerCasedValue.begin(), ::tolower);

			if (lowerCasedValue.find("news") != std::string::npos) {
				return BBC_NEWS;
			}

			if (lowerCasedValue.find("one") != std::string::npos) {
				return BBC_ONE;
			}

			if (lowerCasedValue.find("two") != std::string::npos) {
				return BBC_TWO;
			}

			if (lowerCasedValue.find("four") != std::string::npos) {
				return BBC_FOUR;
			}

			if (lowerCasedValue.find("parliament") != std::string::npos) {
				return BBC_PARLIAMENT;
			}

			return UNKNOWN;
		}

		void Channel::getOutput() {
			std::stringstream manifestEndpointSS;
			std::string endpoint;

			manifestEndpointSS << bbstream::core::BBC_DASH_LLNW_ENDPOINT << this->id << ".mpd";
			endpoint = manifestEndpointSS.str();

			cpr::Response response = cpr::Get(endpoint);

			if (response.status_code == 200) {
				//std::cout << response.text;

				bbstream::core::protocols::Dash * rawDash = new bbstream::core::protocols::Dash(response.text.c_str());
				std::vector<bbstream::core::protocols::AdaptationSet> sets = rawDash->getSets();
				std::cout << sets.at(0).segmentTemplate->InitializationCreator(sets.at(0).representationSet.at(0).id) << '\n';
				std::cout << sets.at(0).segmentTemplate->MediaCreator(sets.at(0).representationSet.at(0).id, "34") << '\n';
			}
		}
	}
}