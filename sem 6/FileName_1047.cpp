#include<iostream>

using namespace std;

enum GEN {
	FEMEIE = 2,
	BARBAT,
	OTHER
};

class Persoana {
	//by default totul e private
	string nume;
	string telefon;
	string CNP;
	const long ID;

protected:
	int varsta;
	float kg;
private:
	GEN gen;

public:
	static string universitate;

	Persoana() :ID(0) {
		this->nume = "numeDefault";
		this->telefon = "telefonUnknown";
		this->CNP = "randomCNP";
		this->varsta = 0;
		this->kg = 0;
		this->gen = FEMEIE;
	}

	Persoana(long ID, string nume, string telefon, string CNP, int varsta, float kg, GEN gen) :ID(ID) {
		this->nume = nume;
		this->telefon = telefon;
		this->CNP = CNP;
		this->varsta = varsta;
		this->kg = kg;
		this->gen = gen;
	}

	Persoana(string nume, string telefon, string CNP) : ID(888) {
		if (nume.empty()) {
			throw new exception("Numele are dim 0");
		}
		if (telefon.length() != 10) {
			throw new exception("Telefonul nu are dim 10");
		}
		if (CNP.length() != 13) {
			throw new exception("CNP nu are dim 13");
		}

		this->nume = nume;
		this->telefon = telefon;
		this->CNP = CNP;

		this->varsta = 0;
		this->kg = 0;
		this->gen = FEMEIE;
	}

	Persoana(const Persoana& p) :ID(p.ID) {
		this->nume = p.nume;
		this->telefon = p.telefon;
		this->CNP = p.CNP;
		this->varsta = p.varsta;
		this->kg = p.kg;
		this->gen = p.gen;
	}

	Persoana& operator=(const Persoana& p) {
		if (this != &p) { //pt a evita cazul: p2=p2
			this->nume = p.nume;
			this->telefon = p.telefon;
			this->CNP = p.CNP;
			this->varsta = p.varsta;
			this->kg = p.kg;
			this->gen = p.gen;
		}

		return *this; // (indirectare) se returneaza obiectul de la adresa din pointerul this
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.empty()) {
			throw new exception("Numele are dim 0");
		}

		this->nume = nume;
	}

	string getTelefon() {
		return this->telefon;
	}

	void setTelefon(string telefon) {
		if (telefon.length() != 10) {
			throw new exception("Telefonul nu are dim 10");
		}

		this->telefon = telefon;
	}

	string getCNP() {
		return this->CNP;
	}

	void setCNP(string CNP) {
		if (CNP.length() != 13) {
			throw new exception("CNP nu are dim 13");
		}

		this->CNP = CNP;
	}

	int getVarsta() const {
		return this->varsta;
	}

	void setVarsta(int varsta) {
		if (varsta < 6) {
			throw new exception("Persoana trebuia sa fie la gradinita.");
		}

		this->varsta = varsta;
	}

	float getKg() {
		return this->kg;
	}

	void setKg(float kg) {
		if (kg < 30.5) {
			throw new exception("Persoana este prea slaba.");
		}

		this->kg = kg;
	}

	GEN getGen() {
		return this->gen;
	}

	void setGen(GEN gen) {
		if (gen == OTHER) {
			throw new exception("Gen OTHER not supported.");
		}

		this->gen = gen;
	}

	void afisare() {
		cout << "ID: " << this->ID
			<< " , Nume: " << this->nume
			<< " , telefon: " << this->telefon
			<< " , CNP: " << this->CNP
			<< " , varsta: " << this->varsta
			<< " , kg: " << this->kg
			<< " , gen: " << this->genToString(this->gen)
			<< " , universitate: " << this->universitate << endl << endl;
	}

	string genToString(GEN gen) const {
		switch (gen)
		{
		case FEMEIE:
			return "Femeie";
		case BARBAT:
			return "Barbat";
		case OTHER:
			return "OTHER";
		}
	}

	GEN stringToGEN(string value) {
		if (value == "Femeie") {
			return FEMEIE;
		}
		else if(value=="Barbat"){
			return BARBAT;
		}
		else {
			return OTHER;
		}
	}

	friend void metodaPrietena(); //functie prietena
	friend class Curs; //clasa prietena 

	friend ostream& operator<<(ostream& out, const Persoana& p);
	friend istream& operator>>(istream& in, Persoana& p);
};

string Persoana::universitate = "ASE";

ostream& operator<<(ostream& out, const Persoana& p) {
	out << "ID: " << p.ID << " Nume: " << p.nume << " , telefon: " << p.telefon << " , CNP:"<< p.CNP << " , varsta: " << p.varsta << " , kg: " << p.kg << " ,gen: "
		<< p.genToString(p.gen) << " universitate: " << p.universitate << endl << endl;

	return out;
}

istream& operator>>(istream& in, Persoana& p) {
	char aux[100];

	cout << "Nume: "; in.getline(aux, 100);
	p.nume = aux;

	cout << "Telefon: "; in.getline(aux, 100);
	p.telefon = aux;

	cout << "CNP: "; in.getline(aux, 100);
	p.CNP = aux;


	cout << "Varsta: "; in >> p.varsta;

	cout << "Kg: "; in >> p.kg;
	in.ignore();//golire buffer

	cout << "Gen: "; in.getline(aux, 100);
	p.gen = p.stringToGEN(aux);

	return in;
}


void metodaPrietena() {
	Persoana p;

	cout << "Pentru ca Persoana s-a imprietenit cu functia GLOBALA void metodaPrietena(); => ca avem acces la zona privata a clasei. Putem accesa CNP si nume(privati): " << p.CNP << " " << p.nume;
}

