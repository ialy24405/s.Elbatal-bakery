#pragma once
#define max_size 100 // Define the maximum size of the queues

template <typename T>
ref class Queue1 {
private:
    array<T>^ arr;
    int front;
    int rear;
public:
    Queue1() {
        arr = gcnew array<T>(100);
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return front == -1 && rear == -1;
    }

    bool IsFull() {
        return rear == 100 - 1;
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