#ifndef WrongCat_hpp
#define WrongCat_hpp

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
		private:

		public:
			// Orthodox Canonical Form
			WrongCat();
			WrongCat( const WrongCat& wrongcat );
			WrongCat& operator=(const WrongCat& wrongcat );
			~WrongCat();
			// member functions
			void makeSound( void ) const;
};

#endif
