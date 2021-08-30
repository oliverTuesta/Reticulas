#include "Reticulas.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{

    Reticulas *r;

    //arr = conjunto A
    int *arr;
    bool **relacion;
    int n;
    do
    {
        cout << "Escriba la cantidad de elementos del conjunto A (4 a 10): ";
        cin >> n;
    } while (n < 3 || n > 10);

    arr = new int[n];

    bool existe;
    for (int i = 0; i < n; i++)
    {

        do
        {
            existe = false;
            printf("A[%02d]: ", i + 1);
            cin >> arr[i];

            for (int j = 0; j < i; j++)
            {
                if (arr[i] == arr[j])
                    existe = true;
            }

        } while (arr[i] < -99 || arr[i] > 99 || existe);
    }

    r = new Reticulas(relacion, arr, n);
    r->mostrarConjunto();
    r->getProductoCartesiano();
    r->esOrdenParcial();
    return 0;
}