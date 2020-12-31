#include <semaphore.h>
class BoundedBlockingQueue {
public:
    queue<int> Q;
    sem_t semEnqueue,semDequeue;
    int capacity = 0;
    BoundedBlockingQueue(int capacity) {
        this->capacity = capacity;
        sem_init(&semEnqueue,0,capacity);
        sem_init(&semDequeue,0,0);
    }
    
    void enqueue(int element) {
        sem_wait(&semEnqueue);
        Q.push(element);
        sem_post(&semDequeue);
    }
    
    int dequeue() {
        sem_wait(&semDequeue);
        int top = Q.front();
        Q.pop();
        sem_post(&semEnqueue);
        return top;
    }
    
    int size() {
        return Q.size();
    }
};
