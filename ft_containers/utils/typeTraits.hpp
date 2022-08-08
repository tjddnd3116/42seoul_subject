#ifndef typeTraits_hpp
#define typeTraits_hpp

#include <type_traits>
#include "../iterator/iterator.hpp"
#include "./utility.hpp"

namespace ft {

template<bool Cond, class T = void>
struct enable_if
{};

template <class T>
struct enable_if<true, T>
{
	typedef T type;
};

}
#endif
