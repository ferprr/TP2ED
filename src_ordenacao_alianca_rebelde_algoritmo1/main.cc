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

void quicksort(vector<Civilization> &civilizations, int begin, int end) {

    int i, j;
    Civilization pivo, aux;
	i = begin;
	j = end-1;
	pivo = civilizations[(begin + end) / 2];

	while(i <= j)
	{
        while((civilizations[i].getDc() < pivo.getDc()) || (civilizations[i].getDc() == pivo.getDc() && pivo.getPc() < civilizations[i].getPc())) {
			    i++;
		}
        while((civilizations[j].getDc() > pivo.getDc()) || (civilizations[j].getDc() == pivo.getDc() && pivo.getPc() > civilizations[j].getPc())) {
			    j--;
		}

		if(i <= j)
		{
			aux = civilizations[i];
			civilizations[i] = civilizations[j];
			civilizations[j] = aux;
			i++;
			j--;
		}
	}
	if(j > begin)
		quicksort(civilizations, begin, j+1);
	if(i < end)
		quicksort(civilizations, i, end);
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

    //ordenação por quicksort
    quicksort(civilizations, 0, total_civilizations);

    for (int i=0; i< total_civilizations; i++){
        cout << civilizations[i].getPlanet() << " ";
        cout << civilizations[i].getDc() <<  " ";
        cout << civilizations[i].getPc() << endl;
    }
}
