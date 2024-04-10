#pragma once
#include <vector>
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
public:
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
    static void addnewCard(String ^ name , int num) {
        CardsInformation^ card = gcnew CardsInformation(name,num);
        GetCardsVector()->Add(card);

    }
    static void AddCard(CardsInformation^ card)
	{
		GetCardsVector()->Add(card);
	}
    
};
