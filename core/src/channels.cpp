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
				tinyxml2::XMLDocument * xmlDoc = rawDash->getDoc();

				std::cout << xmlDoc->FirstChildElement("MPD")->Attribute("publishTime");
			}
		}
	}
}