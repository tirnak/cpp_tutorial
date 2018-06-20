// ls_frontend.cpp

#include "libls.hpp"
#include <memory>
#include <iostream>

int main(int argc, char** argv)
{
	std::string path(argc > 1 ? argv[1] : ".");

	Pointer_to_filenames files_in_dir = std::make_shared<std::vector<std::string>>();
	if (!addFilenamesToVector(path, files_in_dir))
	{
		std::cout << "couldn't get content of " << path << std::endl;
	}

	for (auto& file_name: *files_in_dir)
	{
		std::cout << file_name << " ";
	}
	std::cout << std::endl;
}
