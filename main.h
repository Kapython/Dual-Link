#include <iostream>
#include <stdio.h>

int toMakeChoice(){
    printf("1 - Добавить элемент в список\n");
    printf("2 - Вывести весь список\n");
    printf("3 - ортировать список\n");
    printf("5 - Выход\n\n");

    int choise;

    printf("Выберите пункт: ");
    std::cin >> choise;
    printf("\n");
    return choise;
}

int addToValue(){
    printf("1 - Добавить значение в список\n");
    printf("2 - Выйти\n");

    int choise;
    std::cin >> choise;
    return choise;
}

class manB{
    int age;
};
