#include "List.cpp"
#include <iostream>

using namespace std;

#ifndef STACK

#define STACK

template <class T>
// La pila funciona agregando al principio de la lista. Por lo tanto, para borrar, no tiene
// que recorrer la lista hasta el último elemento para borrarlo.
class Stack{
    private:
        List<T> *stack;
        
    public:
        Stack(){
            stack = new List<T>();
        }

        int size(){
            return stack->size();
        }

        T* getTop(){
            return stack->getFirst()->getData();
        }

        void push(T *data){
            stack->addAtBeginning(data);
        }

        T* pop(){
            return stack->remove(0);
        }

        // Función para imprimir la pila
        void print(){
            Node<T> *nodePointer = stack->getFirst();
            int tamano = size();

            while (nodePointer != nullptr){
                cout << tamano-- << ". " << *(nodePointer->getData()) << endl;
                nodePointer = nodePointer->getNext();
                // consigue el siguiente nodo. Es el next y no el prev porque el primer elemento es el último agregado.
            }
        }

        bool isEmpty(){
            return stack->isEmpty();
        }
};

#endif