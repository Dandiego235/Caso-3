#include "PriorityList.cpp"
#include "PriorityNode.cpp"

#ifndef PRIORITY

#define PRIORITY 1

template <class T>
class PriorityQueue{
    public:
        PriorityQueue(){
            queue = new List<T>();
        }

        // Función para meter un elemento a la cola con prioridad.
        void enqueue(int pPriority, T* pData){
            Node<T> *nodePtr = queue->getFirst(); // Puntero al primer nodo para recorrer la lista.
            int position = 0;
            while(nodePtr != nullptr){
                if (nodePtr->getPriority() > pPriority){
                    // Si la prioridad del nodo que estamos revisando es mayor que la prioridad del nodo que vamos a agregar,
                    // debemos insertar el nodo en la posición del nodo.
                    queue->insert(position, pData, pPriority);
                    break;
                }
                nodePtr = nodePtr->getNext(); // Obtenemos el siguiente nodo e incrementamos la posición.
                position++;
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
            T* result = nullptr;
            if (!queue->isEmpty()) {
                result = queue->find(0);
            }
            return result;
        }

        T* back(){
            queue->getLast()->structure;
        }

        bool isEmpty() {
            return queue->isEmpty();
        }
        
    private:
        List<T> *queue;
};

#endif