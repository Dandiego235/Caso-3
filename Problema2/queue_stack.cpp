#include "../Stack.cpp"

/* Caso 3: Problema 2
   Implementación de cola usando 2 pilas.
*/

template <class T>
class Queue{
    private:
        Stack<T> *pilaEn; // Pila donde se agregan elementos. pila de Enqueue
        Stack<T> *pilaDe; // Pila de donde se van a sacar los elementos. pila de dequeue

        void prepareDequeue(){
            if (pilaDe->isEmpty() && !pilaEn->isEmpty()){
            // Si la pila de dequeue está vacía y hay elementos en la pila donde se agregaron elementos,
            // sacamos todos los elementos de la pila de enqueue y los metemos en la pila de dequeue.
            // Así, todos los elementos quedan en un orden inverso. Y podemos sacarlos normalmente.
                while (!pilaEn->isEmpty()){
                    pilaDe->push(pilaEn->pop());
                }
            }
        }

    public:
        Queue(){
            pilaEn = new Stack<T>();
            pilaDe = new Stack<T>();
        }

        bool isEmpty(){
            return (pilaEn->isEmpty() and pilaDe->isEmpty()); // si las dos pilas están vacías, la cola está vacía.
        }

        void enqueue(T *data){
            pilaEn->push(data); // Mete el nodo al tope de la pila de enqueue.
        }

        T* dequeue(){
            if (!this->isEmpty()){
                prepareDequeue(); // Metemos lo que vamos a dequeue a la pila de dequeue donde queda en el top.
                return pilaDe->pop(); // Sacamos el primer elemento ingresado.
            }
            return nullptr;
        }

        T* front(){
            if (!this->isEmpty()){
                prepareDequeue(); // Metemos lo que vamos a dequeue primero a la pila de dequeue donde queda en el top.
                return pilaDe->getTop();
            }
            return nullptr;
        }
};