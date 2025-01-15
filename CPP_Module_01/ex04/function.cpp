#include "function.hpp"

void	create_file(std::string const filename, std::string line)
{
	std::ofstream	output ((filename + ".replace").c_str());
	output << line;
	output.close();
}

int main(int argc, char **argv)
{
	//if (argc != 4)
	//{
	//	std::cout << "Wrong number of arguments" << std::endl;
	//	return 1;
	//}
	std::ifstream	files(argv[1]);
	std::string		line;

	if (!files.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}
	while (getline(files, line))
	{

	}
	files.close();
	create_file(argv[1], line);
	return 0;
}