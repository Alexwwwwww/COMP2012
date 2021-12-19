#ifndef PRODUCTVECTOR_H
#define PRODUCTVECTOR_H

#include <iostream>
#include "Product.h"
#include <string>
using namespace std;

template <typename T> class ProductVector
{
    private:
        T* data;
        int capacity;
        int length;

    public:
        ProductVector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

        // Add the new element to the back.
        void push_back(const T& s) {
            if (capacity <= length) {
                T* temp = new T[capacity * 2];
                for (int i = 0; i < length; i++){
                    temp[i] = data[i];
                }
                delete[] data;
                data = temp;
                capacity *= 2;
            }

            data[length] = s;
            length++;
        }

        void remove(int x) {
            for (int i = x+1; i < length; i++) {
                data[i - 1] = data[i];
            }
            length--;
        }

        int size() const{ return length; }

        void swap(int i, int j) {
            T temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }

        ~ProductVector() {
            if (data) {
                delete[] data;
            }
        }

    /* ===================================================================
        TODO: operator overloading and make member functions
              Refer to the main.cpp.
       =================================================================== */
    
    // TODO: Copy constructor: Perform deep copying
	// Hint: Make use of assignment operator function `operator=`
    ProductVector(ProductVector& other)
    {
        *this=other;
      
    }
    // TODO: Remove get_value() fuction and Overload `operator[]` to get the i-th element of vector
    // Hint: 'get_value(i)' will be changed like 'data[i]'
    T& operator[](int i) 
    {
        return this->data[i];
    }
    // TODO: Complete sort fuction by ascending order.
    // Hint: Use > operator and swap fuction
    void sort()
    {
        for(int i=0; i<length-1; i++)
        {
            for(int j=i; j<length; j++)
            {
                if(this->data[i]>this->data[j])
                {
                    swap(i,j);
                }
                
            }
        }
    }
    // TODO: Complete isExsit fuction and 
    // Hint: Use == operator, if the parameter is in the ProductVector return true or opposite
    //generic case
    template <typename V>
    
    bool isExist(const V& v) const
    {
        for(int i=0; i<length; i++)
        {
            if(this->data[i]==v)
            {
                return true;
            }
        }
        return false;
    }

    // TODO: Overload `operator=` to replace with ProductVector<T> paramenter
    // Hint: Deep copying is required
    // The existing data is replaced as the same elements of parameter.
    // It will be used like A(ProductVector<Book> type) = B(ProductVector<Book> type)
    //template <typename V>
    // Within the product class
    ProductVector& operator=(const ProductVector & other)
    {
        if(this!=&other)
        {
            if(data)
               delete[] data;
                // copy the array
            //this->data=other.data;
            data=new T[other.capacity];
            for(int i=0; i<other.length;i++)
            {
                data[i]= other.data[i];
            }
                // renew the data member: capacity 
            this->capacity= other.capacity;
                // renew the data member: length
            this->length=other.length;
        }
        return *this;
    }
    
};

#endif
