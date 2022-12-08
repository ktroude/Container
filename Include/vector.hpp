#pragma once

//allocate   -> malloc array
//constrcut  -> malloc elements

//destroy    -> free elements
//deallocate -> free array

//#include <vector>

#include "./iterator/cmp.hpp"
#include "./iterator/enable_if.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include "./iterator/random_access_iterator.hpp"
#include "./iterator/bidirectional_iterator.hpp"

namespace ft
{

template <typename T, typename Allocator = std::allocator<T> >
class vector
{

    public:

typedef T                   value_type;
typedef Allocator           allocator_type;
typedef size_t              size_type;
typedef std::ptrdiff_t      difference_type;
typedef value_type&         reference;
typedef const value_type&   const_reference;

typedef typename Allocator::pointer                             pointer;
typedef typename Allocator::const_pointer                       const_pointer;
typedef typename ft::random_access_iterator<value_type>         iterator;
typedef typename ft::random_access_iterator<const value_type>   const_iterator;
typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator;

    protected:

pointer         _begin;
pointer         _end;
pointer         _end_capacity;
allocator_type  _alloc;

    protected:

template <class InputIt>
difference_type  distance( InputIt first, InputIt last )
{   InputIt save = first;
    difference_type   n = 0;
    for (; first != last; first++)
        n++;
    first = save;
    return n;
}

