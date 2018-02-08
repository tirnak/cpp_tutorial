// ls utility

#include <boost/range/iterator_range.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#include <iostream>

int main(int argc, char** argv)
{
	boost::filesystem::path path_to_list(argc > 1 ? argv[1] : ".");

	std::vector<std::string> files_in_dir;

	using boost::filesystem::directory_iterator;
	directory_iterator end_itr;
	for (directory_iterator itr(path_to_list); itr != end_itr; ++itr)
	{
		files_in_dir.push_back(itr->path().string());
	}
	for (auto& file_name: files_in_dir)
	{
		std::cout << file_name << " ";
	}
	std::cout << std::endl;
}
