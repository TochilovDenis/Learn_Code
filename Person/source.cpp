#include <iostream>
#include <Windows.h>

using namespace std;


void ConsoleSetup(int);

int main() {
	ConsoleSetup(1251);

	return 0;
}

void ConsoleSetup(int mode) {
	SetConsoleCP(mode);
	SetConsoleOutputCP(mode);
}