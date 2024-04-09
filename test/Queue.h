#pragma once
#define max_size 100 // Define the maximum size of the queues

template <typename T>
ref class Queue {
private:
    array<T>^ arr;
    int front;
    int rear;
public:
    Queue() {
        arr = gcnew array<T>(max_size);
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return front == -1 && rear == -1;
    }

    bool IsFull() {
        return rear == max_size - 1;
    }

    void Enqueue(T value) {
        if (IsFull()) {
            Console::WriteLine("Queue is Full");
            return;
        }
        if (IsEmpty()) {
            front = 0;
        }
        arr[++rear] = value;
    }

    T Dequeue() {
        if (IsEmpty()) {
            throw gcnew Exception("Queue is Empty");
        }
        T removedVal = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
        return removedVal;
    }

    T Peek() {
        if (IsEmpty()) {
            throw gcnew Exception("Queue is Empty");
        }
        return arr[front];
    }
};