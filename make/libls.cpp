// libls.cpp

#include "libls.hpp"
#include <boost/range/iterator_range.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#include <memory>
#include <iostream>
#include <vector>

bool addFilenamesToVector(std::string path, Pointer_to_filenames files_in_dir)
{
	boost::filesystem::path path_to_list(path.empty() ? "." : path);
	if (!boost::filesystem::exists(path_to_list))
	{
		return false;
	}

	using boost::filesystem::directory_iterator;
	directory_iterator end_itr;
	for (directory_iterator itr(path_to_list); itr != end_itr; ++itr)
	{
		files_in_dir->push_back(itr->path().string());
	}
	return true;
}
