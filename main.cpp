#include "main.h"
#include "template.h"

int main() {
    //Value<int> tmp();
    //CStorage stor();

    int choise = 0;
    Value<int> intValue;
    Value<char> charValue;
    Value<manB> jobs;
    while (choise != 5){
        choise = toMakeChoice();
        switch (choise){
            case 1: {                
                //std::cout << "Введите число: ";
                //int number;
                //std::cin >> number;
                //intValue.addToHead(number);
                manB tmpMan;
                jobs.addToHead(tmpMan);
                break;
                }
            case 2:{
                printf("Выбор пал на второй пункт\n");

                intValue.printValue();
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
