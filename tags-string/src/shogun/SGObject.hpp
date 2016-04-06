#ifndef __SGObject_H__
#define __SGObject_H__

#include <src/shogun/Tag.hpp>
#include <unordered_map>

using namespace std;

namespace shogun
{

class SGObject
{
public:
    /** default constructor */
	SGObject();

    template <typename T>
    void set(Tag<T> tag, T value);

protected:
	// template <typename T>
	unordered_map<string, void* > tag_map;
};

template <typename T>
void SGObject::set(Tag<T> tag, T value)
{

}

}

#endif // __SGObject_H__
