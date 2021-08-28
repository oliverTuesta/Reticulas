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
    void ingresarR();

    bool esReflexiva();
    bool esAntisimetrica();
    bool esTransitiva();

public:
    Functions(/* args */);
    Functions(bool **, int *, int);
    ~Functions();
    void getProductoCartesiano();
    void showRelacion();

    bool esOrdenParcial();
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
    cout << "\n\t\tProducto cartesiano AxA: \n";
    for (int i = 0; i < this->n; i++)
    {
        this->relacion[i] = new bool[n];
        for (int j = 0; j < this->n; j++)
        {
            this->relacion[i][j] = 0;
            this->productoCartesiano.insert(pair<int, pair<int, int>>(x, pair<int, int>(arr[i], arr[j])));
            if (n == 10)
                printf("%03d: ", x);
            else
                printf("%02d: ", x);
            printf("(%d;%d)\t", this->productoCartesiano[x].first, this->productoCartesiano[x].second);
            x++;
            if ((x - 1) % 5 == 0)
                printf("\n");
        }
    }

    printf("\n\n");
    this->ingresarR();
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
    for (int i = 0; i < this->n; i++)
    {
        printf("\t_");
    }
    printf("\n\n");
    //fin de numeros de referencia

    for (int i = 0; i < this->n; i++)
    {
        //numeros de referencia lateral izquierad
        printf("%02d|\t", this->arr[i]);
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

void Functions::ingresarR()
{

    //num es el valor en la tabla de productos cartesianos
    int n, num;
    int nCuadrado = this->n * this->n;
    do
    {
        printf("Ingrese la longitud de R: ");
        cin >> n;
    } while (n < 1 || n > nCuadrado);
    printf("Ingrese los valores de la tabla del producto cartesiano AxA: \n");
    for (int i = 0; i < n; i++)
    {
        do
        {
            if (n < 10)
                printf("[%d]", i + 1);
            else if (n < 100)
                printf("[%02d] ", i + 1);
            else
                printf("[%03d] ", i + 1);
            cin >> num;
        } while (num < 1 || num > nCuadrado || this->relacion[valores[productoCartesiano[num].first]][valores[productoCartesiano[num].second]]);
        this->relacion[valores[productoCartesiano[num].first]][valores[productoCartesiano[num].second]] = 1;
    }
}

bool Functions::esReflexiva()
{
    bool reflex = true;
    for (int i = 0; i < this->n; i++)
    {
        if (relacion[i][i] == 0)
        {
            reflex = false;
            return reflex;
        }
    }
    return reflex;
}

bool Functions::esAntisimetrica()
{
    bool antisime = true;
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            if (i != j && relacion[i][j] == 1 && relacion[j][i] == 1)
            {
                antisime = false;
                return antisime;
            }
        }
    }
    return antisime;
}

bool Functions::esTransitiva()
{
    bool trans = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (relacion[i][j] == 1 && i != j)
            {
                for (int k = 0; k < n; k++)
                {
                    if (relacion[j][k] == 1 && relacion[i][k] == 1)
                    {
                        trans = true;
                    }
                    if (relacion[j][k] == 1 && relacion[i][k] == 0)
                    {
                        trans = false;
                        return trans;
                    }
                }
            }
        }
    }
    return trans;
}

bool Functions::esOrdenParcial()
{
    bool reflex = this->esReflexiva();
    bool antisime = this->esReflexiva();
    bool trans = this->esTransitiva();
    cout << "Reflexiva: " << reflex << endl;
    cout << "AntiSimetrica: " << antisime << endl;
    cout << "Transitiva: " << trans << endl;
    cout << reflex << antisime << trans << endl;
    if (reflex == true && antisime == true && trans == true)
    {
        cout << "Es de Orden Parcial" << endl;
    }
    else
    {
        cout << "No es de Orden Parcial" << endl;
    }
    return reflex == true && antisime == true && trans == true;
}

#endif