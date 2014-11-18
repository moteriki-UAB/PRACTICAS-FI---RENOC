#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Graphics_Console.h"

#define MAX_NOM_JUGADOR 15
#define MAX_MILLORSJUGADORS 5

// Registre que serveix per guardar la puntuació d'un jugador.

typedef struct
{
	char Nom[MAX_NOM_JUGADOR];
	int puntuacio;
}TipusJugador;

void InicialitzarTaulaMillorJugadors(TipusJugador TMillorsJugadors[]);
void DesplacarArray(TipusJugador TMillorsJugadors[], int posicio);
void EmplenarPosicioArray(TipusJugador &TMillorsJugadors, int punts);
void EscriuRanking(TipusJugador TMillorsJugadors[]);
int EsMillorPuntuacio(TipusJugador TMillorsJugadors[], int punts);
