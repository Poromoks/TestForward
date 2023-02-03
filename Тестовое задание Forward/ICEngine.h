#pragma once
#include "Engine.h"

class ICEngine : public Engine {
public:
	ICEngine();
	void	SetTenv()								override;
	void	StartEngine()							override;
	double	GetTenv()								override;
	double	CalcCurrentV(int i, double A)			override;
	double	CalcCurrentM(int i, double A)			override;
	double	HeatingRate(int i, double A)			override;
	double	CoolingRate()							override;
};