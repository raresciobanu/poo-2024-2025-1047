#include<iostream>

using namespace std;

enum GEN {
	FEMEIE = 2,
	BARBAT
};

class Persoana {
	//by default totul e private
	string nume;
	string telefon;
	string CNP;
protected:
	int varsta;
	float kg;
private:
	GEN gen;

public:
	Persoana() {
		this->nume = "numeDefault";
		this->telefon = "telefonUnknown";
		this->CNP = "randomCNP";
		this->varsta = 0;
		this->kg = 0;
		this->gen = FEMEIE;
	}

	Persoana(string nume, string telefon, string CNP, int varsta, float kg, GEN gen) {
		this->nume = nume;
		this->telefon = telefon;
		this->CNP = CNP;
		this->varsta = varsta;
		this->kg = kg;
		this->gen = gen;
	}

	Persoana(string nume, string telefon, string CNP) {
		this->nume = nume;
		this->telefon = telefon;
		this->CNP = CNP;

		this->varsta = 0;
		this->kg = 0;
		this->gen = FEMEIE;
	}

	Persoana& operator=(const Persoana& p) {
		if (this != &p) {
			this->nume = p.nume;
			this->telefon = p.telefon;
			this->CNP = p.CNP;
			this->varsta = p.varsta;
			this->kg = p.kg;
			this->gen = p.gen;
		}

		return *this;
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	string getTelefon() {
		return this->telefon;
	}

	void setTelefon(string telefon) {
		this->telefon = telefon;
	}

	string getCNP() {
		return this->CNP;
	}

	void setCNP(string CNP) {
		this->CNP = CNP;
	}

	int getVarsta() {
		return this->varsta;
	}

	void setVarsta(int varsta) {
		this->varsta = varsta;
	}

	float getKg() {
		return this->kg;
	}

	void setKg(float kg) {
		this->kg = kg;
	}

	GEN getGen() {
		return this->gen;
	}

	void setGen(GEN gen) {
		this->gen = gen;
	}

	void afisare() {
		cout << "Nume: " << this->nume
			<< " , telefon: " << this->telefon
			<< " , CNP: " << this->CNP
			<< " , varsta: " << this->varsta
			<< " , kg: " << this->kg
			<< " , gen: " << this->genToString(this->gen) << endl << endl;
	}

	string genToString(GEN gen) {
		switch (gen)
		{
		case FEMEIE:
			return "Femeie";
		case BARBAT:
			return "Barbat";
		}
	}

	GEN stringToGEN(string value) {
		if (value == "Femeie") {
			return FEMEIE;
		}
		else {
			return BARBAT;
		}
	}
};

class Profesor : public Persoana {
	int aniVechime;

public:

	Profesor() : Persoana() {
		this->aniVechime = 0;
	}

	Profesor(string nume, string telefon, string CNP, int varsta, float kg, GEN gen, int aniVechime)
		:Persoana(nume, telefon, CNP, varsta, kg, gen) {
		this->aniVechime = aniVechime;
	}

	void afisareProfesor() {
		cout << "Profesor vechime: " << this->aniVechime << endl;
		this->afisare();
	}
};

class Student : public Persoana {
	bool exmatriculat;
	int aniStudii;

	int nrNote;
	double* note;
	char* nivelStudii;//licenta/master/doctorat...etc

public:

	Student() : Persoana() {
		this->exmatriculat = false;
		this->aniStudii = 0;

		this->nrNote = 0;
		this->note = nullptr;

		this->nivelStudii = new char[strlen("licenta") + 1];
		strcpy_s(this->nivelStudii, strlen("licenta") + 1, "licenta");
	}

	Student(string nume, string telefon, string CNP, int varsta, float kg, GEN gen, bool exmatriculat, int aniStudii)
		:Persoana(nume, telefon, CNP, varsta, kg, gen) {
		this->exmatriculat = exmatriculat;
		this->aniStudii = aniStudii;

		this->nrNote = 0;
		this->note = nullptr;

		this->nivelStudii = new char[strlen("licenta") + 1];
		strcpy_s(this->nivelStudii, strlen("licenta") + 1, "licenta");
	}

	Student(string nume, string telefon, string CNP, int varsta, float kg, GEN gen, bool exmatriculat, int aniStudii, int nrNote, double *note, const char* nivelStudii)
		:Persoana(nume, telefon, CNP, varsta, kg, gen) {
		this->exmatriculat = exmatriculat;
		this->aniStudii = aniStudii;

		this->nrNote = nrNote;
		this->note = new double[this->nrNote];
		for (int i = 0; i < nrNote; i++) {
			this->note[i] = note[i];
		}

		this->nivelStudii = new char[strlen(nivelStudii) + 1];
		strcpy_s(this->nivelStudii, strlen(nivelStudii) + 1, nivelStudii);
	}

