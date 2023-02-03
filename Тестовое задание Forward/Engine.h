#pragma once
#include <vector>

class Engine {
public:
	Engine() = default;
	virtual void	SetTenv()									= 0;
	virtual void	StartEngine()								= 0;
	virtual double	GetTenv()									= 0;
	virtual double	CalcCurrentV(int i, double A)				= 0;
	virtual double	CalcCurrentM(int i, double A)				= 0;
	virtual double	HeatingRate(int i, double A)				= 0;
	virtual double	CoolingRate()								= 0;

protected:
	double I				= 0;
	double Toverheat		= 0;
	double Hm				= 0;
	double Hv				= 0;
	double C				= 0;
	double Tenv				= 0;
	double Teng				= 0;

	std::vector <double> M;
	std::vector <double> V;
};