class Profesor : public Persoana {
	int aniVechime;

public:

	Profesor() : Persoana() {
		this->aniVechime = 0;
	}

	Profesor(long ID, string nume, string telefon, string CNP, int varsta, float kg, GEN gen, int aniVechime)
		:Persoana(ID, nume, telefon, CNP, varsta, kg, gen) {
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

	Student(long ID, string nume, string telefon, string CNP, int varsta, float kg, GEN gen, bool exmatriculat, int aniStudii)
		:Persoana(ID, nume, telefon, CNP, varsta, kg, gen) {
		this->exmatriculat = exmatriculat;
		this->aniStudii = aniStudii;

		this->nrNote = 0;
		this->note = nullptr;

		this->nivelStudii = new char[strlen("licenta") + 1];
		strcpy_s(this->nivelStudii, strlen("licenta") + 1, "licenta");
	}

	Student(long ID, string nume, string telefon, string CNP, int varsta, float kg, GEN gen, bool exmatriculat, int aniStudii, int nrNote, double* note, const char* nivelStudii)
		:Persoana(ID, nume, telefon, CNP, varsta, kg, gen) {
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
			cout << "note[" << i << "] = " << this->note[i] << " ";
		}
		cout << endl;

		this->afisare();
	}

	Student& operator=(Student& s) {
		if (this != &s) {
			Persoana::operator=(s);

			this->exmatriculat = s.exmatriculat;
			this->aniStudii = s.aniStudii;

			//evitare memory leaks - dezalocam inainte de realocare
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

	int getNrNote() {
		return this->nrNote;
	}

	double* getNote() {
		return this->note;
	}

	void setNote(double* note, int nrNote) {
		if (note == nullptr) {
			throw new exception("Nu poti seta nullptr pe vectorul de note.");
		}
		else {
			delete[] this->note; //eviti memory leaks

			this->nrNote = nrNote;
			this->note = new double[nrNote];
			for (int i = 0; i < nrNote; i++) {
				this->note[i] = note[i];
			}
		}
	}

	char* getNivelStudii() {
		return this->nivelStudii;
	}

	void setNivelStudii(char* nivelStudii) {
		if (nivelStudii == nullptr) {
			throw new exception("Nu poti seta nullptr pe char* nivelStudii.");
		}
		else {
			delete[] this->nivelStudii; //eviti memory leaks

			this->nivelStudii = new char[strlen(nivelStudii) + 1];
			strcpy_s(this->nivelStudii, strlen(nivelStudii) + 1, nivelStudii);
		}
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

	Profesor getProfesor() {
		return this->profesor;
	}

	void setProfesor(const Profesor& p) {
		if (p.getVarsta() > 65) {
			throw new exception("Proful trebuia sa fie la pensie.");
		}

		this->profesor = p;
	}

	Student* getStudenti() {
		return this->studenti;
	}

	void setStudenti(Student* studenti, int nrStudenti) {
		if (studenti == nullptr) {
			throw new exception("Nu poti seta nullptr pe vectorul de studenti.");
		}
		else {
			delete[] this->studenti; //eviti memory leaks

			this->nrStudenti = nrStudenti;
			this->studenti = new Student[nrStudenti];
			for (int i = 0; i < nrStudenti; i++) {
				this->studenti[i] = studenti[i];
			}
		}
	}
};

//const *p -> un pointer ce pointeaza catre o zona de memorie constanta
//*p const -> un pointer constant
// const *p const -> un pointer constant e pointeaza catre o zona de memorie constanta

void main() {
	Persoana p1;
	p1.afisare();
	p1.setNume("Vasile Popescu");
	p1.afisare();

	Persoana p2("Maria Popescu", "0764343868", "1234123412399");
	p2.afisare();

	Persoana p3(1, "Marin Georgescu", "0765545444", "1224545454", 30, 88.4, BARBAT);
	p3.afisare();

	cout << "\n\n========MOSTENIRE=======\n\n";

	Profesor prof1;
	prof1.afisareProfesor();

	Profesor prof2(2, "Madalin Ion", "0777448663", "1221212121", 40, 93.7, BARBAT, 20);
	prof2.afisareProfesor();

	Student stud1;
	stud1.afisareStudent();

	Student stud2(3, "Vasile Popescu", "0777555555", "199999999", 20, 77.7, BARBAT, false, 3);
	stud2.afisareStudent();

	Student stud3(4, "Maria Raluca", "0753533333", "223333333", 21, 57.7, FEMEIE, false, 2);
	stud3.afisareStudent();

	double note1[5] = { 10, 9, 7.5, 8, 5.6 };
	Student stud4(5, "Ioana Maria", "077444444", "100000111", 30, 51.7, FEMEIE, false, 1, 5, note1, "master");
	stud4.afisareStudent();

	double note2[5] = { 8, 9.4 , 5.5, 6, 7 };
	Student stud5(6, "Marius Georgescu", "071111111", "200000011", 33, 89.7, BARBAT, false, 2, 5, note2,
		"doctorat");
	stud5.universitate = "POLI";
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

	try {
		stud1.setNume("");
	}
	catch (exception* e) {
		cout << endl << endl << "A crapat aplicatia: " << e->what() << endl << endl;
	}
	catch (exception e) {
		cout << endl << endl << "A crapat aplicatia: " << e.what() << endl << endl;
	}
	catch (int e) {
		cout << endl << endl << "A crapat aplicatia: " << e << endl << endl;
	}

	cout << endl << endl << " op << si >> " << endl << endl;

	cout << stud4 << endl;

	cin >> stud4; cout << endl;

	cout << stud4 << endl;
}