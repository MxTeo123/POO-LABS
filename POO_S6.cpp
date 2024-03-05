#include <iostream>
using namespace std;

class CustomException
{
	string mesaj;

public:
	// compactarea codului pentru a ocupa cat mai putin
	// s a folosit lista de initializare
	CustomException(string mesaj) : mesaj(mesaj) {}
	string getMesaj() { return this->mesaj; }
};

class Student
{
	const int codMatricol;

	string nume = "Anonim";
	int nrNote = 0;
	int* note = NULL;
	static float taxaRestanta;
	// atributele statice caracterizeaza clasa
	// cele non-statice caracterizeaza fiecare obiect in particular
	// fiecare obiect poate modifica staticul si se modifica la nivel global

public:
	Student(int codMatricol) :codMatricol(codMatricol)
	{
		cout << "\nApel constructori cu 1 param";

	}

	Student(int codMatricol, string nume, int nrNote, int* note) :codMatricol(codMatricol)
	{
		cout << "\nApel constructori cu toti param";
		this->nume = nume;

		if (nrNote > 0 && note != NULL)
		{
			this->nrNote = nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = note[i];
		}

	}

	Student(const Student& s) :codMatricol(s.codMatricol)
	{
		cout << "\nApel constructori de copiere";
		this->nume = s.nume;

		if (s.nrNote > 0 && s.note != NULL)
		{
			this->nrNote = s.nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = s.note[i];

		}
	}

	Student& operator=(const Student& s)
	{
		cout << "\nApel operator=";
		if (this != &s)
		{
			delete[] this->note;
			this->nume = s.nume;

			if (s.nrNote > 0 && s.note != NULL)
			{
				this->nrNote = s.nrNote;
				this->note = new int[this->nrNote];
				for (int i = 0; i < this->nrNote; i++)
					this->note[i] = s.note[i];
			}
		}
		return *this;
	}

	Student& operator+=(int nota)
	{
		Student s = *this;

		delete[] this->note;
		this->nrNote++;
		this->note = new int[this->nrNote];

		for (int i = 0; i < s.nrNote; i++)
		{
			this->note[i] = s.note[i];
		}
		this->note[this->nrNote - 1] = nota;

		return *this;
	}

	Student operator+(int nota)
	{
		Student s = *this;

		s += nota;
		/*delete[] s.note
		s.nrNote++;
		s.note = new int[s.nrNote];

		for (int i = 0; i < this->nrNote; i++)
		{
			s.note[i] = this->note[i];
		}
		s.note[s.nrNote - 1] = nota;*/
		return s;
	}

	void afisare()
	{
		cout << "\n-----------------";
		cout << "\nCod matricol:" << this->codMatricol;
		cout << "\nNume:" << this->nume;
		cout << "\nNr Note:" << this->nrNote;
		cout << "\nLista Note: ";
		for (int i = 0; i < this->nrNote; i++)
			cout << this->note[i] << " ";
		cout << "\n-------------";
	}


	// orice metoda statica (pentru ca e o metoda a clasei) nu are this->
	static float getTaxaRestanta()
	{
		// pentru atributele statice nu se mai foloseste this
		// pentru ele se foloseste clasa si operatorul de rezolutie (pentru a clarifica mai bine faptul ca e un atribut static)
		return Student::taxaRestanta;
	}

	static void setTaxaRestanta(float taxaRestanta)
	{
		if (taxaRestanta > 0)
		{
			Student::taxaRestanta = taxaRestanta;
		}
		else
		{
			// exception e o clasa predefinita
			throw new exception("Taxa restanta negativa.");
		}
	}

	void setNume(string nume)
	{
		if (nume.size() > 4)
		{
			this->nume = nume;
		}
		else
		{
			throw new CustomException("Numele nu are lungimea corecta!");
		}
	}

