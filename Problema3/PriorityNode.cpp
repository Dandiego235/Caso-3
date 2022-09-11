#include <iostream>

#ifndef PNODE

#define PNODE 1

using namespace std;

template <class T>
class Node{
    private:
        Node<T> *next;
        Node<T> *prev;
        int priority;
    public:
        T *structure; // El nodo apunta a una estructura, un struct o clase.
        Node(){
            next = nullptr;
            prev = nullptr;
            structure = nullptr;
            priority = 0;
        }
        Node(T *pointer, int pPriority){
            next = nullptr;
            prev = nullptr;
            structure = pointer; // Se establece el puntero de la estructura como el puntero ingresado.
            priority = pPriority;
        }

        Node<T>* getNext(){
            return next;
        };

        Node<T>* getPrev(){
            return prev;
        }

        void setNext(Node<T> *pointer){
            this->next = pointer;
        };

        void setPrev(Node<T> *pointer){
            this->prev = pointer;
        }

        void setPriority(int pPriority){
            priority = pPriority;
        }

        int getPriority(){
            return priority;
        }
};

#endif