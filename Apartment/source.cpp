#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

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

	string GetApartmentString() const {
		return "Количество комнат: " + to_string(AmountOfRooms()) +
			" | Метраж: " + ValueString(Meterage()) +
			" кв.м | Номер квартиры: " + to_string(NumberOfApartment()) +
			" | Количество жильцов: " + to_string(AmountOfResidents()) +
			" | Наличие балкона: " + (Balcony() ? "Да" : "Нет") + "\n";
	}

	string ValueString(double value) const {
		ostringstream ss;
		ss << fixed << setprecision(2) << value;
		return ss.str();
	}

	void PrintApartment() const {
		cout << GetApartmentString();
	}
};

void ConsoleSetup(int);
//Задача №2
//int generateRandomInt(int, int);
//double generateRandomDouble(double, double);
//bool generateRandomBool();

//template<typename T>
//T generateRandom(T, T);
//Apartment GeneratedApartment();
//void PrintGeneratedApartment();

//Задача №3
template<typename T>
T generateRandom(T, T);
Apartment GeneratedApartment();
Apartment* GenerateAndFillArrayWithApartment(int, int, int, int);
void PrintArrayWithApartment(Apartment*, int, int, int, int);

int main() {
	ConsoleSetup(1251);

	// Задача №1.
	/*Apartment a;
	a = { 1, 42.2, 154, 1, false };
	a.PrintApartment();*/

	// Задача №2.
	/*srand(unsigned(time(0)));
	PrintGeneratedApartment();
	PrintGeneratedApartment();
	PrintGeneratedApartment();*/

	// Задача №3
	srand(unsigned(time(0)));
	int oneRoom = 10, twoRoom = 10, threeRoom = 10, fourRoom = 10;
	Apartment* apartments = GenerateAndFillArrayWithApartment(oneRoom, twoRoom, threeRoom, fourRoom);
	PrintArrayWithApartment(apartments, oneRoom, twoRoom, threeRoom, fourRoom);
	delete[] apartments;

	return 0;
}

void ConsoleSetup(int mode) {
	SetConsoleCP(mode);
	SetConsoleOutputCP(mode);
}

// Задача №2

//int generateRandomInt(int min, int max) {
//	return min + (rand() % ((max + 1) - min));
//}
//
//double generateRandomDouble(double min, double max) {
//	return min + double(rand()) / double(RAND_MAX) * (max - min);
//}
//bool generateRandomBool() {
//	return  rand() % 2;
//}

template<typename T>
T generateRandom(T min, T max) {
	if constexpr (is_integral<T>::value) {
		return T(min + (rand() % ((max + 1) - min)));
	}
	else if constexpr (is_floating_point<T>::value) {
		return T(min + double(rand()) / double(RAND_MAX) * (max - min));
	}
	else if constexpr (is_same<T, bool>::value) {
		return rand() % 2;
	}
}

Apartment GeneratedApartment() {
	Apartment gA;
	gA.AmountOfRooms(generateRandom(1, 5));
	gA.Meterage(generateRandom(20.0, 100.0));
	gA.NumberOfApartment(generateRandom(1, 200));
	gA.AmountOfResidents(generateRandom(1, 5));
	gA.Balcony(generateRandom(0, 1) == 0);
	return gA;
}

void PrintGeneratedApartment() {
	Apartment gA = GeneratedApartment();
	gA.PrintApartment();
}

// Задача №3
Apartment* GenerateAndFillArrayWithApartment(int oneRoom, int twoRoom, int threeRoom, int fourRoom) {
	int totalRoom = oneRoom + twoRoom + threeRoom + fourRoom;
	Apartment* apartments = new Apartment[totalRoom];
	for (size_t i = 0; i < totalRoom; i++) {
		Apartment gfA;
		gfA.AmountOfRooms(i < oneRoom ? 1 : i < oneRoom + twoRoom ? 2 : i < oneRoom + twoRoom + threeRoom ? 3 : 4);
		gfA.Meterage(generateRandom(20.0, 100.0));
		gfA.NumberOfApartment(generateRandom(1, 200));
		gfA.AmountOfResidents(generateRandom(1, 5));
		gfA.Balcony(generateRandom(0, 1) == 0);
		apartments[i] = gfA;
	}
	return apartments;
}

void PrintArrayWithApartment(Apartment* a, int oneRoom, int twoRoom, int threeRoom, int fourRoom) {
	int totalRoom = oneRoom + twoRoom + threeRoom + fourRoom;
	for (size_t i = 0; i < totalRoom; i++) {
		cout << "Квартира " << (i + 1) << ": | ";
		cout << a[i].GetApartmentString();
	}
}