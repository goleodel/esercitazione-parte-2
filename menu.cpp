/*! \file CGrid.h
    \brief Declaration of the base class Griglia
	\author Iannone-Delfini
*/

#include "CShape.h"


#include <iostream>
#include <cmath>
#include <vector>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include  "CRightTriangle.h"
#include "menu.h"


#define MAX_SHAPES 100

using namespace std;

int menu()
{
    int scelta;

    cout << "\n===== MENU =====" << endl;
    cout << "1. Aggiungi elemento" << endl;
    cout << "2. Rimuovi elemento" << endl;
    cout << "3. Visualizza elementi" << endl;
    cout << "4. Salva dati" << endl;
    cout << "5. Carica dati" << endl;
    cout << "0. Esci" << endl;

    cout << "\nScelta: ";
    cin >> scelta;

    return scelta;
}

void creazioneGriglia(){
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;
}


void aggiungiElemento()
{
    int scelta;

    cout << "\n====== CHE ELEMENTO VUOI AGGIUNGERE ======" << endl;
    cout << "1. Triangolo" << endl;
    cout << "2. Rombo" << endl;
    cout << "3. Rettangolo" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    float x, y;
    float base, altezza;
    float diagonaleMaggiore, diagonaleMinore;
    int bordo;
    int scala;

    cout << "\nInserisci coordinata x: ";
    cin >> x;

    cout << "Inserisci coordinata y: ";
    cin >> y;

    if(scelta == 1)
    {
        cout << "Inserisci base: ";
        cin >> base;

        cout << "Inserisci altezza: ";
        cin >> altezza;

        shapes[nShapes++] = new RightTriangle(x, y, base, altezza, scala);
    }

    else if(scelta == 2)
    {
        cout << "Inserisci diagonale maggiore: ";
        cin >> diagonaleMaggiore;

        cout << "Inserisci diagonale minore: ";
        cin >> diagonaleMinore;

        shapes[nShapes++] = new Rhombus(x, y, diagonaleMaggiore, diagonaleMinore, scala);
    }

    else if(scelta == 3)
    {
        cout << "Inserisci base: ";
        cin >> base;

        cout << "Inserisci altezza: ";
        cin >> altezza;

        shapes[nShapes++] = new Rectangle(x, y, base, altezza, bordo, scala);
    }

    else
    {
        cout << "\nScelta non valida!" << endl;
    }
}



void rimuoviElemento(){
    int indice;

    if(nShapes == 0)
    {
        cout << "\nNessuna figura presente!" << endl;
        return;
    }

    cout << "\n===== FIGURE PRESENTI =====" << endl;

    for(int i = 0; i < nShapes; i++)
    {
        cout << i << ". ";
        shapes[i]->Dump();
        cout << endl;
    }

    cout << "\nQuale elemento vuoi rimuovere? ";
    cin >> indice;

    if(indice < 0 || indice >= nShapes)
    {
        cout << "\nIndice non valido!" << endl;
        return;
    }

    delete shapes[indice];

    for(int i = indice; i < nShapes - 1; i++)
    {
        shapes[i] = shapes[i + 1];
    }

    nShapes--;

    cout << "\nElemento rimosso correttamente!" << endl;
}


void visualizzaElementi();
void salvaDati();
void caricaDati();

