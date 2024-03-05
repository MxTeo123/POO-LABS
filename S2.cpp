#include <iostream>
using namespace std;

voidf1(int a, int b)
{
	int aux;
	aux = a;
	a = b;
	b = aux;

}


void f2(int &a, int &b)
{ 
	int aux;
	aux = a;
	a = b;
	b = aux;


}

void f3(int* a, int* b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void f4(int* a, int* b)
{
	int* aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main()
{
	int x, y;
	x = 2;
	y = 5;
	cout << "/nApel functie f1(transfer prin valoare)";
	f1(x, y);
	cout << "x= " << x << " y= " << y << endl;


	x = 2; y = 5;

	cout << "/nApel functie f2(transfer prin valoare)";
	f2(x, y);
	cout << "x= " << x << " y= " << y << endl;


	x = 2; y = 5;

	cout << "/nApel functie f3(transfer prin pointeri)";
	f3(&x, &y);
	cout << "x= " << x << " y= " << y << endl;

	return 0;
}
