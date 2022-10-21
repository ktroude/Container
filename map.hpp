#include <functional>
#include "./iterator/bidirectional_iterator.hpp"
#include "./iterator/pair.hpp"
#include <iostream>

namespace ft
{

enum Color
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>*  			_left;      //Left child of node
	RBTreeNode<T>*  			_right;     //Right child of node
	RBTreeNode<T>*  			_prev;      //Parents of nodes		
	T               			_data;      //Stored data (ft::pair<K, V> for map && ft::pair<K, K> for set)
	Color           			_color;     //The color of the node
	
//	typename std::allocator<T>::pointer		_ptr;		//Pointer used for allocator functions
	
	RBTreeNode(const T& x) :_left(NULL) ,_right(NULL) ,_prev(NULL) , _data(x) ,_color(RED) {}

	// operator RBTreeNode<const T> () const 
	// 	{return const_cast<T>(_data);}   // cast iterator -> const iterator
};

template<class T>    // take pointer | 
struct TreeIterator
{
    public:

	typedef T					value_type;
	typedef RBTreeNode<T>		Node;
	typedef RBTreeNode<const T>	const_Node;
	typedef TreeIterator<T>		iterator;    //Type of forward iterator
	typedef	value_type&			reference;
	typedef value_type*			pointer;
	
	Node	*_node;                                //Encapsulated pointer
	Node	*_max;

TreeIterator(Node* node) :_node(node), _max(NULL) {}
TreeIterator(Node* node, Node *max) :_node(node), _max(max) {}
TreeIterator() : _node(NULL) {}
TreeIterator(const iterator &it) :  _node(it._node) {}

operator TreeIterator<const T> () const   // cast iterator -> const iterator
{
	return TreeIterator<const T>((const_Node *)_node);
}

iterator &operator=(const iterator& it)
{	if (*this != it)
		_node = it._node;
	return *this;	}

reference operator*() const
{   return _node->_data;    }

pointer	operator->() const
{   return &_node->_data;    }

bool  operator ==(const iterator& it) const
{   return _node == it._node;    }

bool  operator !=(const iterator& it) const
{   return !(_node == it._node);    }

iterator& operator++()
{
    Increment();
    return *this;
}

iterator operator++(int)
{
	iterator tmp(_node);
    Increment();
    return tmp;
}


iterator& operator--()
{
	if (_node == NULL && _max)
	{
		_node = _max;
		_max = NULL;
		return *this;
	}
	else if (_node)
    	Decrement();
    return *this;
}

iterator operator--(int)
{
	iterator tmp = TreeIterator(this->_node);
    if (_node == NULL && _max)
	{
		_node = _max;
		_max = NULL;
	}
	else
    	Decrement();
    return tmp;
}

    private:

// Incr && Decr private cause used in pre and post Incr/Decr
iterator& Increment()
{
	if (_node->_right)  // Going right then search the most left node of right
	{
		Node* left = _node->_right;
		while (left->_left)
		    left = left->_left;
		_node = left;   //  ++Then it becomes the node
	}
	else    // The right subtree is empty
	{ 
	    //Find an ancestor whose child is not on the father's right
		Node* cur = _node;
		Node* parent = cur->_prev;
		while (parent && cur == parent->_right)
		{
			cur = cur->_prev;
			parent = parent->_prev;
		}
		_node = parent;//++Then it becomes the node
	}
	return *this;
}

iterator& Decrement() // Same logic as Increment but here going to left
{
	if (_node->_left)
	{
		Node* right = _node->_left;
		while (right->_right)
		    right = right->_right;
		_node = right;
	}
	else
	{ 
		Node* cur = _node;
		Node* parent = cur->_prev;
		while (parent && cur == parent->_left)
		{
			cur = cur->_prev;
			parent = parent->_prev;
		}
		_node = parent;
	}
	return *this;
}

};

