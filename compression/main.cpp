#include <iostream>
#include "compress.h"

void menue()
{
	std::cout << "press 1 for compressing file\n";
	std::cout << "press 2 for decompressing file\n";
}

int main()
{
	menue();
	int number;
	std::cin >> number;
	std::cout << "Then enter filename like example.txt\n";
	std::string filename{};
	std::cin >> filename;
	Compress ob(filename);
	if (number == 1)
		ob.compress();
	else if (number == 2)
		ob.decompress();


}

