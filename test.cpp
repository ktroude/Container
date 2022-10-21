#include "map.hpp"
#include <map>
#include <iostream>
#include <list>

#define _pair TESTED_NAMESPACE::pair
#define TESTED_NAMESPACE ft
// #define TESTED_NAMESPACE std

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

// --- Class foo
template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo




















#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;

static int iter = 0;

template <typename MAP>
void	ft_erase(MAP &mp, const T1 param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp;

	mp[42] = "lol";

	mp[50] = "mdr";
	mp[25] = "funny";

	mp[46] = "bunny";
	mp[21] = "fizz";
	mp[30] = "buzz";
	mp[55] = "fuzzy";

	mp[18] = "bee";
	mp[23] = "coconut";
	mp[28] = "diary";
	mp[35] = "fiesta";
	mp[44] = "hello";
	mp[48] = "world";
	mp[53] = "this is a test";
	mp[80] = "hey";

	mp[12] = "no";
	mp[20] = "idea";
	mp[22] = "123";
	mp[24] = "345";
	mp[27] = "27";
	mp[29] = "29";
	mp[33] = "33";
	mp[38] = "38";

	mp[43] = "1";
	mp[45] = "2";
	mp[47] = "3";
	mp[49] = "4";
	mp[51] = "5";
	mp[54] = "6";
	mp[60] = "7";
	mp[90] = "8";

	printSize(mp);

	/* A classic btree should give this:
	 *                                      42
	 *                     /                                            \
	 *                    25                                            50
	 *           /                 \                         /                       \
	 *          21                 30                       46                       55
	 *      /       \           /      \                /       \             /           \
	 *     18       23        28        35            44         48         53             80
	 *   /   \    /    \    /    \     /   \        /   \       /   \     /    \         /     \
	 *  12   20  22    24  27    29  33    38     43    45    47    49   51    54       60      90
	 *
	 * */

	ft_erase(mp, 25); // right != NULL; left != NULL
	ft_erase(mp, 55); // right != NULL; left != NULL

	/* After deleting 25 and 55, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    24                                            50
	 *           /                 \                         /                      \
	 *          21                 30                       46                      54
	 *      /       \           /      \                /       \             /           \
	 *     18       23        28        35            44         48         53             80
	 *   /   \    /         /    \     /   \        /   \       /   \     /              /     \
	 *  12   20  22        27    29  33    38     43    45    47    49   51             60      90
	 *
	 * */

	ft_erase(mp, 24); // right != NULL; left != NULL
	ft_erase(mp, 54); // right != NULL; left != NULL

	/* After deleting 24 and 54, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          21                 30                       46                      53
	 *      /       \           /      \                /       \             /           \
	 *     18       22        28        35            44         48         51             80
	 *   /   \              /    \     /   \        /   \       /   \                    /     \
	 *  12   20            27    29  33    38     43    45    47    49                  60      90
	 *
	 * */

	ft_erase(mp, 22); // right == NULL; left == NULL
	ft_erase(mp, 51); // right == NULL; left == NULL

	ft_erase(mp, 21); // right == NULL; left != NULL
	ft_erase(mp, 53); // right != NULL; left == NULL

	/* After deleting 22, 51 and then 21, 53, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          20                 30                       46                      80
	 *      /                   /      \                /       \                /        \
	 *     18                 28        35            44         48             60         90
	 *   /                  /    \     /   \        /   \       /   \
	 *  12                 27    29  33    38     43    45    47    49
	 *
	 * */

	ft_erase(mp, 20); // right == NULL; left != NULL

	/* After deleting 20, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          18                 30                       46                      80
	 *      /                   /      \                /       \                /        \
	 *     12                 28        35            44         48             60         90
	 *                      /    \     /   \        /   \       /   \
	 *                     27    29  33    38     43    45    47    49
	 *
	 * */

	ft_erase(mp, 23); // right != NULL; left != NULL

	/* After deleting 23, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        35            44         48             60         90
	 *                      /    \     /   \        /   \       /   \
	 *                     27    29  33    38     43    45    47    49
	 *
	 * */

	ft_erase(mp, 42); // right != NULL; left != NULL; parent == NULL

	/* After deleting 42, I would get:
	 *                                      38
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        35            44         48             60         90
	 *                      /    \     /            /   \       /   \
	 *                     27    29  33           43    45    47    49
	 *
	 * */

	ft_erase(mp, 38); // right != NULL; left != NULL; parent == NULL

	/* After deleting 38, I would get:
	 *                                      35
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        33            44         48             60         90
	 *                      /    \                  /   \       /   \
	 *                     27    29               43    45    47    49
	 *
	 * */

	ft_erase(mp, 35); // right != NULL; left != NULL; parent == NULL

	/* After deleting 35, I would get:
	 *                                      33
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /                       /       \                /        \
	 *                        28                      44         48             60         90
	 *                      /    \                  /   \       /   \
	 *                     27    29               43    45    47    49
	 *
	 * */

	ft_erase(mp, 33); // right != NULL; left != NULL; parent == NULL

	/* After deleting 33, I would get:
	 *                                      30
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 28                       46                      80
	 *                          /      \                /       \                /        \
	 *                        27       29             44         48             60         90
	 *                                              /   \       /   \
	 *                                            43    45    47    49
	 *
	 * */

	return (0);
}



/*



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
		transplant(n, NULL);
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
	while (n != _root && n->_color == BLACK)
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
			if (x && x->_color == RED) 
			{
				x->_color = BLACK;
				n->_prev->_color = RED;
				rotate_right(n->_prev);
				x = n->_prev->_left;
			}
			if (x && (!x->_right || x->_right->_color == BLACK) && (!x->_left || x->_left->_color == BLACK))
			{
						x->_color = RED;
						n = n->_prev;
			}
			else
			{
				if (x && x->_left->_color == BLACK)
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



*/