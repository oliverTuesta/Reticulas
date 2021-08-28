#include "Functions.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{

    Functions *f;

    //arr = conjunto A
    int *arr;
    bool **relacion;
    int n;
    do
    {
        cout << "Escriba la cantidad de elementos del conjunto A (4 a 10): ";
        cin >> n;
    } while (n < 4 || n > 10);

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i + 1);
        cin >> arr[i];
    }
    f = new Functions(relacion, arr, n);
    cout << "Producto cartesiano AxA: \n";
    f->getProductoCartesiano();

    return 0;
}