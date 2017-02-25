#include <iostream>
#include <core.h>
#include <channels.h>


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
		std::cout << argv[1];
	}

	bbstream::core::Channel * bbcnews = new bbstream::core::Channel(bbstream::core::CHANNELS::BBC_NEWS);
	std::cout << "Channel: " << bbcnews->getName() << '\n';

	return 1;
}