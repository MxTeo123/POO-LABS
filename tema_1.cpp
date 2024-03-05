#include <iostream>
using namespace std;
void vector(int v[], int &n)
{
	int p, i, j;

	for (i = 0; i < n; i++)
	{
		if (v[i] % 2 == 0)
		{
			n++;
			p = i;
			for (j = n; j > p; j--)
				v[j] = v[j - 1];

			v[p + 1] = v[p] * 2;
			i++;

		}
	}

}
int main()
{
	int *v, n, i, nr = 0;
	cin >> n;

	v = new int[6];

	for (i = 0; i < n; i++)
	
		cin >> v[i];


		vector(v, n);
	
	for (i = 0; i < n; i++)
		cout << v[i] << " ";

	delete v;
	
}