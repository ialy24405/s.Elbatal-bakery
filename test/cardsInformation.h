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
    static int getCardsID() {
		return cardsID;
	}
    property System::String^ Name {
        System::String^ get() {
            return name;
        }
        void set(System::String^ value) {
            name = value;
        }
    }
    System::String^ getName() {
        return name;
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
        void set(int value) {
			monthlyBread = value;
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
