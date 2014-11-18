#include "Graphics_Console.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define INICI_X 4               // Inici del taulell respecte la cantonada superior esquerre.
#define INICI_Y 6               // Inici del taulell respecte la cantonada superior esquerre.

#define FI_X 36                 // Fi del taulell respecte la cantonada superior esquerre.
#define FI_Y 26                 // Fi del taulell respecte la cantonada superior esquerre.

#define GESPA 177               // Codi Color.
#define RED 4                   // Codi Color.
#define CAR 219                 // Codi Car. 
#define FROG 153                // Codi Frog. 
#define SORTIR 4                // Codi Tecla.
#define TECLA_ESC 27            // Codi Tecla.
#define TECLA_DRETA 77          // Codi Tecla.
#define TECLA_ESQUERRA 75       // Codi Tecla.
#define TECLA_ADALT 72          // Codi Tecla.

int Joc(int Nivell);
void Taulell(HANDLE hScreen);
void InfoPuntsPartida(int Punts, HANDLE hScreen);
void InfoVidesPartida(int Vides, HANDLE hScreen);
void InfoNivellPartida(int Nivell, HANDLE hScreen);
void GameOver(HANDLE hScreen);
void NivellSuperat(HANDLE hScreen);
void PintarObj();
void MenuNivellDificultat();

void PintarObj(int X, int Y, char obj, int ColorObj, HANDLE hScreen);
void EsborrarObj(int X, int Y, char obj, HANDLE hScreen);
void MoureFrog(int &FrogX, int &FrogY, int DirX, int DirY, HANDLE hScreen);
void MoureCar(int &CarX, int &CarY, HANDLE hScreen);
void Impacte();
void Victoria();
int Aleatori(int min, int max);
