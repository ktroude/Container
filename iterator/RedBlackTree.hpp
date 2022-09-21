#pragma once
#include "pair.hpp"

namespace ft
{

enum Color
{
	RED,
	BLACK
};

template<class K, class V>
struct TreeNode
{
	TreeNode<K, V>	*_left;		//Left child of node
	TreeNode<K, V>	*_right;	//Right child of node
	TreeNode<K, V>	*_parent;	//Parents of nodes	
	ft::pair<K, V>	_kv;
	K				_id;
	value			_value;
	Color 			_color;		//The color of the node
	
	RBTreeNode(const pair<K,V>& kv) :_left(NULL) ,_right(NULL) ,_parent(NULL) ,_kv(kv) ,_color(RED) {}
};

template<class K, class V>
class Tree
{
	public:

typedef ft::TreeNode<K, V>					Node;
//typedef ft::TreeNode<K, const V>			const_Node;
typedef V									value;
typedef K									key;
typedef ptrdiff_t 							difference_type;
typedef size_t								size_type;
typedef std::allocator<Node>				allocator_type;
// typedef IterTree<value>					iterator;
// typedef IterTree<const value>			const_iterator;
typedef reverse_iterator<iterator> 			reverse_iterator;
typedef reverse_iterator<const_iterator>	const_reverse_iterator;

	protected:

Node			*_root;
size_type		_size;
allocator_type	_alloc;
// key				_id;
// value			_value;

	public:

RBTree() : _root(NULL) , _size(0), _alloc(allocator_type()) {}
RBTree(const tree& src) : _root(src._tree), _size(src._size), _alloc(src._alloc) {} 

// Node *createNode(value v) 
// {
	// Node *n = _alloc.allocate(1);
	// _alloc.construct(n, v);
	// return (n);
// }

Node *createNode(key k, value v) 
{
	Node *n = _alloc.allocate(1);
	_alloc.construct(n, v);
	n->_value = v;
	n->_id = k;
	return (n);
}

void	deleteNode(Node *n)
{
	_alloc.destroy(n);
	_alloc.deallocate(n, 1);
}

bool	KeyEqual(const Node &lhs, const Node &rhs) const
{	return lhs._id == rhs.id;	}

bool	KeyCmp(const Node &lhs, const Node &rhs) const
{	return lhs._id > rhs.id;	}

Node insert(const pair<K, V>& kv)
	{
		//1. The tree is empty
		if (_root == NULL)
		{
			_root = createNode(k, v);
			_root->_color = BLACK;		// The root node is always black
			return make_pair(_root, true);
		}

};






} // namespace ft