#ifndef CONSTRUCT_H
#define CONSTRUCT_H

//construct: 构造
//destroy：析构

#include<new>
#include<type_traits>

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

template < typename _TP>
void destroy( _TP* ptr){

}

#endif