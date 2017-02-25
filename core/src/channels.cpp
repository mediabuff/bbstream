#include <string>
#include <channels.h>
#include <sstream>
#include <locale>
#include <algorithm>

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

		}
	}
}