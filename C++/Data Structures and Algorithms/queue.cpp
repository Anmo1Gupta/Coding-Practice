//Queue Using Arrays

#include <bits/stdc++.h> 
using namespace std; 
 
class Queue { 
public: 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a queue of given capacity. 
// It initializes size of queue as 0 
Queue* createQueue(unsigned capacity) 
{ 
    Queue* queue = new Queue(); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
  
    // This is important, see the enqueue 
    queue->rear = capacity - 1; 
    queue->array = new int[( 
        queue->capacity * sizeof(int))]; 
    return queue; 
} 
  
// Queue is full when size becomes equal to the capacity 
int isFull(Queue* queue) 
{ 
    return (queue->size == queue->capacity); 
} 
  
// Queue is empty when size is 0 
int isEmpty(Queue* queue) 
{ 
    return (queue->size == 0); 
} 
  
// Function to add an item to the queue. It changes rear and size 
void enqueue(Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1) 
                  % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    cout << item << " enqueued to queue\n"; 
} 
  
// Function to remove an item from queue. It changes front and size 
int dequeue(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Function to get front of queue 
int front(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 
  
// Function to get rear of queue 
int rear(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
} 
  

int main() 
{ 
    Queue* queue = createQueue(1000); 
  
    enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 
  
    cout << dequeue(queue) 
         << " dequeued from queue\n"; 
  
    cout << "Front item is "
         << front(queue) << endl; 
    cout << "Rear item is "
         << rear(queue) << endl; 
  
    return 0; 
}

// Queue Using Linked List

// #include <bits/stdc++.h> 
// using namespace std; 
  
// struct QNode { 
//     int data; 
//     QNode* next; 
//     QNode(int d) 
//     { 
//         data = d; 
//         next = NULL; 
//     } 
// }; 
  
// struct Queue { 
//     QNode *front, *rear; 
//     Queue() 
//     { 
//         front = rear = NULL; 
//     } 
  
//     void enQueue(int x) 
//     { 
  
//         // Create a new LL node 
//         QNode* temp = new QNode(x); 
  
//         // If queue is empty, then 
//         // new node is front and rear both 
//         if (rear == NULL) { 
//             front = rear = temp; 
//             return; 
//         } 
  
//         // Add the new node at 
//         // the end of queue and change rear 
//         rear->next = temp; 
//         rear = temp; 
//     } 
  
//     // Function to remove 
//     // a key from given queue q 
//     void deQueue() 
//     { 
//         // If queue is empty, return NULL. 
//         if (front == NULL) 
//             return; 
  
//         // Store previous front and 
//         // move front one node ahead 
//         QNode* temp = front; 
//         front = front->next; 
  
//         // If front becomes NULL, then 
//         // change rear also as NULL 
//         if (front == NULL) 
//             rear = NULL; 
  
//         delete (temp); 
//     } 
// }; 
  
// int main() 
// { 
//     Queue q; 
//     q.enQueue(10); 
//     q.enQueue(20); 
//     q.deQueue(); 
//     q.deQueue(); 
//     q.enQueue(30); 
//     q.enQueue(40); 
//     q.enQueue(50); 
//     q.deQueue(); 
//     cout << "Queue Front : " << (q.front)->data << endl; 
//     cout << "Queue Rear : " << (q.rear)->data; 
// } 