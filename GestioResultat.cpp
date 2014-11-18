#include "GestioResultats.h"

//===================================================================================
// NOM: InicialitzarTaulaMillorJugadors
//===================================================================================
// DESCRIPCIÓ: Inicialitza la taula que guarda les millors puntuacions amb totes les
// puntuacions a 0.
//===================================================================================

void InicialitzarTaulaMillorJugadors(TipusJugador TMillorsJugadors[])
{
	int i;

	for (i = 0; i < MAX_MILLORSJUGADORS; i++)
	{
		strcpy(TMillorsJugadors[i].Nom, "---------------");
		TMillorsJugadors[i].puntuacio = 0;
	}
}

//===================================================================================
// NOM: EsMillorPuntuacio
//===================================================================================
// DESCRIPCIÓ: Mira si la puntuació que es passa a "punts" és millor que alguna de les
// que hi ha guardada a la taula de millors puntuacions. Si és millor, retorna l'índex
// de la primera posició de la taula que s'ha trobat amb una puntuació inferior. Si no 
// en troba cap d'inferior retorna un -1.
//===================================================================================

int EsMillorPuntuacio(TipusJugador TMillorsJugadors[], int punts)
{
	int i = 0;
	int trobat = 0;

	do
	{
		if (TMillorsJugadors[i].puntuacio < punts)
		{
			trobat = 1;
		}
		i++;

	} while ((i < MAX_MILLORSJUGADORS) && (!trobat));

	if (trobat)
	{
		return (i - 1);
	}
	else
	{
		return -1;
	}
}

//===================================================================================
// NOM: DesplacarArray
//===================================================================================
// DESCRIPCIÓ: Mou tots els registres de la taula a partir de "posicio" una posicio a
// la dreta per deixar lloc a un nou registre de puntuacions.
//===================================================================================

void DesplacarArray(TipusJugador TMillorsJugadors[], int posicio)
{
	int i;

	for (i = MAX_MILLORSJUGADORS - 1; i > posicio; i--)
	{
		strcpy(TMillorsJugadors[i].Nom, TMillorsJugadors[i - 1].Nom);
		TMillorsJugadors[i].puntuacio = TMillorsJugadors[i - 1].puntuacio;
	}
}

//===================================================================================
// NOM: EmplenarPosicioArray
//===================================================================================
// DESCRIPCIÓ: omple un registre de puntuacions ("jugador") amb els punts que es passen
// com a paràmetre i el nom que s'introdueix per teclat.
//===================================================================================

void EmplenarPosicioArray(TipusJugador &TMillorsJugadors, int punts)
{
	system("CLS");

	printf("Entra el teu nom\n");
	scanf_s("%15s", &(TMillorsJugadors.Nom));
	fflush(stdin);
	(TMillorsJugadors).puntuacio = punts;
}

//===================================================================================
// NOM: EscriuRanking
//===================================================================================
// DESCRIPCIÓ: mostra per pantalla les millors puntuacions.
//===================================================================================

void EscriuRanking(TipusJugador TMillorsJugadors[])
{
	int i;

	HANDLE hScreen;

	hScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	InitScreen(hScreen);

	TextColor(LIGHTCYAN, BLACK, hScreen);

	printf("---------- Millors Puntuacions ---------- \n\n");

	for (i = 0; i < MAX_MILLORSJUGADORS; i++)
	{
		printf("|   %d. - %s        %d\n\n", i+1, TMillorsJugadors[i].Nom, TMillorsJugadors[i].puntuacio);
	}

	printf("----------------------------------------- \n\n");
}
