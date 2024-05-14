#pragma once
#include <vector>
#include "Queue.h"
#include "PriorityQueue.h"
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
    static Queue1<int>^ PayingQueue;
    static PriorityQueue<List<int>^>^ bakeryMaleQueue;
    static PriorityQueue<List<int>^>^ bakeryFemaleQueue;
    static float moneyNoCard = 0;
    static float moneyCard = 0;
    static int breadCard = 0;
    static int breadNoCard = 0;
    static float totalMoney = 0;
    static int totalBread = 0;
	static String^ Adminname;
public:
    static String^ getAdminName() {
		return Adminname;
    }
    static void setAdminName(String^ name) {
		Adminname = name;
    }
    static float getMoneyNoCard() {
        return moneyNoCard;
        }
    static void setMoneyNoCard(float money) {
        moneyNoCard += money;
        //setTotalMoney(money);
		}
    static float getMoneyCard() {
		return moneyCard;
        }
    static void setMoneyCard(float money) {
        moneyCard += money;
        //setTotalMoney(money);
        }
    static int getBreadCard() {
        return breadCard;
		}
    static void setBreadCard(int bread) {
		breadCard += bread;
        //setTotalBread(bread);
        }
    static int getBreadNoCard() {
        return breadNoCard;
		}
    static void setBreadNoCard(int bread) {
		breadNoCard += bread;
        //setTotalBread(bread);
		}
    static float getTotalMoney() {
        return totalMoney;
        }
    static void setTotalMoney(float money) {
        totalMoney += money;
		}
    static int getTotalBread() {
		return totalBread;
        }
    static void setTotalBread(int bread) {
        totalBread += bread;
		}
    // Method to get the reference to the FemaleQueue
    static PriorityQueue<List<int>^>^ GetBakeryFemaleQueue() {
		if (bakeryFemaleQueue == nullptr)
		{
			bakeryFemaleQueue = gcnew PriorityQueue<List<int>^>();
		}
        return bakeryFemaleQueue;
        }
    static void AddToBakeryFemaleQueue(List<int>^ list) {
        GetBakeryFemaleQueue()->Enqueue(list);
        }

    // Method to get the reference to the MaleQueue
    static PriorityQueue<List<int>^>^ GetBakeryMaleQueue() {
        if (bakeryMaleQueue == nullptr)
        {
            bakeryMaleQueue = gcnew PriorityQueue<List<int>^>();
        }
		return bakeryMaleQueue;
    }

    static void AddToBakeryMaleQueue(List<int>^ list) {
		GetBakeryMaleQueue()->Enqueue(list);
        }
    // Method to get the reference to the PayingQueue
    
    static Queue1<int>^ GetPayingQueue(){
        if (PayingQueue == nullptr)
		{
			PayingQueue = gcnew Queue1<int>();
		}
		return PayingQueue;
    }
    static void AddToPayingQueue(int id){
		GetPayingQueue()->Enqueue(id);
	}
    static void RemoveFromPayingQueue(){
        GetPayingQueue()->Dequeue();
        }
    static int getFrontPayingQueue(){
        return GetPayingQueue()->Peek();
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
    static int getCustomerBread(int i) {
        return customersVector[i]->BreadNum;
        }
    static bool getCustomerGender(int i) {
        return customersVector[i]->Gender;
		}
    static int getCustomerAge(int i) {
        return customersVector[i-1]->Age;
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
    static void SetCustomerBread(int id, int bread) {
		for (int i = 0; i < GetCustomersVector()->Count; i++)
		{
			if (GetCustomersVector()[i]->CustomerID == id)
			{
				GetCustomersVector()[i]->BreadNum = bread;
			}
		}
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
    static void RemoveCard(int id)
	{
		for (int i = 0; i < GetCardsVector()->Count; i++)
		{
			if (GetCardsVector()[i]->getID() == id)
			{
				GetCardsVector()->RemoveAt(i);
				break;
			}
		}
	}
	static void RemoveCard(String^ name)
	{
		for (int i = 0; i < GetCardsVector()->Count; i++)
		{
			if (GetCardsVector()[i]->getName() == name)
			{
				GetCardsVector()->RemoveAt(i);
				break;
			}
		}
	}
	static bool CheckCard(int id)
	{
		for (int i = 0; i < GetCardsVector()->Count; i++)
		{
			if (GetCardsVector()[i]->getID() == id)
			{
				return true;
			}
		}
		return false;
	}
	static bool CheckCard(String^ name)
	{
		for (int i = 0; i < GetCardsVector()->Count; i++)
		{
			if (GetCardsVector()[i]->getName() == name)
			{
				return true;
			}
		}
		return false;
	}
    static bool VaildBreadNum(int id, int bread) {
        		for (int i = 0; i < GetCustomersVector()->Count; i++)
		{
			if (GetCustomersVector()[i]->CustomerID == id)
			{
				if (GetCustomersVector()[i]->BreadNum >= bread)
				{
					return true;
				}
			}
		}
		return false;
    }
    static int GetRemainBread(int id) {
        for (int i = 0; i < GetCardsVector()->Count; i++)
        {
            if (GetCardsVector()[i]->ID == id)
            {
                return GetCardsVector()[i]->MonthlyBread;
            }
        }
        return 0;
    }
    static void SetRemainBread(int id, int bread) {
		for (int i = 0; i < GetCardsVector()->Count; i++)
		{
			if (GetCardsVector()[i]->ID == id)
			{
				GetCardsVector()[i]->MonthlyBread -= bread;
			}
		}
	}
    static int GetFamilySize(int id) {
        for (int i = 0; i < GetCardsVector()->Count; i++)
        {
            if (GetCardsVector()[i]->ID == id)
            {
                return GetCardsVector()[i]->FamilySize;
            }
        }
        return 0;
	}
};
