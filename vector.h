#ifndef VECTOR_H
#define VECTOR_H
#include"allocator.h"

namespace mySTL {

template< typename _TP>
class vector{
public:
    typedef _TP value_type;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef value_type& reference;
    typedef size_t size_type;
protected:
    iterator start; //开始指针
    iterator finish;    //结束指针
    iterator end_of_storage;   //目前容量最后一个指针
public:
    iterator begin() { return start; }
    const_iterator begin() { return start; }
    iterator rbegin(){ return finish; }
    const_iterator rbegin(){ return finish; }
    iterator end() { return finish; }
    const_iterator end() { return finish; }
    iterator rend(){ return start; }
    const_iterator rend(){ return start; }
    size_type size() const { return size_type( end() - begin()); }    
    size_type capacity(){ return size_type( end_of_storage - begin()); }
    bool empty() { return end() == begin(); }
    vector(): start( nullptr), finish( nullptr), end_of_storage( nullptr){ }
    vector( size_t n);
    vector( size_t n, value_type value);
    void insert( value_type& value);
    void reserve();
    void clear();
    void emplace( iterator ptr, value_type value);
    void push_back( value_type value);
    value_type pop_back( );
    void swap( iterator left, iterator right);
private:
    void init_fill( size_type n, value_type &value);    //给了值的初始化
    void try_init();    //不带初始值只分配内存
};



} // namespace mySTL

#endif  //!VECTOR_H