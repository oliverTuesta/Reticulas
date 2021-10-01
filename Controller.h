#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "OrdenParcial.h"
#include "Reticula.h"
#include <iostream>
#include <map>

class Controller
{
private:
    bool **relacion;
    int n;
    OrdenParcial *ordenParcial;
    Reticula *reticula;
    int *conjunto;
    map<int, pair<int, int>> pares;

    void generarProductoCartesiano();
    void ordenarConjunto();
    void mostrarConjunto();
    void mostrarComplementos(Reticula *reticula);

public:
    Controller();
    ~Controller();

    void mostrarResultados();
    void ingresarRelacion();
    void ingresarConjunto();
    void mostrarMatriz();
};

Controller::Controller()
{
    ingresarConjunto();
    ordenarConjunto();
    mostrarConjunto();
    ingresarRelacion();
    mostrarResultados();
}

Controller::~Controller()
{
}

void Controller::mostrarResultados()
{
    ordenParcial = new OrdenParcial(relacion, n);

    printf("\n\t*****RESULTADOS*****\n");
    mostrarMatriz();
    ordenParcial->mostrarResultados();
    printf("Orden parcial: ");
    if (ordenParcial->esOrdenParcial())
    {
        printf("SI\n");
        reticula = new Reticula(relacion, n);
        printf("\nReticula: ");
        if (reticula->esReticula())
        {
            printf("SI\n");
            mostrarComplementos(reticula);
        }
        else
            printf("NO\n");
    }
    else
    {
        printf("NO\n");
    }
}

void Controller::ingresarRelacion()
{
    generarProductoCartesiano();
    printf("Ingrese la relacion R sobre AxA, cuando termine digite CONFIRMAR para terminar el proceso: \n");
    int nCuadrado = n * n;
    int num, i = 0;
    while (cin >> num && i < nCuadrado)
    {
        printf("\npar (%d %d)\n", pares[num].first, pares[num].second);
        relacion[pares[num].first][pares[num].second] = true;
        i++;
    }
}

void Controller::generarProductoCartesiano()
{
    relacion = new bool *[n];
    int x = 1;
    cout << "\n\t\tProducto cartesiano AxA: \n";
    for (int i = 0; i < n; i++)
    {
        relacion[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            relacion[i][j] = 0;
            pares.insert(pair<int, pair<int, int>>(x, pair<int, int>(i, j)));
            if (n == 10)
                printf("[%03d]: ", x);
            else
                printf("[%02d]: ", x);
            printf("(%d;%d)\t", conjunto[pares[x].first], conjunto[pares[x].second]);
            x++;
            if ((x - 1) % 5 == 0)
                printf("\n");
        }
    }
}

void Controller::ingresarConjunto()
{
    do
    {
        cout << "Escriba la cantidad de elementos del conjunto A (4 a 10): ";
        cin >> n;
    } while (n < 3 || n > 10);

    conjunto = new int[n];

    bool existe;
    for (int i = 0; i < n; i++)
    {
        do
        {
            existe = false;
            printf("A[%02d]: ", i + 1);
            cin >> conjunto[i];

            for (int j = 0; j < i; j++)
            {
                if (conjunto[i] == conjunto[j])
                    existe = true;
            }

        } while (conjunto[i] < -99 || conjunto[i] > 99 || existe);
    }
}

void Controller::mostrarConjunto()
{
    printf("\nA = {");
    for (int i = 0; i < n; i++)
    {
        printf("%d", conjunto[i]);
        if (i + 1 < n)
            printf("; ");
    }
    printf("}\n");
}

void Controller::ordenarConjunto()
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (conjunto[j] < conjunto[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        int temp = conjunto[min_idx];
        conjunto[min_idx] = conjunto[i];
        conjunto[i] = temp;
    }
}
//Fin de selection sort

void Controller::mostrarMatriz()
{
    // Numeros de referencia superiores
    printf("\n\t");
    for (int i = 0; i < n; i++)
    {
        printf("%02d\t", conjunto[i]);
    }
    printf("\n");
    for (int i = 0; i < n * 2; i++)
    {
        printf("_____");
    }
    printf("\n\n");
    //fin de numeros de referencia

    for (int i = 0; i < n; i++)
    {
        //numeros de referencia lateral izquierad
        printf("%02d|\t", conjunto[i]);
        //fin de numeroes de referencia
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", relacion[i][j]);
        }
        printf("\n  |\n");
    }
}

void Controller::mostrarComplementos(Reticula *reticula)
{

    printf("\nComplementos de cada vertice:\n");

    vector<vector<int>> complementosVertices = reticula->getComplementos();

    for (int i = 0; i < n; i++)
    {
        printf("[%02d]: ", conjunto[i]);
        if (complementosVertices[i].size() == 0)
        {
            printf("No tiene complementos");
        }

        for (int j = 0; j < complementosVertices[i].size(); j++)
        {
            printf("%d ", conjunto[complementosVertices[i][j]]);
        }
        printf("\n");
    }
}

#endif