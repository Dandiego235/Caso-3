#include "List.cpp"
#include <iostream>

using namespace std;

#ifndef STACK

#define STACK

template <class T>
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
            return stack->getLast()->structure;
        }

        void push(T *data){
            stack->addAtBeginning(data);
            //cout << "pushed " << *data << endl;
        }

        T* pop(){
            return stack->remove(0);
        }

        void print(){
            Node<T> *nodePointer = stack->getFirst();
            int tamano = size();

            while (nodePointer != nullptr){
                cout << tamano-- << ". " << *(nodePointer->structure) << endl;
                nodePointer = nodePointer->getNext();
            }
        }

        bool isEmpty(){
            return stack->isEmpty();
        }
};

#endif