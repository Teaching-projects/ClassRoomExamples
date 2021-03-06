#include <iostream>
using namespace std;

#include "Warrior.hpp"

int main(){
    Warrior w1, w2;
    
    inputFromTerminal(w1);
    inputFromTerminal(w2);

    while ( isAlive(w1) && isAlive(w2))
    {
        printCombatStatus(w1,w2);
        attack(w1,w2);
        printCombatStatus(w1,w2);
        if (isAlive(w2)) attack(w2,w1);
    }
    printCombatStatus(w1,w2);

    cout << ( isAlive(w1) ? w1.name : w2.name ) << " wins.\n";
    
    return 0;
}