    public:

// constructor

vector() : _begin(NULL), _end(NULL), _end_capacity(NULL) {}    // alloacte(1 ou 0) ???
explicit vector( const Allocator& alloc ) : _alloc(alloc), _begin(NULL), _end(NULL), _end_capacity(NULL) {}
explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : _alloc(alloc)
{   this->_begin = this->_alloc.allocate(count);
    this->_end_capacity = this->_begin + count;
    this->_end= this->_begin;
    for (; count > 0; count--)
        this->_alloc.construct(_end++, value);    // malloc un tableau de taille begin-end, incremente end pour qu il pointe apres le tableau (iterator end() tmtc)
}

template< class InputIt >
vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::valor>::type* = NULL) : _alloc(alloc) 
{   
    difference_type dif = this->distance(first, last);
    this->_begin = this->_alloc.allocate(dif);
    this->_end_capacity = this->_begin + dif;
    this->_end= this->_begin;
    for (; dif > 0; dif--) 
        this->_alloc.construct(_end++, *(first++));
}

vector( const vector& src) : _alloc(src._alloc)
{
    size_type n = src.size();
    this->_begin = this->_alloc.allocate(n);
    this->_end = this->_begin;
    this->_end_capacity = this->_begin + n;
    pointer src_ptr = src._begin;
    while (n--) 
        this->_alloc.construct(this->_end++, *src_ptr++);
}

// destructor
~vector()
{   
    this->clear();
    this->_alloc.deallocate(this->_begin, this->capacity());
}

vector& operator=(const vector& x)
{
    if (this != &x)
    {
        this->clear();
        this->insert(this->_begin, x.begin(), x.end());
    }
    return *this;
}

// assign() -   assigns values to the container
void assign( size_type count, const T& value )
{
    this->clear();
    if (count <= this->capacity())
        while (count--)
            this->_alloc.construct(_end++, value);
    else
    {
        this->_alloc.deallocate(this->_begin, this->capacity());
        this->_begin = this->_alloc.allocate(count);
        _end_capacity = this->_begin + count;
        this->_end = this->_begin;
        while (count--) 
            this->_alloc.construct(_end++, value);
    }
}

template <class InputIt>
void assign( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::valor>::type* = NULL)
{
    size_type n = distance(first, last);
    if (this->capacity() < n) {
        this->_begin = this->_alloc.allocate(n);
        this->_end_capacity = this->_begin + n;
        this->_end = this->_begin;
    } else 
        this->clear();
    while (n--)
        this->_alloc.construct(this->_end++, *first++);
}

// get_allocator()  -   returns the associated allocator
allocator_type get_allocator() const
{   return this->_alloc;  }



/*  Element access  */

// at() -   access specified element with bounds checking (throw exception)
reference at( size_type pos )
{    
    if (pos >= size())
        throw std::out_of_range("out of range\n");
    return this->_begin[pos];
}

const_reference at( size_type pos ) const
{    
    if (pos >= size())
        throw std::out_of_range("out of range\n");
    return this->_begin[pos];
}

// operator []  -   access specified element
reference operator[]( size_type pos )
{   return  this->_begin[pos];}

const_reference operator[]( size_type pos ) const
{   return  this->_begin[pos];}

// front()   -   access the first element
reference front()
{   return  *this->_begin;   }
const_reference front() const
{   return  *this->_begin;   }

// back()   -   access the first element
reference back()
{   return *(this->_end- 1); }
const_reference back() const
{   return *(this->_end- 1); }

// data()   -   direct access to the underlying array
T* data()
{   return *this->_begin;    }
const T* data() const
{   return *this->_begin;    }



/*  Iterators   */

// begin()  -   returns an iterator to the beginning
iterator begin()
{   return this->_begin;    }    
const_iterator begin() const
{   
    const_iterator  it(this->_begin);
    return it; 
}

// end()    -   returns an iterator to the end
iterator end()
{   return _end;    }
const_iterator end() const
{   return _end;    }

// rbegin() -   returns a reverse iterator to the beginning
reverse_iterator rbegin()
{   return reverse_iterator(end()); }
const_reverse_iterator rbegin() const
{   return reverse_iterator(end()); }

//rend()    -  returns a reverse iterator to the end 
reverse_iterator rend()
{   return reverse_iterator(begin()); }
const_reverse_iterator rend() const
{   return reverse_iterator(begin()); }



/*  Capacity    */

//  empty() -   checks whether the container is empty
bool empty() const
{   return (this->_end == this->_begin);    }

// size()    -   returns the number of elements
size_type size() const
{  return (this->_end - this->_begin); }

// max_size()   -   returns the maximum possible number of elements
size_type max_size() const
{   return this->_alloc.max_size();   }

void reserve(size_type n)
{
    if (n > this->max_size())
        {throw std::out_of_range("max size reached");}
    if (this->capacity() >= n)
        return;
    
    pointer prev_start = this->_begin;
    pointer prev_end = this->_end;
    size_type prev_capacity = this->capacity();

    this->_begin = this->_alloc.allocate(n);
    this->_end_capacity = this->_begin + n;
    this->_end = this->_begin;

    for (pointer target = prev_start; target != prev_end; ++target)
        this->_alloc.construct(this->_end++, *target);
    for (size_type len = prev_end - prev_start; len > 0; --len)
        this->_alloc.destroy(--prev_end);
    this->_alloc.deallocate(prev_start, prev_capacity);
}

// capacity()   -   returns the number of elements that the container has currently allocated space for.
size_type capacity() const
{   return (this->_end_capacity - this->_begin);    }

/*  Modifiers   */

// clear()  -   clears the contents
void clear()
{   while (this->_begin != _end)
        this->_alloc.destroy(--_end); }

// insert() -   inserts elements
iterator insert( iterator pos, const T& value ) //  inserts value before pos
{
    pointer p = this->_begin + (pos - this->begin());
    pointer ret = p;
    if (this->_end < this->_end_capacity)
    {
        if (p == this->_end)
            this->_alloc.construct(this->_end++, value);
        else
        {
            this->_alloc.construct(this->_end, *(this->_end - 1));
            for (pointer tmp = this->_end - 1; tmp != p; tmp--)
                *tmp = *(tmp - 1);
            *p = value;
            ret = p;
            this->_end++;
        }
    }
    else
    {
        allocator_type& a = this->_alloc;               // new _alloc
        pointer begin = a.allocate(this->size() + 1);   // new _begin
        pointer end = begin;                            // new _end
        pointer tmp = this->_begin;                     // pour se balader dans _alloc sans bouger _begin
        while (tmp != p)
            a.construct(end++, *tmp++);
        ret = end;
        a.construct(end++, value);
        while (tmp != this->_end && p != this->_end)
            a.construct(end++, *tmp++);
        this->clear();
        this->_alloc.deallocate(this->_begin, this->capacity());
        this->_begin = begin;
        this->_end = end;
        this->_alloc = a;
        this->_end_capacity = this->_end;
    }
    return iterator(ret);
}

void insert( iterator pos, size_type count, const T& value )   // inserts count copies of the value before pos
{
    pointer p = this->_begin + (pos - this->begin());
    if (count > 0)
    {
        allocator_type& a = this->_alloc;
        pointer begin = a.allocate(this->size() + count);
        pointer end = begin; 
        pointer tmp = this->_begin;
        while (tmp != p && p != this->_begin)
            a.construct(end++, *tmp++);
        while (count--)
            a.construct(end++, value);
        while (tmp != this->_end)
            a.construct(end++, *tmp++);
        this->clear();
        this->_alloc.deallocate(this->_begin, this->capacity());
        this->_begin = begin;
        this->_end = end;
        this->_alloc = a;
        this->_end_capacity = this->_end;
    }
}


template< class InputIt >
void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::valor>::type* = NULL ) // inserts elements from range [first, last) before pos.
{
    pointer p = this->_begin + (pos - this->begin());
    allocator_type& a = this->_alloc;
    size_type n = 0;
    for (InputIt it = first; it != last; it++)
        n++;
    pointer begin = a.allocate(this->size() + n);
    pointer end = begin; 
    pointer tmp = this->_begin;
    while (tmp != p && p != this->_begin)
        a.construct(end++, *tmp++);
    for (InputIt it = first; it != last; it++)
        a.construct(end++, *it);
    while (tmp != this->_end)
        a.construct(end++, *tmp++);
    this->clear();
    this->_alloc.deallocate(this->_begin, this->capacity());
    this->_begin = begin;
    this->_end = end;
    this->_alloc = a;
    this->_end_capacity = this->_end;
}

