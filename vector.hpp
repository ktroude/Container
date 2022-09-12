#pragma once

//allocate   -> malloc array
//constrcut  -> malloc elements

//destroy    -> free elements
//deallocate -> free array

//#include <vector>

#include <iostream>
#include <memory>
#include <stdexcept>
#include "./iterator/random_access_iterator.hpp"

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

template< class InputIt >
difference_type  distance( InputIt first, InputIt last )
{   difference_type   n = 0;
    for (; first != last; first++)
        n++;
    return n;   }

//pointer allocate(size_type n) 
//{ return _alloc.allocate(n); }

    public:

// constructor

vector() : _begin(NULL), _end(NULL), _end_capacity(NULL) {_alloc.allocate(1);}    // alloacte(1 ou 0) ???
explicit vector( const Allocator& alloc ) : _alloc(alloc), _begin(NULL), _end(NULL), _end_capacity(NULL) {}
explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : _alloc(alloc)
{   this->_begin = this->_alloc.allocate(count);
    this->_end_capacity = this->_begin + count;
    this->_end= this->_begin;
    for (; count > 0; count--)
        this->_alloc.construct(_end++, value);    // malloc un tableau de taille begin-end, incremente end pour qu il pointe apres le tableau (iterator end() tmtc)
}

template< class InputIt >
vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ) : _alloc(alloc) 
{   
    difference_type dif = ft::distance(first, last);
    this->_begin = this->_alloc.allocate(dif);
    this->_end_capacity = this->_begin + dif;
    this->_end= this->_begin;
    for (; dif > 0; dif--) 
        this->_alloc.construct(_end++, *first++); }

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

vector& operator=( const vector& other )
{   if (this != &other)
    {
        this->clear();
        this->_alloc.deallocate(this->_begin, this->capacity());
        this->_begin = this->_end= this->_end_capacity = NULL;
        const_iterator it(other.begin());
        difference_type dif = other._end_capacity - other._begin;
        this->_begin = this->_alloc.allocate(dif);
        _end_capacity = this->_begin + dif;
        this->_end= this->_begin;
        for (; dif > 0 ; dif--)
            this->_alloc.construct(_end++, *it++);
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
void assign( InputIt first, InputIt last )
{
            size_type n = distance(first, last);
            if (this->capacity() < n) {
                this->_begin = this->_alloc.allocate(n);
                this->_end_capacity = this->_begin + n;
                this->_end = this->_begin;
            } else 
            { this->clear(); }
            while (n--)
            this->_alloc.construct(this->_end++, *first++);
}

// get_allocator()  -   returns the associated allocator
allocator_type get_allocator() const
{   return this->_alloc;  }



/*  Element access  */

// at() -   access specified element with bounds checking (throw exception)
reference at( size_type pos )
{    if (pos >= size())
        throw std::out_of_range("out of range\n");
    return this->_begin[pos]; }
const_reference at( size_type pos ) const
{    if (pos >= size())
        throw std::out_of_range("out of range\n");
    return this->_begin[pos]; }

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
{   const_iterator  it(this->_begin);
   return it; }

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
{   return (this->_end== this->_begin);    }

// size()    -   returns the number of elements
size_type size() const
{   return (size_type)(this->_end- this->_begin);  }

// max_size()   -   returns the maximum possible number of elements
size_type max_size() const
{   return this->_alloc.max_size();   }

// reserve()    -   increase the capacity of the vector
void reserve( size_type new_cap )
{
    if (new_cap > max_size())
        throw std::length_error("max size reached.\n");
    if (new_cap <= size())
        return ;
    pointer b = this->_begin;
    pointer e = _end;
    size_type c = this->capacity();
    this->_begin = this->_alloc.allocate(new_cap);
    this->_end= this->_begin;
    _end_capacity = this->_begin + new_cap;
    for (pointer p = b; p != e; p++)
        this->_alloc.construct(_end++, *p);
    while (b != e)
        this->_alloc.destroy(--e);
    this->_alloc.deallocate(b, c);
}

// capacity()   -   returns the number of elements that the container has currently allocated space for.
size_type capacity() const
{   size_type   n = 0;
    for (const_iterator it = this->begin(); it != this->end(); it++)
        n++;
    return n;   }


/*  Modifiers   */

// clear()  -   clears the contents
void clear()
{   while (this->_begin != _end)
        this->_alloc.destroy(--_end); }

// insert() -   inserts elements
iterator insert( iterator pos, const T& value ); //  inserts value before pos
void insert( iterator pos, size_type count, const T& value );   // inserts count copies of the value before pos
template< class InputIt >
void insert( iterator pos, InputIt first, InputIt last ); // inserts elements from range [first, last) before pos.

//erase()   -   erases elements
iterator erase( iterator pos ); // Removes the element at pos.
iterator erase( iterator first, iterator last ); // Removes the elements in the range [first, last)

// push_back()   -   adds an element to the end
void push_back( const T& value )
{   if (size() > capacity())
        reserve(capacity() * 2);
    *_end++ = value;
}

// pop_back()   -   removes the last element
void pop_back();

// resize() -   changes the number of elements stored
void resize( size_type count );
void resize( size_type count, T value = T() );

// swap()   -   Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
void swap( vector& other );

};

/*  No mumber ft (operator overload) */

/*
template <typename T>
bool    operator==(ft::vector<T> &src)
{
    if (size() != src.size())
        return false;
    for (iterator i = begin(); i != end(); i++)
        if (* != src.m_Data[i])
            return false;
    return true;
}

bool    operator==(const vector &src)
{
    if (m_Size != src.m_Size)
        return false;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] != src.m_Data[i])
            return false;
    return true;
}

bool    operator!=(vector &src)
{
    if (m_Size != src.m_Size)
        return true;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] != src.m_Data[i])
            return true;
    return false;
}

bool    operator!=(const vector &src)
{
    if (m_Size != src.m_Size)
        return true;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] != src.m_Data[i])
            return true;
    return false;
}

bool    operator>=(const vector &src)
{
    if (m_Size < src.m_Size)
        return false;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] < src.m_Data[i])
            return false;
    return true;
}

bool    operator>=(vector &src)
{
    if (m_Size < src.m_Size)
        return false;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] < src.m_Data[i])
            return false;
    return true;
}

bool    operator>(const vector &src)
{
    if (m_Size <= src.m_Size)
        return false;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] <= src.m_Data[i])
            return false;
    return true;
}

bool    operator>(vector &src)
{
    if (m_Size <= src.m_Size)
        return false;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] <= src.m_Data[i])
            return false;
    return true;
}

bool    operator<(const vector &src)
{
    if (m_Size >= src.m_Size)
        return false;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] >= src.m_Data[i])
            return false;
    return true;
}

bool    operator<(vector &src)
{
    if (m_Size >= src.m_Size)
        return false;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] >= src.m_Data[i])
            return false;
    return true;
}

bool    operator<=(const vector &src)
{
    if (m_Size > src.m_Size)
        return false;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] > src.m_Data[i])
            return false;
    return true;
}

bool    operator<=(vector &src)
{
    if (m_Size > src.m_Size)
        return false;
    for (size_t i = 0; i < m_Size; i++)
        if (m_Data[i] > src.m_Data[i])
            return false;
    return true;
}
*/

}