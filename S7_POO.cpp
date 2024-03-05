

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;


class Produs
{
	char* denumire = NULL;
	int nrZile = 0;
	float* preturi = NULL;
	int stoc = 0;

public:
	Produs(const char* denumire, int stoc)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->stoc = stoc;
	}

	Produs(const Produs& p)
	{
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);
		this->stoc = p.stoc;
		this->nrZile = p.nrZile;
		this->preturi = new float[this->nrZile];
		for (int i = 0; i < this->nrZile; i++)
			this->preturi[i] = p.preturi[i];
	}

	Produs& operator=(const Produs& p)
	{
		if (this != &p)
		{
			delete[] this->denumire;
			delete[] this->preturi;
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
			this->stoc = p.stoc;
			this->nrZile = p.nrZile;
			this->preturi = new float[this->nrZile];
			for (int i = 0; i < this->nrZile; i++)
				this->preturi[i] = p.preturi[i];
		}
		return *this;
	}

	bool operator>(Produs p)
	{
		return this->stoc > p.stoc;
	}

	// pentru a permite si modificarea se returneaza prin referinta
	float& operator[](int index)
	{
		if (index > 0 && index < this->nrZile)
		{
			return this->preturi[index];
		}
	}

	// pre incrementare
	Produs& operator++()
	{
		this->stoc++;
		return *this;
	}

	// post incrementare (pentru a se diferentia cele 2 functii, se pune acel int ca parametru care nu o sa fie folosit
	Produs operator++(int)
	{
		Produs copie = *this;
		this->stoc++;
		return copie;
	}

	// cast la float
	operator float()
	{
		return this->preturi[this->nrZile - 1];
	}

	// explicit se foloseste doar pentru a cere explicit ((int) in fata)
	// recomandare pt proiect: toate cast-urile explicit
	explicit operator int()
	{
		return this->stoc;
	}

	float operator()(int li, int ls)
	{
		int ct = ls - li + 1;
		float suma = 0;
		for (int i = li; i <= ls; i++)
		{
			suma += this->preturi[i];
		}
		return suma / ct;
	}

	// operatorul functie fara parametrii (nu este implementat)
	int operator()()
	{
		return 0;
	}

	void setPreturi(float* preturi, int nrZile)
	{
		if (nrZile > 0 && preturi != NULL)
		{
			delete[] this->preturi;
			this->nrZile = nrZile;
			this->preturi = new float[this->nrZile];
			for (int i = 0; i < this->nrZile; i++)
				this->preturi[i] = preturi[i];
		}
	}

	void adaugaPret(float pretNou)
	{
		Produs p = *this;
		delete[] this->preturi;
		this->nrZile++;
		this->preturi = new float[this->nrZile];
		for (int i = 0; i < p.nrZile; i++)
			this->preturi[i] = p.preturi[i];
		this->preturi[this->nrZile - 1] = pretNou;
	}

	void afisare()
	{
		cout << "\n--------------------";
		cout << "\nDenumire: " << this->denumire;
		cout << "\nStoc: " << this->stoc;
		cout << "\nNr zile: " << this->nrZile;
		cout << "\nIstoric preturi: ";
		for (int i = 0; i < this->nrZile; i++)
			cout << this->preturi[i] << " ";
		cout << "\n--------------------";
	}

	~Produs()
	{
		delete[] this->denumire;
		delete[] this->preturi;
	}

	friend ostream& operator<<(ostream& out, Produs p)
	{
		out << "\n--------------------";
		out << "\nDenumire: " << p.denumire;
		out << "\nStoc: " << p.stoc;
		out << "\nNr zile: " << p.nrZile;
		out << "\nIstoric preturi: ";
		for (int i = 0; i < p.nrZile; i++)
			cout << p.preturi[i] << " ";
		out << "\n--------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Produs& p)
	{
		delete[] p.denumire;
		delete[] p.preturi;
		char aux[100];
		cout << "\nIntroduceti denumirea: ";
		in >> aux;
		p.denumire = new char[strlen(aux) + 1];
		strcpy(p.denumire, aux);
		cout << "\nIntroduceti stoc: ";
		in >> p.stoc;
		cout << "\nIntroduceti nr zile analiza: ";
		in >> p.nrZile;
		if (p.nrZile < 0)
		{
			p.nrZile = 0;
			p.preturi = NULL;
		}
		else
		{
			p.preturi = new float[p.nrZile];
			for (int i = 0; i < p.nrZile; i++)
			{
				cout << "p[" << i << "]=";
				in >> p.preturi[i];
			}
		}
		return in;
	}
};

int main()
{
	Produs p1("paine graham", 100);
	p1.afisare();
	p1.adaugaPret(8.5);
	p1.adaugaPret(8.7);
	p1.adaugaPret(9.1);
	p1.afisare();
	Produs p2(p1);
	p2.afisare();
	Produs p3("Produs", 0);
	p3 = p2;
	p3.afisare();

	// operator comparatie (<= > < >= != ==)
	if (p1 > p2)
	{
		cout << "\nP1 are un stoc mai mare ca p2";
	}
	else
	{
		cout << "\nInvers";
	}

	// operatorul index []
	float pret = p3[2];
	cout << "\nPretul este: " << pret;

	p3[2] = 15.6;
	p3.afisare();

	// operatorul ++ (are prioritatea fata de = )
	p1 = p3++;
	// p1.operator=(p3.operator++(2)); (forma explicita)
	p1.afisare();
	p3.afisare();

	p1 = ++p3;
	p1.afisare();
	p3.afisare();

	// operator cast
	float pretCurent = p3;

	int stoc = (int)p3;

	// odata introdus castul float, acesta poate aduce erori (nu avem + dar totusi randurile comentate merg) deoarece nu este explicit
	/*int test;
	test = p3 + p2;
	test = p3 + 2;*/

	// operator functie
	float pretMediu = p3(0, 1);

	cin >> p3;
	cout << p3;
	return 0;
}