#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "compress.h"

Compress::Compress(std::string other) : filename(std::move(other)) {	}

	void Compress::compress()
	{
		std::string a = open_and_read_file();
		CompressionString(a);
		save_to_file("compressed_" + filename);
	}

	void Compress::decompress()
	{
		std::string a = open_and_read_file();
		DecompressionString(a);
		std::cout << "File saved to decompressed_" + filename<<std::endl;
	}

	std::string Compress::open_and_read_file() const
	{
		std::fstream file;
		file.open(filename);
		std::string tmp{};
		std::string sresult{};
		std::cout << "reading file..." << std::endl;
		while (!file.eof())
		{
			file >> tmp;
			sresult += tmp;
		}
		return sresult;
	}
	void Compress::DecompressionString(const std::string& str)
	{
		unsigned int current = 0;
		std::cout << "decompressing file..." << std::endl;
		std::ofstream MyFile("decompressed_"+filename);
		do
		{
			std::string tmp{};
			int count = 0;
			if (str[current] <= ('9') && str[current] > '0')
			{
				while (str[current] <= ('9') && str[current] > '0')
				{
					tmp += str[current];
					++count;
					++current;
				}
				int n_times = std::stoi(tmp);
				for (int i = 0; i < n_times; i++)
				{
					MyFile << str[current];
				}
			}
			else {
				MyFile << str[current];
			}
			++current;
		} while (str[current] != '\0');
	}
Compress::Data Compress::CompressionString(const std::string& str)
	{
		unsigned int current = 0;
		std::cout << "compressing file..." << std::endl;
		do
		{
			if (str[current] == str[current + 1])
			{
				++obj.counter;
			}
			else {
				obj.letter = str[current];
				result.push_back(obj);
				obj.counter = 1;
			}
			++current;
		} while (str[current] != '\0');
		return result;
	}

	void Compress::save_to_file(const std::string& other)
	{
		std::ofstream MyFile(other);
		for (int i = 0; i < result.size(); i++)
		{
			if (result[i].counter == 1)
				MyFile << result[i].letter;
			else if (result[i].counter == 2)
				MyFile << result[i].letter << result[i].letter;
			else
				MyFile << result[i].counter << result[i].letter;
		}
		std::cout << "saved to compressed_" + filename;
	}

