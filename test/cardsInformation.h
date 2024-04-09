#pragma once
ref class CardsInformation {
private:
    System::String^ name;
    int familySize;
    int monthlyBread;
    static int cardsID = 0;
    int id;

public:
    CardsInformation() {}
    CardsInformation(System::String^ n, int fz) {
        this->name = n;
        this->familySize = fz;
        this->monthlyBread = familySize * 150;
        this->id = ++cardsID;
    }

    property System::String^ Name {
        System::String^ get() {
            return name;
        }
        void set(System::String^ value) {
            name = value;
        }
    }
    property int FamilySize {
        int get() {
            return familySize;
        }
        void set(int value) {
            familySize = value;
            monthlyBread = familySize * 150;
        }
    }
    int getFamilySize() {
		return familySize;
	}

    property int MonthlyBread {
        int get() {
            return monthlyBread;
        }
    }
    int getMonthlyBread() {
        return monthlyBread;
        }

    property int ID {
        int get() {
            return id;
        }
    }
    int getID() {
		return id;
	}
    
};
