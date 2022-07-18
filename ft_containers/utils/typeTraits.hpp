#ifndef typeTraits_hpp
#define typeTraits_hpp

#include <type_traits>
#include "../iterator/iterator.hpp"

namespace ft {

template<bool Cond, class T = void>
struct enable_if
{};

template <class T>
struct enable_if<true, T>
{
	typedef T type;
};

template<typename T, typename = void>
struct is_iterator
{
   static const bool value = false;
};

template<typename T>
struct is_iterator<T, typename enable_if<!std::is_same<typename iterator_traits<T>::value_type, void>::value>::type>
{
   static const bool value = true;
};
}
#endif
