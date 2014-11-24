#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>

template <typename T> class Value
{
struct Node {
        T data;
        Node *prew;
        Node *next;
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
    void setBeginning();
    bool isNotEmpty();
    void setNext();
    void setPrew();
    int sizeValue();
    T getData(); //Получить элемент
    void searchData(T data);
    void delData(T data);
    void sortData();
    //void clear();

private:
    Node *pHead;
    Node *pTail;
    Node *pCurr;
    int length;
};

template<typename T> Value<T>::Value(): pHead(NULL), pCurr(NULL), pTail(NULL), length(0){}

template<typename T> Value<T>::Value(T element):
    pHead(NULL), pCurr(NULL), pTail(NULL), length(0){
    addToHead(element);
}

template <typename T> Value<T>::Value(const Value &){}

template <typename T> Value<T>& Value<T>::operator=(const Value &rhs){
    if (this == rhs)
        return this;
}

template<typename T> Value<T>::~Value(){}

template <typename T> bool Value<T>::isNotEmpty(){
    if (pHead)
        return true;
    return false;
}

template<typename T> void Value<T>::addFirstNode(T data){
    pHead = new Node;
    pHead->data = data;
    //pHead->next = pHead;
    //pHead->prew = pHead;
    pCurr = pTail = pHead;
    length++;
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
        Node* pTemp = searchData(data);
        pTemp->prew->next = pTemp->next;
        pTemp->next->prew = pTemp->prew;
        delete pTemp;
    }
}

template <typename T> void Value<T>::searchData(T data){
    if (isNotEmpty()){
        setBeginning();
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
        Node* pTemp; // = new Node;
        Node* pSwap; // = new Node;
        //int i(0), j(0);
        setBeginning();
        pTemp = pCurr;
        for (int i(0); i<length-1; i++){
            for (int j(0); j<length-1; j++){
                setNext();
                if (pTemp->data < pCurr->data){
                    pSwap = pCurr;
                    pCurr = pTemp;
                    pTemp = pSwap;
                }
            }
            pTemp = pTemp->next;
            pCurr = pTemp;
        }
    delete pTemp;
    delete pSwap;
    }
    else {
        std::cout << "Список пуст" << std::endl;
    }
}

template <typename T> T Value<T>::getData(){
    return pCurr->data;
}

template <typename T> void Value<T>::setBeginning(){
    pCurr = pHead;
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
