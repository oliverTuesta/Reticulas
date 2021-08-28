#ifndef _FUNCIONS_H
#define _FUNCIONS_H

#include <iostream>
#include <map>

using namespace std;

class Functions
{
private:
    map<int, int> valores;
    int* arr;
    int n;
    bool** relacion;

    //producto cartesiano AxA
    map<int, pair<int, int>> productoCartesiano;

    void asignarValores();
    bool reflex;
    bool antisime;
    bool trans;
public:
    Functions(/* args */);
    Functions(bool**, int*, int);
    ~Functions();
    void getProductoCartesiano();
    void showRelacion();
    void antisimetrica();
    void reflexiva();
    void transitiva();
    void ordenParcial();
};

Functions::Functions(/* args */)
{
}

Functions::Functions(bool** relacion, int* arr, int n)
{
    this->relacion = relacion;
    this->arr = arr;
    this->n = n;
    this->asignarValores();
}

Functions::~Functions()
{
}

void Functions::getProductoCartesiano()
{
    relacion = new bool* [this->n];
    int x = 1;
    for (int i = 0; i < this->n; i++)
    {
        this->relacion[i] = new bool[n];
        for (int j = 0; j < this->n; j++)
        {
            this->relacion[i][j] = 0;
            this->productoCartesiano.insert(pair<int, pair<int, int>>(x, pair<int, int>(arr[i], arr[j])));
            printf("%d:\t(%d;%d)\n", x, this->productoCartesiano[x].first, this->productoCartesiano[x].second);
            x++;
        }
    }

    //ejemplo de que el usuario forma el conjunto R;
    //el usuario seleciona el 5 producto cartesiano
    this->relacion[valores[productoCartesiano[1].first]][valores[productoCartesiano[1].second]] = 1;
    //el usuario seleciona el 7 producto cartesiano
    this->relacion[valores[productoCartesiano[3].first]][valores[productoCartesiano[3].second]] = 1;
    //el usuario seleciona el 10 producto cartesiano
    this->relacion[valores[productoCartesiano[5].first]][valores[productoCartesiano[5].second]] = 1;
    //el usuario seleciona el 11 producto cartesiano
    this->relacion[valores[productoCartesiano[7].first]][valores[productoCartesiano[7].second]] = 1;
    this->relacion[valores[productoCartesiano[8].first]][valores[productoCartesiano[8].second]] = 1;
    this->relacion[valores[productoCartesiano[9].first]][valores[productoCartesiano[9].second]] = 1;
    this->relacion[valores[productoCartesiano[10].first]][valores[productoCartesiano[10].second]] = 1;
    this->relacion[valores[productoCartesiano[13].first]][valores[productoCartesiano[13].second]] = 1;
    this->relacion[valores[productoCartesiano[15].first]][valores[productoCartesiano[15].second]] = 1;
    this->relacion[valores[productoCartesiano[19].first]][valores[productoCartesiano[19].second]] = 1;
    this->relacion[valores[productoCartesiano[25].first]][valores[productoCartesiano[25].second]] = 1;
    this->showRelacion();
}
void Functions::showRelacion()
{
    // Numeros de referencia superiores
    printf("\t");
    for (int i = 0; i < this->n; i++)
    {
        printf("%d\t", this->arr[i]);
    }
    printf("\n");
    //fin de numeros de referencia

    for (int i = 0; i < this->n; i++)
    {
        //numeros de referencia lateral izquierad
        printf("%d\t", this->arr[i]);
        //fin de numeroes de referencia
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", this->relacion[i][j]);
        }
        printf("\n");
    }
}

void Functions::reflexiva()
{
    this->reflex = true;
    for (int i = 0; i < this->n; i++)
    {
        if (relacion[i][i] == 0) {
            reflex = false;
            return;
        }
    }
}
void Functions::antisimetrica()
{
    this->antisime = true;
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && relacion[i][j] == 1 && relacion[j][i] == 1) {
                antisime = false;
                return;
            }
        }
    }
}
void Functions::transitiva()
{
    this->trans = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (relacion[i][j] == 1 && i != j)
            {
                for (int k = 0; k < n; k++)
                {
                    if (relacion[j][k] == 1 && relacion[i][k] == 1) {
                        trans = true;
                    }
                    if (relacion[j][k] == 1 && relacion[i][k] == 0) {
                        trans = false;
                        return;
                    }
                }
            }
        }
    }
}
void Functions::ordenParcial()
{
    cout << "Reflexiva: " <<reflex << endl;
    cout << "AntiSimetrica: " <<antisime << endl;
    cout << "Transitiva: " <<trans<< endl;
    cout << reflex << antisime << trans << endl;
    if (reflex == true && antisime == true && trans== true) {
        cout << "Es de Orden Parcial" << endl;
    }
    else {
        cout << "No es de Orden Parcial" << endl;
    }
}
void Functions::asignarValores()
{
    for (int i = 0; i < n; i++)
    {
        valores.insert(pair<int, int>(arr[i], i));
    }
}

#endif
