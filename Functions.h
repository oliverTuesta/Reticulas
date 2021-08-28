#ifndef _FUNCIONS_H
#define _FUNCIONS_H

#include <iostream>
#include <map>

using namespace std;

class Functions
{
private:
    map<int, int> valores;
    int *arr;
    int n;
    bool **relacion;

    //producto cartesiano AxA
    map<int, pair<int, int>> productoCartesiano;

    void asignarValores();

public:
    Functions(/* args */);
    Functions(bool **, int *, int);
    ~Functions();
    void getProductoCartesiano();
    void showRelacion();
};

Functions::Functions(/* args */)
{
}

Functions::Functions(bool **relacion, int *arr, int n)
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
    relacion = new bool *[this->n];
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
    this->relacion[valores[productoCartesiano[5].first]][valores[productoCartesiano[5].second]] = 1;
    //el usuario seleciona el 7 producto cartesiano
    this->relacion[valores[productoCartesiano[7].first]][valores[productoCartesiano[7].second]] = 1;
    //el usuario seleciona el 10 producto cartesiano
    this->relacion[valores[productoCartesiano[10].first]][valores[productoCartesiano[10].second]] = 1;
    //el usuario seleciona el 11 producto cartesiano
    this->relacion[valores[productoCartesiano[11].first]][valores[productoCartesiano[11].second]] = 1;
    //el usuario seleciona el 25 producto cartesiano
    this->relacion[valores[productoCartesiano[16].first]][valores[productoCartesiano[16].second]] = 1;
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

void Functions::asignarValores()
{
    for (int i = 0; i < n; i++)
    {
        valores.insert(pair<int, int>(arr[i], i));
    }
}

#endif