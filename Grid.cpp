/*! \file CShape.cpp
    \brief implementation of class Grid
	\author Delfini-Iannone
*/

#include "Grid.h"
#include <iostream>

using namespace std;

/// @brief dimensione della griglia 100x100
const float Grid::SIZE = 100.0f;


///@brief costruttore: inizializza struttura dati
Grid::Grid()
{
    nShapes = 0;
    for (int i = 0; i < MAX_SHAPES; i++)
        shapes[i] = nullptr;
}


///@brief restituisce numero di shape presenti
int Grid::GetSize()
{
    return nShapes;
}


///@brief verifica se una shape è dentro la griglia 100x100
bool Grid::IsInside(Shape* s)
{
    float x = s->GetX();
    float y = s->GetY();
    float w = s->GetWidth();
    float h = s->GetHeight();

    return (x >= 0 && y >= 0 &&
            x + w <= SIZE &&
            y + h <= SIZE);
}


///@brief inserisce una shape nella griglia
void Grid::AddShape(Shape* s)
{
    if (nShapes >= MAX_SHAPES)
    {
        cout << "Griglia piena!" << endl;
        delete s;
        return;
    }

    if (!IsInside(s))
    {
        cout << "Figura fuori dalla griglia 100x100!" << endl;
        delete s;
        return;
    }

    shapes[nShapes++] = s;
}


///@brief compatta array dopo cancellazione
void Grid::Shift(int index)
{
    for (int i = index; i < nShapes - 1; i++)
        shapes[i] = shapes[i + 1];

    nShapes--;
}


///@brief elimina una shape
void Grid::DeleteShape(int index)
{
    if (index < 0 || index >= nShapes)
    {
        cout << "Indice non valido!" << endl;
        return;
    }

    delete shapes[index];
    Shift(index);
}


 ///@brief elimina tutte le shape
void Grid::DeleteAll()
{
    for (int i = 0; i < nShapes; i++)
        delete shapes[i];

    nShapes = 0;
}


///@brief sposta una shape nella griglia
void Grid::MoveShape(int index, float x, float y)
{
    if (index < 0 || index >= nShapes)
    {
        cout << "Indice non valido!" << endl;
        return;
    }

    Shape* s = shapes[index];

    float oldX = s->GetX();
    float oldY = s->GetY();

    s->SetPosition(x, y);

    if (!IsInside(s))
    {
        cout << "Spostamento non valido!" << endl;
        s->SetPosition(oldX, oldY);
    }
}


///@brief modifica shape (dimensioni + testo)
void Grid::EditShape(int index, float w, float h, const char* text, float sf)
{
    if (index < 0 || index >= nShapes)
    {
        cout << "Indice non valido!" << endl;
        return;
    }

    Shape* s = shapes[index];

    float oldW = s->GetWidth();
    float oldH = s->GetHeight();

    s->SetDim(w, h);
    s->SetText(text);

    if (!IsInside(s))
    {
        cout << "Modifica non valida (fuori griglia)!" << endl;
        s->SetDim(oldW, oldH);
    }
}


///@brief stampa tutte le shape

void Grid::PrintShapes()
{
    for (int i = 0; i < nShapes; i++)
    {
        cout << "\n[" << i << "]" << endl;
        shapes[i]->Dump();
    }
}


///@brief stampa dettaglio di una shape

void Grid::PrintShape(int index)
{
    if (index < 0 || index >= nShapes)
    {
        cout << "Indice non valido!" << endl;
        return;
    }

    shapes[index]->Dump();
}