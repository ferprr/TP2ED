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

void selectionSort(vector<Civilization> &civilizations, int total_civilizations) {

    vector<Civilization> aux;

    for (int i = 0; i<total_civilizations; i++){
        Civilization civilization;
        aux.push_back(civilization);
    }
    for (int index = 0; index < total_civilizations; ++index) {
        int lowerIndex = index;
        for (int nextIndex = index+1; nextIndex < total_civilizations; ++nextIndex) {
            if (civilizations[nextIndex].getDc() < civilizations[lowerIndex].getDc()) {
                lowerIndex = nextIndex;
            } else if (civilizations[nextIndex].getDc() == civilizations[lowerIndex].getDc() && civilizations[nextIndex].getPc() > civilizations[lowerIndex].getPc()){
                lowerIndex = nextIndex;
            }
        }
        aux[index] = civilizations[index];
        civilizations[index] = civilizations[lowerIndex];
        civilizations[lowerIndex] = aux[index];
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

    //ordenação por selection
    selectionSort(civilizations, total_civilizations);

    for (int i=0; i< total_civilizations; i++){
        cout << civilizations[i].getPlanet() << " ";
        cout << civilizations[i].getDc() << " ";
        cout << civilizations[i].getPc() << endl;
    }

}