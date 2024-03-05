#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
class Student
{
	string Nume;
	string Prenume;
	string Facultate;
	string An;
	int NrNote;
	int Note[10];

public:

	Student()  //constructor default
	{
		Nume = " - ";
		Prenume = "  - ";
		Facultate = " - ";
		An = " 0 ";
		NrNote = 0;
		Note[10] = { 0 };
	}

	void setNume(string nume)
	{
		Nume = nume;

	}
	string getNume()
	{
		return Nume;
	}
	void setPrenume(string prenume)
	{
		Prenume = prenume;

	}
	string getPrenume()
	{
		return Prenume;
	}
	void setFacultate(string facultate)
	{
		Facultate = facultate;

	}
	string getFacultate()
	{
		return Facultate;
	}
	void setAn(string an)
	{
		An = an;

	}
	string getAn()
	{
		return An;
	}
	void setNrNote(int nrNote)
	{
		NrNote = nrNote;

	}
	int getNrNote()
	{
		return NrNote;
	}
	
	//metode de set si get

	void prezentare()
	{
		
		cout << "Nume: " << Nume << endl;
		cout << "Prenume: " << Prenume << endl;
		cout << "Facultate: " << Facultate << endl;
		cout << "An studiu: " << An << endl;
		cout << "Numar note " << NrNote << endl;
		cout << "Note: ";
		for (int i = 0;i < NrNote;i++)
			cout << Note[i] << " ";
		cout << endl;
		cout << "----------------------------------------------" << endl;
	}

	Student(string nume, string prenume, string facultate, string an, int nrNote, int* note)   //constructor cu parametri
	{
		Nume = nume;
		Prenume = prenume;
		Facultate = facultate;
		An = an;
		NrNote = nrNote;
		for(int i=0; i<nrNote ; i++)
		Note[i] = note[i];

	}

};

int main()
{
	cout << "----------------------------------------------" << endl;
	int note[] = { 10,4,5, 9 };
	Student stud1=Student("Ioan", "Andrei", "ASE MAN", "I", 4,note);
	stud1.prezentare();

	int note1[] = { 5,6,9 };
	Student stud2=Student("Nistor", "Vlad", "ASE FABBV", "II", 3,note);
	stud2.prezentare();

	int note2[] = { 10,9 };
	Student stud3 = Student("Popescu", "Ilinca", "ASE CSIE", "I", 2, note);
	stud3.prezentare();

	Student stud4;
	stud4.prezentare();

	stud1.setAn("II"); //set
	cout << stud1.getNume()<<" "<<stud1.getPrenume() << " studiaza la " << stud1.getFacultate() << " in anul " << stud1.getAn(); //get
	
	
}