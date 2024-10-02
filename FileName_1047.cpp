#include<iostream>

using namespace std;

class Persoana {
	//by default totul e private
	string nume;
	string telefon;
	string CNP;
protected:
	int varsta;
	float kg;
private:
	bool gen;

public:
	Persoana() {
		this->nume = "numeDefault";
		this->telefon = "telefonUnknown";
		this->CNP = "randomCNP";
		this->varsta = 0;
		this->kg = 0;
		this->gen = false;
	}

	Persoana(string nume, string telefon, string CNP, int varsta, float kg, bool gen) {
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

	bool getGen() {
		return this->kg;
	}

	void setGen(bool gen) {
		this->gen = gen;
	}

	void afisare() {
		cout << "Nume: " << this->nume
			<< " , telefon: " << this->telefon
			<< " , CNP: " << this->CNP
			<< " , varsta: " << this->varsta
			<< " , kg: " << this->kg
			<< " , gen: " << this->gen << endl << endl;
	}
};

class Profesor : public Persoana {
	int aniExperienta;
};

void main() {
	Persoana p1;
	p1.afisare();
	p1.setNume("Vasile Popescu");
	p1.afisare();

	Persoana p2("Maria Popescu", "0764343868", "3223224242");
	p2.afisare();

	Persoana p3("Marin Georgescu", "0765545444", "1224545454", 30, 88.4, true);
	p3.afisare();
}