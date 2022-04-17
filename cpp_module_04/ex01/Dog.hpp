#ifndef Dog_hpp
#define Dog_hpp

#include "Animal.hpp"

class Dog : public Animal
{
		private:

		public:
			// Orthodox Canonical Form
			Dog();
			Dog(const Dog& dog);
			Dog& operator=(const Dog& dog);
			~Dog();
			// member functions
			void makeSound( void ) const;
};
#endif
