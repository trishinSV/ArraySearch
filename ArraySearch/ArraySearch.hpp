//
//  ArraySearch.hpp
//  ArraySearch
//
//  Created by Сергей Тришин on 04.04.17.
//  Copyright © 2017 Сергей Тришин. All rights reserved.
//

//Максимальный отрицательный элемент в массиве int float
#ifndef ArraySearch_hpp
#define ArraySearch_hpp
#include <iostream>

template <typename T>
class ArraySearch {
    T *arrayPtr;    //указатель на начало массива
    size_t size;    //размер массива
    T max;
public:
    ArraySearch(int);   //конструктор
    ~ArraySearch();     //деструктор
    void setArray(T*);  //заполнение массива
    void printMax();    //вывод числа
    bool findMax();     //поиск числа
};

template <typename T>
ArraySearch<T>::ArraySearch(int s)
{
    size = s;
    arrayPtr = new T[size]; // выделить память под массив
}

// деструктор
template <typename T>
ArraySearch<T>::~ArraySearch()
{
    delete [] arrayPtr; // удаляем массив
}

template <typename T>
void ArraySearch<T>::setArray(T *temp){
    
    //заполнение массива
    for (size_t i; i < size; i++) {
        arrayPtr[i] = temp[i];
    }
    
    int pos = -1;
    
    //поиск первого отрицательного элемента в массиве
    for (int i = 0; i < size; i++) {
        if(arrayPtr[i] < 0){
            pos = i;
            break;
        }
    }
    //если не была сохранена позиция отрицательного элемента, значит таких нет
    if (pos == -1) {
        perror("Отрицательных элементов нет");
        getchar();
    } else
    max = arrayPtr[pos];
}


template <typename T>
bool ArraySearch<T>:: findMax(){
    //поиск максимального отрицательного элемента
    for (size_t i = 0; i < size; i++) {
        if (arrayPtr[i] < 0) {
            if(arrayPtr[i] > max){
                max = arrayPtr[i];
            }
        }
    }
    
    //если элемент был найден значит true иначе false
    return max < 0 ? true : false;
}


template <typename T>
void ArraySearch<T>:: printMax(){
    
    //вывод числа
    if (findMax()) {
        std::cout << "Максимальный отрицательный элемент: "<< max << std::endl;
    }
}



#endif /* ArraySearch_hpp */
