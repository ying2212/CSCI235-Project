#include "Character.hpp"
#include "Barbarian.hpp"
#include "Mage.hpp"
#include "Tavern.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include <iostream>

int main() {
    // //DISPLAY AND EATTAINTEDSTEW TESTED SUCCESSFUL!!!!!
    // //Testing with subclasses display() and eatTaintedStew
    // std::cout << "This is Mage Display and eatTaintedStew" << std::endl;
    // Mage SPYNACH = Mage();
    // SPYNACH.setName("SPYNACH");
    // SPYNACH.setRace("UNDEAD");
    // SPYNACH.setVitality(6);
    // SPYNACH.setArmor(4);
    // SPYNACH.setLevel(4);
    // SPYNACH.setSchool("ILLUSION");
    // SPYNACH.setCastingWeapon("WAND");
    // SPYNACH.setIncarnateSummon(true);
    // SPYNACH.display();
    // SPYNACH.eatTaintedStew();
    // std::cout << SPYNACH.getVitality() << std::endl << std::endl;

    // std::cout << "This is Ranger Display and eatTaintedStew" << std::endl;
    // Ranger MARROW = Ranger();
    // MARROW.setName("MARROW");
    // MARROW.setRace("UNDEAD");
    // MARROW.setVitality(9);
    // MARROW.setArmor(6);
    // MARROW.setLevel(5);
    // MARROW.setEnemy();
    // MARROW.addArrows("Wood",30);
    // MARROW.addArrows("Fire",5);
    // MARROW.addArrows("Water",5);
    // MARROW.addArrows("Poison",5);
    // MARROW.addAffinity("Fire");
    // MARROW.addAffinity("Poison");
    // MARROW.setCompanion(true);
    // MARROW.setCompanion(true);
    // MARROW.display();
    // MARROW.eatTaintedStew();
    // std::cout << MARROW.getVitality() << std::endl << std::endl;

    // std::cout << "This is Scoundrel Display and eatTaintedStew" << std::endl;
    // Scoundrel FLEA = Scoundrel();
    // FLEA.setName("FLEA");
    // FLEA.setRace("DWARF");
    // FLEA.setVitality(12);
    // FLEA.setArmor(7);
    // FLEA.setLevel(5);
    // FLEA.setDagger("Adamant");
    // FLEA.setFaction("Cutpurse");
    // FLEA.setDisguise(true);
    // FLEA.display();
    // FLEA.eatTaintedStew();
    // std::cout << FLEA.getVitality() << std::endl << std::endl;

    // std::cout << "This is Barbarian Display and eatTainted Stew" << std::endl;
    // Barbarian BONK = Barbarian();
    // BONK.setName("BONK");
    // BONK.setRace("HUMAN");
    // BONK.setVitality(11);
    // BONK.setArmor(5);
    // BONK.setLevel(5);
    // BONK.setEnemy();
    // BONK.setMainWeapon("MACE");
    // BONK.setSecondaryWeapon("ANOTHERMACE");
    // BONK.setEnrage(true);
    // BONK.display();
    // BONK.eatTaintedStew();
    // std::cout << BONK.getVitality() << BONK.getMainWeapon() << std::endl << std::endl;

    Tavern tavern = Tavern("characters.csv");
    tavern.displayCharacters();


    // Character* character = new Barbarian("HAPPY", "ELF", 9, 0, 8, false, "BUCKET", "TABLE",false);
    // Character* character2 = new Barbarian("MAPPY", "HUMAN", 9, 0, 8, true, "PILLOW", "TABLE",false);
    // tavern.enterTavern(character);
    // tavern.enterTavern(character2);
    // tavern.displayCharacters();
    // tavern.displayRace("HUMAN");
    return 0;
}