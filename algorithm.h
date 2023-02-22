#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<new>
#include<string.h>

namespace mySTL{

//返回value1和value2中大的那个，相等时返回value1
template< typename _TP>
const _TP& max( const _TP value1, const _TP value2){
    return value1 < value2 ? value2 : value1;
}

//自定义比大小的方式_Compare
template <typename _TP, typename _Compare>
const _TP& max( const _TP value1, const _TP value2, _Compare cmp){
    return cmp(value1, value2) ? value2 : value1;
}

//返回value1和value2中小的那个，相等时返回value1
template< typename _TP>
const _TP& min( const _TP value1, const _TP value2){
    return value1 > value2 ? value2 : value1;
}

//自定义比大小的方式_Compare
template <typename _TP, typename _Compare>
const _TP& min( const _TP value1, const _TP value2, _Compare cmp){
    return cmp(value1, value2) ? value2 : value1;
}

//swap两个iterator
template< typename Iterator>
void iterator_swap( Iterator iter1, Iterator iter2){
    Iterator p = iter1;
    iter1 = iter2;
    iter2 = p;
}

//把[first,last)的元素复制到[newFirst, newFirst + (last - first))中, 返回newFirst
template < typename Iterator>
Iterator copy_some( Iterator first, Iterator last, Iterator newFirst){
    for( ; first != last; ++first, ++newFirst){
        *newFirst = *first;
    }
    return newFirst;
}



} // namespace myST


#endif