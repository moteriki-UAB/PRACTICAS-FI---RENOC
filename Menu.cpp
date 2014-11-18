#include "Menu.h"

void MenuPrincipal()
{
	HANDLE hScreen;

	hScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	InitScreen(hScreen);

	TextColor(LIGHTGREEN, BLACK, hScreen);

	printf("------------- Menu Principal ------------\n");
	printf("|                                       |\n");
	printf("|  1. Jugar                             |\n");
	printf("|  2. Configurar                        |\n");
	printf("|  3. Millors Puntuacions               |\n");
	printf("|  4. Sortir                            |\n");
	printf("|                                       |\n");
	printf("-----------------------------------------\n\n");

	printf("Completed by Adri & Richi Company S.L.");
}

void MenuNivellDificultat()
{
	HANDLE hScreen;

	hScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	InitScreen(hScreen);

	TextColor(LIGHTMAGENTA, BLACK, hScreen);

	printf("------------ Menu Dificultat ------------\n");
	printf("|                                       |\n");
	printf("|  1. Principiant                       |\n");
	printf("|  2. Mitja                             |\n");
	printf("|  3. Expert                            |\n");
	printf("|                                       |\n");
	printf("-----------------------------------------");
}
