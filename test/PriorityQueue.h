#pragma once
#include "Windows.h"
template <typename T>
ref class PriorityQueue {
private:
    int size;
public:
    array<T>^ arr;
    PriorityQueue() {
        arr = gcnew array<T>(max_size);
        size = 0;
    }
    PriorityQueue(PriorityQueue<T>^ other) {
        arr = gcnew cli::array<T>(max_size);
        size = other->size;
        Array::Copy(other->arr, arr, other->size);
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
    
    void Clear() {
		size = 0;
	}
    int Count() {
		return size;
	}
	void Print() {
		for (int i = 0; i < size; i++) {
			Console::WriteLine(arr[i]);
		}
	}
	//static const int max_size = 100;
};