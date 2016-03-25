#ifndef __SGObject_H__
#define __SGObject_H__

#include <Tag.h>
#include <unordered_map>

using namespace std;

namespace shogun
{

class SGObject
{
public:
    /** default constructor */
	CSGObject();

    template <typename T>
    void set(Tag<T> tag, T value);

protected:
	unordered_map<string, Tag> tag_map;
}

}

template <typename T>
void set(Tag<T> tag, T value)
{

}

#endif // __SGObject_H__
