// cat utility
#include <fstream>
#include <iostream>
#define FIRST_ARGUMENT argv[1]

int main(int argc, char** argv) {

	std::ifstream file_to_cat(FIRST_ARGUMENT);
	std::string line;

	if (file_to_cat.is_open())
	{
		while ( getline (file_to_cat,line) )
		{
			std::cout << line << '\n';
		}
		file_to_cat.close();
	}
	else
	{
		std::cout << "Unable to open file " << FIRST_ARGUMENT; 
	}

	return 0;
}
