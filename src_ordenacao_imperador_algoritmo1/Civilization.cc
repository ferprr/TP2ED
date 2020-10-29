#include "headers/Civilization.h"
#include <string>

using std::string;

Civilization::Civilization() {
    setDc(0);
    setPc(0);
}
void Civilization::setDc(int dc){
    this->dc = dc;
}
void Civilization::setPc(int pc){
    this->pc = pc;
}
int Civilization::getDc(){
    return this->dc;
}
int Civilization::getPc() {
    return this->pc;
}
void Civilization::setPlanet(string name){
    this->planet = name;
}
string Civilization::getPlanet(){
    return this->planet;
}
Civilization::~Civilization() {}
