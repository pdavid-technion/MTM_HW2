#include <iostream>
#include "Pirate.h"
#include <cstring>

using std::cout, std::endl;


int main() {

<<<<<<< HEAD
    Pirate luffy("Luffy", 1000000);
    Pirate zoro("Zoro", 500000);
=======
    Pirate luffy("Luffy", GUM_GUM_FRUIT);
    Pirate zoro("Zoro");
>>>>>>> origin/devil_fruit

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
