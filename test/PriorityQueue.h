#pragma once
template <typename T>
ref class PriorityQueue {
private:
    array<T>^ arr;
    int size;
public:
    PriorityQueue() {
        arr = gcnew array<T>(max_size);
        size = 0;
    }

    bool IsEmpty() {
        return size == 0;
    }

    bool IsFull() {
        return size == max_size;
    }

    void Enqueue(T value) {
        if (IsFull()) {
            Console::WriteLine("Priority Queue is Full");
            return;
        }
        int i;
        for (i = size - 1; i >= 0; --i) {
            if (arr[i][2] < value[2]&&value[2]>=60) // Assuming T is a comparable type
                arr[i + 1] = arr[i];
            else
                break;
        }
        arr[i + 1] = value;
        ++size;
    }

    T Dequeue() {
        if (IsEmpty()) {
            throw gcnew Exception("Priority Queue is Empty");
        }
        T value = arr[0];
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        --size;
        return value;
    }

    T Peek() {
        if (IsEmpty()) {
            throw gcnew Exception("Priority Queue is Empty");
        }
        return arr[0];
    }
};