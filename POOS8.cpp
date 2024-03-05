#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

class Cadou {
private:
	string denumire = "Anonim";
	float pret = 0;

public:
	Cadou()
	{
	}

	Cadou(string denumire, float pret)
	{
		this->denumire = denumire;
		this->pret = pret;
	}

	Cadou(const Cadou& c)
	{
		this->denumire = c.denumire;
		this->pret = c.pret;
	}

	Cadou& operator=(const Cadou& c)
	{
		this->denumire = c.denumire;
		this->pret = c.pret;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Cadou& c)// afiseaza date
	{
		out << "\nDenumire: " << c.denumire << ", pret: " << c.pret;
		return out;
	}

	friend ofstream& operator<<(ofstream& out, const Cadou& c)// afiseaza date
	{
		out << c.denumire << endl << c.pret;
		return out;
	}
	friend istream& operator>>(istream& in, Cadou& c)//citim date de la tastatura
	{
		cout << "Introduceti denumire: ";
		in >> c.denumire;
		cout << "Introduceti pret: ";
		in >> c.pret;
		return in;
	}
	friend ifstream& operator>>(ifstream& in, Cadou& c)//citim date de la tastatura
	{

		in >> c.denumire;
		in >> c.pret;
		return in;
	}
};

//citire si scriere in fisiere text
// relatia has a,de compunere;

class WishList
{
	string detinator = "Anonim";
	int nrCadouri = 0;
	//facem un vector de cadouri
	Cadou** listaCadouri = NULL; // prima steluta este ca alocare dinamica a vectorului. cea de a 2 o combin cu cadoul si avem un vector care va detine adrese

public:

	WishList()
	{

	}
	WishList(string detinator, int nrCadouri, Cadou** listaCadouri)
	{
		this->detinator = detinator;
		if (nrCadouri > 0 && listaCadouri != NULL)
		{
			this->nrCadouri = nrCadouri;
			this->listaCadouri = new Cadou * [this->nrCadouri];
			// in shalow copy depinde de datele din input;
			// pe deep copy
			for (int i = 0; i < this->nrCadouri; i++)
			{
				this->listaCadouri[i] = new Cadou(*listaCadouri[i]);// trimitem un cadou si aloc o zona noua de memorie. orice modificare a imputului nu va impacta modificari in wishlist

			}//shalow copy;
			//this->listaCadouri[i] = listaCadouri[i];
		}

	}

	WishList(const WishList& w)
	{
		this->detinator = w.detinator;
		if (w.nrCadouri > 0 && w.listaCadouri != NULL)
		{
			this->nrCadouri = w.nrCadouri;
			this->listaCadouri = new Cadou * [this->nrCadouri];
			// in shalow copy depinde de datele din input;
			// pe deep copy
			for (int i = 0; i < this->nrCadouri; i++)
			{
				this->listaCadouri[i] = new Cadou(*w.listaCadouri[i]);// trimitem un cadou si aloc o zona noua de memorie. orice modificare a imputului nu va impacta modificari in wishlist

			}//shalow copy;
			//this->listaCadouri[i] = listaCadouri[i];
		}
	}
	WishList& operator=(const WishList& w)
	{
		if (this != &w)
		{
			for (int i = 0; i < this->nrCadouri; i++)
			{
				delete this->listaCadouri[i]; // fara paranteze pt ca am alocat un singur obiect;
				delete[] this->listaCadouri;
			}
			this->detinator = w.detinator;
			if (w.nrCadouri > 0 && w.listaCadouri != NULL)
			{
				this->nrCadouri = w.nrCadouri;
				this->listaCadouri = new Cadou * [this->nrCadouri];
				// in shalow copy depinde de datele din input;
				// pe deep copy
				for (int i = 0; i < this->nrCadouri; i++)
				{
					this->listaCadouri[i] = new Cadou(*w.listaCadouri[i]);// trimitem un cadou si aloc o zona noua de memorie. orice modificare a imputului nu va impacta modificari in wishlist

				}//shalow copy;
				//this->listaCadouri[i] = listaCadouri[i];
			}
			else
			{
				this->nrCadouri = 0;
				this->listaCadouri = NULL;
			}

		}
		return *this;
	}

	bool operator!()
	{
		if (this->listaCadouri == NULL)
		{
			return true;
		}
		else
		{
			return false;

			return this->listaCadouri == NULL;
		}

	}
	~WishList()
	{
		for (int i = 0; i < this->nrCadouri; i++)
		{
			delete this->listaCadouri[i]; // fara paranteze pt ca am alocat un singur obiect;
			delete[] this->listaCadouri;
		}

	}
	friend ostream& operator<<(ostream& out, const WishList w)
	{
		out << "\nDetinator" << w.detinator;
		out << "\nNr cadouri:" << w.nrCadouri;
		for (int i = 0; i < w.nrCadouri; i++)
		{
			out << *w.listaCadouri[i];
		}
		return out;
	}



};

//pt acasa: wishlist2 vect alocat static de Cadou*
//Wishlist3 ->vector satatic de Cadou
//Wishlist4 ->vector alocat dinamic de cadou
class Wishlist5
{
	string  detinator;
	Cadou* cadouSpecial;
	int nrPrieteni;
	Cadou*** listaCadouri;
	int* nrCadouriPrieteni;
};

int main()
{
	Cadou c1("carte", 120);
	Cadou c2("stilou", 560);
	Cadou c3("caciula", 300);
	Cadou* listaCadouri[] = { &c1,&c2,&c3 };
	WishList w1;
	WishList w2; ("DZM", 3, listaCadouri);
	cout << w2;
	WishList w3(w2);
	cout << w3;

	w1 = w3;
	cout << w1;
	//fisiere text;
	ofstream g("fisier.txt");
	g << c1; // ofstream is a ostream
	g.close();
	ifstream f("fisier.txt");
	Cadou c4;
	f >> c4;
	cout << c4;

	int n = 2;
	if (!n)
		cout << "\nn este zero";
	cout << endl << n;

	int a, b = 3;
	a = !b;
	cout << endl << a << " " << b;

	if (!w1)
		cout << "\nWishlist nu are cadouri";


	return 0;
}
