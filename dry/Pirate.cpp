#include "Pirate.h"

Pirate::Pirate(): name(""), bounty(0), devilFruit(DEVIL_FRUIT::NONE) {}
Pirate(const string& name, DEVIL_FRUIT devilFruit, int bounty): name(name), bounty(bounty), devilFruit(devilFruit) {}


void Pirate::setName(const string& name){
    this->name = name;
}


void Pirate::setDevilFruit(DEVIL_FRUIT devilFruit){
    this->devilFruit = devilFruit;
}


std::string Pirate::getName(){
    return name;
}


DEVIL_FRUIT Pirate::getDevilFruit(){
    return devilFruit;
}


const char* const devilFruitNames[] = {
    "Gum Gum",
    "Smoke Smoke",
    "Flame Flame",
    "Rumble Rumble",
    "String String",
    "Ice Ice",
    "None"
};

std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << "name: " << pirate.name << ", bounty: " << pirate.bounty << " (Devil Fruit: " << devilFruitNames[pirate.devilFruit] << ")";
    return os;
}

int Pirate::getBounty(){
    return this->bounty;
}

void Pirate::setBounty(int bounty){
    this->bounty = bounty;
}