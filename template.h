#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>

template <typename T> class Value
{
struct Node {
        T data;
        Node* prew;
        Node* next;
        Node(): prew(this), next(this) {}
};
public:
    Value();
    Value(T element);
    ~Value();
    Value(const Value &);
    Value& operator=(const Value &);
    void addFirstNode(T data);
    void addToHead(T data);
    void setHead();
    void setTail();
    bool isNotEmpty();
    void setNext();
    void setPrew();
    int sizeValue();
    T getData(); //Получить элемент
    void searchData(T data);
    void delData(T data);
    void sortData();
    void clear();

private:
    Node* pHead;
    Node* pCurr;
    Node* pTail;
    int length;
};

template<typename T> Value<T>::Value():
    pHead(NULL), pCurr(NULL), pTail(NULL), length(0){}

template<typename T> Value<T>::Value(T element):
    pHead(NULL), pCurr(NULL), pTail(NULL), length(0){
    addToHead(element);
}

template <typename T> Value<T>::~Value(){
    clear();
}

template <typename T> Value<T>::Value(const Value &){}

template <typename T> Value<T>& Value<T>::operator=(const Value &rhs){
    if (this == rhs)
        return this;
}

template <typename T> bool Value<T>::isNotEmpty(){
    if (pHead)
        return true;
    return false;
}

template<typename T> void Value<T>::addFirstNode(T data){
    pHead = new Node;
    pHead->data = data;
    pCurr = pTail = pHead;
    length++;
}

template <typename T> void Value<T>::clear(){
    setTail();
    for (int i(0); i<sizeValue(); i++){
        Node* pTemp;
        pTemp = pCurr;
        setNext();
        delete pTemp;
        length--;
    }
    pHead = pTail = pCurr = NULL;
    std::cout << "Список очищен" << std::endl << std::endl;

}

template <typename T> void Value<T>::addToHead(T data){
    if (!isNotEmpty()){
        addFirstNode(data);
        return;
    }
    Node *pTemp = new Node;
    pTemp->data = data;
    pTemp->prew = pHead;
    pHead->next = pTemp;
    pTemp->next = pTail;
    pTail->prew = pTemp;
    pHead = pTemp;
    pCurr = pHead;
    length++;
}

template <typename T> void Value<T>::delData(T data){
    if (isNotEmpty()){
        Node* pTemp;
        setHead();
        for (int i(0); i<length; i++){
            if (data == pCurr->data){
                pTemp = pCurr;
                pCurr->prew->next = pCurr->next;
                pCurr->next->prew = pCurr->prew;
                setHead();
                delete pTemp;
                pTemp = NULL;
                length--;
                return;
            }
            else {
                setPrew();
            }
        }
    }
}

template <typename T> void Value<T>::searchData(T data){
    if (isNotEmpty()){        
        setHead();
        for (int i(0); i<length && pCurr->data != data; i++){
            setNext();
        }
        if (pCurr->data == data)
            return pCurr;
        else
            std::cout << "Такого элемента нет в списке" << std::endl;
    }
    else{
        std::cout << "Список пуст" << std::endl;
    }
}

template <typename T> void Value<T>::sortData(){
    if (isNotEmpty()){
        Node* pTemp; // Временный указатель
        setHead();
        pTemp = pHead;
        while (pTemp != pTail) { //если текущее положение не хвост входим
            setPrew();
            while (pCurr != pHead) { //если текущее положение не голова входим
                if (pTemp->data > pCurr->data){
                    //T tempData = pTemp->data;
                    //pTemp->data = pCurr->data;
                    //pCurr->data = tempData;

                    std::swap(pTemp->data, pCurr->data);
                }
                setPrew(); // переключам текущее положение в ранее добавленное
            }
            pTemp = pTemp->prew; // переключаем на следующее сравниваемое значение
            pCurr = pTemp;
        }
    }
    else {
        std::cout << "Список пуст\n\n" << std::endl;
    }
}

template <typename T> T Value<T>::getData(){
    return pCurr->data;
}

template <typename T> void Value<T>::setHead(){
    pCurr = pHead;
}

template <typename T> void Value<T>::setTail(){
    pCurr = pTail;
}

template <typename T> void Value<T>::setNext(){
    pCurr = pCurr->next;
}

template <typename T> void Value<T>::setPrew(){
    pCurr = pCurr->prew;
}

template <typename T> int Value<T>::sizeValue(){
    return length;
}

#endif // TEMPLATE_H
