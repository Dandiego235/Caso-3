#include "PriorityList.cpp"
#include "PriorityNode.cpp"
#include <iostream>

#ifndef PRIORITY

#define PRIORITY 1

template <class T>
class PriorityQueue{
    private:
        List<T> *queue;
    public:
        PriorityQueue(){
            queue = new List<T>();
        }

        // Función para meter un elemento a la cola con prioridad.
        void enqueue(int pPriority, T* pData){
            Node<T> *nodePtr = queue->getFirst(); // Puntero al primer nodo para recorrer la lista.
            while(nodePtr != nullptr){
                if (nodePtr->getPriority() > pPriority){
                    // Si la prioridad del nodo que estamos revisando es mayor que la prioridad del nodo que vamos a agregar,
                    // debemos insertar el nodo en la posición del nodo.
                    queue->insertAtNode(nodePtr, pData, pPriority);
                    break;
                }
                nodePtr = nodePtr->getNext(); // Obtenemos el siguiente nodo e incrementamos la posición.
            }
            if (nodePtr == nullptr){ // Si no nos salimos del ciclo, es que el nodo debe agregarse al final.
                queue->add(pData, pPriority);
            }
        }

        // Función para sacar el primer elemento de la cola.
        T* dequeue(){
            if (!queue->isEmpty()){
                return queue->remove(0);
            }
            return nullptr;
        }

        // Función que retorna la estructura del primer elemento.
        T* front() {
            if (!queue->isEmpty()){
                return queue->getFirst()->getData();
            }
            return nullptr;
        }

        bool isEmpty() {
            return queue->isEmpty();
        }

        int size() {
            return queue->size();
        }

        void print(){
            Node<T> *nodePtr = queue->getFirst();
            while (nodePtr != nullptr){
                cout << nodePtr << " " << nodePtr->getData() << endl;
            }
        }
};

#endif