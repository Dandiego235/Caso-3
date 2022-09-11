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

        void enqueue(int pPriority, T* pData){
            Node<T> *nodePtr = queue->getFirst();
            int position = 0;
            while(nodePtr != nullptr){
                if (nodePtr->getPriority() > pPriority){
                    queue->insert(position, pData, pPriority);
                    break;
                }
                nodePtr = nodePtr->getNext();
                position++;
            }
            if (nodePtr == nullptr){
                queue->add(pData, pPriority);
            }
        }

        T* dequeue(){
            if (!queue->isEmpty()){
                return queue->remove(0);
            }
            return nullptr;
        }

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