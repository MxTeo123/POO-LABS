#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

enum UM
{
	LITRU, KILOGRAM, BUC
};

class Produs 
{
	const int cod;
	string denumire = "NA";
	int nrZile = 0;
	float* preturi = NULL;
	UM um = UM::BUC;

public:
	// lista initalizatori (:)
	// disponibili doar la constructor
	// trebuie folosita la declarare de atribut constant
	Produs(int cod) : cod(cod)
	{
		cout << "\nAPEL CONSTRUCTOR CU 1 PARAMETRU";
	}

	// in lista de initializatori se ruleaza inaintea codului
	Produs(int cod, string denumire, int nrZile, float* preturi, UM um) : cod(cod)
	{
		cout << "\nAPEL CONSTRUCTOR CU TOTI PARAMETRII";
		this->denumire = denumire;
		this->um = um;
		if (nrZile > 0 && preturi != NULL)
		{
			this->nrZile = nrZile;
			this->preturi = new float[this->nrZile];
			for (int i = 0; i < this->nrZile; i++)
			{
				this->preturi[i] = preturi[i];
			}
		}
	}

	Produs(const Produs& p) : cod(p.cod)
	{
		cout << "\nAPEL CONSTRUCTOR DE COPIERE";
		this->denumire = p.denumire;
		this->um = p.um;
		if (p.nrZile > 0 && p.preturi != NULL)
		{
			this->nrZile = p.nrZile;
			this->preturi = new float[this->nrZile];
			for (int i = 0; i < this->nrZile; i++)
			{
				this->preturi[i] = p.preturi[i];
			}
		}
	}

	Produs& operator=(const Produs& p)
	{
		cout << "\nAPEL OPERATOR =";
		if (this != &p)
		{
			delete[] this->preturi; // dezalocare deoarece obiectul deja exista
			this->denumire = p.denumire;
			this->um = p.um;
			if (p.nrZile > 0 && p.preturi != NULL)
			{
				this->nrZile = p.nrZile;
				this->preturi = new float[this->nrZile];
				for (int i = 0; i < this->nrZile; i++)
				{
					this->preturi[i] = p.preturi[i];
				}
			}
			else
			{
				this->nrZile = 0;
				this->preturi = NULL;
			}
		}
		return *this; // returnul implica constructorul de copiere si destructorul
	}

	void afisare()
	{
		cout << "\n************";
		cout << "\nDenumire: " << this->denumire;
		cout << "\nCod Produs: " << this->cod;
		cout << "\nUnitate masura: " << this->um;
		cout << "\nNr zile analiza preturi: " << this->nrZile;
		cout << "\nIstoric preturi: ";
		for (int i = 0; i < this->nrZile; i++)
		{
			cout << this->preturi[i] << " ";
		}
		cout << "\n************";
	}

	~Produs()
	{
		cout << "\nAPEL DESTRUCTOR";
		delete[] this->preturi;
	}
};

Produs f1(Produs p1, Produs vp[10])
{
	Produs p(102);
	p = vp[0];
	return p;
}

Produs& f2(Produs p2)
{
	Produs p(103);
	return p;
}

Produs f3(Produs p1)
{
	Produs p(102);
	return p;
}

int main()
{
	Produs p1(102);
	p1.afisare();

	float preturi[] = { 12.4, 15, 17.6, 19 };
	Produs p2(103, "Lapte", 4, preturi, UM::LITRU);
	p2.afisare();

	Produs p3(p2);
	p3.afisare();

	p1 = p3;
	// p1.operator=(p3) - forma explicita operator egal
	// * pasi supraincarcare operatori *
	// pas 1 --------------------
	// * identificare tip operator (binar sau unar)
	// pas 2 --------------------
	// * identificare nr de operanzi + tipul lor
	// pas 3 --------------------
	// * daca primul operand este de tipul clasei , atunci implementarea acestei supraincarcari se poate realiza pe baza unei
	// metode a clasei
	// * daca primul operand nu este de tipul clasei, atunci implementarea acestei supraincarcarii nu se poate realiza pe baza
	// unei metode a clasei, ci pe baza unei functii exterioare a clasei
	// pas 4 --------------------
	// * ce returneaza si ce obiecte sunt modificabile?
	p1.afisare();

	int a, b, c;
	a = b = 2;
	a = a;

	Produs p4(105);
	p4 = p1 = p3;
	p4.afisare();
	p4 = p4;
	p4.afisare();

	cout << "\n##############################";
	Produs p10 = f3(p3);
	cout << "\n##############################";
	p10 = f3(p3);
	cout << "\n##############################";
	return 0;
}

// tema
// clasa noua, trebuie sa contina enum, alocare dinamica, trecere prin tot ce am facut
// (geteri, seteri, validari, functii in afara clasei, supraincarcare operatori, etc)