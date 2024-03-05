#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Echipa  
{
	string Nume;
	int NrCupe;
	int NrJucatori;
	string Jucatori[30];

public:
	Echipa() 
	{
		Nume = "-";
		NrCupe = 0;
		NrJucatori = 0;
		Jucatori[30]={};
	}

	void setNume(string nume)
	{
		Nume = nume;
	}
	string getNume()
	{
		return Nume;
	}

	void setNrCupe(int nrCupe)
	{
		NrCupe = nrCupe;

	}
	int getNrCupe()
	{
		return NrCupe;
	}
	//set si get

	void prezentare()
	{
		cout << "Nume echipa: " << Nume<<endl;
		cout << endl;
		if (NrCupe > 0)
			cout << "Au castigat liga campionilor de " << NrCupe << " ori" << endl;
		else
			cout << Nume<< " nu au castigat niciodata liga campionilor"<<endl;
		cout << endl;
		cout << "Nr jucatori: " << NrJucatori<<endl;
		cout << endl;
		cout << "Jucatori:" << endl;
		for (int i = 0;i < NrJucatori;i++)
			cout << Jucatori[i] <<endl;
		cout << "----------------------------------------------" << endl;
		cout << endl;
		
	}

	Echipa(string nume, int nrCupe, int nrJucatori, string* jucatori)
	{
		Nume = nume;
		NrCupe = nrCupe;
		NrJucatori = nrJucatori;
		for (int i = 0;i < nrJucatori;i++)
			Jucatori[i] = jucatori[i];
		
	}
};

int main()
{
	cout << "----------------------------------------------" << endl;
	string playeri1[] = { "Harry Maguire(C)","Cristiano Ronaldo","Casemiro", "Marcus Rashford", "Jadon Sancho", "Raphael Varane","Luke Shaw", "Scott McTominay", "David De Gea", "Victor Lindelof","Malacia Tyrell","Martinez Lisandro","Wan-Bissaka","Christian Eriksen", "Fred", "Donny Van de Beek", "Antony", "Anthony Elanga", "Alejandro Garnacho"};
	Echipa echipa1 = Echipa("Manchester United F.C.", 3, 19, playeri1);
	echipa1.prezentare();
	
	string playeri2[] = { "Marquinhos(C)","Neymar","Kylian Mbappe","Lionel Messi","Sergio Ramos","Marco Veratti","Gianluigi Donnarumma","Juan Bernat","Arkhaf Hakimi","Presnel Kimpembe","Nuno Mendes", "Nordi Mukiele","Danilo Pereira","Renato Sanches","Pablo Sarabia","Carlos Soler","Vitinha"};
	Echipa echipa2 = Echipa("Paris Saint-Germain F.C.", 0, 15, playeri2);
	echipa2.prezentare();

	string playeri3[] = { "Manuel Neuer(C)", "Sven Ulreich", "Alphonso Davies", "Lucas Hernandez","Benjamin Pavard","Dayot Upamecano", "De Light Matthijs", "Leon Goretzka","Ryan Gravenberch","Joshua Kimmich","Jamal Musiala","Marcel Sabitzer","Chupo-Moting Eric Maxim","Kingsley Coman","Serge Gnabry","Sadio Mane", "Thomas Muller","Leroy Sane"};
	Echipa echipa3 = Echipa("FC Bayern Munich", 6, 18, playeri3);
	echipa3.prezentare();
	
	cout << "In seara asta va avea loc meciul dintre " << echipa1.getNume() << " si " << echipa2.getNume()<<endl;
	echipa2.setNrCupe(2);
	cout << echipa2.getNume() << " are " << echipa2.getNrCupe() << " campionate castigate"<<endl;

}