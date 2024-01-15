#include "Character.hpp"
#include "Tavern.hpp"
#include "ArrayBag.hpp"
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>

int main() {

    Tavern tavern;
    Character c1("MAINCHARACTER", "UNDEAD", 10, 5, 10, false);
    Character c2("NAAN", "HUMAN", 4, 3, 2, true);
    Character c6("SPYNACH", "ELF", 2, 1, 1, true);

    tavern.enterTavern(&c1);
    tavern.enterTavern(&c2);
    tavern.enterTavern(&c6);
    tavern.setMainCharacter(&c1);

    tavern.combat(); // combat should terminate after printing "NO MORE ENEMIES"

    tavern.createCombatQueue();

    // Call the combat function
    tavern.combat();

    c1.setVitality(100);
    c1.setArmor(100);
    tavern.exitTavern(&c2);
    Character c5("SHAPPY", "ELF", 2, 2, 2, false);
    Character c3("SECONDENEMY", "DWARF", 2, 2, 2, true);
    Character c4("NAAN", "HUMAN", 4, 3, 2, true);

    tavern.enterTavern(&c3);
    tavern.enterTavern(&c4);
    tavern.createCombatQueue("NONE");
    tavern.setMainCharacter(&c5);

    // Call the combat function again
    tavern.combat();

    return 0;
}
