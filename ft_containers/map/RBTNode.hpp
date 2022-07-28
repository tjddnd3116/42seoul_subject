#ifndef RBTNode_hpp
#define RBTNode_hpp

#include <string>

namespace ft {
template <class T>
struct RBTNode
{
	typedef	T	value_type;

	std::string		_color;
	value_type		_value;
	RBTNode*		_parent;
	RBTNode*		_left;
	RBTNode*		_right;

	// constructor
	RBTNode(RBTNode* parent, RBTNode* left, RBTNode* right) :
		_value(),
		_parent(parent),
		_left(left),
		_right(right)
	{
		_color = "black";
	}
	RBTNode(const value_type& val, RBTNode* parent, RBTNode* left, RBTNode* right) :
		_value(val),
		_parent(parent),
		_left(left),
		_right(right)
	{
		_color = "black";
	}
	// destructor
	~RBTNode()
	{}

	void	setNodeColor(const std::string& color)
	{
		_color = color;
	}
};

}

#endif
