#pragma once
public ref class CustomerInformation {
private:
    bool gender;
    int customerID;
    int breadNum;
    int age;

public:
    CustomerInformation(bool g, int age) {
        this->gender = g;
        this->age = age;
        this->breadNum = 0;
    }

    CustomerInformation() {}

    property int Age {
        int get() {
            return age;
        }
        void set(int value) {
            age = value;
        }
    }

    property bool Gender {
        bool get() {
            return gender;
        }
        void set(bool value) {
            gender = value;
        }
    }

    property int CustomerID {
        int get() {
            return customerID;
        }
        void set(int value) {
            customerID = value;
        }
    }

    property int BreadNum {
        int get() {
            return breadNum;
        }
        void set(int value) {
            breadNum = value;
        }
    }
};
