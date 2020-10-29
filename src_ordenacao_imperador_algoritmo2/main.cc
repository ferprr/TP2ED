#include <cstdio>
#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include "headers/Civilization.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void insertionSort(vector<Civilization> &civilizations, int total_civilizations) {

    vector<Civilization> aux;
    for (int i = 0; i < total_civilizations; i++){
        Civilization civilization;
        aux.push_back(civilization);
    }
    for (int i = 1; i < total_civilizations; i++) {
		aux[i] = civilizations[i];
		int j = i - 1;
		while (((j >= 0) && (civilizations[j].getDc() > aux[i].getDc())) || (civilizations[j].getDc() == aux[i].getDc() && civilizations[j].getPc() < aux[i].getPc())) {
			civilizations[j + 1] = civilizations[j];
			j--;
		}
		civilizations[j + 1] = aux[i];
	}
}
int main() {

    int total_civilizations;
    cin >> total_civilizations;

    vector<Civilization> civilizations;
    Civilization civilization;
    string name;
    int distance;
    int population;

    for (int i=0; i < total_civilizations; i++){
        cin >> name;
        civilization.setPlanet(name);
        cin >> distance;
        civilization.setDc(distance);
        cin >> population;
        civilization.setPc(population);

        civilizations.push_back(civilization);
    }

    //ordenação por insertion
    insertionSort(civilizations, total_civilizations);

    for (int i=0; i< total_civilizations; i++){
        cout << civilizations[i].getPlanet() << " ";
        cout << civilizations[i].getDc() << " ";
        cout << civilizations[i].getPc() << endl;
    }

}
