#ifndef Animal_hpp
#define Animal_hpp

#include <iostream>

class Animal
{
		private:
			std::string _type;

		public:
			// Orthodox Canonical Form
			Animal();
			Animal( Animal& animal);
			Animal& operator=(Animal & animal);
			~Animal();
			// member functions
			void makeSound( void ) const;
			// getter
			std::string getType( void ) const;
			// setter
			void setType( std::string type );
};
#endif
