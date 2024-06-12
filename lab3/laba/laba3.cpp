#include <iostream>
#include "logic.h"
#include "ConsoleApplication1.cpp"
#include "Windows.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string expression = "A&B|C";

	Logic logic(expression);

	return 0;
}