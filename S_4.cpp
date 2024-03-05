 #include <iostream>
using namespace std;


class Student {

    string nume="Anonim";  //char* nume;
    int nrNote=0;
    int* note=NULL;

public:
    Student() {
        cout << "\nApel Constr Fara param";
    }
    Student(string nume, int nrNote, int* note)
    {
        this->nume = nume;
        if (nrNote > 0 && note != NULL) {
            this->nrNote = nrNote;
            this->note = new int[this->nrNote];
            for (int i = 0; i < this->nrNote;i++)
                this->note[i] = note[i];
        }
    }

    Student(const Student& s)
    {
        cout << "\nApel constr copy";
        this->nume = nume;
        if (nrNote > 0 && s.note != NULL) {
            this->nrNote = s.nrNote;
            this->note = new int[this->nrNote];
            for (int i = 0; i < this->nrNote;i++)
                this->note[i] = s.note[i];
        }

    }

    void afisare()
    {
        cout << " \nStudentul " << this->nume;
        if (this->nrNote == 0)
            cout << " nu are note inregistrarate.";
        else
        {
            cout << "are " << this->nrNote << " note";
            for (int i = 0;i < this->nrNote; i++)
                cout << this->note[i] << " ";
            cout << " .";
        }
    }

    ~Student()
    { //destructor
        cout << "\nApel destructor";
        delete this->note;
    }

};



int main()
{
    Student s1;
    int note[] = { 10, 5 ,7 , 3, 2 };
    Student s2("Gigel", 5, note);
    s1.afisare();
    s2.afisare();

    Student* ps;
    ps = new Student();
    Student* ps2;
    ps2 = new Student[10];
    Student* ps3;
    ps3 = &s1;
    delete ps; //dezalocare, fara paranteze pt ca are un sg elemente
    delete[] ps2; //dezalocare
    return 0;
    Student s3 = s2;
    s3.afisare();
}
//daca nu venim cu destructor, elementele nu se elibereaza corespunzator


//tema de ales o clasa: clasa sa CONTINA un string si un vector de stringuri(string*), bool, un constr cu toti param cativa param, fara param, geter, seter, destructor
//data viit facem operatorul =, stiva, copy elision

