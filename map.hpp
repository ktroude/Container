#include <functional>
#include "./iterator/bidirectional_iterator.hpp"

template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > > 
class map
{

    public:

typedef Key                         key_type;
typedef T                           mapped_type;
typedef std::pair<const Key, T>     value_type;
typedef std::size_t                 size_type;
typedef std::ptrdiff_t              difference_type;
typedef Compare                     key_compare;
typedef Allocator                   allocator_type;
typedef value_type&                 reference;
typedef const value_type&           const_reference;
typedef Allocator::pointer          pointer;
typedef Allocator::const_pointer    const_pointer;
 
typedef typename ft::bidirectional_iterator<value_type> iterator;
typedef typename ft::bidirectional_iterator<value_type> const_iterator;
typedef typename ft::reverse_iterator<iterator>         reverse_iterator;
typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator;

    protected:

allocator_type  _alloc;


};