#include <iostream>
using namespace std;
void elim2(int*& v, int& n)
{
    int n2;
    n2 = n - 2;
    int* aux = (int*)malloc(n2 * sizeof(int));
    int k = 0;
    for (int i = 2; i < n; i++)
        aux[k++] = v[i];
    free(v);
    v = aux;
    n = n2;



}

void elimk(int*& v, int& n, int k)
{
    int n2;
    n2 = n - k;
    int* aux = (int*)malloc(n2 * sizeof(int));
    int j = 0;
    for (int i = 0; i < n2; i++)
        aux[j++] = v[i];
    free(v);
    v = aux;
    n = n2;

}

void dublu(int*& v, int& n)
{
    int n2 = n;
    for (int i = 0; i < n; i++)
        if (v[i] % 2 == 0)
            n2++;
    int* aux = (int*)malloc(n2 * sizeof(int));
    int k = 0;
    for (int i = 0; i < n2; i++)
    {
        if (v[i] % 2 != 0)
            aux[k++] = v[i];
        else
        {
            aux[k++] = v[i];
            aux[k++] = v[i] * 2;
        }
    }
        free(v);
        v = aux;
        n = n2;
    
}



int main()
{
    //int k;
    //cin >> k;
    int n, i, * v;
    cin >> n;
   v = new int[n];
    for (i = 0; i < n; i++)

        cin >> v[i];

    //elim2(v, n);
    //elimk(v,n,k);
    //dublu(v,n);

    for (i = 0; i < n; i++)
        cout << v[i] << " ";

    

}