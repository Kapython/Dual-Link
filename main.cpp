#include "main.h"
#include "template.h"

int main() {
    //Value<int> tmp();
    //CStorage stor();

    int choise = 0;
    Value<int> intValue;
    //Value<char> charValue;
    //Value<manB> manValue;
    while (choise != 5){
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
                for (int i(0); i<intValue.sizeValue();i++){
                    std::cout << intValue.getData() << std::endl;
                    intValue.setPrew();
                }
                printf("\n");
                break;
                }
            case 3:{
                printf("\n");
                printf("Сортировка\n\n");
                intValue.sortData();
                break;
            }
            case 5:{                
                printf("Спасибо\n\n");
                break;
                }
            default:{
                printf("Введите коректное значение\n");
                break;
                }
        }
    }

    return 0;
}
