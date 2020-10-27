#ifndef MASODIK
#define MASODIK

#include <string>

class Warrior {
    public:
        Warrior():name("Default"),dmg(10),hpw(10){}
        Warrior(const std::string& name, int hp, int mana, int dmg=0, int hpw=0);
        bool isAlive() const;
        std::string toString() const;
        void attack(Warrior& defender) const;
        void heal(Warrior& other);
        std::string getName() const;
    
    private:
        const std::string name;
        int hp;
        int mana;
        const int dmg;
        const int hpw;
};


void printCombatStatus(const Warrior& w1, const Warrior& w2);

#endif

