#include "Stack.cpp"

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

int main(){
    int valores[] = {1,2,3,4,5,6,7,8,9,10};

    Queue<int> *cola = new Queue<int>();
    for (int index = 0; index < 10; index++){
        cola->enqueue(&valores[index]);
    }

    cout << *cola->dequeue() << endl;
    cout << *cola->dequeue() << endl;
    cout << *cola->dequeue() << endl;

    int* numberQ = (int*) malloc(sizeof(int));
    *numberQ = 11;
    cola->enqueue(numberQ);

    cout << *cola->dequeue() << endl;
    cout << *cola->dequeue() << endl;
    cout << *cola->dequeue() << endl;

    numberQ = (int*) malloc(sizeof(int));
    *numberQ = 12;
    cola->enqueue(numberQ);

    while (!(cola->isEmpty())){
        cout << *cola->dequeue() << endl;
    }
}