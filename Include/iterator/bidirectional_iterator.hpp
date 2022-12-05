#pragma once

#include "iterator.hpp"

namespace ft
{

template <typename T>
class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
{
    public:

typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;        
typedef T* pointer;
typedef T& reference;

    protected:

pointer _current;

    public:

bidirectional_iterator() : _current(NULL){}
bidirectional_iterator(pointer ptr) : _current(ptr){};
bidirectional_iterator(const bidirectional_iterator<T>& src) : _current(src._current) {}
~bidirectional_iterator() {}
pointer base() const {  return _current;    } // get_current()

operator bidirectional_iterator<const T> () const   // cast iterator -> const iterator
{   return _current;    }

reference   operator*() const
{   return *_current;   }

pointer     operator->() const
{   return _current;    }

bidirectional_iterator& operator++()
{   ++_current;
    return *this;   }

bidirectional_iterator operator++(int)
{   bidirectional_iterator  tmp(_current);
    ++_current;
    return  tmp;  }

bidirectional_iterator& operator--()
{   --_current;
    return  *this;  }

bidirectional_iterator  operator--(int)
{   bidirectional_iterator  tmp(*this);
    --_current;
    return  tmp;    }

bidirectional_iterator operator+(difference_type n) const
{   return bidirectional_iterator(_current + n);    }

bidirectional_iterator operator-(difference_type n) const
{   return bidirectional_iterator(_current - n);    }

bidirectional_iterator&  operator+=(difference_type n)
{   _current += n;
    return *this;   }

bidirectional_iterator&  operator-=(difference_type n)
{   _current -= n;
    return *this;   }

};

template <class Iterator1, class Iterator2>
bool    operator==(const ft::bidirectional_iterator<Iterator1> lhs, const ft::bidirectional_iterator<Iterator2> rhs)
{   return (lhs.base() == rhs.base());    }

template <class Iterator1, class Iterator2>
bool    operator!=(const ft::bidirectional_iterator<Iterator1> lhs, const ft::bidirectional_iterator<Iterator2> rhs)
{   return (lhs.base() != rhs.base());    }

template <class Iterator1, class Iterator2>
bool    operator<(const ft::bidirectional_iterator<Iterator1>& lhs, const ft::bidirectional_iterator<Iterator2>& rhs)
{   return (lhs.base() < rhs.base());   }

template <class Iterator1, class Iterator2>
bool    operator<=(const ft::bidirectional_iterator<Iterator1>& lhs, const ft::bidirectional_iterator<Iterator2>& rhs)
{   return (lhs.base() <= rhs.base());  }

template <class Iterator1, class Iterator2>
bool    operator>(const ft::bidirectional_iterator<Iterator1>& lhs, const ft::bidirectional_iterator<Iterator2>& rhs)
         {  return (lhs.base() > rhs.base());   }

template <class Iterator1, class Iterator2>
bool    operator>=(const ft::bidirectional_iterator<Iterator1>& lhs, const ft::bidirectional_iterator<Iterator2>& rhs)
{   return (lhs.base() >= rhs.base());  }

template <class Iter>
ft::bidirectional_iterator<Iter> operator+(typename ft::bidirectional_iterator<Iter>::difference_type n, const ft::bidirectional_iterator<Iter>& it)
{   return ft::bidirectional_iterator<Iter>(it.base() + n);}

template <class Iterator1, class Iterator2>
typename ft::bidirectional_iterator<Iterator1>::difference_type operator+(const ft::bidirectional_iterator<Iterator1>& lhs, const ft::bidirectional_iterator<Iterator2>& rhs)
{   return lhs.base() + rhs.base(); }


template <class Iterator1, class Iterator2>
typename ft::bidirectional_iterator<Iterator1>::difference_type operator-(const ft::bidirectional_iterator<Iterator1>& lhs, const ft::bidirectional_iterator<Iterator2>& rhs)
{   return lhs.base() - rhs.base(); }

}; //namespace ft












