#include "function.hpp"

void	create_file(std::string const filename, std::string line)
{
	std::ofstream	output ((filename + ".replace").c_str());
	output << line;
	output.close();
}