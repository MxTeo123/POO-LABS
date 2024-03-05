#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum Grad
{
	ASIST = 1, LECT = 2, CONF = 3, PROF = 4
};

class IFile
{
public:
	// functie virtuala pura (= 0)
	// minim o functie virtuala pura -> clasa devine abstracta
	// nu pot exista variabile de tipul clasei abstracte
	virtual void writeToFile(fstream& f) = 0;
	virtual void readFromFile(fstream& f) = 0;
	// clasele din care se deriveaza trebuie sa aiba implementate functiile virtuale pure neaparat
};

class Angajat : public IFile
{
private:
	string nume = "Anonim";
protected:
	int vechime = 0;
	int nrLocuriMunca = 0;
	string* locuriMunca = NULL;
	float salariu = 0;

public:
	void writeToFile(fstream& f)
	{
		// scriere nume (string)
		// scriere lungime + scriere sir efectiv (date)
		int lg = this->nume.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->nume.data(), lg * sizeof(char));
		// scriere vechime (int)
		f.write((char*)&this->vechime, sizeof(int));
		// scriere nr locuri de munca (int)
		f.write((char*)&this->nrLocuriMunca, sizeof(int));
		for (int i = 0; i < this->nrLocuriMunca; i++)
		{
			// scrierea in 2 pasi a stringului/charului
			int lg = this->locuriMunca[i].length() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->locuriMunca[i].data(), lg * sizeof(char));
		}
		// scriere salariu (float)
		f.write((char*)&this->salariu, sizeof(float));
	}
	void readFromFile(fstream& f)
	{
		// citire nume
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->nume = buffer;
		delete[] buffer;
		// citire vechime
		f.read((char*)&this->vechime, sizeof(int));
		// citire locuri de munca
		delete[] this->locuriMunca;
		f.read((char*)&this->nrLocuriMunca, sizeof(int));
		this->locuriMunca = new string[this->nrLocuriMunca];
		for (int i = 0; i < this->nrLocuriMunca; i++)
		{
			f.read((char*)&lg, sizeof(int));
			char* buffer = new char[lg];
			f.read(buffer, lg);
			this->locuriMunca[i] = buffer;
			delete[] buffer;
		}
		// citire salariu
		f.read((char*)&this->salariu, sizeof(float));
	}
	Angajat()
	{
		cout << "\nCONSTRUCTOR FARA PARAM ANGAJAT";
	}

	Angajat(string nume, int vechime, int nrLocuriMunca, string* locuriMunca, float salariu)
	{
		cout << "\nCONSTRUCTOR CU PARAM ANGAJAT";
		this->nume = nume;
		this->vechime = vechime;
		this->salariu = salariu;
		if (locuriMunca != NULL && nrLocuriMunca != 0)
		{
			this->nrLocuriMunca = nrLocuriMunca;
			this->locuriMunca = new string[this->nrLocuriMunca];
			for (int i = 0; i < this->nrLocuriMunca; i++)
				this->locuriMunca[i] = locuriMunca[i];
		}
	}

	Angajat(const Angajat& a)
	{
		cout << "\nCONSTRUCTOR COPIERE ANGAJAT";
		this->nume = a.nume;
		this->vechime = a.vechime;
		this->salariu = a.salariu;
		if (a.locuriMunca != NULL && a.nrLocuriMunca > 0)
		{
			this->nrLocuriMunca = a.nrLocuriMunca;
			this->locuriMunca = new string[this->nrLocuriMunca];
			for (int i = 0; i < this->nrLocuriMunca; i++)
				this->locuriMunca[i] = a.locuriMunca[i];
		}
	}

	Angajat& operator=(const Angajat& a)
	{
		cout << "\nOPERATOR = ANGAJAT";
		this->nume = a.nume;
		this->vechime = a.vechime;
		this->salariu = a.salariu;
		delete[] this->locuriMunca;
		if (a.locuriMunca != NULL && a.nrLocuriMunca > 0)
		{
			this->nrLocuriMunca = a.nrLocuriMunca;
			this->locuriMunca = new string[this->nrLocuriMunca];
			for (int i = 0; i < this->nrLocuriMunca; i++)
				this->locuriMunca[i] = a.locuriMunca[i];
		}
		else
		{
			this->nrLocuriMunca = 0;
			this->locuriMunca = NULL;
		}
		return *this;
	}

	~Angajat()
	{
		cout << "\nDESTRUCTOR ANGAJAT";
		delete[] this->locuriMunca;
	}


	friend ostream& operator<<(ostream& out, const Angajat& a)
	{
		out << "\nNume: " << a.nume;
		out << "\nVechime: " << a.vechime;
		out << "\nSalariu: " << a.salariu;
		if (a.locuriMunca != NULL)
		{
			out << "\nLocuri munca: ";
			for (int i = 0; i < a.nrLocuriMunca; i++)
				out << a.locuriMunca[i] << ", ";
		}
		return out;
	}

	virtual  float calculSalariu()
	{
		return this->salariu;
	}
};

