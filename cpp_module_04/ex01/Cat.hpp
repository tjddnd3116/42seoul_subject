#ifndef Cat_hpp
#define Cat_hpp

#include "Animal.hpp"

class Cat : public Animal
{
		private:

		public:
			// Orthodox Canonical Form
			Cat();
			Cat(const Cat& cat);
			Cat& operator=(const Cat& cat);
			~Cat();
			// member functions
			void makeSound( void ) const;
};

#endif
