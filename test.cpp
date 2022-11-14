#include "map.hpp"
#include <string>
#include <vector>
int main()
{
    std::vector<int> v;

    v.resize(500);


vector<_Tp, _Allocator>::resize(size_type sz)
{
    size_type cs = size();
    if (cs < sz)
        this->__append(sz - cs); // new-size - size() 
    else if (cs > sz)
        this->__destruct_at_end(this->__begin_ + sz);
}

vector<_Tp, _Allocator>::__append(size_type __n)
{
    if (static_cast<size_type>(this->__end_cap() - this->__end_) >= __n)
        this->__construct_at_end(__n);
    else
    {
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__recommend(size() + __n), size(), __a);
        __v.__construct_at_end(__n);
        __swap_out_circular_buffer(__v);
    }
}

}