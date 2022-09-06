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
            stack->add(data);
            cout << "pushed " << *data << endl;
        }

        /*void push(T data){
            T *pointer = new T(data);
            stack->add(pointer);
            cout << "pushed " << data << endl;
        }*/

        T* pop(){
            return stack->remove(size()-1);
        }

        void print(){
            Node<T> *nodePointer = stack->getLast();
            int tamano = size();

            while (nodePointer != nullptr){
                cout << tamano-- << ". " << *(nodePointer->structure) << endl;
                nodePointer = nodePointer->getPrev();
            }
        }
};

#endif