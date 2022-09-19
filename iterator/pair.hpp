#pragma once

namespace ft
{
template<typename T1, typename T2>
class pair:
{
    public:

typedef    T1   first_type;
typedef    T2   second_type;

    protected:

T1  first;
T2  second;

    public:

pair() {}
pair( const T1& x, const T2& y ) : first(x), second(y) {}

template< class U1, class U2 >
pair( const pair<U1, U2>& p ) : first(p.get_T1), second(p.get_T2) {}

pair& operator=( const pair& other )
{   this->first = other.get_T1;
    this->second = other.get_T2;
    return *this;   }

const T1&   get_T1() const {return this->first; }
const T2&   get_T2() const {return this->second; }

};

template< class T1, class T2 >
ft::pair<T1,T2> make_pair( T1 t, T2 u )
{   return pair(t, u);  }

template< class T1, class T2 >
bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{   return (lhs.first == rhs.first && lhs.second== rhs.second);  }

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
