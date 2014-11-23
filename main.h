#include <iostream>
#include <stdio.h>

int toMakeChoice(){
    printf("(1) Добавить элемент в список\n");
    printf("(2) Вывести весь список\n");
    printf("(5) Выход\n");

    int choise;

    printf("Выберите пункт: ");
    std::cin >> choise;
    return choise;
}

class manB{
    int age;
};
