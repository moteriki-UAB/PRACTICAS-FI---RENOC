#include "Joc.h"

//===================================================================================
// NOM: InfoPuntsPartida
//===================================================================================
// DESCRIPCIÓ: Escriu per pantalla els punts que porta el jugador en la partida.
//===================================================================================

void InfoPuntsPartida(int Punts, HANDLE hScreen)
{
	TextColor(WHITE, BLACK, hScreen);
	GotoXY(INICI_X + 2, INICI_Y - 4, hScreen);
	printf("Punts: %d", Punts);
}

//===================================================================================
// NOM: InfoVidesPartida
//===================================================================================
// DESCRIPCIÓ: Escriu per pantalla el numero de vides que li queden al jugador.
//===================================================================================

void InfoVidesPartida(int Vides, HANDLE hScreen)
{
	TextColor(WHITE, BLACK, hScreen);
	GotoXY(INICI_X + 2, INICI_Y - 2, hScreen);
	printf("Vides: %d", Vides);
}

//===================================================================================
// NOM: InfoNivellPartida
//===================================================================================
// DESCRIPCIÓ: Escriu per pantalla el nivell en el que es troba el jugador.
//===================================================================================

void InfoNivellPartida(int Nivell, HANDLE hScreen)
{
	TextColor(WHITE, BLACK, hScreen);
	GotoXY(INICI_X + 26, INICI_Y - 4, hScreen);
	printf("Nivell: %d", Nivell);
}

//===================================================================================
// NOM: GameOver
//===================================================================================
// DESCRIPCIÓ: Escriu per pantalla el missatge "GAME OVER".
//===================================================================================

void GameOver(HANDLE hScreen)
{
	TextColor(RED, BLACK, hScreen);
	GotoXY(INICI_X + 12, INICI_Y + 14, hScreen);
	printf("GAME OVER");
}

//===================================================================================
// NOM: NivellSuperat
//===================================================================================
// DESCRIPCIÓ: Escriu per pantalla el missatge "NIVELL SUPERAT".
//===================================================================================

void NivellSuperat(HANDLE hScreen)
{
	TextColor(YELLOW, BLACK, hScreen);
	GotoXY(INICI_X + 9, INICI_Y + 14, hScreen);
	printf("NIVELL SUPERAT\n\n\n\n\n\n\n\n");
}

//===================================================================================
// NOM: Taulell
//===================================================================================
// DESCRIPCIÓ: Dibuixa els límits del camp de joc.
//===================================================================================

void Taulell(HANDLE hScreen)
{
	int i;

	system("CLS");
	TextColor(LIGHTGREEN, BLACK, hScreen);
	GotoXY(INICI_X, INICI_Y, hScreen);


	for (i = INICI_X; i <= FI_X; i++)
	{
		TextColor(LIGHTGREEN, BLACK, hScreen);
		GotoXY(i, INICI_Y, hScreen);
		printf("%c", GESPA);
	}

	for (i = INICI_X; i <= FI_X; i++)
	{
		TextColor(LIGHTGREEN, BLACK, hScreen);
		GotoXY(i, INICI_Y + 1, hScreen);
		printf("%c", GESPA);
	}

	for (i = INICI_X; i <= FI_X; i++)
	{
		TextColor(LIGHTGREEN, BLACK, hScreen);
		GotoXY(i, INICI_Y + 2, hScreen);
		printf("%c", GESPA);
	}

	for (i = INICI_X; i <= FI_X; i++)
	{
		TextColor(LIGHTGREEN, BLACK, hScreen);
		GotoXY(i, FI_Y, hScreen);
		printf("%c", GESPA);
	}

	for (i = INICI_X; i <= FI_X; i++)
	{
		TextColor(LIGHTGREEN, BLACK, hScreen);
		GotoXY(i, FI_Y - 1, hScreen);
		printf("%c", GESPA);
	}

}

int Aleatori(int min, int max)
{
	int aux;

	aux = rand() % (max - min + 1) + min;

	return aux;
}

//===================================================================================
// NOM: Joc
//===================================================================================
// DESCRIPCIÓ: Funció el bucle principal d'execució del joc.
//===================================================================================