//erase()   -   erases elements
iterator erase( iterator pos ) // Removes the element at pos.
{
    difference_type ps = pos - this->begin();
    pointer p = this->_begin + ps;
    iterator ret = iterator(p);
    while (p + 1 != this->_end)
    {   *p = *(p + 1);
        p++;    }
    this->_alloc.destroy(--this->_end);
    return ret;
}

iterator erase( iterator first, iterator last ) // Removes the elements in the range [first, last)
{
    pointer p = this->_begin + (first - this->begin());
    iterator r = iterator(p);
    if (first != last)
    {
        while (p + (last - first) != this->_end)
        {   *p = *(p + (last - first));
            p++;    }
        while (last-- != first)
            this->_alloc.destroy(--this->_end);
    }
    return r;
}

// push_back()   -   adds an element to the end
void push_back( const T& value )
{   
    if (this->size() == 0)
        reserve(1);
    else if (this->_end == this->_end_capacity)
        reserve(capacity() * 2);
    this->_alloc.construct(_end++, value);
}
void pop();
// pop_back()   -   removes the last element
void pop_back()
{   _alloc.destroy(--_end); }


void resize( size_type count )
{   if (count < this->size())
    {
        while (this->size() != count)
            _alloc.destroy(--_end);
        _end_capacity = _begin + count;
    }
    else if (count > this->size())
    {
        reserve(count);
        while (_end != _end_capacity)
            _alloc.construct(_end++, 0);
    }
}

void resize( size_type count, T value)
{   if (count < this->size())
    {
        while (this->size() != count)
            _alloc.destroy(--_end);
        _end_capacity = _begin + count;
    }
    else if (count > this->size())
    {
        reserve(count);
        while (_end != _end_capacity)
            _alloc.construct(_end++, value);
    }
}

// swap()   -   Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
void swap( vector& other )
{
    pointer         begin_s = this->_begin;
    pointer         end_s = this->_end;
    pointer         end_capacity_s = this->_end_capacity;
    allocator_type  alloc_s = this->_alloc;
    
    this->_begin = other._begin;
    this->_end = other._end;
    this->_end_capacity = other._end_capacity;
    this->_alloc = other._alloc;
    
    other._begin = begin_s;
    other._end = end_s;
    other._end_capacity = end_capacity_s;
    other._alloc = alloc_s;
}

};

/*  No mumber ft (operator overload) */

template <typename T>
bool    operator==(const ft::vector<T>& x, const ft::vector<T>& y)
{
    if (x.size() != y.size())
        return false;
    typename ft::vector<T>::const_iterator it1 = x.begin();
    typename ft::vector<T>::const_iterator it2 = y.begin();
    for (size_t i = x.size(); i < x.size(); i++)
        if (*(it1 + i) != *(it2 + i))
                return false;
    return true;
}   

template <typename T>
bool    operator!=(const ft::vector<T>& x, const ft::vector<T>& y)
{   return !(x == y);    }

template <typename T>
bool operator<(const ft::vector<T>& x, const ft::vector<T>& y)
{   return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }

template <typename T>
bool operator>(const ft::vector<T>& x, const ft::vector<T>& y)
{   return y < x;   }

template <typename T>
bool operator>=(const ft::vector<T>& x, const ft::vector<T>& y)
{   return !(x < y);    }

template <typename T>
bool operator<=(const ft::vector<T>& x, const ft::vector<T>& y)
{   return !(x > y);    }

}