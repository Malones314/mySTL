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
    iterator end() { return finish; }
    const_iterator end() { return finish; }
    size_type size() const { return size_type( end() - begin()); }    
    size_type capacity(){ return size_type( end_of_storage - begin()); }
    bool empty() { return end() == begin(); }
    void init_with_value( size_t n, value_type value);
    vector( ): start( nullptr), finish( nullptr), end_of_storage( nullptr){ }
    vector( size_t n){

    }
};
template< typename T>
void  vector<T>::init_with_value( size_type n, T value){
    begin = 
}

} // namespace mySTL

#endif  //!VECTOR_H