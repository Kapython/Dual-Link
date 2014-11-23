#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>

template <typename T> class Value
{
struct Node {
        T data;
        Node *prew;
        Node *next;
        Node(): prew(NULL), next(NULL) {}
};
public:
    Value();
    Value(T element);
    ~Value();
    Value(const Value<T> &rhs);
    Value& operator=(const Value<T> &);
    void addFirstNode(T data);
    void addToHead(T data);
    void setBeginning();
    bool isNotEmpty();
    void setNext();
    void setPrew();
    int sizeValue();
    void printValue();
    //void addToTail(T data);
    //T pop(); //Получить элемент и удалить его из списка
    //T get(); //Получить элемент неудаляя его
    //void delData(T data);

    //void clear();
    //


private:
    Node *pHead;
    Node *pCurr;
    int length;
};

template<typename T> Value<T>::Value(): pHead(NULL), pCurr(NULL), length(0){}

template<typename T> Value<T>::Value(T element): pHead(NULL), pCurr(NULL), length(0){
    addToHead(element);
}

template <typename T> Value<T>::Value(const Value<T> &rhs){
    this->Node.data = rhs.Node.data;
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
    pHead->next = pHead;
    pHead->prew = pHead;
    pCurr = pHead;
    length++;
}

template <typename T> void Value<T>::addToHead(T data){
    if (!isNotEmpty()){
        addFirstNode(data);
        return;
    }
    Node *pNewNode = new Node;
    pNewNode->data = data;
    pNewNode->prew = pHead->prew;
    pNewNode->next = pHead;
    pHead->prew->next = pNewNode;
    pHead->prew = pNewNode;
    pHead = pNewNode;
    pCurr = pHead;
    length++;
}

template <typename T> void Value<T>::printValue(){
    if(isNotEmpty()){
        setBeginning();
        for(int i(0);i<length;i++){
            std::cout << pCurr->data << " " << std::endl;
            setNext();
        }
    }
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
