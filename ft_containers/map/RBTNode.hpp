#ifndef RBTNode_hpp
#define RBTNode_hpp

#include <string>

namespace ft {

enum Color
{
	RED,
	BLACK
};

template <class T>
struct RBTNode
{
	typedef	T	value_type;

	Color			_color;
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
		_color = RED;
	}
	RBTNode(const value_type& val, RBTNode* parent, RBTNode* left, RBTNode* right) :
		_value(val),
		_parent(parent),
		_left(left),
		_right(right)
	{
		_color = RED;
	}

	// destructor
	~RBTNode()
	{}

	bool	operator==(const RBTNode& op)
	{
		if (_value == op._value)
			return (true);
		return (false);
	}

};

}

#endif
