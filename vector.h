#ifndef VECTOR_H
#define VECTOR_H
#include"allocator.h"
#include"algorithm.h"
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
private:
    void init_fill( size_type n, value_type &value);    //给了值的初始化
    void try_init();    //不带初始值只分配内存
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
    vector( size_t n){
        init_fill( n, value_type());
    }
    vector( size_t n, value_type value){
        init_fill( n, value);
    }
    //在ptr后插入value，空间富足
    void insert_( iterator ptr, value_type& value){ 
        mySTL::copy_some( ptr+1, end(), ptr+2);
        ptr
        
    }
    iterator insert( iterator ptr, value_type& value){
        size_type _n = ptr - begin();
        if( finish != end_of_storage && ptr == end()){
            mySTL::construct( end_of_storage, value);
            end_of_storage++;
        }else if( finish != end_of_storage && ptr != end){
            insert_( ptr, value);
        }else { //finish == end_of_storage
            //开辟空间，新空间为旧空间的两倍
            
        }
            
    }

    void reserve();
    void clear();
    void emplace( iterator ptr, value_type value);
    void push_back( value_type value);
    value_type pop_back( );
    void swap( iterator left, iterator right);

};


} // namespace mySTL

#endif  //!VECTOR_H