#include <iostream>
#include "ICEngine.h"

ICEngine::ICEngine() {
	I			= 10;
	Toverheat	= 110;
	Hm			= 0.01;
	Hv			= 0.0001;
	C			= 0.1;

	M = { 20, 75, 100, 105, 75, 0 };
	V = { 0, 75, 150, 200, 250, 300 };
}

void ICEngine::SetTenv() {
	std::cout << "Введите температуру окружающей среды: ";
	std::cin >> Tenv;
}

double ICEngine::GetTenv() {
	return Tenv;
}

double ICEngine::CalcCurrentV(int i, double A) {
	if (A <= V[i + 1])
		return A;
	else
		return V[i + 1];
}

double ICEngine::CalcCurrentM(int i, double A) {
	if (i == 5)
		return 0;
	else
		return ((M[i + 1] - M[i]) / V[i + 1]) * CalcCurrentV(i, A) + M[i];
}

double ICEngine::HeatingRate(int i, double A) {
	return CalcCurrentM(i, CalcCurrentV(i, A)) * Hm + pow(CalcCurrentV(i, A), 2) * Hv;;
}

double ICEngine::CoolingRate() {
	return C * (Tenv - Teng);;
}

void ICEngine::StartEngine() {
	Teng = GetTenv();

	double A = 0;
	int i = 0;

	int time = 0;

	while (Teng < Toverheat)
	{
		std::cout << std::endl << "A = " << A << std::endl;
		std::cout << "time = " << time << std::endl;
		std::cout << "Teng = " << Teng << std::endl;
		A += CalcCurrentM(i, A) / I;
		Teng += HeatingRate(i, A) - CoolingRate();

		if (i < V.size() - 2 and CalcCurrentV(i, A) >= V[i + 1])
			i++;

		time++;
	}

	std::cout << "Время до перегрева двигателя внутреннего сгорания: " << time << std::endl;
}