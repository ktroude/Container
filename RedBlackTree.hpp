#pragma once

#include <memory>
#include <iostream>
#include "./iterator/pair.hpp"
#include "./iterator/iterator.hpp"

enum Color
{
	RED,
	BLACK
};

template<class T, class Allocator = std::allocator<T> >
struct RBTreeNode
{
	RBTreeNode<T>*  			_left;      //Left child of node
	RBTreeNode<T>*  			_right;     //Right child of node
	RBTreeNode<T>*  			_prev;      //Parents of nodes		
	T               			_data;      //Stored data (ft::pair<K, V> for map && ft::pair<K, K> for set)
	Color           			_color;     //The color of the node
	typename std::allocator<T>::pointer	_ptr;		//Pointer used for allocator functions
	
	RBTreeNode(const T& x) :_left(NULL) ,_right(NULL) ,_prev(NULL) ,_data(x) ,_color(RED) {}
};

template<class T> //,class reference = T&, class Ptr
struct TreeIterator
{
	typedef RBTreeNode<T>               Node;    //Type of node
	typedef TreeIterator<T>   TreeIt;    //Type of forward iterator
	typedef T*							pointer;
	typedef T&							reference;
    Node* _node;                                //Encapsulated pointer

    private:

// Incr && Decr private cause used in pre and post Incr/Decr
TreeIt& Increment()
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

TreeIt& Decrement() // Same logic as Increment but here going to left
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

    public:

TreeIterator(Node* node) :_node(node) {}

reference operator*()
{   return _node->_data.first;    }

reference operator->()
{   return &_node->_data.first;    }

bool  operator ==(const TreeIt& s) const
{   return _node == s._node;    }

bool  operator !=(const TreeIt& s) const
{   return !(_node == s._node);    }

TreeIt& operator++()
{
    Increment();
    return *this;
}

// TreeIt& operator++(int)
// {
//     TreeIt tmp = *this;
//     Increment();
//     return tmp;
// }

TreeIt& operator--()
{
    Decrement();
    return *this;
}

// TreeIt& operator--(int)
// {
//     TreeIt tmp = *this;
//     Decrement();
//     return tmp;
// }


};



template<class K, class T, class KeyOfT>    // struct KeyofT defined in set or map class    // class T -> ether :   ft::pair<K, V> (map) || class T = class K (set)
class RBTree
{
    public:
	
typedef RBTreeNode<T>				Node;
typedef TreeIterator<T>		iterator;
typedef std::allocator<Node>		allocator_type;
	
    protected:

Node    		*_root;
allocator_type	_alloc;    
	
	public:
    
RBTree() :_root(NULL) {}

iterator begin()    // Most left node
{
	Node* left = _root;
	while (left && left->_left)
	{
		left = left->_left;
	}
	return iterator(left);
}

iterator end()  // Most right node (ether NIL or NULL)  -> try implement NIL (safer)
{   return iterator(NULL);  }

Node	*creatNode(T value)
{
	Node	*newNode = _alloc.allocate(1);
	_alloc.construct(newNode, value);
	return newNode;
}

void	delNode(Node *to_del)
{
	_alloc.destroy(to_del);
	_alloc.deallocate(to_del, 1);
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

void	printTree()
{
	for (iterator it = begin(); it != end(); ++it)
		std::cout << "key = " << *it << std::endl;
}

iterator find (const KeyOfT& k)
{
	iterator it = begin();
	for (; it != end(); ++it)
		if (*it == k)
			return it;
	return end();
}
 
ft::pair<iterator, bool> insert( const T& value )
{
	if (find(value) != NULL)					// check, is value already exist in the tree?
		return (ft::make_pair(end(), false));
	Node *NewNode = creatNode(value);	
	if (_root == NULL)
	{
		_root = NewNode;
		_root->_color = BLACK;
		return ft::make_pair(iterator(NewNode), true);
	}
	Node	*current = _root;
	Node	*parent = NULL;
	while (current) 
	{
		parent = current;
		if (value > current->_data.first)
			current = current->_right;
		else
			current = current->_left;
	}
	current = NewNode;
	current->_prev = parent;						// creat link between the NewNode and his parent
	if (current->_data.first > parent->_data.first)			// create link between parent && NewNode
		parent->_right = current;
	else
		parent->_left = current;
	ajustTree(current);
	return ft::make_pair(iterator(current), true);
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
		if (parent && n == parent->_right && gp && parent == gp->_right)
		{
			rotate_left(parent);
			ajustTree(gp);
		}
		if (parent && n == parent->_left && gp && parent == gp->_left)
		{
			rotate_right(parent);
			ajustTree(gp);
		}
	}
	return ;
}

void rotate_left(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* parentParent = parent->_prev;
		//先旋转
		parent->_right = subRL;
		subR->_left = parent;

		parent->_prev = subR;
		//在改父亲结点
		if (subRL)
			subRL->_prev = parent;
		if (_root == parent)
		{
			_root = subR;
			_root->_prev = NULL;
		}

		else
		{
			//subR旋转后可能是左右子树2种情况
			if (parentParent->_left == parent)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;
			subR->_prev = parentParent;
		}
	}
	void rotate_right(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* parentParent = parent->_prev;//记录parent的父亲结点
		//subLR做parent->_left
		parent->_left = subLR;
		subL->_right = parent;
		//同时更新动的2个节点的parent
		//注意subLR还可能是空结点
		if (subLR)
			subLR->_prev = parent;
		parent->_prev = subL;
		//parent可能是单独的树，或者子树,分情况
		if (_root == parent)
		{
			_root = subL;
			_root->_prev = NULL;
		}

		else
		{
			//还有可能parent是子树，可能是左子树
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				//也可能是右子树
				parentParent->_right = subL;
			//调整subL的父亲结点
			subL->_prev = parentParent;
		}
	}



};











