
#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    int bounty;

public:
    Pirate(const string& name);
    Pirate();
    Pirate(const string& name, int bounty);
    ~Pirate() = default;

    int getBounty();
    void setBounty(int bounty);

    void setName(const string& name);

    string getName();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
