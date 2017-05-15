//
//  main.cpp
//  ArraySearch
//
//  Created by Сергей Тришин on 04.04.17.
//  Copyright © 2017 Сергей Тришин. All rights reserved.
//

#include <iostream>
#include <list>
#include "ArraySearch.hpp"
#define ARRAY_SIZE 4 // задаем размер массива

typedef float T;

int main(int argc, const char * argv[]) {

    ArraySearch<T> array(ARRAY_SIZE); //создаем экземпляр класса
    T temp[ARRAY_SIZE]; //массив с числами
    
    // заполнение массива
    std::cout << "Введите элементы массива\n";
    
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        std:: cin >>temp[i];
    }
    
    //поиск и вывод числа
    array.setArray(temp);
    array.printMax();
    
    getchar();
    return 0;
}
