
#include "Pirate.h"


Pirate::Pirate(const string& name): name(name), bounty(0) {}
Pirate::Pirate(): name(""), bounty(0) {}
Pirate::Pirate(const string& name, int bounty): name(name), bounty(bounty) {}

void Pirate::setName(const string& name){
    this->name = name;
}


std::string Pirate::getName(){
    return name;
}


std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << "name: " << pirate.name << ", bounty: " << pirate.bounty;
    return os;
}

int Pirate::getBounty(){
    return this->bounty;
}

void Pirate::setBounty(int bounty){
    this->bounty = bounty;
}
