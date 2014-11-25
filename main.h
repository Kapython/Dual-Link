#include <iostream>


int toMakeChoice(){
    std::cout << "\t\t ---Menu---\n\n";
    std::cout << "1 - Добавить элемент в список\n";
    std::cout << "2 - Вывести весь список\n";
    std::cout << "3 - Сортировать список\n";
    std::cout << "4 - Очистить список\n";
    std::cout << "5 - Удалить элемент\n";
    std::cout << "6 - Выход\n\n";

    int choise;

    std::cout << "Выберите пункт: ";
    std::cin >> choise;
    std::cout << "\n";
    return choise;
}

int addToValue(){
    std::cout <<"1 - Добавить значение в список\n";
    std::cout << "2 - Выйти\n";

    int choise;
    std::cin >> choise;
    return choise;
}

class manB{
    int age;
};
