#include <iostream>
#include "ICEngine.h"

int main()
{
	std::vector <Engine*> engines;
	engines.push_back(new ICEngine);

	for (const auto& engine : engines) {
		engine->SetTenv();
		engine->StartEngine();
	}

	system("pause");
	return 0;
}