template <class T>
bool	operator==(ft::TreeIterator<T> lhs, ft::TreeIterator<T> rhs)
{	return (lhs._node->_data.first  == rhs._node->_data.first);	}

template <class Iterator>
bool	operator!=(ft::TreeIterator<Iterator> lhs, ft::TreeIterator<Iterator> rhs)
{	return !(lhs == rhs);	}


template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::RBTreeNode< ft::pair<const Key, T> > > >
class map
{
    public:

typedef Key										key_type;				// the key (obviously)
typedef T										mapped_type;			// value associated to key
typedef ft::pair<const Key, T>					value_type;
typedef const ft::pair<const Key, T>			const_value_type;
typedef Compare									key_compare;			// --> ?? useless

typedef size_t 									size_type;
typedef std::ptrdiff_t 							difference_type;
typedef value_type&								reference;
typedef value_type*								pointer;
typedef const_value_type& 						const_reference;

typedef Allocator								allocator_type;
typedef typename Allocator::pointer				alloc_pointer;
//typedef typename Allocator::const_pointer		const_pointer;

typedef RBTreeNode<value_type>					Node;
typedef RBTreeNode<const_value_type>			const_Node;

typedef TreeIterator<value_type>				iterator;
typedef TreeIterator<const_value_type>			const_iterator;
typedef ft::reverse_iterator<iterator>			reverse_iterator;
typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

class value_compare : public std::binary_function<value_type, value_type, bool>
{
    friend class map;
	protected:
key_compare comp;
value_compare(key_compare c) : comp(c) {}
	public:
bool operator()(const value_type& x, const value_type& y) const
    {	return comp(x.first, y.first);	} // x < y
};

    protected:

Node    		*_root;
// Node			*_NIL;
allocator_type	_alloc;
value_compare	_comp;



	public:
    
map() :_root(NULL), _alloc(Allocator()), _comp(Compare()) {}
explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) : _root(NULL), _alloc(alloc), _comp(comp){}

