#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "??";
}

Brain::Brain( std::string idea )
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}

Brain::Brain(const Brain& brain)
{
	*this = brain;
}

Brain& Brain::operator=(const Brain &brain)
{
	for(int i = 0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	return (*this);
}

Brain::~Brain()
{}
