#include <functional>
#include "./iterator/bidirectional_iterator.hpp"
#include "./iterator/pair.hpp"

namespace ft
{


enum Color
{
	RED,
	BLACK
};

template<class T = ft::pair<class K, class V>, class Allocator = std::allocator<T> >
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

template<class T = ft::pair<class K, class V> > //,class reference = T&, class Ptr
struct TreeIterator
{
	typedef RBTreeNode<T>               Node;    //Type of node
	typedef TreeIterator<T>				iterator;    //Type of forward iterator
	typedef T*							pointer;
	typedef T&							reference;
    Node	*_node;                                //Encapsulated pointer

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

    public:

TreeIterator(Node* node) :_node(node) {}
TreeIterator() : _node(NULL) {}

iterator operator=(const iterator& it)
{	if (*this != it)
		_node = it._node;
	return *this;	}

reference operator*()
{   return _node->_data;    }

pointer operator->()
{   return _node->_data;    }

bool  operator ==(const iterator& s) const
{   return _node == s._node;    }

bool  operator !=(const iterator& s) const
{   return !(_node == s._node);    }

iterator& operator++()
{
    Increment();
    return *this;
}

iterator operator++(int)
{
	iterator tmp = iterator(this->_node);
    Increment();
    return tmp;
}

iterator& operator--()
{
    Decrement();
    return *this;
}

iterator operator--(int)
{
	iterator tmp = iterator(this->_node);
    Decrement();
    return tmp;
}

};


template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
    public:

typedef Key										key_type;				// the key (obviously)
typedef T										mapped_type;			// value associated to key
typedef ft::pair<const Key, T>					value_type;
typedef size_t 									size_type;
typedef std::ptrdiff_t 							difference_type;
typedef Compare									key_compare;			// --> ??
typedef Allocator 								allocator_type;
typedef value_type&								reference;
typedef const value_type& 						const_reference;
typedef typename Allocator::pointer				pointer;
typedef typename Allocator::const_pointer		const_pointer;
typedef TreeIterator<value_type>				iterator;
typedef const iterator							const_iterator;
typedef ft::reverse_iterator<iterator>			reverse_iterator;
typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
typedef RBTreeNode<value_type>					Node;
	
class value_compare : public std::binary_function<value_type, value_type, bool>
{
    friend class map;
	protected:
key_compare comp;
value_compare(key_compare c) : comp(c) {}
	public:
bool operator()(const value_type& x, const value_type& y) const
    {	return comp(x.first, y.first);	}
};

    protected:

Node    		*_root;
allocator_type	_alloc;
value_compare	_comp;
	
	public:
    
map() :_root(NULL), _alloc(Allocator()), _comp(Compare()) {}
explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) : _root(NULL), _alloc(alloc), _comp(comp){}

// template< class InputIt >
// map( InputIt first, InputIt last,const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _alloc(alloc), _comp(comp)
// {	insert(first, last);	}

map( const map& other ) 
{	for (iterator it = other.begin; it != other.end(); it++)
		insert(*it);
}


~map() 
{	for (iterator it = begin(); it != end(); it++)
		delNode(it._node);
}

