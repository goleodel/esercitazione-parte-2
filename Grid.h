/*! \file CGrid.h
    \brief Declaration of the class Grid
	\author Delfini-Iannone
*/


#ifndef GRID_H
#define GRID_H

#include "CShape.h"

#define MAX_SHAPES 10


 ///@brief Classe Grid: gestisce un insieme di Shape su una griglia logica 100x100
class Grid
{
private:
    Shape* shapes[MAX_SHAPES];   ///< array di puntatori a Shape
    int nShapes;                 ///< numero di shape presenti

    static const float SIZE;     ///< dimensione griglia (100x100)

   
     ///@brief verifica se una shape è contenuta nella griglia
     ///@param s puntatore alla shape da controllare
     ///@return true se è dentro la griglia, false altrimenti
    bool IsInside(Shape* s);

    
     ///@brief compatta l'array dopo una rimozione
     ///@param index posizione da cui shiftare
    void Shift(int index);

public:
    
     ///@brief costruttore
     
    Grid();

    
    ///@brief restituisce numero di shape
    
    int GetSize();

    
     ///@brief inserisce una nuova shape nella griglia
     ///@param s puntatore alla shape
    void AddShape(Shape* s);

    
     ///@brief elimina una shape dalla griglia
     ///@param index indice della shape
    void DeleteShape(int index);

    
     /// @brief elimina tutte le shape
    void DeleteAll();

    
     ///@brief sposta una shape nella griglia
     /// @param index indice shape
     /// @param x nuova posizione x
     /// @param y nuova posizione y
    void MoveShape(int index, float x, float y);

    
     ///@brief modifica dimensioni e testo di una shape
     ///@param index indice shape
     ///@param w nuova larghezza
     /// @param h nuova altezza
     ///@param text nuovo testo
    void EditShape(int index, float w, float h, const char* text,float sf);

    
     ///@brief stampa tutte le shape
    void PrintShapes();

    
     ///@brief stampa dettaglio di una shape
     ///@param index indice shape
    void PrintShape(int index);
};

#endif