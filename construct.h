#ifndef CONSTRUCT_H
#define CONSTRUCT_H

//construct: 构造
//destroy：析构

#include<new>
#include<type_traits>

namespace mySTL {

//memberName()
template< typename _TP>
void construct( _TP* ptr){
    new( (void*) ptr) _TP();
}

//memberName( value)
template< typename _TP, typename _TP2>
void construct( _TP* ptr, const _TP2& value){
    new ((void*) ptr) _TP( value);
}

//memberName( { value1, value2.....})
template< typename _TP, typename... Args>
void construct( _TP* ptr, Args&&... arg){
    new ((void*)ptr) _TP(std::forward<Args>(args)... );   //把lvalue reference变成rvalue reference 
}

//with trivial destructor
template < typename _TP>
void destroy_one( _TP* ptr, std::true_type) {   }

//without trivial destructor
template < typename _TP>
void destroy_one( _TP* ptr, std::false_type) {
    if( ptr != nullptr){    //非空时调用其析构函数
        ptr->~_TP();
    }
}

template < typename _TP>
void destroy( _TP* ptr){
    destroy_one( ptr, std::is_trivially_destructible<_TP>{});
}

//with trivial destructor
template< typename _Iterator>
void destroy_some( _Iterator first, _Iterator last, std::true_type){    }

//without trivial destructor
template< typename _Iterator>
void destroy_some( _Iterator first, _Iterator last, std::false_type){
    for ( ; first != last; ++first)
        destroy( &(*first) );
}

template< typename _Iterator>
void destroy( _Iterator first, _Iterator last){
    destroy_some( first, last, std::is_trivially_destructible < typename std::iterator_traits< _Iterator>::type>{});
}

} // namespace mySTL

#endif