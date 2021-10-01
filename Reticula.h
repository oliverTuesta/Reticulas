#ifndef _RETICULA_H_
#define _RETICULA_H_

#include <vector>
#include <iostream>
using namespace std;

class Reticula
{
private:
    bool **relacion;
    bool **relacionSimplificada;
    int n;
    vector<vector<int>> complementosVertices;

    int maxima, minima;

    void agregarComplemento(int a, int b);
    bool tieneMaximaCotaInferior(int a, int b, int &maximaCotInf);
    bool tieneMinimaCotaSuperior(int a, int b, int &mminimaCotSup);
    void determinaMaximaYMinima();
    void determinarRelacionSimplificada();

public:
    Reticula();
    Reticula(bool **, int);
    ~Reticula();

    bool esReticula();
    vector<vector<int>> getComplementos();
};

Reticula::Reticula()
{
}

Reticula::Reticula(bool **relacion, int n)
{
    this->relacion = relacion;
    this->n = n;
}

Reticula::~Reticula()
{
}

bool Reticula::esReticula()
{
    int maximaCotaInf = 0;
    int minimaCotaSup = 0;
    determinarRelacionSimplificada();
    determinaMaximaYMinima();
    bool todosTienenMaximaYMinima = true;

    //inisializar complementos
    for (int i = 0; i < n; i++)
    {
        vector<int> nuevoVector;
        complementosVertices.push_back(nuevoVector);
    }

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            maximaCotaInf = 0;
            minimaCotaSup = 0;

            if (!tieneMaximaCotaInferior(i, j, maximaCotaInf) || !tieneMinimaCotaSuperior(i, j, minimaCotaSup))
            {
                todosTienenMaximaYMinima = false;
            }
            else
            {

                if (maximaCotaInf == minima && minimaCotaSup == maxima)
                {
                    agregarComplemento(i, j);
                }
            }
        }
    }
    if (todosTienenMaximaYMinima)
    {
    }

    return todosTienenMaximaYMinima;
}

void Reticula::agregarComplemento(int a, int b)
{
    complementosVertices[a].push_back(b);
    complementosVertices[b].push_back(a);
}

vector<vector<int>> Reticula::getComplementos() { return complementosVertices; }

bool Reticula::tieneMaximaCotaInferior(int a, int b, int &maximaCotInf)
{

    if (relacionSimplificada[a][b] || relacionSimplificada[b][a])
    {
        if (relacionSimplificada[a][b])
            maximaCotInf = a;
        else
            maximaCotInf = b;
        return true;
    }

    bool tieneMin = false;
    vector<int> cotasInferiores;

    for (int i = 0; i < n; i++)
    {
        if (relacion[i][a] && relacion[i][b])
        {
            cotasInferiores.push_back(i);
        }
    }
    if (cotasInferiores.size() == 1)
    {
        tieneMin = true;
        maximaCotInf = cotasInferiores[0];
    }
    else
    {
        int esMinima = false;
        for (int i = 0; i < cotasInferiores.size(); i++)
        {
            for (int j = 0; j < cotasInferiores.size(); j++)
            {
                if (!relacion[cotasInferiores[j]][cotasInferiores[i]])
                {
                    break;
                }
                if (j == cotasInferiores.size() - 1)
                {
                    maximaCotInf = cotasInferiores[i];
                    esMinima = true;
                }
            }
            if (esMinima)
            {
                tieneMin = true;
                break;
            }
        }
    }
    return tieneMin;
}

bool Reticula::tieneMinimaCotaSuperior(int a, int b, int &minimaCotaSup)
{

    if (relacionSimplificada[a][b] || relacionSimplificada[b][a])
    {
        if (relacionSimplificada[a][b])
            minimaCotaSup = b;
        else
            minimaCotaSup = a;
        return true;
    }

    bool tieneMax = false;
    vector<int> cotasSuperiores;
    for (int i = 0; i < n; i++)
    {
        if (relacion[a][i] == true && relacion[b][i] == true)
        {
            cotasSuperiores.push_back(i);
        }
    }
    if (cotasSuperiores.size() == 1)
    {
        tieneMax = true;
        minimaCotaSup = cotasSuperiores[0];
    }
    else
    {
        int esMaximo = false;
        for (int i = 0; i < cotasSuperiores.size(); i++)
        {
            for (int j = 0; j < cotasSuperiores.size(); j++)
            {
                if (!relacion[cotasSuperiores[i]][cotasSuperiores[j]])
                {
                    break;
                }

                if (j == cotasSuperiores.size() - 1)
                {
                    esMaximo = true;
                }
            }
            if (esMaximo)
            {
                minimaCotaSup = cotasSuperiores[i];

                tieneMax = true;
                break;
            }
        }
    }
    return tieneMax;
}

void Reticula::determinaMaximaYMinima()
{

    int cont1 = 0;
    int cont2 = 0;
    for (int i = 0; i < n; i++)
    {
        cont1 = 0;
        cont2 = 0;
        for (int j = 0; j < n; j++)
        {
            cont1 += !relacionSimplificada[i][j];

            cont2 += !relacionSimplificada[j][i];
        }
        if (cont1 == n)
            maxima = i;

        if (cont2 == n)
            minima = i;
    }
}

void Reticula::determinarRelacionSimplificada()
{
    bool **aux = new bool *[n];

    for (int i = 0; i < n; i++)
    {
        aux[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            aux[i][j] = 0;
        }
    }

    //eliminando diagonal
    relacionSimplificada = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        relacionSimplificada[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                relacionSimplificada[i][j] = relacion[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int z = 0; z < n; z++)
            {
                if (relacionSimplificada[i][z] && relacionSimplificada[z][j])
                {
                    aux[i][j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (relacionSimplificada[i][j] && aux[i][j])
            {
                relacionSimplificada[i][j] = 0;
            }
        }
    }
}

#endif