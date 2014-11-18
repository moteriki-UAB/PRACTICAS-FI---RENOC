#include "Menu.h"
#include "Joc.h"
#include "GestioResultats.h"

#define JUGAR '1'                // Definició de les tecles per cadascuna de les opcions del menú.
#define CONFIGURAR '2'           // Definició de les tecles per cadascuna de les opcions del menú.
#define PUNTUACIO '3'            // Definició de les tecles per cadascuna de les opcions del menú.
#define OPCIO_SORTIR '4'         // Definició de les tecles per cadascuna de les opcions del menú.

void main()
{
	char opcio;
	char nivell = '1';
	int punts = 0;
	int posicio = -1;

	TipusJugador TMillorsJugadors[MAX_MILLORSJUGADORS];

	InicialitzarTaulaMillorJugadors(TMillorsJugadors);

	do
	{

		system("CLS");
		MenuPrincipal();
		opcio = _getch();
		
		switch (opcio)
		{
		    case JUGAR: /* Crida a la funció que executa el joc amb el nivell actual. 
			             Quan s'acaba el joc comprova si la puntuació obtinguda és millor
			             que alguna de les guardades a la taula, i en aquest cas, l'afegeix
			             com a millor puntuació a la posició que toqui. */
				
				        punts = Joc(nivell - '0');
			            system("CLS");
				        posicio = EsMillorPuntuacio(TMillorsJugadors, punts);
				        if (posicio >= 0)
				        {
					        DesplacarArray(TMillorsJugadors, posicio);
					        EmplenarPosicioArray(TMillorsJugadors[posicio], punts);
				        }
			            break;

			case CONFIGURAR: do
				             {
				                 system("CLS");
					             MenuNivellDificultat();
			                     nivell = _getch();
					             if ((nivell < '1') || (nivell > '3'))
			                     {
					                 printf("\n\n");
					                 printf("OPCIO INCORRECTA. \n");
					                 Sleep(250);
			                     }
				             } while ((nivell != '1') && (nivell != '2') && (nivell != '3'));
				             break;

		    case PUNTUACIO: system("CLS");

				            EscriuRanking(TMillorsJugadors);
			                printf("Prem una tecla per tornar al menu principal.");
				            _getch();
				            break;

		    case OPCIO_SORTIR: exit(0);
			                   break;

		    default:  printf("\n\n AQUESTA OPCIO NO ES CORRECTA \n");
			          Sleep(250);
			          break;
		}

	}while(opcio!=SORTIR);
}
