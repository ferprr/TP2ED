#include <cstdio>
#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <math.h>
#include "headers/Civilization.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void merge(vector<Civilization> &civilizations, int left, int middle, int right) { 
    int n1 = middle - left + 1; 
    int n2 = right - middle; 

    vector<Civilization> Left, Right;
  
    for(int i = 0; i < n1; i++) {
        Civilization civilization;
        Left.push_back(civilization);
        Left[i] = civilizations[left + i]; 
    }
    
    for(int j = 0; j < n2; j++) {
        Civilization civilization;
        Right.push_back(civilization);
        Right[j] = civilizations[middle + 1 + j]; 
    }

    int i = 0;  
    int j = 0;  
    int k = left; 
      
    while (i < n1 && j < n2) { 

        if ((Left[i].getDc() < Right[j].getDc()) || (Left[i].getDc() == Right[j].getDc() && Left[i].getPc() >= Right[j].getPc())) {
            civilizations[k] = Left[i]; 
            i++;
        } else if ((Left[i].getDc() > Right[j].getDc()) || (Left[i].getDc() == Right[j].getDc() && Left[i].getPc() <= Right[j].getPc())) {
            civilizations[k] = Right[j]; 
            j++; 
        }
        k++; 
    }  
    while (i < n1)  
    { 
        civilizations[k] = Left[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        civilizations[k] = Right[j]; 
        j++; 
        k++; 
    } 
} 
   
void mergeSort(vector<Civilization> &civilizations, int left, int right) 
{ 
    if (left < right) { 
        int middle = left + (right - left) / 2; 
        mergeSort(civilizations, left, middle); 
        mergeSort(civilizations, middle + 1, right); 
        merge(civilizations, left, middle, right); 
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

    //ordenação por mergesort
    mergeSort(civilizations, 0, total_civilizations-1);

    for (int i=0; i< total_civilizations; i++){
        cout << civilizations[i].getPlanet() << " ";
        cout << civilizations[i].getDc() << " ";
        cout << civilizations[i].getPc() << endl;
    }

}
