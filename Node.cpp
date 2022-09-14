#include <iostream>

#ifndef NODE

#define NODE 1

using namespace std;

// Lista doblemente enlazada
template <class T>
class Node{
    private:
        Node<T> *next; //punteros al nodo siguiente y anterior
        Node<T> *prev;
        T *structure; // El nodo apunta a una estructura, un struct o clase.
        
    public:
        Node(){
            next = nullptr;
            prev = nullptr;
            structure = nullptr;
        }
        Node(T *pointer){
            next = nullptr;
            prev = nullptr;
            structure = pointer; // Se establece el puntero de la estructura como el puntero ingresado.
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

        void setData(T* pStructure){
            structure = pStructure;
        }

        T* getData(){
            return structure;
        }
};

#endif