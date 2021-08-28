#ifndef _FUNCIONS_H
#define _FUNCIONS_H

#include <iostream>

using namespace std;

class Functions
{
private:
public:
    Functions(/* args */);
    ~Functions();
    void getProductoCartesiano(bool **, int *, int);
    void showProducto(bool **, int *, int);
};

Functions::Functions(/* args */)
{
}

Functions::~Functions()
{
}

void Functions::getProductoCartesiano(bool **relacion, int *arr, int n)
{
    relacion = new bool *[n];
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        relacion[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            relacion[i][j] = 0;
            printf("%d:\t(%d;%d)\n", x, arr[i], arr[j]);
            x++;
        }
    }
    this->showProducto(relacion, arr, n);
}
void Functions::showProducto(bool **relacion, int *arr, int n)
{
    printf("\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", relacion[i][j]);
        }
        printf("\n");
    }
}

#endif