class Profesor : public Angajat
{
	Grad gradDidactic = Grad::ASIST;
	int nrOreSuplimentare = 0;

public:
	Profesor()
	{
		cout << "\nCONSTRUCTOR FARA PARAM PROFESOR";
	}

	Profesor(string n, int v, int nrL, string* lM, float s, Grad g, int nrO) :Angajat(n, v, nrL, lM, s)
	{
		cout << "\nCONSTRUCTOR CU PARAM PROFESOR";
		this->gradDidactic = g;
		this->nrOreSuplimentare = nrO;
	}

	Profesor(const Profesor& p) :Angajat(p)//apel copy constr din clasa Angajat + upcast de la Profesor la Angajat
	{
		cout << "\nCONSTRUCTOR COPIERE PROFESOR";
		this->gradDidactic = p.gradDidactic;
		this->nrOreSuplimentare = p.nrOreSuplimentare;
	}

	Profesor& operator=(const Profesor& p)
	{
		Angajat::operator=(p);
		cout << "\nOPERATOR = PROFESOR";
		this->gradDidactic = p.gradDidactic;
		this->nrOreSuplimentare = p.nrOreSuplimentare;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Profesor& p)
	{
		out << (Angajat)p;
		out << "\nGrad didactic: " << p.gradDidactic;
		out << "\nNr ore suplimentare: " << p.nrOreSuplimentare;
		return out;
	}

	~Profesor()
	{
		cout << "\nDESTRUCTOR PROFESOR";
	}

	float calculSalariu()
	{
		return Angajat::calculSalariu() + this->nrOreSuplimentare * 15;
	}
};

int main()
{
	string lista[] = { "CNCV","ASE" };
	Angajat a("Maria", 10, 2, lista, 5000);
	Profesor p("Gigel", 5, 2, lista, 4000, Grad::LECT, 15);
	Angajat a2 = a;

	// virtualizare
	cout << "\nLucrul cu obiecte";
	cout << "\nSalariu Angajat: " << a.calculSalariu();
	cout << "\nSalariu Profesor: " << p.calculSalariu();
	a = p;
	cout << "\nSalariu angajat (fost profesor): " << a.calculSalariu();
	a = a2;

	// pentru a evidentia virtualizarea se folosesc 2 pointeri
	cout << "\nLucrul cu pointeri";
	Angajat* pa = &a;
	Profesor* pp = &p;
	cout << "\nLucrul cu obiecte";
	cout << "\nSalariu Angajat: " << pa->calculSalariu();
	cout << "\nSalariu Profesor: " << pp->calculSalariu();
	pa = pp;
	cout << "\nSalariu angajat (fost profesor): " << pa->calculSalariu();

	cout << "\nLucrul cu fisiere binare";
	//IFile f;
	IFile* pf;
	pf = &a;
	pf = &p;

	fstream fout("fisier.txt", ios::out | ios::binary);
	a.writeToFile(fout);
	fout.close();
	fstream fin("fisier.txt", ios::in | ios::binary);
	Angajat anou;
	anou.readFromFile(fin);
	fin.close();
	cout << anou;
	return 0;
}

// tema 1
// definire o clasa de baza, 2 clase derivate (animal -> caine si pisica)
// o clasa tip colecte (o colectie de animale)
// evidentiarea virtualizarii prin intermediul clasei de tip colectie
// cum se face:
// metoda virtuala in clasa de baza (animal)
// vector de pointeri in colectie (animalele din ograda)

// tema 2
// virtualizare citire si scriere in fisiere binare
// virtualizarea cout ului
// daca nu se pot face astea 2 ^, se fac astea:
// clasa care sa detina: char, char*, string, int, int*, enum
// implementarea citirii si a scrierii in fisier binar a atributelor din aceasta clasa