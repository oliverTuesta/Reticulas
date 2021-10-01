#ifndef _ORDEN_PARCIAL_H_
#define _ORDEN_PARCIAL_H_

#include <iostream>

class OrdenParcial
{
private:
    bool **relacion;
    int n;
    bool esReflexiva();
    bool esTransitiva();
    bool esAntisimetrica();

public:
    OrdenParcial();
    OrdenParcial(bool **, int);

    ~OrdenParcial();

    bool esOrdenParcial();
    void mostrarResultados();
};

OrdenParcial::OrdenParcial()
{
}

OrdenParcial::OrdenParcial(bool **relacion, int n)
{
    this->relacion = relacion;
    this->n = n;
}

OrdenParcial::~OrdenParcial()
{
}

bool OrdenParcial::esOrdenParcial()
{
    return esReflexiva() && esAntisimetrica() && esTransitiva();
}

bool OrdenParcial::esReflexiva()
{

    for (int i = 0; i < n; i++)
    {
        if (!relacion[i][i])
            return false;
    }
    return true;
}

bool OrdenParcial::esAntisimetrica()
{
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && relacion[i][j] && relacion[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

bool OrdenParcial::esTransitiva()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && relacion[i][j])
            {
                bool tieneRelacion = false;
                for (int x = 0; x < n; x++)
                {

                    if (relacion[j][x])
                    {
                        tieneRelacion = true;
                        if (!relacion[i][x])
                            return false;
                    }
                    if (x == n - 1 && !tieneRelacion)
                        return false;
                }
            }
        }
    }
    return true;
}

void OrdenParcial::mostrarResultados()
{
    printf("\nReflexiva: ");
    if (esReflexiva())
        printf("SI\n");
    else
        printf("NO\n");

    printf("Antisimetrica: ");
    if (esAntisimetrica())
        printf("SI\n");
    else
        printf("NO\n");

    printf("Transitiva: ");
    if (esTransitiva())
        printf("SI\n");
    else
        printf("NO\n");
}

#endif