#pragma once

#include <iostream>
#include <fstream>
#include <vector>

struct counter_struct
{
	char letter;
	int counter = 1;
};
class Compress
{
public:
	Compress(std::string other);

public:
	using Data = std::vector<counter_struct>;
	void compress();
	void decompress();
private:
	std::string open_and_read_file() const;
	Data CompressionString(const std::string&);
	void DecompressionString(const std::string&);
	void save_to_file(const std::string&);

private:
	std::string m_filename;
	counter_struct m_obj;
	Data m_result;
};


