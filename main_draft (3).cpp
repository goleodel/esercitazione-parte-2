/*! \file main_draft.cpp
    \brief testare le classi create
	\author Delfini-Iannone
*/

#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"
#include "menu.h"

using namespace std;

#define MAX_SHAPES 10


/// @brief per verificare il corretto funzionamento del programma 
int main()
{
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    cout << "===== TEST GERARCHIA SHAPE =====" << endl;

    /// 1. Creazione figure (l'ultimo numero è la scala(vengono create al 100% cioè sf=1))
    shapes[nShapes++] = new Rectangle(0, 0, 10, 5, 1);
    shapes[nShapes++] = new Rhombus(2, 2, 10, 6, 1);
    shapes[nShapes++] = new RightTriangle (6, 8, 3, 5, 1);


    /// 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");
    shapes[2]->SetText("Triangolo");



    /// 3. Dump polimorfico
    cout << endl << "===== DUMP POLIMORFICO =====" << endl;
    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }


    /// 4. test della funzione Scale
    cout << endl << "===== SCALA LA FIGURA =====" << endl;
    for (int i = 0; i < nShapes; i++) {
        shapes[i]-> Scale(0.5);
    }

    /// 5. Dump con scala
    cout << endl << "===== DUMP SCALATO =====" << endl;
    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }



    /// 6. distruzione delle classi
    cout << endl << "===== FINE TEST =====" << endl;
    for (int i = 0; i < nShapes; i++) {
        delete shapes[i];
    }
    return 0;

}


    int scelta;

    do
    {
        scelta = menu();

        switch(scelta)
        {
            case 1:
                aggiungiElemento();
                break;

            case 2:
                rimuoviElemento();
                break;

            case 3:
                visualizzaElementi();
                break;

            case 4:
                salvaDati();
                break;

            case 5:
                caricaDati();
                break;

            case 0:
                cout << "\nUscita dal programma..." << endl;
                break;

            default:
                cout << "\nScelta non valida!" << endl;
        }

    } while(scelta != 0);

    return 0;


    



