#pragma once
#include <vector>
#include"Admin.h"
#include "CardsInformation.h"
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
public:
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
