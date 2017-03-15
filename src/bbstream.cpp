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