template< class InputIt >
explicit map( InputIt first, InputIt last,const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _root(NULL), _alloc(alloc), _comp(comp)
{
	while (first != last)
		insert(*first++);
}

map( const map& other ) : _root(other._root), _alloc(other._alloc), _comp(other._comp) {}

void DelTree(Node* x)
{
	if (!x)
		return;
	while (x != 0) {
		DelTree(x->_right);
		Node *y = x->_left;
		delNode(x);
		x = y;
	}
}

~map(){}

map& operator=(const map& x)
{
	clear();
	insert(x.begin(), x.end());
//    if (this != &x)
//		_root = x._root;
	return *this;
}

allocator_type get_allocator() const
{	return _alloc;	}

T& at( const Key& key )
{	for (iterator it = begin(); it != end(); it++)
		if (it->_node->_data.first == key)
			return it->_node->_data.second;
	throw std::out_of_range("key not found\n");
	return _root->_data.second;
}

T& operator[] (const key_type& key) {
    iterator iter = insert(value_type(key, mapped_type())).first;
    return iter->second;
}

iterator begin()   // Most left node
{
	Node* left = _root;
	while (left && left->_left)
		left = left->_left;
	return iterator(left);
}

const_iterator begin() const
{
	Node *left = _root;
	while (left && left->_left)
		left = left->_left;
	const_Node *n = reinterpret_cast<const_Node *>(left);
	return const_iterator(n);
}

iterator end() // Most right node (ether NIL or NULL)  -> try implement NIL (safer)
{
	Node *ret = _root;
	while (ret && ret->_right)
		ret = ret->_right;
	return iterator(NULL, ret);
}

const_iterator end() const
{
	return const_iterator(NULL);
// 	Node *ret = _root;
// 	while (ret && ret->_right)
// 		ret = ret->_right;
// 	const_iterator	it;
// 	it._node = ret;
// 	return ++it;
}

reverse_iterator rbegin();
const_reverse_iterator rbegin() const;

reverse_iterator rend();
const_reverse_iterator rend() const;

bool empty() const
{	return (_root ? false : true);	}

size_type size() const
{
	if (_root == NULL)
		return 0;
	size_type n = 0;	
	for (const_iterator it = begin(); it != end(); it++)
		n++;
	return n;
}

size_type max_size() const
{	return _alloc.max_size();	}

void clear()
{	DelTree(_root);
	_root = NULL;	}

iterator find ( const Key& key )
{
	iterator it = begin();
	for (; it != end(); ++it)
		if (it._node->_data.first == key)
			return it;
	return end();
}

const_iterator find( const Key& key ) const
{	
	const_iterator it = begin();
	for (; it != end(); ++it)
		if (it._node->_data.first == key)
			return const_iterator(reinterpret_cast<const_Node *>(it._node));
	return end();
}

ft::pair<iterator, bool> insert( const value_type& value )
{
	if (_root == NULL)
	{
		Node *NewNode = creatNode(value);	
		_root = NewNode;
		_root->_color = BLACK;
		return ft::make_pair(iterator(_root), true);
	}
	Node	*current = _root;
	Node	*parent = NULL;
	while (current) 
	{
		parent = current;
		if (value.first > current->_data.first)
			current = current->_right;
		else if (value.first < current->_data.first)
			current = current->_left;
		else
			return (ft::make_pair(current, false));
	}
	Node *NewNode = creatNode(value);	
	current = NewNode;
	current->_prev = parent;						// creat link between the NewNode and his parent
	if (current->_data.first > parent->_data.first)			// create link between parent && NewNode
		parent->_right = current;
	else
		parent->_left = current;
	ajustTree(current);
	return ft::make_pair(iterator(current), true);
}

iterator insert( iterator hint, const value_type& value )
{
	hint = begin();
	if (_root == NULL)
	{
		Node *NewNode = creatNode(value);	
		_root = NewNode;
		_root->_color = BLACK;
		return iterator(_root);
	}
	Node	*current = _root;
	Node	*parent = NULL;
	while (current) 
	{
		parent = current;
		if (value.first > current->_data.first)
			current = current->_right;
		else if (value.first < current->_data.first)
			current = current->_left;
		else
			return iterator(current);
	}
	Node *NewNode = creatNode(value);	
	current = NewNode;
	current->_prev = parent;						// creat link between the NewNode and his parent
	if (current->_data.first > parent->_data.first)			// create link between parent && NewNode
		parent->_right = current;
	else
		parent->_left = current;
	ajustTree(current);
	return iterator(current);
}

template< class InputIt >
void insert( InputIt first, InputIt last )
{
	for (InputIt it = first; it != last; it++)
		insert(*it);
}


ft::pair<iterator,iterator> equal_range( const Key& key )
{	return ft::make_pair(lower_bound(key), upper_bound(key));	}

ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
{	return ft::make_pair(lower_bound(key), upper_bound(key));	}

iterator lower_bound( const Key& key )
{
	for (iterator it = begin(); it != end(); it++)
		if (it._node->_data.first >= key)
			return it;
	return end();
}

const_iterator lower_bound( const Key& key ) const
{
	for (const_iterator it = begin(); it != end(); it++)
		if (it._node->_data.first >= key)
			return it;
	return end();
}

iterator upper_bound( const Key& key )
{
	for (iterator it = begin(); it != end(); it++)
		if (it._node->_data.first > key)
			return it;
	return end();
}

const_iterator upper_bound( const Key& key ) const
{
	for (const_iterator it = begin(); it != end(); it++)
		if (it._node->_data.first > key)
			return it;
	return end();
}

key_compare key_comp() const
{	return _comp.comp;	}

value_compare value_comp() const
{	return _comp;	}

size_type count(const key_type& x) const 
{ return find(x) == end() ? 0 : 1; }

iterator erase( iterator pos )
{
	remove(pos._node);
	return pos;
}

iterator erase( iterator first, iterator last )
{
	iterator ret;
	for (iterator it = first; it != last;)
		ret = erase(it++);
	return ret;
}

size_type erase( const Key& key )
{
	iterator pos = find(key);
	if (pos == end())
		return 0;
	erase(pos);
	return 1;
}

void remove(Node *n)
{
	Node *x, *y, *tmp;
	Color y_color;
	
	y = n;
	y_color = n->_color;
	tmp = NULL;
	if (!n->_left && !n->_right)
	{
		tmp = creatNode(n->_data);
		tmp->_color = BLACK;
		transplant(n, tmp);
		x = tmp;
	}
	else if (!n->_left)
	{
		x = n->_right;
		transplant(n, n->_right);
	}
	else if (!n->_right)
	{
		x = n->_left;
		transplant(n, n->_left);
	}
	else
	{
		y = minimum(n);
		x = y->_left;
		if (!x)
		{
			tmp = creatNode(n->_data);
			tmp->_color = BLACK;
			tmp->_prev = y;
			y->_left = tmp;
			x = tmp;
		}
		y_color = y->_color;
		if (y->_prev != n)
		{
			transplant(y, x);
			y->_left = n->_left;
			if (y->_left)
				y->_left->_prev = y;
		}
		transplant(n, y);
		y->_color = n->_color;
		y->_right = n->_right;
		if (y->_right)
		y->_right->_prev = y;
	}
	if (y_color == BLACK)
		adjustRemove(x);
	if (tmp)
	{
		transplant(tmp, NULL);
		delNode(tmp);
	}
}

void adjustRemove(Node *n)
{
	while (n != _root && n->_color)
	{
		if (n->_prev && n == n->_prev->_left)
		{
			Node *x = n->_prev->_right;
			if (x && x->_color == RED)
			{
				x->_color = BLACK;
				n->_prev->_color = RED;
				rotate_left(n->_prev);
				x = n->_prev->_right;
			}
			if (x && (!x->_left || x->_left->_color == BLACK) && (!x->_right || x->_right->_color == BLACK))
			{
				x->_color = RED;
				n = n->_prev;
			}
			else
			{
				if (x && (!x->_right || x->_right->_color == BLACK))
				{
					if (x->_left)
						x->_left->_color = BLACK;
					x->_color = RED;
					rotate_right(x);
					x = n->_prev->_right;
				}
				if (x)
				{
					x->_color = n->_prev->_color;
					x->_right->_color = BLACK;
				}
				n->_prev->_color = BLACK;
				rotate_left(n->_prev);
				n = _root;
			}
		} 
		else 
		{
			Node *x = n->_prev->_left;
			if (x && x->_color) 
			{
				x->_color = BLACK;
				n->_prev->_color = RED;
				rotate_right(n->_prev);
				x = n->_prev->_left;
			}
			if (x && (!x->_right || !x->_right->_color) && (!x->_left || !x->_left->_color))
			{
						x->_color = RED;
						n = n->_prev;
			}
			else
			{
				if (x && !x->_left->_color)
				{
					x->_right->_color = BLACK;
					x->_color = RED;
					rotate_left(x);
					x = n->_prev->_left;
				}
				if (x)
				{
					x->_color = n->_prev->_color;
					x->_left->_color = BLACK;
				}
				n->_prev->_color = BLACK;
				rotate_right(n->_prev);
				n = _root;
			}
		}
	}
	n->_color = BLACK;
}

void transplant(Node *n, Node *child)
{			
	if (!n->_prev)
		_root = child;
	else if (n == n->_prev->_left)
		n->_prev->_left = child;
	else
		n->_prev->_right = child;
	if (child)
		child->_prev = n->_prev;
}

 Node	*minimum(Node *node)
  {
		if (node->_left)
			return (max(node->_left));

		if(node->_prev && node == node->_prev->_right)
			return (node->_prev);

		Node *parent = node;
		while (parent && parent->_prev && parent == parent->_prev->_left)
			parent = parent->_prev;
		return ((parent) ? parent->_prev : NULL);
	}

  Node *max(Node *node) {
    while (node->_right != NULL)
      node = node->_right;
    return node;
  }
















































































// iterator erase( iterator first, iterator last )
// {
// 	iterator ret = first;
// 	while (first != last)
// 	{
// 		ret = erase(first);
// 		first++;
// 	}
// 	return ret;
// }

// iterator erase( iterator pos )
// {
// 	iterator ret = pos;
// 	if (pos._node == NULL)
// 		return end();
// 	Node *x;
// 	Node *y;
// 	Node *z = pos._node;

// 	if (!z)
// 		return end();
// 	y = z;
// 	int y_original_color = y->_color;				// 2	- save his color;
// 	if (z && z->_left == NULL)						// 3	- if left child is NULL
// 	{
// 		x = z->_right;								// a) Assign right child of del to x	
// 		Transplant(z, z->_right);					// b) Transplant del with x;
// 	}
// 	else if (z && z->_right == NULL)				// 4	- if right child is NULL
// 	{
// 		x = z->_left;								// a) Assign left child of del to x;
// 		Transplant(z, z->_left);					// b) Transplant del with x;
// 	}
// 	else											// 5	- all other cases
// 	{
// 		y = minimum(z->_right);						// a) Assign min of right substree of  del into y;
//     	y_original_color = y->_color;				// b) Save the color of y into original color;
//     	x = y->_right;								// c) Assign right child of y into x;
// 		if (y->_prev == z)							// d) If y is a child of del, then set the parent of x as y;
//         	x->_prev = y;
// 		else										// e) Else transplant y with right child of y;
// 		{
//         	Transplant(y, y->_right);
//         	y->_right = z->_right;
//         	y->_right->_prev = y;
// 		}
// 		Transplant(z, y);							// f) Transplant del with y;
//     	y->_left = z->_left;
//     	y->_left->_prev = y;
//     	y->_color = z->_color;						// g) Set the color of y with original color;
// 	}
// 	delNode(z);
// 	if (y_original_color == BLACK)					// 6	- if the original color is BLACK then call deleteFix
//       deleteFix(x);
// 	return ++ret;
// }

// size_type erase( const Key& key )
// {
// 	iterator it = find(key);
// 	if (it == end())
// 		return 0;
// 	erase(it);
// 	return 1;
// }







// void deleteFix(Node *x)
// {
// 	Node	*s;
// 	while (x != _root && x->_color == BLACK)									// 1	- loop for this algo, oppering while x is not root and color of x is black
// 	{
//     	if (x == x->_prev->_left) 												// 2	- If x ios the left child of it's parent :
// 		{
//         	s = x->_prev->_right;												// a) assign s to the uncle of x;
//         	if (s->_color == RED)												// b) if the uncle is RED	------> CASE I
// 			{
//         		s->_color = BLACK;												// a- set color of right child of x's parent as black;
//         		x->_prev->_color = RED;											// b- set the color of x prev as RED;
//         		rotate_left(x->_prev);											// c- left rotate x parent;
//         		s = x->_prev->_right;											// d- assign the right child of the parent of x in s;
//         	}
//         	if (s->_left->_color == BLACK && s->_right->_color == BLACK)		// c) if the color of both right n left child are BLACK  ------> CASE II
// 			{
//         		s->_color = RED;												// a- set color of s as RED;
//           		x = x->_prev;													// b- assign parent of x to x;
//         	}
// 			else																// d) if color of right child of s is black ------> CASE III
// 			{
//         		if (s->_right->_color == BLACK)									
// 				{
//         			s->_left->_color = BLACK;									// a- set the color of left child of s as black;
//             		s->_color = RED;											// b- set color of s as red; 
//             		rotate_right(s);												// c- right rotate s;
//             		s = x->_prev->_right;										// d- assign the right child of parent of x into s;
//         		}																// e) If any of the cqse happend then ------> CASE IV
//         		s->_color = x->_prev->_color;									// a- set color of s as the color of x's parent;
//         		x->_prev->_color = BLACK;										// b- set the color of x's parent as black;
//         		s->_right->_color = BLACK;										// c- set the color of the right child of s as black;
//         		rotate_left(x->_prev);											// d- left rotate x parent;
//         		x = _root;														// e- x became the root;
//         	}
//       	} 
// 		else																	// 3	- Same code but for x is the rightchild of his parent;
// 		{
//     	    s = x->_prev->_left;
//         	if (s->_color == RED)
// 			{
//         		s->_color = BLACK;
//         		x->_prev->_color = RED;
//         		rotate_right(x->_prev);
//         		s = x->_prev->_left;
// 			}
//         	if (s->_right->_color == BLACK && s->_right->_color == BLACK)
// 			{
//         		s->_color = RED;
//         		x = x->_prev;
//         	}
// 			else
// 			{
//           		if (s->_left->_color == BLACK)
// 				{
//     	    	    s->_right->_color = BLACK;
//     	    	    s->_color = RED;
//     	    	    rotate_left(s);
//     	    	    s = x->_prev->_left;
//     			}
//           		s->_color = x->_prev->_color;
//           		x->_prev->_color = BLACK;
//           		s->_left->_color = BLACK;
//           		rotate_right(x->_prev);
//           		x = _root;
//         }
//       }
//     }
// 	x->_color = BLACK;															// 4	- Set color of root as black
// }

// void Transplant(Node *n, Node *child)
// {			
// 	if (!n->_prev)
// 		_root = child;
// 	else if (n == n->_prev->_left)
// 		n->_prev->_left = child;
// 	else
// 		n->_prev->_right = child;
// 	if (child)
// 		child->_prev = n->_prev;
// }

// Node	*minimum(Node *node)		// search smallest key in a subtree from a node
// {
// 	while (node->_left != NULL)
//       node = node->_left;
//     return node;
// }
















































	private:

Node *add(value_type value)
{
	if (find(value.first) == end())
		return (NULL);
	Node *n = creatNode(value);
	insert(n);
	return (n);
}

void insert(Node* n) 
{
	if (!_root) 
	{
		_root = n;
		return;
	}

	Node *curr = _root;
	while (1) 
	{
		if (_comp(curr->_data, n->_data))
		{
			if (!curr->_right)
			{
				n->_prev= curr;
				curr->_right= n;
				break;
			}
		else
			curr = curr->_right;
		} 
		else
		{
			if (!curr->_left)
			{
				n->_prev = curr;
				curr->_left= n;
				break;
		} 
		else
			curr = curr->_left;
		}
	}
		ajustTree(n);
}

Node	*creatNode(value_type value)
{
	Node *n = _alloc.allocate(1);
	_alloc.construct(n, value);
	return n;
}

void	delNode(Node *to_del)
{
	_alloc.destroy(to_del);
	_alloc.deallocate(to_del, 1);
	to_del = NULL;
}

Node	*getParent(Node *current)
{	return current->_prev;	}

Node	*getGp(Node *current)
{
	if (current->_prev == NULL)
		return NULL;
	else if (current->_prev->_prev == NULL)
		return NULL;
	else
		return current->_prev->_prev;
}

Node	*getUncle(Node* current)
{
	Node *gp = getGp(current);
	if (gp == NULL)
		return NULL;
	Node *parent = current->_prev;
	if (gp->_right == parent)
		return gp->_left;
	else
		return gp->_right;
}

void	ajustTree(Node *n)		// ajust color and perform rotation
{
	Node *parent = getParent(n);
	Node *uncle = getUncle(n);
	Node *gp = getGp(n);
	if (_root &&  _root->_color == RED)
		_root->_color = BLACK;
	if (parent->_color == BLACK)
		return	;
	if (parent->_color == RED && uncle && uncle->_color == RED)
	{
		parent->_color = BLACK;
		uncle->_color = BLACK;
		while (gp != _root)
		{
			if (gp->_color == RED)
				gp->_color = BLACK;
			if (gp->_color == BLACK)
				gp->_color = RED;
			parent = gp;
			gp = parent->_prev;
		}
	}
	if (parent && parent->_color == RED && (uncle == NULL || uncle->_color == BLACK))
	{
		if (parent && n == parent->_left && gp && parent == gp->_right)
		{
			rotate_right(parent);
			rotate_left(n);
			ajustTree(gp);
		}
		if (parent && n == parent->_right && gp && parent == gp->_left)
		{
			rotate_left(parent);
			rotate_right(n);
			ajustTree(gp);
		}
		if (parent && gp && n == parent->_right && parent == gp->_right)
		{
			rotate_left(parent);
//			ajustTree(gp);
		}
		if (parent && n == parent->_left && gp && parent == gp->_left)
		{
			rotate_right(parent);
//			ajustTree(gp);
		}
	}
	return ;
}


void rotate_left(Node *x)
{
    Node *y = x->_right;
    x->_right = y->_left;
    if (y->_left != NULL)
    	y->_left->_prev = x;
    y->_prev = x->_prev;
    if (x->_prev == NULL)
    	_root = y;
    else if (x == x->_prev->_left)
    	x->_prev->_left = y;
    else
    	x->_prev->_right = y;
    y->_left = x;
    x->_prev = y;
  }

void rotate_right(Node *n)
{
	if (!n || !n->_left)
		return;
	Node *lc = n->_left ;
	n->_left = lc->_right;
	if (n->_left)
		n->_left->_prev = n;
	
	if (!n->_prev)
		_root = lc;
	else if (n == n->_prev->_left)
		n->_prev->_left = lc;
	else
		n->_prev->_right = lc;		
	lc->_prev = n->_prev ;
	n->_prev = lc;
	lc->_right = n;
}


// void rotate_right(Node *x)
// {
//     Node *y = x->_left;
//     x->_left = y->_right;
//     if (y->_right != NULL)
//     	y->_right->_prev = x;
//     y->_prev = x->_prev;
//     if (x->_prev == NULL)
// 		_root = y;
//     else if (x == x->_prev->_right)
//     	x->_prev->_right = y;
//     else
//       x->_prev->_left = y;
//     y->_right = x;
//     x->_prev = y;
// }


// void rotate_left(Node* parent)
// 	{
// 		Node* subR = parent->_right;
// 		Node* subRL = subR->_left;
// 		Node* parentParent = parent->_prev;

// 		parent->_right = subRL;
// 		subR->_left = parent;

// 		parent->_prev = subR;

// 		if (subRL)
// 			subRL->_prev = parent;
// 		if (_root == parent)
// 		{
// 			_root = subR;
// 			_root->_prev = NULL;
// 		}

// 		else
// 		{

// 			if (parentParent->_left == parent)
// 				parentParent->_left = subR;
// 			else
// 				parentParent->_right = subR;
// 			subR->_prev = parentParent;
// 		}
// 	}
// 	void rotate_right(Node* parent)
// 	{
// 		Node* subL = parent->_left;
// 		Node* subLR = subL->_right;
// 		Node* parentParent = parent->_prev;

// 		parent->_left = subLR;
// 		subL->_right = parent;

// 		if (subLR)
// 			subLR->_prev = parent;
// 		parent->_prev = subL;

// 		if (_root == parent)
// 		{
// 			_root = subL;
// 			_root->_prev = NULL;
// 		}

// 		else
// 		{

// 			if (parentParent->_left == parent)
// 				parentParent->_left = subL;
// 			else

// 				parentParent->_right = subL;

// 			subL->_prev = parentParent;
// 		}
// 	}





























};




} //namespace ft
