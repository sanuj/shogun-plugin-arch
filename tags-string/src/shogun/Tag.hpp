#ifndef __TAG_H__
#define __TAG_H__

#include <string>

namespace shogun {

template <class T>
class Tag
{
public:
    Tag(std::string name) : name_(name) { }
    std::string name_;
};

}

#endif // __TAG_H__
