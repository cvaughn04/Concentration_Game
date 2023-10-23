#ifndef ARRAY2T
#define ARRAY2T

#include <iostream>
#include <iomanip>
#include <string>
#include "AbilityT.h"


template<typename T>
class Array2T {
    public:

       Array2T(){};
       Array2T(size_t r, size_t c);
       ~Array2T();
       Array2T(const Array2T & src);

       Array2T & operator = (const Array2T & src);
       T & operator[] (size_t r, size_t c);

       size_t Capacity() const;
       size_t Rows() const;
       size_t Columns() const;


    private:
       size_t  capacity{0},
               rows{0},
               columns{0};
       T * data{nullptr};


};

template<typename T>
Array2T<T>::Array2T(size_t r, size_t c) {
    rows = r;
    columns = c;
    capacity = rows * columns;

    if (capacity == 0) {
        std::cerr << "ERROR: Attempting to construct an empty Array2T class, Dont do that" << std::endl;
    } else {
        data = new T[capacity];
    }
}

//destructor
template<typename T>
Array2T<T>::~Array2T() {
    delete[] data;
    data = nullptr;
};

//copy constrcutor
template<typename T>
Array2T<T>::Array2T(const Array2T & src){
      capacity = src.capacity;

      data = new T[capacity];
      for(size_t i = 0; i < capacity; ++i) {
         data[i] = src.data[i];
      }
}

//overload assignment operator
template<typename T>
Array2T<T> & Array2T<T>::operator = (const Array2T & src) {
    if (this != &src) {
        capacity = src.capacity;
        rows = src.rows;
        columns = src.columns;

        if (this->data  != nullptr) {
            delete [] data;
        }
        
        this->data = new T[capacity];
        for(size_t i = 0; i < capacity; ++i) {
            this->data[i] = src.data[i];
        }
    }
    return *this;
}

template<typename T>
T & Array2T<T>::operator[] (size_t r, size_t c) {
    size_t index {0};

    if (r < rows and c < columns) {
        index = (r * columns + c);
    } else {
        std::cerr << "ERROR: Attempting an invalid index, returning data at position 0" << std::endl;
    }
    return data[index];
}

template<typename T>
size_t Array2T<T>::Capacity() const{ 
    return capacity;
}

template<typename T>
size_t Array2T<T>::Rows() const{ 
    return rows;
}

template<typename T>
size_t Array2T<T>::Columns() const{
    return columns;
}

#endif