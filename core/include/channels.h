#include <string>

namespace bbstream {
	namespace core {
		enum CHANNELS {
			BBC_ONE, // bbc_one_hd
			BBC_TWO, // bbc_two_hd
			BBC_FOUR, // bbc_four
			BBC_NEWS, //bbc_news24, bbc_news_channel_hd
			BBC_PARLIAMENT // bbc_parliament
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

			static std::string parseChannelName(std::string value) {};

			void getOutput() {};
		};
	}
}