map& operator=( const map& other )
{	for (iterator it = other.begin(); it != other.end(); it++)
		insert(*it);
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

T& operator[]( const Key& key )
{	for (iterator it = begin(); it != end(); it++)
		if (it->_node->_data.first == key)
			return it->_node->_data.second;
	return _root->_data.second;
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
	Node* left = _root;
	while (left && left->_left)
		left = left->_left;
	return const_iterator(left);
}

iterator end() // Most right node (ether NIL or NULL)  -> try implement NIL (safer)
{   return iterator(NULL);  }

const_iterator end() const
{	return const_iterator(NULL);	}

reverse_iterator rbegin();
const_reverse_iterator rbegin() const;

reverse_iterator rend();
const_reverse_iterator rend() const;

bool empty() const
{	return _root ? false : true;	}

size_type size() const
{	
	size_type n = 0;	
	for (iterator it = begin(); it != end(); it++)
		n++;
		return n;
}

size_type max_size() const
{	return _alloc.max_size();	}

void clear()
{	for (iterator it = begin(); it != end(); it++)
		delNode(it->_node);	}

iterator find (const value_type& key)
{
	iterator it = begin();
	for (; it != end(); ++it)
		if (it._node->_data == key)
			return it;
	return end();
}

const_iterator find( const Key& key ) const
{	
	const_iterator it = begin();
	for (; it != end(); ++it)
		if (it._node->_data == key)
			return it;
	return end();
}


ft::pair<iterator, bool> insert( const value_type& value )
{
	iterator it = find(value);
	if (it != NULL)					// check, is value already exist in the tree?
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
		if (value.first > current->_data.first)
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

	private:

Node	*creatNode(value_type value)
{
	Node	*newNode = Node(value);
	newNode->_ptr = _alloc.allocate(1);
	_alloc.construct(newNode->_ptr, value);
	return newNode;
}

void	delNode(Node *to_del)
{
	_alloc.destroy(to_del->_ptr);
	_alloc.deallocate(to_del->_ptr, 1);
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




} //namespace ft




















/*

template <class T>
struct Node
{
    Node                        *_prev;
    Node                        *_right;
    Node                        *_left:
    char                        _color;     // 'R'(red) && 'B' (black)
    T                           _data;
    bool                        _NIL;       // true = NIL | false = no NIL
    std::allocator<T>           _alloc;
    std::allocator<T>::pointer  _ptr;

    Node(const &T x) : _prev(NULL), _right(NULL), _left(NULL), _color('R'), _data(x), _NIL(false)
    {   _ptr = _alloc.allocate(1); 
        _alloc.construct(_ptr, _data);  }
    
    Node() : _prev(NULL), _right(NULL), _left(NULL), _color('B'), _NIL(true)
    {   _ptr = _alloc.allocate(1);
        _alloc.construct(_ptr, 0);  }
};



template<class T>
class RBTree
{

	public:

typedef typename ft::RBTreeIterator<T>	iterator;


    protected:
Node    *_root;
Node    *_current;  // utile? a voir

    public:
RBTree()
{   _root = &Node();
    _current = _root;   }

RBTree(const T& x)
{   _root = &Node(x);
    _current = _root;   }

Node    *creatNode()
{   return & Node();    }

Node    *creatNode(const T& x)
{   return & Node(x);   }

void    delNode(Node *n)
{   n->_alloc.destroy(n->_ptr);
    n->_alloc.deallocate(n->_ptr, 1);   }

iterator begin()
{
	Node* left = _root;
	while (left->_NIL == false) //&& left->_left->_NIL == false)
		left = left->_left;
	return iterator(left);
}

iterator end()
{
	Node* right = _root;
	while (right->_NIL == false)
		right = right->_right;
	right = right->_right;
	return iterator(right);
}



};


template<class T>
struct RBTreeIterator
{
    private:

Node* _current;

    public:

typedef RBTree<T> 			Node;
typedef RBTreeIterator<T> 	iterator;

RBTreeIterator(Node* n= NULL) :_current(n) {} // Constructors 

T& operator*() 
{   return _current->_data;    }

T* operator->() 
{   return &(_current->_data);  }

iterator& operator++()
{
	Increment();
	return *this;
}

iterator& operator++(int) 
{
	iterator tmp = this;
	Increment();
	return tmp;
}
	
iterator& operator--()
{
	Decrement();
	return *this;
}

iterator& operator--(int) 
{
	iterator tmp = this;
	Decrement();
	return tmp;
}

bool operator==(const iterator& s) 
{	return _current == s._current;	}

bool operator!=(const iterator& s) 
{	return _current != s._current;	}

    private:

void Increment()
{   
	if (_node->_right)
	{
		// The next access is the first node in the middle order in the right tree
		Node* left = _current->_right;
		while (left->_left)
		{
		    left = left->_left;
		}
			_current = left;//++Then it becomes the node
	}
	else  //The right subtree is empty
	{ 
	    //Find an ancestor whose child is not on the father's right
		Node* cur = _node;
		Node* prev = cur->_prev;
		while (prev && cur == prev->_right)
		{
			cur = cur->_prev;
			prev = prev->_prev;
		}
		_current = prev;	//++Then it becomes the node
	}
	return *this;
}

void Decrement() 
{
	if (_node->_left)
	{
			// The next access is the first node in the middle order in the right tree
		Node* left = _current->_left;
		while (right->_right)
		{
			right = right->_right;
		}
		_current = right;
		}
	else
	{
		Node* cur = _node;
		Node* parent = cur->_parent;
		while (parent && cur == parent->_left)
		{
		cur = cur->_parent;
		parent = parent->_parent;
		}
		_current = parent;
	}
	return *this;
}
};



template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > 
class map
{

    public:

typedef Key                         key_type;
typedef T                           mapped_type;
typedef ft::pair<const Key, T>      value_type;
typedef std::size_t                 size_type;
typedef std::ptrdiff_t              difference_type;
typedef Compare                     key_compare;
typedef value_type&                 reference;
typedef const value_type&           const_reference;
 

typedef typename ft::RBTreeIterator<value_type> 		iterator;
typedef typename ft::bidirectional_iterator<const value_type>	const_iterator;


// typedef typename ft::bidirectional_iterator<value_type> iterator;
// typedef typename ft::bidirectional_iterator<value_type> const_iterator;
typedef typename ft::reverse_iterator<iterator>         reverse_iterator;
typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator;

    protected:

RBTree<ft::pair<K,V> _tree;

    public:

ft::pair<iterator, bool> insert( const value_type& value )
{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_color = BLACK;//The root node is black
			return make_pair(_root, true);
		}
}

template< class InputIt >
void insert( InputIt first, InputIt last )
{

}








*/


