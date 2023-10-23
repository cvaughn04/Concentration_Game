#ifndef ARRAYT
#define ARRAYT

#include <iostream>
#include "AbilityT.h"


template<typename T>
class ArrayT {
    public:

       ArrayT(){};
       ArrayT(size_t c);
       ArrayT(const ArrayT & src);
       ~ArrayT();

       ArrayT & operator = (const ArrayT & src);

       void PushBack(T);
       void PopBack();

       T & operator[] (size_t index);

       size_t Size() const;
       size_t Capacity() const;

    private:
       size_t  size{0},
               capacity{0};
       T * data{nullptr};

};


template <typename T>
ArrayT<T>::ArrayT(size_t c){
     capacity = c;
     data = new T[capacity];
}

template <typename T>
ArrayT<T>::ArrayT(const ArrayT & src){
      size = src.size;
      capacity = src.capacity;

      data = new T[capacity];
      for(size_t idx = 0; idx < size; ++idx) {
         data[idx] = src.data[idx];
      }
}

template <typename T>
ArrayT<T>::~ArrayT() {
     delete [] data;
}

template <typename T>
ArrayT<T> & ArrayT<T>::operator = (const ArrayT & src) {
    if (this != &src) {
        size = src.size;
        capacity = src.capacity;
        if (data  != nullptr) {
            delete [] data;
        }
        data = new T[capacity];
        for(size_t i = 0; i < size; ++i) {
            data[i] = src.data[i];
        }
    }
    return * this;
}


template <typename T>
void ArrayT<T>::PushBack(T i){
     T * tmp{nullptr};

     if (size == capacity) {
         ++capacity ;
         tmp = new T[capacity];

         for(size_t idx = 0; idx < size; ++idx) {
            tmp[idx] = data[idx];
         }

         delete [] data;
         data = tmp;
         tmp = nullptr;

     }
     data[size] = i;
     ++size;
}

template <typename T>
void ArrayT<T>::PopBack(){
    if (size >0) {
     --size;
    }
}

template <typename T>
T & ArrayT<T>::operator[] (size_t index){

     if (index <size) {
        return data[index];
     } else {
        std::cerr << "Invalid index " << std::endl;
        return data[0];
     }
}

template <typename T>
size_t ArrayT<T>::Size() const{
    return size;
}

template <typename T>
size_t ArrayT<T>::Capacity() const{
    return capacity;
}

#endif
