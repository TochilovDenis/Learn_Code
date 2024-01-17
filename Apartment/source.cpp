#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

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
//template<typename T>
//T generateRandom(T, T);
//Apartment* GenerateAndFillArrayWithApartment(int, int, int, int);
//void PrintArrayWithApartment(Apartment*, int, int, int, int);

//Задача №4
template<typename T>
T generateRandom(T, T);
vector<Apartment> GenerateAndFillArrayWithApartment(int, int, int, int);
vector<vector<Apartment>>* CreateBuilding(int, int, int, int, int);
void SortBuildingByRoomsAndMeterage(vector<vector<Apartment>>&);
void PrintBuilding(const vector<vector<Apartment>>&);

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
	/*srand(unsigned(time(0)));
	int oneRoomAmount = 10, twoRoomAmount = 10, threeRoomAmount = 10, fourRoomAmount = 10;
	Apartment* apartments = GenerateAndFillArrayWithApartment(oneRoomAmount, twoRoomAmount, threeRoomAmount, fourRoomAmount);
	PrintArrayWithApartment(apartments, oneRoomAmount, twoRoomAmount, threeRoomAmount, fourRoomAmount);
	delete[] apartments;*/

	// Задача №4
	srand(unsigned(time(0)));
	int floorsAmount = 9, oneRoomAmount = 1, twoRoomAmount = 1, threeRoomAmount = 1, fourRoomAmount = 1;
	vector<vector<Apartment>>* building = CreateBuilding(floorsAmount, oneRoomAmount, twoRoomAmount, threeRoomAmount, fourRoomAmount);
	SortBuildingByRoomsAndMeterage(*building);
	PrintBuilding(*building);
	delete building;

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
//
//template<typename T>
//T generateRandom(T min, T max) {
//	if constexpr (is_integral<T>::value) {
//		return T(min + (rand() % ((max + 1) - min)));
//	}
//	else if constexpr (is_floating_point<T>::value) {
//		return T(min + double(rand()) / double(RAND_MAX) * (max - min));
//	}
//	else if constexpr (is_same<T, bool>::value) {
//		return rand() % 2;
//	}
//}
//
//Apartment GeneratedApartment() {
//	Apartment gA;
//	gA.AmountOfRooms(generateRandom(1, 5));
//	gA.Meterage(generateRandom(20.0, 100.0));
//	gA.NumberOfApartment(generateRandom(1, 200));
//	gA.AmountOfResidents(generateRandom(1, 5));
//	gA.Balcony(generateRandom(0, 1) == 0);
//	return gA;
//}
//
//void PrintGeneratedApartment() {
//	Apartment gA = GeneratedApartment();
//	gA.PrintApartment();
//}

// Задача №3

//Apartment* GenerateAndFillArrayWithApartment(int oneRoomAmount, int twoRoomAmount, int threeRoomAmount, int fourRoomAmount) {
//	int totalRoom = oneRoomAmount + twoRoomAmount + threeRoomAmount + fourRoomAmount;
//	Apartment* apartments = new Apartment[totalRoom];
//	for (size_t i = 0; i < totalRoom; i++) {
//		Apartment gfA;
//		gfA.AmountOfRooms(i < oneRoomAmount ? 1 : i < oneRoomAmount + twoRoomAmount ? 2 : i < oneRoomAmount + twoRoomAmount + threeRoomAmount ? 3 : 4);
//		gfA.Meterage(generateRandom(20.0, 100.0));
//		gfA.NumberOfApartment(generateRandom(1, 200));
//		gfA.AmountOfResidents(generateRandom(1, 5));
//		gfA.Balcony(generateRandom(0, 1) == 0);
//		apartments[i] = gfA;
//	}
//	return apartments;
//}
//
//void PrintArrayWithApartment(Apartment* a, int oneRoomAmount, int twoRoomAmount, int threeRoomAmount, int fourRoomAmount) {
//	int totalRoom = oneRoomAmount + twoRoomAmount + threeRoomAmount + fourRoomAmount;
//	for (size_t i = 0; i < totalRoom; i++) {
//		cout << "Квартира " << (i + 1) << ": | ";
//		cout << a[i].GetApartmentString();
//	}
//}

// Задача №4
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

vector<Apartment> GenerateAndFillArrayWithApartment(int oneRoomAmount, int twoRoomAmount, int threeRoomAmount, int fourRoomAmount) {
	int totalRoom = oneRoomAmount + twoRoomAmount + threeRoomAmount + fourRoomAmount;
	vector<Apartment> apartments(totalRoom);
	for (size_t i = 0; i < totalRoom; i++) {
		Apartment gfA;
		if (i < oneRoomAmount) {
			gfA.AmountOfRooms(1);
			gfA.Meterage(generateRandom(30.0, 50.0));
		}
		else if (i < oneRoomAmount + twoRoomAmount) {
			gfA.AmountOfRooms(2);
			gfA.Meterage(generateRandom(50.0, 70.0));
		}
		else if (i < oneRoomAmount + twoRoomAmount + threeRoomAmount) {
			gfA.AmountOfRooms(3);
			gfA.Meterage(generateRandom(70.0, 90.0));
		}
		else {
			gfA.AmountOfRooms(4);
			gfA.Meterage(generateRandom(90.0, 100.0));
		}
		gfA.NumberOfApartment(generateRandom(1, 200));
		gfA.AmountOfResidents(generateRandom(1, 5));
		gfA.Balcony(generateRandom(0, 1) == 0);
		apartments[i] = gfA;
	}
	return apartments;
}

vector<vector<Apartment>>* CreateBuilding(int floorsAmount, int oneRoomAmount, int twoRoomAmount, int threeRoomAmount, int fourRoomAmount) {
	vector<vector<Apartment>>* building = new vector<vector<Apartment>>(floorsAmount);
	int apartmentNumber = 1;

	(*building)[0] = GenerateAndFillArrayWithApartment(oneRoomAmount, twoRoomAmount, threeRoomAmount, fourRoomAmount);
	for (Apartment& apartment : (*building)[0]) {
		apartment.NumberOfApartment(apartmentNumber++);
	}

	// Копирование метража и номера квартира на все остальные этажи
	for (int i = 1; i < floorsAmount; i++) {
		(*building)[i] = GenerateAndFillArrayWithApartment(oneRoomAmount, twoRoomAmount, threeRoomAmount, fourRoomAmount);
		for (int j = 0; j < (*building)[i].size(); ++j) {
			(*building)[i][j].Meterage((*building)[0][j].Meterage());
			(*building)[i][j].NumberOfApartment(apartmentNumber++);
		}
	}
	return building;
}

void SortBuildingByRoomsAndMeterage(vector<vector<Apartment>>& building) {
	for (vector<Apartment>& floor : building) {
		for (int i = 0; i < floor.size() - 1; ++i) {
			for (int j = 0; j < floor.size() - i - 1; ++j) {
				if (floor[j].AmountOfRooms() > floor[j + 1].AmountOfRooms() ||
					(floor[j].AmountOfRooms() == floor[j + 1].AmountOfRooms() && floor[j].Meterage() > floor[j + 1].Meterage())) {
					swap(floor[j], floor[j + 1]);
				}
			}
		}
	}
}

void PrintBuilding(const vector<vector<Apartment>>& building) {
	for (int floorIndex = 0; floorIndex < building.size(); floorIndex++){
		cout << "Этаж " << (floorIndex + 1) << ": \n";
		for (const Apartment& apartment : building[floorIndex])
		{
			apartment.PrintApartment();
		}
	}
}