	float calculTotalPlataRestante()
	{
		int ct = 0;
		for (int i = 0; i < this->nrNote; i++)
		{
			if (this->note[i] < 5)
			{
				ct++;
			}
		}
		return ct * Student::taxaRestanta;
	}

	~Student()
	{
		cout << "\nApel destructor";
		delete[] this->note;
	}

	// declaram o "prietenie" intre coasa si acea metoda
	// pentru a avea acces la zona private (daca metoda ar fi in afara)
	friend Student operator+(int nota, const Student& s)
	{
		// varianta 1;
		//Student rez = s;
		//rez += nota;
		//return rez;

		// varianta 2
		//return s + nota;

		// de implementat
	}
	// orice metoda friend e din afara clasei, dar o punem in clasa pentru a simplifica lucrurile legate de semnatura
};

// variabilele statice se initializeaza precum cele globale
float Student::taxaRestanta = 75;


int main()
{
	Student s1(1001);
	int note[] = { 4, 8, 10 };
	Student s2(1002, "Gigel", 3, note);
	s1.afisare();
	s2.afisare();
	Student s3(s2);
	Student s4 = s2;
	s4.afisare();
	Student* ps = new Student(1008);
	delete ps;

	// de aici incepe seminarul 6
	Student s5(1002);
	s5 = s2;
	s5.afisare();

	// se poate apela geterul si seterul cu orice obiect
	cout << "\nTAXA RESTANTA: " << s1.getTaxaRestanta();
	s1.setTaxaRestanta(100);
	cout << "\nTAXA RESTANTA: " << s1.getTaxaRestanta();

	// folosim clasa si operatorul de rezolutie pentru a clarifica faptul ca e o metoda statica (a clasei, nu a obiectului)
	Student::setTaxaRestanta(75);
	cout << "\nTAXA RESTANTA: " << Student::getTaxaRestanta();
	Student::setTaxaRestanta(100);
	cout << "\nTAXA RESTANTA: " << Student::getTaxaRestanta();

	cout << "\nTotal plata restante: " << s5.calculTotalPlataRestante();

	// try se foloseste ori de cate ori avem o metoda care arunca exceptii
	try
	{
		Student::setTaxaRestanta(-5);
	}
	catch (exception* ex) // in cazul in care metoda a aruncat exceptia
	{
		cout << endl << ex->what(); // what pentru a vedea mesajul introdus;
		delete ex;
	}

	// se poate folosi try ca un fel de if
	// daca nu se primeste o exceptie, liniile din try se executa
	// daca se primeste o exceptie, atunci nu se executa
	try
	{
		s5.setNume("Gi"); // possible failure
		s5.afisare();
	}
	catch (CustomException* ex)
	{
		cout << endl << ex->getMesaj();
		delete ex;
	}

	s5 += 10; // adauga o noua nota la finalul vectorului
	s5.afisare();

	s3 = s5 + 7;
	s3.afisare();

	s3 = 7 + s5;

	return 0;

}

// plan pt s6 + s7
// atribut static
// throw exception (try & catch)
// supraincarcarea operatorilor (=, <<, >>, +, ++ (pre & post incrementare), <=, +=, !, cast, [], functie)
// atribut static combinat cu atribut constant

// SEMINAR 9 TEST !!!!!!!!!!! (22 nov)
// la test vom avea un starting point
// adaugarea a 2 atribute noi (care sa faca referire la clasa si sa aiba sens dpdv logic)
// metode de prelucrare (una inventata sau una conform cerintei)
// o sa existe vectori alocati dinamici
// una din chichitele pentru nota 10 la test va avea legatura cu reutilizarea supraincarcarii pentru exemple particulare
// alta ar fi implementarea unei metode fara friend, geteri si seteri

// tema
// supraincarcarea operatorului -=
// s -= 3 elimina ultimele 3 note
// de implementat functia friend
// + ca de obicei, clasa noua, tot ce am facut pana acum + exception, customException, cat mai multe chestii