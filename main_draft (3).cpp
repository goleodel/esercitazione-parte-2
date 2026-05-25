/*! \file main.cpp
    \brief testare le classi create
    \author Delfini-Iannone
*/

#include <iostream>
#include "Grid.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"

using namespace std;

/*!
    \brief Funzione principale del programma

    Gestisce il menu interattivo per:
    - visualizzare i poligoni
    - modificare figure
    - spostare figure
    - inserire nuove figure
    - eliminare figure
*/
int main()
{
    Grid grid;

    int scelta;

    do
    {
        cout << "\n===== SHAPE MANAGER =====" << endl;
        cout << "1. Visualizza tutti i poligoni" << endl;
        cout << "2. Visualizza dettaglio poligono" << endl;
        cout << "3. Modifica poligono" << endl;
        cout << "4. Sposta poligono" << endl;
        cout << "5. Inserisci nuovo poligono" << endl;
        cout << "6. Cancella poligono" << endl;
        cout << "7. Cancella tutti" << endl;
        cout << "0. Esci" << endl;
        cout << "Scelta: ";

        cin >> scelta;

        if(cin.fail())
        {
            cout << "Input non valido. Chiusura programma." << endl;
            return 0;
        }

        if (scelta == 1)
        {
            grid.PrintShapes();
        }
        else if (scelta == 2)
        {
            int i;

            cout << "Indice: ";
            cin >> i;

            if(cin.fail())
            {
                cout << "Input non valido. Chiusura programma." << endl;
                return 0;
            }

            grid.PrintShape(i);
        }
        else if (scelta == 3)
        {
            int i;
            float w, h;
            char text[50];

            cout << "Indice: ";
            cin >> i;

            if(cin.fail())
            {
                cout << "Input non valido. Chiusura programma." << endl;
                return 0;
            }

            cout << "Nuova larghezza: ";
            cin >> w;

            if(cin.fail())
            {
                cout << "Input non valido. Chiusura programma." << endl;
                return 0;
            }

            cout << "Nuova altezza: ";
            cin >> h;

            if(cin.fail())
            {
                cout << "Input non valido. Chiusura programma." << endl;
                return 0;
            }

            if(w <= 0 || h <= 0)
            {
                cout << "Dimensioni non valide" << endl;
                continue;
            }

            cout << "Testo: ";
            cin >> text;

            grid.EditShape(i, w, h, text,1);
        }
        else if (scelta == 4)
        {
            int i;
            float x, y;

            cout << "Indice: ";
            cin >> i;

            if(cin.fail())
            {
                cout << "Input non valido. Chiusura programma." << endl;
                return 0;
            }

            cout << "Nuova x: ";
            cin >> x;

            if(cin.fail())
            {
                cout << "Input non valido. Chiusura programma." << endl;
                return 0;
            }

            cout << "Nuova y: ";
            cin >> y;

            if(cin.fail())
            {
                cout << "Input non valido. Chiusura programma." << endl;
                return 0;
            }

            grid.MoveShape(i, x, y);
        }
        else if (scelta == 5)
        {
            int type;
            float x, y, w, h, sf;
            char text[50];

            cout << "Tipo (1 Rettangolo, 2 Rombo, 3 Triangolo): ";
            cin >> type;

            if(cin.fail())
            {
                cout << "Input non valido. Chiusura programma." << endl;
                return 0;
            }

            cout << "x y w h: ";
            cin >> x >> y >> w >> h;

            if(cin.fail())
            {
                cout << "Input non valido. Chiusura programma." << endl;
                return 0;
            }

            if(w <= 0 || h <= 0)
            {
                cout << "Dimensioni non valide" << endl;
                continue;
            }

            sf = 1;

            cout << "Testo: ";
            cin >> text;

            Shape* s = nullptr;

            if (type == 1)
                s = new Rectangle(x, y, w, h, sf);
            else if (type == 2)
                s = new Rhombus(x, y, w, h, sf);
            else if (type == 3)
                s = new RightTriangle(x, y, w, h, sf);
            else
            {
                cout << "Tipo non valido" << endl;
                continue;
            }

            s->SetText(text);
            grid.AddShape(s);
        }
        else if (scelta == 6)
        {
            int i;

            cout << "Indice: ";
            cin >> i;

            if(cin.fail())
            {
                cout << "Input non valido. Chiusura programma." << endl;
                return 0;
            }

            grid.DeleteShape(i);
        }
        else if (scelta == 7)
        {
            grid.DeleteAll();
        }
        else if (scelta == 0)
        {
            grid.DeleteAll();
        }

    } while (scelta != 0);

    return 0;
}