int Joc(int Nivell)
{
	HANDLE hScreen;
	int CarX, CarY, FrogX, FrogY, DirX, DirY, Impacte, Victoria, VelocitatJoc, ContCar, punts, Vides;
	char tecla = 0;

	srand((unsigned)time(NULL));

	hScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	InitScreen(hScreen);

	Taulell(hScreen);

	Vides = 3;                                                   // Vides inicials.
	punts = 0;                                                   // Punts inicials.

	InfoPuntsPartida(punts, hScreen);
	InfoVidesPartida(Vides, hScreen);
	InfoNivellPartida(Nivell, hScreen);

	CarX = INICI_X;												 // Coordenada del Car (Eix X).
	CarY = Aleatori(INICI_Y + 3, FI_Y - 2);                      // Coordenada del Car (Eix Y) [Definida per la funció Aleatori].
	FrogX = INICI_X + 16;                                        // Coordenada del Frogg (Eix X).
	FrogY = FI_Y;												 // Coordenada del Frogg (Eix Y).
	Impacte = 0;                                                 // Determina si ha hagut un impacte entre el Frogg o el Car.
	Victoria = 0;                                                // Determina si s'ha superat el nivell o no.
	VelocitatJoc = 1000;                                         // Velocitat inicial del joc.
	ContCar = VelocitatJoc / Nivell;                             // Determina la velocitat en funció del nivell de joc.

	PintarObj(CarX, CarY, CAR, BLUE, hScreen);
	PintarObj(FrogX, FrogY, FROG, WHITE, hScreen);

	do
	{
		do
		{
			if (_kbhit())
			{
				tecla = _getch();

				switch (tecla)
				{
				case TECLA_ESQUERRA:                                                // Desplaçar el Frogg una posició cap a la esquerra.
					DirX = -1;
					DirY = 0;
					MoureFrog(FrogX, FrogY, DirX, DirY, hScreen);
					break;

				case TECLA_DRETA:                                                   // Desplaçar el Frogg una posició cap a la dreta.
					DirX = 1;
					DirY = 0;
					MoureFrog(FrogX, FrogY, DirX, DirY, hScreen);
					break;

				case TECLA_ADALT:                                                   // Desplaçar el Frogg una posició cap a dalt.
					DirX = 0;
					DirY = -1;
					MoureFrog(FrogX, FrogY, DirX, DirY, hScreen);
					break;
				}
			}

			if (ContCar == 0)
			{
				MoureCar(CarX, CarY, hScreen);
				ContCar = VelocitatJoc / Nivell;
			}

			ContCar--;

			if (FrogY == INICI_Y + 2)
			{
				Victoria = 1;
			}

			if ((CarX == FrogX) && (CarY == FrogY))
			{
				Impacte = 1;
			}

		} while ((Impacte == 0) && (Victoria == 0) && (tecla != TECLA_ESC) && (Vides != 0));            // Sortim si hem impactat amb el Car, si hem superat el nivell, si teclejem la tecla ESC o si ens hem quedat sense vides.

		if (Victoria == 1)
		{
			punts = punts + (100 * Nivell);
			InfoPuntsPartida(punts, hScreen);

			Nivell++;
			InfoNivellPartida(Nivell, hScreen);

			NivellSuperat(hScreen);

			GotoXY(INICI_X, FI_Y + 2, hScreen);
			TextColor(WHITE, BLACK, hScreen);
			system("pause");
			system("CLS");

			Victoria = 0;
		}

		FrogX = INICI_X + 16;
		FrogY = FI_Y;
		
		Taulell(hScreen);

		InfoPuntsPartida(punts, hScreen);
		InfoVidesPartida(Vides, hScreen);
		InfoNivellPartida(Nivell, hScreen);

		PintarObj(CarX, CarY, CAR, BLUE, hScreen);
		PintarObj(INICI_X + 16, FI_Y, FROG, WHITE, hScreen);

		if (Impacte == 1)
		{
			Vides--;
			InfoVidesPartida(Vides, hScreen);
		}

		Impacte = 0;

	} while ((tecla != TECLA_ESC) && (Vides != 0) && (Nivell != 4));       // S'acaba el joc si ens hem quedat sense vides, si hem superat el nivell 3 i si s'ha pressionat la tecla ESC.

	if (Vides == 0)
	{
		GameOver(hScreen);

		GotoXY(INICI_X, FI_Y + 2, hScreen);
		TextColor(WHITE, BLACK, hScreen);
		system("pause");
	}

	return punts;
}

//===================================================================================
// NOM: PintarObjecte
//===================================================================================
// DESCRIPCIÓ: Pinta un objecte a la posicio x,y de la pantalla hScreen
// imprimeix simbol Obj, passat com parametre, en color "colorobj".
//===================================================================================

void PintarObj(int x, int y, char obj, int colorobj, HANDLE hScreen)
{
	TextColor(colorobj, BLACK, hScreen);
	GotoXY(x, y, hScreen);
	printf("%c", obj);
}

//===================================================================================
// NOM: EsborrarObjecte
//===================================================================================
// DESCRIPCIÓ: Esborra un objecte a la posicio x,y de la pantalla hScreen
// imprimeix simbol Obj, passat com parametre, en color BLACK.
//===================================================================================

void EsborrarObj(int x, int y, char obj, HANDLE hScreen)
{
	TextColor(BLACK, BLACK, hScreen);
	GotoXY(x, y, hScreen);
	printf("%c", obj);
}

//===================================================================================
// NOM: MoureFrog
//===================================================================================
// DESCRIPCIÓ: Mou el canó en l'eix X en la direcció DirX (1=dreta / -1=esquerra)
//             Retorna la nova coordenada X de la posició del Frogg.
//===================================================================================

void MoureFrog (int &FrogX, int &FrogY, int DirX, int DirY, HANDLE hScreen)
{
    if ((FrogY <= FI_Y) && (FrogY >= FI_Y - 1))
	{
		PintarObj(FrogX, FrogY, GESPA, LIGHTGREEN, hScreen);
	}
	else
	{
		EsborrarObj(FrogX, FrogY, FROG, hScreen);
	}

	if ((FrogX > INICI_X + 1) && (FrogX < FI_X))
	{
		FrogX = FrogX + DirX;
		FrogY = FrogY + DirY;
	}

	PintarObj(FrogX, FrogY, FROG, WHITE, hScreen);
}

//===================================================================================
// NOM: MoureCar
//===================================================================================
// DESCRIPCIÓ: Mou l'alien una posició i actualitza el valor de les seves coordenades.
//===================================================================================

void MoureCar(int &CarX, int &CarY, HANDLE hScreen)
{
	EsborrarObj(CarX, CarY, CAR, hScreen);

    CarX = CarX + 1;

	if (CarX == FI_X)
	{
		CarX = INICI_X;
		CarY = Aleatori(INICI_Y + 3, FI_Y - 2);
	}

	PintarObj(CarX, CarY, CAR, BLUE, hScreen);
}

