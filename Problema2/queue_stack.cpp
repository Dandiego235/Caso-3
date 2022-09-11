#include "../Stack.cpp"

template <class T>
class Queue{
    private:
        Stack<T> *pilaEn;
        Stack<T> *pilaDe;

    public:

        Queue(){
            pilaEn = new Stack<T>();
            pilaDe = new Stack<T>();
        }
        void enqueue(T *data){
            pilaEn->push(data);
        }

        T* dequeue(){
            if (pilaDe->isEmpty() && !pilaEn->isEmpty()){
                while (!pilaEn->isEmpty()){
                    pilaDe->push(pilaEn->pop());
                }
            } else if (pilaDe->isEmpty() && pilaEn->isEmpty()){
                return nullptr; // La cola está vacía.
            }
            return pilaDe->pop();
        }

        bool isEmpty(){
            return (pilaEn->isEmpty() and pilaDe->isEmpty());
        }
};