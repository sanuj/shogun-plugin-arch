#ifndef _SGObject_H_
#define _SGObject_H_

#include <src/shogun/Tag.hpp>
#include <src/shogun/Any.hpp>
#include <unordered_map>

namespace shogun
{

	class SGObject
	{
		public:
		    /** default constructor */
			SGObject() {};

			~SGObject();

		    template <typename T>
		    void set(Tag<T> tag, T value);

			template <typename T>
			T get(Tag<T> tag);

		protected:
			std::unordered_map<std::string, Any*> tag_map;
	};

	template <typename T>
	void SGObject::set(Tag<T> tag, T value)
	{
		tag_map[tag.getName()] = new Any(value);
	}

	template <typename T>
	T SGObject::get(Tag<T> tag)
	{
		Any* a = tag_map[tag.getName()];
		return a->as<T>();
	}

	SGObject::~SGObject() {
		// use auto here?
		for(std::unordered_map<std::string, Any*>::iterator it = tag_map.begin(); it != tag_map.end(); ++it)
			delete(it->second);
	}

}

#endif // _SGObject_H_
