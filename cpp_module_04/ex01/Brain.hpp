#ifndef Brain_hpp
#define Brain_hpp

#include <iostream>

class Brain
{
		private:
			std::string _ideas[100];

		public:
			Brain();
			Brain( std::string idea );
			Brain( const Brain& );
			Brain& operator=( const Brain& brain );
			~Brain();

};
#endif
