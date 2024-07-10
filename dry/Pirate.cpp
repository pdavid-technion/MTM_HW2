
#include "Pirate.h"


<<<<<<< HEAD
Pirate::Pirate(const string& name): name(name), bounty(0) {}
Pirate::Pirate(): name(""), bounty(0) {}
Pirate::Pirate(const string& name, int bounty): name(name), bounty(bounty) {}
=======
Pirate::Pirate(const string& name, DEVIL_FRUIT devilFruit): name(name), devilFruit(devilFruit) {}

>>>>>>> origin/devil_fruit

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
<<<<<<< HEAD
    os << "name: " << pirate.name << ", bounty: " << pirate.bounty;
=======
    os << pirate.name << " (Devil Fruit: " << devilFruitNames[pirate.devilFruit] << ")";
>>>>>>> origin/devil_fruit
    return os;
}

int Pirate::getBounty(){
    return this->bounty;
}

void Pirate::setBounty(int bounty){
    this->bounty = bounty;
}
