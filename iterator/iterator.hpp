#pragma once

#include <cstddef>

namespace ft 
{


/*-------------------------------------Definition Iterateur-----------------------------------------*/

// Tag pour definir quel iterateur sera utilise dans "iterator_categorie" (voir en dessous)
struct input_iterator_tag { }; // ecrire et ++ only
struct output_iterator_tag { }; // lire et ++ only
struct forward_iterator_tag : public input_iterator_tag { }; // lire, ecrire et multi ++
struct bidirectional_iterator_tag : public forward_iterator_tag { }; // lire, ecrire, ++ et -- possible;
struct random_access_iterator_tag : public bidirectional_iterator_tag { }; // lire, ecrire, ++, -- et acces a un element du tableau, peut importe sa place;


// Ce dont a besoin un iterateur pour fonctionner, explications de ces 5 variables plus bas;
template< class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
struct iterator
{
    typedef Category    iterator_category;      // une des 5 categories du dessus
    typedef T           value_type;             // variable de type T;
    typedef Distance    difference_type;        // = std::ptrdiff_t size entre deux pointer;
    typedef Pointer     pointer;                // = *T;        
    typedef Reference   reference;              // = T&;
};



template <class Iterator>
struct iterator_traits                   // rename, pour que les noms soient plus explicites et que ca puisse matcher avec les protos des containeurs et de <algorithms>
{
    typedef typename Iterator::difference_type      difference_type;         
    typedef typename Iterator::value_type           value_type;                   
    typedef typename Iterator::pointer              pointer;                          
    typedef typename Iterator::reference            reference;
    typedef typename Iterator::iterator_category    iterator_category;     
};



template <class T>                                                      // introduction du type T (specialisation) pour que Iterator::iterator_traits
struct iterator_traits<T*>                                              // Les characteristiques que doit comporter un iterateur
{
    typedef ptrdiff_t                   difference_type;                // Le type de distance (ou type de la différence) entre deux iterateurs. Ce peut être un type integral comme int.
    typedef T                           value_type;                     // Le type de valeur est le type d’objet sur lequel l’iterateur pointe. 
    typedef T*                          pointer;                        // pointeur sur la variable de type T
    typedef T&                          reference;                      // Reference de la variable de type T
    typedef random_access_iterator_tag  iterator_category;              // Categorie : output, input, forward, bidirectionnal, random access.
};

template <class T>
struct iterator_traits<T* const>                                        // version pour accepter les classes const                                        
{
    typedef ptrdiff_t                   difference_type;                
    typedef       T                     value_type;                     
    typedef const T*                    pointer;                    
    typedef const T&                    reference;                   
    typedef random_access_iterator_tag  iterator_category;               

};


/*-------------------------------------Reverse Iterateur-----------------------------------------*/

// iterateur ou ++ deviens -- et inversement 
template <class Iterator> // iterateur peut etre : bidirectionnel ou random access (dans ce projet)
class reverse_iterator
{

    public:

typedef Iterator                            iterator_type;
typedef iterator_traits<Iterator>           traits;
typedef typename traits::reference          reference;
typedef typename traits::difference_type    difference_type;
typedef typename traits::pointer            pointer;
    
    
    protected:

Iterator    current;

    public:

reverse_iterator() : current(NULL) { }
explicit reverse_iterator( iterator_type x ) : current(x) { }                   // construire a partir d un type    |      explicit keyword --> empeche le compilateur de faire des conversions implicites;
template <class U> reverse_iterator(const reverse_iterator<U>& other) : current(other.base()){ }        // construire a partir d un autre iterateur (copie);
iterator_type base() const { return current; }        // get_current();

operator reverse_iterator<const Iterator>() const  
{ return this->current; }

//template <I>
reverse_iterator& operator=(const reverse_iterator<Iterator>& other)
{   current = other.base();
    return *this;   }

reference operator*() const 
{   iterator_type tmp = current;
    return *(--tmp);    }

reference   operator[](difference_type n) const
{   return *(*this + n);    }

pointer operator->() const 
{   return &(operator*());  }

reverse_iterator operator-(difference_type n) const 
{   return reverse_iterator(current + n);   }

reverse_iterator operator+(difference_type n) const
{   return reverse_iterator(current - n);   }

reverse_iterator &operator++()
{   --current;
    return *this;   }

reverse_iterator operator++(int)
{   reverse_iterator    tmp(*this);
    --current;
    return tmp;    }


reverse_iterator &operator+=(difference_type n)
{   current -= n;
    return *this;   }


reverse_iterator &operator--()
{   ++current;
    return *this;   }

reverse_iterator operator--(int)
{   reverse_iterator tmp(*this);
    ++current;
    return tmp; }

reverse_iterator &operator-=(difference_type n)
{   current += n;
    return *this;   }

};


// ---------------      NO MEMBER FUNCTIONS   /////////////////  (inverser valeur de retour?)

template <class Iterator1, class Iterator2>
bool operator==( const ft::reverse_iterator <Iterator1>& lhs, const ft::reverse_iterator <Iterator2>& rhs )
{   return  (*lhs.base() == *rhs.base());   }

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{   return  !(lhs == rhs);    }

template <class Iter>
reverse_iterator<Iter>  operator-(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& x)
{   return reverse_iterator<Iter>(x.base() + n);   }

template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{   return  (lhs.base() > rhs.base());  }

template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{   return  (lhs.base() >= rhs.base()); }

template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{   return  (lhs.base() < rhs.base());  }

template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{   return  (lhs.base() <= rhs.base()); }

template< class InputIt >
typename iterator_traits<InputIt>::difference_type  distance( InputIt first, InputIt last )
{   typename iterator_traits<InputIt>::difference_type   n = 0;
    for (; first != last; first++)
        n++;
    return n;   }

template <class Iter>
ft::reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& x)
{   return ft::reverse_iterator<Iter>(x.base() - n);   }

template <class Iter1, class Iter2>
typename reverse_iterator<Iter1>::difference_type operator-(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{   return y.base() - x.base(); }

template <class Iter>
ft::reverse_iterator<Iter> operator-(typename ft::reverse_iterator<Iter>::pointer x, typename ft::reverse_iterator<Iter>::difference_type n)
{   return (ft::reverse_iterator<Iter> (x - n));}


} // namespace ft
