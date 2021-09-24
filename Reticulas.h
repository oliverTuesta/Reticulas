#ifndef _FUNCIONS_H
#define _FUNCIONS_H

#include <iostream>
#include <map>

using namespace std;

class Reticulas
{
private:
    //Valores de R
    map<int, int> valores;
    int *arr;
    int n;
    bool **relacion;
    bool **nuevaRelacion; // relacion sin diagonal y elevada al cuadrado

    //producto cartesiano AxA
    map<int, pair<int, int>> productoCartesiano;

    void asignarValores();
    void ingresarR();

    bool esReflexiva();
    bool esAntisimetrica();
    bool esTransitiva();

    void swap(int *, int *);
    void Ordenamiento(int *, int);

    void crearNueavaRelacion();

public:
    Reticulas(/* args */);
    Reticulas(bool **, int *, int);
    ~Reticulas();
    void getProductoCartesiano();
    void showRelacion(bool **);
    bool esOrdenParcial();
    void mostrarConjunto();
};

Reticulas::Reticulas(/* args */)
{
}

Reticulas::Reticulas(bool **relacion, int *arr, int n)
{
    this->relacion = relacion;
    this->Ordenamiento(arr, n);
    this->arr = arr;
    this->n = n;
    this->asignarValores();
}

Reticulas::~Reticulas()
{
}

void Reticulas::getProductoCartesiano()
{
    relacion = new bool *[this->n];
    int x = 1;
    cout << "\n\t\tProducto cartesiano AxA: \n";
    for (int i = 0; i < this->n; i++)
    {
        this->relacion[i] = new bool[n];
        for (int j = 0; j < this->n; j++)
        {
            this->relacion[i][j] = 0;
            this->productoCartesiano.insert(pair<int, pair<int, int>>(x, pair<int, int>(arr[i], arr[j])));
            if (n == 10)
                printf("[%03d]: ", x);
            else
                printf("[%02d]: ", x);
            printf("(%d;%d)\t", this->productoCartesiano[x].first, this->productoCartesiano[x].second);
            x++;
            if ((x - 1) % 5 == 0)
                printf("\n");
        }
    }

    printf("\n\n");
    this->ingresarR();
    this->showRelacion(relacion);
    crearNueavaRelacion();
}
void Reticulas::showRelacion(bool **relacion)
{
    // Numeros de referencia superiores
    printf("\n\t");
    for (int i = 0; i < n; i++)
    {
        printf("%02d\t", arr[i]);
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
        printf("%02d|\t", arr[i]);
        //fin de numeroes de referencia
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", relacion[i][j]);
        }
        printf("\n  |\n");
    }
}

void Reticulas::asignarValores()
{
    for (int i = 0; i < n; i++)
    {
        valores.insert(pair<int, int>(arr[i], i));
    }
}

void Reticulas::ingresarR()
{
    printf("Ingrese la relacion R sobre AxA, cuando termine digite CONFIRMAR para terminar el proceso: \n");
    int nCuadrado = n * n;
    int num, i = 0;
    while (cin >> num && i < nCuadrado)
    {
        if (num < 1 || num > nCuadrado || this->relacion[valores[productoCartesiano[num].first]][valores[productoCartesiano[num].second]])
            printf("Ingrese otro valor\n");
        else
            relacion[valores[productoCartesiano[num].first]][valores[productoCartesiano[num].second]] = 1;
        i++;
    }
}
bool Reticulas::esReflexiva()
{
    for (int i = 0; i < this->n; i++)
    {
        if (!relacion[i][i])
            return false;
    }
    return true;
}

bool Reticulas::esAntisimetrica()
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

bool Reticulas::esTransitiva()
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

bool Reticulas::esOrdenParcial()
{
    bool reflex = this->esReflexiva();
    bool antisime = this->esAntisimetrica();
    bool trans = this->esTransitiva();
    cout << "Reflexiva: " << reflex << endl;
    cout << "Antisimetrica: " << antisime << endl;
    cout << "Transitiva: " << trans << endl;
    cout << reflex << antisime << trans << endl;
    if (reflex && antisime && trans)
    {
        cout << "Es de Orden Parcial" << endl;
    }
    else
    {
        cout << "No es de Orden Parcial" << endl;
    }
    return reflex && antisime && trans;
}

//Selection Sort
void Reticulas::swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Reticulas::Ordenamiento(int *arr, int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        this->swap(&arr[min_idx], &arr[i]);
    }
}
//Fin de selection sort

void Reticulas::mostrarConjunto()
{
    printf("\nA = {");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i + 1 < n)
            printf("; ");
    }
    printf("}\n");
}

void Reticulas::crearNueavaRelacion()
{

    bool **aux = new bool *[n];

    for (int i = 0; i < n; i++)
    {
        aux[i] = new bool[n];
        for (int j = 0; j < this->n; j++)
        {
            aux[i][j] = 0;
        }
    }

    //eliminando diagonal
    nuevaRelacion = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        nuevaRelacion[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                nuevaRelacion[i][j] = relacion[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int z = 0; z < n; z++)
            {
                if (nuevaRelacion[i][z] && nuevaRelacion[z][j])
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
            if (nuevaRelacion[i][j] && aux[i][j])
            {
                nuevaRelacion[i][j] = 0;
            }
        }
    }

    showRelacion(aux);
    showRelacion(nuevaRelacion);
}

#endif
