// libls.hpp

#ifndef _LIBLS_H_
#define _LIBLS_H_

#include <memory>
#include <iostream>
#include <vector>

typedef std::shared_ptr<std::vector<std::string>> Pointer_to_filenames;
bool addFilenamesToVector(std::string path, Pointer_to_filenames to_return);

#endif
