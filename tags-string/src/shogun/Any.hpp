/*
 * This code has been taken from
 * https://github.com/shogun-toolbox/aer/blob/master/src/aer/util/any.hpp
 *
 */

#ifndef _ANY_H_
#define _ANY_H_

#include <string.h>
#include <stdexcept>
#include <typeinfo>
#include <cxxabi.h>
#include <iostream>

namespace shogun
{
    namespace impl
    {
    	template <typename T>
    	std::string demangledType()
    	{
    		size_t length;
    		int status;
    		char* demangled = abi::__cxa_demangle(typeid(T).name(), nullptr, &length, &status);
    		std::string demangled_string(demangled);
    		free(demangled);
    		return demangled_string;
    	}

    	class BaseAnyPolicy
    	{
    		public:
    			virtual void set(void** storage, const void* v) const = 0;
    			virtual void clear(void** storage) const = 0;
    			virtual std::string type() const = 0;
    			virtual bool matches(const std::type_info& ti) const = 0;
    	};

    	template <typename T>
    	class PointerValueAnyPolicy : public BaseAnyPolicy
    	{
    		public:
    			virtual void set(void** storage, const void* v) const
    			{
    				*(storage) = new T(*reinterpret_cast<T const*>(v));
    			}
    			virtual void clear(void** storage) const
    			{
    				delete reinterpret_cast<T*>(*storage);
    			}
    			virtual std::string type() const
    			{
    				return impl::demangledType<T>();
    			}
    			virtual bool matches(const std::type_info& ti) const
    			{
    				return typeid(T) == ti;
    			}
    	};
    }

	class Any
	{
	public:
		struct Empty;

		Any() : policy(selectPolicy<Empty>()), storage(nullptr)
		{
		}
		template <typename T>
		explicit Any(const T& v) : policy(selectPolicy<T>()), storage(nullptr)
		{
			policy->set(&storage, &v);
		}
		Any(const Any& other) : policy(other.policy), storage(nullptr)
		{
			policy->set(&storage, other.storage);
		}
		Any& operator=(const Any& other)
		{
			policy->clear(&storage);
			policy = other.policy;
			policy->set(&storage, other.storage);
			return *(this);
		}
		~Any()
		{
			policy->clear(&storage);
		}
		template <typename T>
		T& as() const
		{
			if (sameType<T>())
			{
				return *(reinterpret_cast<T*>(storage));
			}
			else
			{
				throw std::logic_error("Bad cast to" + impl::demangledType<T>() +
						" but the type is " + policy->type());
			}
		}
		template <typename T>
		inline bool sameType() const
		{
			return (policy == selectPolicy<T>()) || sameTypeFallback<T>();
		}
		template <typename T>
		bool sameTypeFallback() const
		{
			return policy->matches(typeid(T));
		}
		bool empty() const
		{
			return sameType<Empty>();
		}
	private:
		template <typename T>
		static impl::BaseAnyPolicy* selectPolicy()
		{
			typedef impl::PointerValueAnyPolicy<T> Policy;
			static Policy policy;
			return &policy;
		}
	private:
		impl::BaseAnyPolicy* policy;
		void* storage;
	};

	struct Any::Empty
	{
	};

	namespace
	{
		template <typename T>
		inline Any erase_type(const T& v)
		{
			return Any(v);
		}

		template <typename T>
		inline T recall_type(const Any& any)
		{
			return any.as<T>();
		}
	}

}

#endif
