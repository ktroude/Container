#pragma once

#include "iterator.hpp"

namespace ft
{

template <typename T>
class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
{
    public:

typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;        
typedef T* pointer;
typedef T& reference;

    protected:

pointer _current;

    public:

random_access_iterator() : _current(NULL){}
random_access_iterator(pointer ptr) : _current(ptr){};
random_access_iterator(const random_access_iterator<T>& src) : _current(src._current) {}
~random_access_iterator() {}
pointer base() const {  return _current;    } // get_current()

operator random_access_iterator<const T> () const   // cast iterator -> const iterator
{   return _current;    }

reference   operator*() const
{   return *_current;   }

pointer     operator->() const
{   return _current;    }

reference   operator[](difference_type n) const
{   return *(_current + n); }

random_access_iterator& operator++()
{   ++_current;
    return *this;   }

random_access_iterator operator++(int)
{   random_access_iterator  tmp(_current);
    ++_current;
    return  tmp;  }

random_access_iterator& operator--()
{   --_current;
    return  *this;  }

random_access_iterator  operator--(int)
{   random_access_iterator  tmp(*this);
    --_current;
    return  tmp;    }

random_access_iterator operator+(difference_type n) const
{   return random_access_iterator(_current + n);    }

random_access_iterator operator-(difference_type n) const
{   return random_access_iterator(_current - n);    }

random_access_iterator&  operator+=(difference_type n)
{   _current += n;
    return *this;   }

random_access_iterator&  operator-=(difference_type n)
{   _current -= n;
    return *this;   }

};

template <class Iterator1, class Iterator2>
bool    operator==(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs)
{   return (lhs.base() == rhs.base());    }

template <class Iterator1, class Iterator2>
bool    operator!=(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs)
{   return (lhs.base() != rhs.base());    }

template <class Iterator1, class Iterator2>
bool    operator<(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
{   return (lhs.base() < rhs.base());   }

template <class Iterator1, class Iterator2>
bool    operator<=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
{   return (lhs.base() <= rhs.base());  }

template <class Iterator1, class Iterator2>
bool    operator>(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
         {  return (lhs.base() > rhs.base());   }

template <class Iterator1, class Iterator2>
bool    operator>=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
{   return (lhs.base() >= rhs.base());  }

template <class Iter>
ft::random_access_iterator<Iter> operator+(typename ft::random_access_iterator<Iter>::difference_type n, const ft::random_access_iterator<Iter>& it)
{   return ft::random_access_iterator<Iter>(it.base() + n);}

template <class Iterator1, class Iterator2>
typename ft::random_access_iterator<Iterator1>::difference_type operator+(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
{   return lhs.base() + rhs.base(); }


template <class Iterator1, class Iterator2>
typename ft::random_access_iterator<Iterator1>::difference_type operator-(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
{   return lhs.base() - rhs.base(); }

}; //namespace ft