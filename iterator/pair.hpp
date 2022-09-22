#pragma once

namespace ft
{

template <typename T1, typename T2>
class pair
{
    public:

T1  first;
T2  second;

pair() {}
pair( const T1& x, const T2& y ) : first(x), second(y) {}

template< class U1, class U2 >
pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}

pair& operator=( const pair& other )
{   this->first = other.first;
    this->second = other.second;
    return *this;   }

operator pair<const T1, T2>() const 
{ return (pair<const T1, T2>(first, second)); }

};

template<class T1, class T2>
ft::pair<T1, T2> make_pair(T1 t, T2 u)
{   return (pair<T1, T2>(t, u));    }

template< class T1, class T2 >
bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{   return (lhs.first == rhs.first && lhs.second == rhs.second);  }

template< class T1, class T2 >
bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{   return !(lhs == rhs);   }

template< class T1, class T2 >
bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{   return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);  }

template< class T1, class T2 >
bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{   return (rhs < lhs); }

template< class T1, class T2 >
bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{   return !(lhs > rhs);    }

template< class T1, class T2 >
bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{   return !(rhs > lhs);    }

} //namespace ft;
