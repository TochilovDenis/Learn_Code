#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Apartment {
	int m_AmountOfRooms{ 0 }; // Количество комнат
	double m_Meterage{ 0 };	 // Метраж
	int m_NumberOfApartment{ 0 }; // Номер кватриты
	int m_AmountOfResidents{ 0 }; // Количество жильцов
	bool m_Balcony{ false }; // Наличие Балкона

	// setter - устанавливает значение приватных переменных
	void AmountOfRooms(int value) { m_AmountOfRooms = value; }
	void Meterage(double value) { m_Meterage = value; }
	void NumberOfApartment(int value) { m_NumberOfApartment = value; }
	void AmountOfResidents(int value) { m_AmountOfResidents = value; }
	void Balcony(bool value) { m_Balcony = value; }

	// getter - возвращает его приватных переменных
	int AmountOfRooms() const { return m_AmountOfRooms; }
	double Meterage() const { return m_Meterage; }
	int NumberOfApartment() const { return m_NumberOfApartment; }
	int AmountOfResidents() const { return m_AmountOfResidents; }
	bool Balcony() const { return m_Balcony; }

	string GetApartmenttString() const {
		return "Количество комнат: " + to_string(AmountOfRooms()) +
			" | Метраж: " + ValueString(Meterage()) +
			" кв.м | Номер квартиры: " + to_string(NumberOfApartment()) +
			" | Количество жильцов: " + to_string(AmountOfResidents()) +
			" | Наличие балкона: " + (Balcony() ? "Да" : "Нет");
	}

	string ValueString(double value) const {
		ostringstream ss;
		ss << value;
		return ss.str();
	}

	void PrintApartment() const {
		cout << GetApartmenttString();
	}
};

void ConsoleSetup(int);

int main() {
	ConsoleSetup(1251);

	// Задача №1.
	Apartment a;
	a = { 1, 42.2, 154, 1, false };
	a.PrintApartment();

	return 0;
}

void ConsoleSetup(int mode) {
	SetConsoleCP(mode);
	SetConsoleOutputCP(mode);
}