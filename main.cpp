#include "main.h"
#include "template.h"

int main() {
    //Value<int> tmp();
    //CStorage stor();

    int choise = 0;
    Value<int> intValue;
    //Value<char> charValue;
    //Value<manB> manValue;
    while (choise != 6){
        choise = toMakeChoice();
        switch (choise){
            case 1: {
                std::cout << "Введите число: ";
                int number;
                std::cin >> number;
                intValue.addToHead(number);
                break;
                }
            case 2:{
                if (intValue.isNotEmpty()){
                    intValue.setHead();
                    for (int i(0); i<intValue.sizeValue();i++){
                        std::cout << intValue.getData() << "; ";
                        intValue.setPrew();
                    }
                    std::cout <<"\n";
                }
                else{
                    std::cout << "Список пуст\n\n";
                }
                break;
                }
            case 3:{
                std::cout << "\n";
                std::cout << "Сортировка\n\n";
                intValue.sortData();
                break;
            }
            case 4:{
                intValue.clear();
                break;
            }
            case 5:{
                int choise(0);
                while (choise !=3){
                    std::cout << "1 - удалить элемент\n";
                    std::cout << "3 - Выход\n\n";
                    std::cout << "Выберите пункт: ";
                    std::cin >> choise;
                    if (choise == 1){
                        if (intValue.isNotEmpty()){
                            intValue.setHead();
                            for (int i(0); i<intValue.sizeValue();i++){
                                std::cout << intValue.getData() << "; ";
                                intValue.setPrew();
                            }
                            std::cout <<"\n";
                            std::cout << "Ведите элемент для удаления: ";
                            std::cin >> choise;
                            intValue.delData(choise);
                        }
                        else{
                            std::cout << "Список пуст внесите элементы в список\n\n";
                            choise = 3;
                        }
                    }
                }
            ;
                break;
                }
            case 6:{
                std::cout << "Спасибо\n\n";
                break;
                }
            default:{
                std::cout << "Введите коректное значение\n";
                break;
                }
        }
    }

    return 0;
}
