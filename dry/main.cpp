#include <iostream>
#include "Pirate.h"
#include <cstring>

using std::cout, std::endl;


int main() {


    Pirate luffy("Luffy", GUM_GUM_FRUIT, 1000000);
    Pirate zoro("Zoro", 500000);
    Pirate try("try", 500000);


    const int crewSize = 2;
    
    Pirate strawHatCrew[2];
    strawHatCrew[0] = luffy;
    strawHatCrew[1] = zoro;
    
    cout << "Straw Hat crew contains:" << endl;
    for (int i = 0; i < crewSize; i++) {
        cout << strawHatCrew[i] << endl;
    }

    return 0;
}