#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include<utility>
#include"construct.h"
//用于资源分配与释放，调用construct进行对象的构造、析构

namespace mySTL {

template < typename _TP>
class allocator{
public:
    typedef _TP value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;
      
public:
    pointer allocate();
    pointer allocate( size_type n);
    void deallocate( pointer ptr);
    void deallocate( pointer ptr, size_type n);
    void construct( pointer ptr);
    void construct( pointer ptr, value_type v);
    template <class... Args>
    static void construct( pointer ptr, Args&& ...args);

    void destroy( pointer ptr);
    void destroy( pointer first, pointer last);
};

template < typename _TP>
_TP* allocator<_TP>::allocate( ){
    return static_cast<_TP*>(new(sizeof(_TP)));
}

template < typename _TP>
_TP* allocator<_TP>::allocate( size_type n){
    if( n == 0)
        return nullptr;
    return static_cast<_TP*>(new( n * sizeof(_TP)));
}

template < typename _TP>
void allocator< _TP>::deallocate( _TP* ptr){
    if( ptr != nullptr)
        delete( ptr);
}

template< typename _TP>
void allocator< _TP>::deallocate( _TP* ptr, size_t n){
    if( ptr != nullptr)
        delete( ptr);
}

template< typename _TP>
void allocator<_TP>::construct( _TP* ptr){
    mySTL::construct( ptr);
}

template< typename _TP>
void allocator<_TP>::construct( pointer ptr, value_type v){
    mySTL::construct( ptr, v);
}

template< typename _TP> template< typename ...Args>
void allocator<_TP>::construct( _TP* ptr, Args&& ...args){
    mySTL::construct( ptr, std::forward<Args>(args)...);
}

template< typename _TP>
void allocator<_TP>::destroy( _TP* ptr){
    mySTL::destroy( ptr);
}

template< typename _TP>
void allocator<_TP>::destroy( _TP* first, _TP* last){
    mySTL::destroy( first, last);
}

} // namespace mySTL；
#endif