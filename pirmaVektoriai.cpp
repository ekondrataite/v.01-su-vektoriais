// pirmaVektoriai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct studentas {
	string vardas;
	string pavarde;
	vector<int> pazymiai;
	float egzaminas;
	float galutinis;
};

float vidurkis(vector<int> pazymiai) {
	int suma = 0;
	int dydis = pazymiai.size();

	for (int i = 0; i < dydis; i++) {
		suma += pazymiai[i];
	}
	return suma / dydis;
}

float mediana(vector<int> pazymiai) {
	sort(pazymiai.begin(), pazymiai.end());

	if (pazymiai.size() % 2 == 0) {
		return (pazymiai[pazymiai.size() / 2 - 1] + pazymiai[pazymiai.size() / 2]) / 2;
	}
	else {
		return pazymiai[pazymiai.size() / 2];
	}
}

float galutinis_balas(float vidurkis, int egzaminas) {
	return 0.4 * vidurkis + 0.6 * egzaminas;
}

bool compareV(studentas a, studentas b) {
	return a.vardas < b.vardas;
}
bool compareP(studentas a, studentas  b) { 
	return a.pavarde < b.pavarde;
}

int main()
{
	cout << "Ar norite duomenis ivesti ar nuskaityti is failo?" << endl;
	cout << "Iveskite 'Nuskaityti', jei duomenis nuskaitysite is failo" << endl;
	cout << "Iveskite 'Ivesti', jei ranka ivesite duomenis" << endl;

	string pasirinkimas;
	cin >> pasirinkimas;

	vector<studentas> grupe;
	studentas laikinas;
	
	//failo nuskaitymas

	if (pasirinkimas == "Nuskaityti") {
		ifstream file("studentai10000.txt");

		string vardas, pavarde;
		int pazymiai;
		float egzaminas;
		int l;

		file >> l;

		for (int key = 0; key < l; key++) {
			file >> vardas;
			grupe[key].vardas;

			file >> pavarde;
			grupe[key].pavarde;

			file >> pazymiai;
			laikinas.pazymiai.push_back(key);

			file >> egzaminas;
			grupe[key].egzaminas;
		}
		return l;

		
	}

	if (pasirinkimas == "Ivesti") {
		int n = 0;

		cout << "Iveskite studentu, kuriu duomenis pildysite, skaiciu: ";
		cin >> n;

		grupe.reserve(n);

		for (int i = 0; i < n; i++) {
			cout << "Iveskite studento varda, pavarde, egzamino ivertinima: " << endl;
			cin >> laikinas.vardas >> laikinas.pavarde >> laikinas.egzaminas;

			cout << "Iveskite studento semestro namu darbu pazymius" << endl;
			cout << "Suvede visus pazymius, suveskite 'end' ir spauskite Enter" << endl;

			laikinas.pazymiai.reserve(50);
			string input = "";
			while (input != "end") {

				cin >> input;
				if (input == "end") {
					break;
				}
				laikinas.pazymiai.push_back(stoi(input));
			}
			grupe.push_back(laikinas);

			cout << "Studentas: " << laikinas.vardas << " " << laikinas.pavarde << endl;
			cout << "Egzamino ivertinimas: " << laikinas.egzaminas << endl;
			cout << "Semestro namu darbu pazymiai: ";
			for (auto& p : laikinas.pazymiai) {
				cout << p << " ";
			}
			cout << endl;
		}
	}

	cout << "Iveskite kaip norite rusiuoti duomenis" << endl;
	cout << "Jei rusiuosite pagal vardus iveskite 'V'" << endl;
	cout << "Jei rusiuosite pagal pavardes iveskite 'P'" << endl;

	string p;
	cin >> p;

	if (p == "V") {
		sort(grupe.begin(), grupe.end(), compareV);
	}
	else {
		sort(grupe.begin(), grupe.end(), compareP);
	}

	cout << "Iseitis" << endl;
	cout << "Vardas" << setw(30) << "Pavarde" << setw(30) << "Galutinis balas (vidurkis)" << setw(30);
	cout << "Galutinis balas (mediana)" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	for (auto& g : grupe) {		
		cout << g.vardas << setw(30) << g.pavarde << setw(30) << galutinis_balas(vidurkis(g.pazymiai), g.egzaminas) << setw(30);
		cout << setw(30) << galutinis_balas(mediana(g.pazymiai), g.egzaminas) << endl;
		g.pazymiai.clear();
	}
	grupe.clear();
}
