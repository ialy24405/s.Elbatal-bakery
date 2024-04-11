#pragma once
#include <vector>
#include"Admin.h"
#include "CardsInformation.h"
#include "CustomerInformation.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
public ref class DataManager
{
private:
    static List<CardsInformation^>^ cardsVector;
    static List<Admin^>^ adminsList;
    static List<CustomerInformation^>^ customersVector;
    static int customerMaleID=0, customerFemaleID=0;
    static List<int>^ PayingQueue;
public:
    // Method to get the reference to the PayingQueue
    
    static List<int>^ GetPayingQueue(){
        if (PayingQueue == nullptr)
		{
			PayingQueue = gcnew List<int>();
		}
		return PayingQueue;
    }
    static void AddToPayingQueue(int id){
		GetPayingQueue()->Add(id);
	}
    // Method to get the reference to the customersVector
    
    static List<CustomerInformation^>^ GetCustomersVector()
	{
		if (customersVector == nullptr)
		{
			customersVector = gcnew List<CustomerInformation^>();
		}
		return customersVector;
	}
    static void AddCustomer(CustomerInformation^ customer)
        {
        GetCustomersVector()->Add(customer);
        }
    static int AddCustomer(bool gender, int age) {
        CustomerInformation^ customer = gcnew CustomerInformation(gender, age);
        if (gender) {
            customer->CustomerID = ++customerMaleID;
        }
        else {
            customer->CustomerID = ++customerFemaleID;
        }
        GetCustomersVector()->Add(customer);
        return customer->CustomerID;
    }
    static int getCustomerID(int i) {
		return customersVector[i]->CustomerID;
	}
    static bool CheckCustomer(int id)
    {
        for (int i = 0; i < GetCustomersVector()->Count; i++)
		{
			if (GetCustomersVector()[i]->CustomerID == id)
			{
				return true;
			}
		}
		return false;
    }

    // Method to get the reference to the adminsList
    static List<Admin^>^ GetAdminsList()
	{
		if (adminsList == nullptr)
		{
			adminsList = gcnew List<Admin^>();
		}
		return adminsList;
	}
    static void AddAdmin(Admin^ admin)
        {
        GetAdminsList()->Add(admin);
		}
    static void AddAdmin(String^ name, String^ password)
        {
        Admin^ admin = gcnew Admin(name, password);
        GetAdminsList()->Add(admin);
        }
    static bool CheckAdmin(String^ name, String^ password)
		{
		for (int i = 0; i < GetAdminsList()->Count; i++)
			{
			if (GetAdminsList()[i]->getUserName() == name && GetAdminsList()[i]->getPassword() == password)
				{
				return true;
				}
			}
		return false;
		}
    // Method to get the reference to the cardsVector
    static List<CardsInformation^>^ GetCardsVector()
    {
        if (cardsVector == nullptr)
        {
            cardsVector = gcnew List<CardsInformation^>();
        }
        return cardsVector;
    }
    static int getID(int i) {
        return cardsVector[i]->getID();
    }
    static String^ getName(int i) {
		return cardsVector[i]->getName();
	}
    static int getSize() {
		return cardsVector->Count;
	}
    static int addnewCard(String ^ name , int num) {
        CardsInformation^ card = gcnew CardsInformation(name,num);
        GetCardsVector()->Add(card);
        return CardsInformation::getCardsID();

    }
    static void AddCard(CardsInformation^ card)
	{
		GetCardsVector()->Add(card);
	}
    
};
