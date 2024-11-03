#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

// Define the structure for queue nodes
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new queue and return a pointer to it
Queue* CreateQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL; // Memory allocation failed
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
bool IsEmpty(Queue* queue) {
    return (queue == NULL || queue->front == NULL);
}

// Function to add an element to the queue
bool Enqueue(Queue* queue, int value) {
    if (queue == NULL) {
        return false; // Queue not initialized
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false; // Memory allocation failed
    }
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // Queue is empty, set both front and rear to the new node
        queue->front = queue->rear = newNode;
    } else {
        // Add the new node at the end of the queue and update rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return true;
}

// Function to remove an element from the queue and return its value
int Dequeue(Queue* queue) {
    if (queue == NULL || queue->front == NULL) {
        return -1; // Queue is empty or not initialized
    }
    Node* temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL; // Queue is now empty
    }
    free(temp);
    return value;
}

// Function to dispose of the queue and free all allocated memory
void DisposeQueue(Queue* queue) {
    if (queue == NULL) {
        return;
    }
    Node* current = queue->front;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(queue);
}

#endif // QUEUE_H
