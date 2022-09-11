#include "queue_stack.cpp"
#include <iostream>

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