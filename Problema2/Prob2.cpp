#include "queue_stack.cpp"
#include <iostream>

int main(){
    int valores[] = {1,2,3,4,5,6,7,8,9,10}; // Agregamos estos valores a la cola

    Queue<int> *cola = new Queue<int>();

    cout << "Está vacía? " << cola->isEmpty() << endl; // Probamos isEmpty.

    for (int index = 0; index < 10; index++){
        cola->enqueue(&valores[index]);
    }

    cout << *cola->front() << endl; // Probamos el front y el dequeue
    cout << *cola->dequeue() << endl;
    cout << *cola->front() << endl;
    cout << *cola->dequeue() << endl;
    cout << *cola->front() << endl;
    cout << *cola->dequeue() << endl;

    cout << "Está vacía? " << cola->isEmpty() << endl;
    
    int* numberQ = (int*) malloc(sizeof(int)); // Agregamos un número
    *numberQ = 11;
    cola->enqueue(numberQ);

    cout << *cola->front() << endl;
    cout << *cola->dequeue() << endl;
    cout << *cola->front() << endl;
    cout << *cola->dequeue() << endl;
    cout << *cola->front() << endl;
    cout << *cola->dequeue() << endl;

    numberQ = (int*) malloc(sizeof(int));
    *numberQ = 12;
    cola->enqueue(numberQ);

    while (!(cola->isEmpty())){
        cout << *cola->front() << endl;
        cout << *cola->dequeue() << endl;
    }

    cout << "Está vacía? " << cola->isEmpty() << endl;
}