	void afisareStudent() {
		cout << "Studentul are: " << this->aniStudii << " ani de studii si este exmatriculat: "
			<< (this->exmatriculat ? " DA " : " NU ") << endl;

		cout << "Nr. note: " << this->nrNote << endl << "Note: ";
		for (int i = 0; i < this->nrNote; i++) {
			cout << "note[" << i << "] = " << this->note << " ";
		}
		cout << endl;
		
		this->afisare();
	}

	Student& operator=(const Student& s) {
		if (this != &s) {
			Persoana::operator=(s);

			this->exmatriculat = s.exmatriculat;
			this->aniStudii = s.aniStudii;

			delete[] this->note;
			delete[] this->nivelStudii;

			this->nrNote = s.nrNote;
			this->note = new double[s.nrNote];
			for (int i = 0; i < s.nrNote; i++) {
				this->note[i] = s.note[i];
			}

			this->nivelStudii = new char[strlen(s.nivelStudii) + 1];
			strcpy_s(this->nivelStudii, strlen(s.nivelStudii) + 1, s.nivelStudii);
		}

		return *this;
	}

	~Student() {
		cout << "Destructor Student: " << this->getNume() << endl;
		delete[] note;
		delete[] nivelStudii;
	}
};

//has a
class Curs {
	string nume;

	Student* studenti;
	int nrStudenti;

	Profesor profesor;

public:

	Curs() {
		this->nume = "cursInexistent";
		this->nrStudenti = 0;
		this->studenti = nullptr;
		this->profesor = Profesor();
	}

	Curs(string nume, Student* studenti, int nrStudenti, Profesor profesor) {
		this->nume = nume;
		this->nrStudenti = nrStudenti;

		this->studenti = new Student[nrStudenti];
		for (int i = 0; i < nrStudenti; i++) {
			this->studenti[i] = studenti[i];
		}

		this->profesor = profesor;
	}

	void afisare() {
		cout << "Curs nume: " << this->nume << endl;

		profesor.afisareProfesor();

		cout << "Nr studenti: " << nrStudenti << "\nStudentii: " << endl;
		for (int i = 0; i < nrStudenti; i++) {
			this->studenti[i].afisareStudent();
		}
	}

	~Curs() {
		delete[] this->studenti;//evitare memory leaks
		cout << "s a distrus cursul: " << this->nume << endl;
	}
};

void main() {
	Persoana p1;
	p1.afisare();
	p1.setNume("Vasile Popescu");
	p1.afisare();

	Persoana p2("Maria Popescu", "0764343868", "3223224242");
	p2.afisare();

	Persoana p3("Marin Georgescu", "0765545444", "1224545454", 30, 88.4, BARBAT);
	p3.afisare();

	cout << "\n\n========MOSTENIRE=======\n\n";

	Profesor prof1;
	prof1.afisareProfesor();

	Profesor prof2("Madalin Ion", "0777448663", "1221212121", 40, 93.7, BARBAT, 20);
	prof2.afisareProfesor();

	Student stud1;
	stud1.afisareStudent();

	Student stud2("Vasile Popescu", "0777555555", "199999999", 20, 77.7, BARBAT, false, 3);
	stud2.afisareStudent();

	Student stud3("Maria Raluca", "0753533333", "223333333", 21, 57.7, FEMEIE, false, 2);
	stud3.afisareStudent();

	double note1[5] = { 10, 9, 7.5, 8, 5.6 };
	Student stud4("Ioana Maria", "077444444", "100000111", 30, 51.7, FEMEIE, false, 1, 5, note1, "master");
	stud4.afisareStudent();

	double note2[5] = { 8, 9.4 , 5.5, 6, 7 };
	Student stud5("Marius Georgescu", "071111111", "200000011", 33, 89.7, BARBAT, false, 2, 5, note2,
		"doctorat");
	stud5.afisareStudent();

	cout << endl << endl << "==========CURSURI============" << endl << endl;
	Student* studentiPointer = new Student[5];
	studentiPointer[0] = stud1;
	studentiPointer[1] = stud2;
	studentiPointer[2] = stud3;

	Curs curs1;
	curs1.afisare();

	Curs curs2("POO", studentiPointer, 3, prof2);
	curs2.afisare();

	Curs curs3("ATP", studentiPointer, 3, prof2);
	curs3.afisare();

	delete[] studentiPointer;//evitare memory leaks in main
}