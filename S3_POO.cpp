#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Student
{
private:
	char* nume;
	int anStudiu;
	int nrNote;
	int note[20];

public:
	// metode
	// - constructori (fara parametri, cu parametri)
	// - constructuri (constructor de copiere)
	// - destructor
	// - metode tip accesor (de tip get si set); faciliteaza lucrarile cu clasele private
	// - metode de prelucrare (functii)
	// - supraincarcarea operatorilor

	Student()
	{
		cout << "\nApel constructor fara parametri";

		// nume = (char*)malloc((strlen("Anonim") + 1) * sizeof(char));
		nume = new char[strlen("Anonim") + 1]; // alocare dinamica char

		strcpy(nume, "Anonim");
		anStudiu = 0;
		nrNote = 0;
	}

	// this = pointer la obiectul apelator
	Student(const char* nume, int anStudiu, int nrNote, int* note)
	{
		cout << "\nApel constructor cu toti parametri";

		int i;

		this->nume = new char[strlen(nume) + 1];

		strcpy(this->nume, nume);
		this->anStudiu = anStudiu;
		this->nrNote = nrNote;
for (i = 0; i < nrNote; i++)
		{
			this->note[i] = note[i];
		}
	}

	Student(const char* nume)
	{
		cout << "\nApel constructor doar cu parametrul nume";

		this->nume = new char[strlen(nume) + 1];

		strcpy(this->nume, nume);
		this->anStudiu = 1;
		this->nrNote = 0;
	}

	// metode tip accesor
	char* getNume()
	{
		return this->nume;
	}

	void setNume(const char* nume)
	{
		// cand modific numele, obiectul deja exista
		// adica exista posibilitatea sa existe deja un nume acolo
		delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];

		strcpy(this->nume, nume);
	}

	void afisare()
	{
		int i;

		cout << "\n--------------";
		cout << "\nNume: " << nume;
		cout << "\nAn Studiu: " << anStudiu;
		cout << "\nNumar note: " << nrNote;
		cout << "\nLista Note: ";
		for (i = 0; i < nrNote; i++)
		{
			cout << note[i] << " ";
		}
		cout << "\n--------------";
	}
};

int main()
{
	Student s; // se apeleaza constructorul fara parametri
	s.afisare();
	Student* ps; // pointer = adresa; orice pointer ocupa 4 octeti
	ps = &s; // s2 pointeaza la s
	char nume[] = "Gigel";
	Student s2(nume);

	Student s3("Gigel");
	s3.afisare();

	int note[] = { 10,4,5 };
	Student s4("Costel", 2, 3, note);
	s4.afisare();

	cout << "\n\n" << s4.getNume();
	s4.setNume("Costelus");
	cout << "\n\n" << s4.getNume();

	return 0;

	// tema:
	// - transformare sablon modificare vector dinamic in static

	// de amintit profa (pentru semninarul urmator)
	// - operator new cu paranteze rotunde
	// - pointer constanti (toate cele 4 combinatii)
	// - delete pe pointer

	// tema 2;
	// - alegem o clasa care sa contina vector static, dinamic + alte atribute
	// - constructor fara parametri, cu toti parametri, cu mai putini parametri
	// - metode de afisare
	// - metode accesor pentru fiecare atribut (grija la vectori cu dimensiunea sa)
	// - adaugara toate verificarile si restrictiile necesare
}