
/*************************************************
 * @author:  Guan Ying Goh       
 * @date:  09-13-23
 * @discription:  test.cpp
 * @instructor:   Professor Ligorio
 ************************************************/
 
 
#include <iostream>
#include "Character.hpp" // Include the Character class header file
#include "Barbarian.hpp"
#include "Mage.hpp"
#include "Ranger.hpp"
#include "Scoundrel.hpp"

int main() {
    
    Mage mage = Mage();
    mage.setName("defaultMage");
    mage.setRace("ELF");
    mage.setVitality(5);
    mage.setArmor(3);
    mage.setLevel(2);
    mage.setEnemy();
    
    std::cout << "Name: " << mage.getName() << std::endl;
    std::cout << "Race: " << mage.getRace() << std::endl;
    std::cout << "Vitality: " << mage.getVitality() << std::endl;
    std::cout << "Armor: " << mage.getArmor() << std::endl;
    std::cout << "Level: " << mage.getLevel() << std::endl;
    std::cout << "Enemy: " << (mage.isEnemy() ? "TRUE" : "FALSE") << std::endl<<std::endl;
    
    Mage SPYNACH("SPYNACH", "ELF", 6, 4, 4,false, "ILLUSION", "WAND", true);
    std::cout << "Name: " << SPYNACH.getName() << std::endl;
    std::cout << "Race: " << SPYNACH.getRace() << std::endl;
    std::cout << "Vitality: " << SPYNACH.getVitality() << std::endl;
    std::cout << "Armor: " << SPYNACH.getArmor() << std::endl;
    std::cout << "Level: " << SPYNACH.getLevel() << std::endl;
    std::cout << "Enemy: " << (SPYNACH.isEnemy() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "School of Magic: " << SPYNACH.getSchool() << std::endl;
    std::cout << "Weapon: " << SPYNACH.getCastingWeapon() << std::endl;
    std::cout << "Summon Incarnate: " << (SPYNACH.hasIncarnateSummon() ? "TRUE" : "FALSE") << std::endl<<std::endl;
    
    Scoundrel scoundrel = Scoundrel();
    scoundrel.setName("defaultScoundrel");
    scoundrel.setRace("HUMAN");
    scoundrel.setVitality(6);
    scoundrel.setArmor(4);
    scoundrel.setLevel(3);
    scoundrel.setEnemy();
    
    std::cout << "Name: " << scoundrel.getName() << std::endl;
    std::cout << "Race: " << scoundrel.getRace() << std::endl;
    std::cout << "Vitality: " << scoundrel.getVitality() << std::endl;
    std::cout << "Armor: " << scoundrel.getArmor() << std::endl;
    std::cout << "Level: " << scoundrel.getLevel() << std::endl;
    std::cout << "Enemy: " << (scoundrel.isEnemy() ? "TRUE" : "FALSE") << std::endl<<std::endl;
    
    Scoundrel FLEA("FLEA", "DWARF", 12, 7, 5,false, "Adamant", "Cutpurse", true);
    std::cout << "Name: " << FLEA.getName() << std::endl;
    std::cout << "Race: " << FLEA.getRace() << std::endl;
    std::cout << "Vitality: " << FLEA.getVitality() << std::endl;
    std::cout << "Armor: " << FLEA.getArmor() << std::endl;
    std::cout << "Level: " << FLEA.getLevel() << std::endl;
    std::cout << "Enemy: " << (FLEA.isEnemy() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "Dagger: " << FLEA.getDagger() << std::endl;
    std::cout << "Faction: " << FLEA.getFaction() << std::endl;
    std::cout << "Disguise: " << (FLEA.hasDisguise() ? "TRUE" : "FALSE") << std::endl<<std::endl;

    Ranger ranger = Ranger();
    ranger.setName("defaultRanger");
    ranger.setRace("UNDEAD");
    ranger.setVitality(8);
    ranger.setArmor(4);
    ranger.setLevel(5);
    ranger.setEnemy();
    
    std::cout << "Name: " << ranger.getName() << std::endl;
    std::cout << "Race: " << ranger.getRace() << std::endl;
    std::cout << "Vitality: " << ranger.getVitality() << std::endl;
    std::cout << "Armor: " << ranger.getArmor() << std::endl;
    std::cout << "Level: " << ranger.getLevel() << std::endl;
    std::cout << "Enemy: " << (ranger.isEnemy() ? "TRUE" : "FALSE") << std::endl<<std::endl;
    
    Ranger MARROW = Ranger();
    MARROW.setName("MARROW");
    MARROW.setRace("UNDEAD");
    MARROW.setVitality(9);
    MARROW.setArmor(6);
    MARROW.setLevel(5);
    MARROW.setEnemy();
    MARROW.addArrows("Wood",30);
    MARROW.addArrows("Fire",5);
    MARROW.addArrows("Water",5);
    MARROW.addArrows("Poison",5);
    MARROW.addAffinity("Fire");
    MARROW.addAffinity("Poison");
    MARROW.setCompanion(true);
    MARROW.setCompanion(true);

    
    
    std::cout << "Name: " << MARROW.getName() << std::endl;
    std::cout << "Race: " << MARROW.getRace() << std::endl;
    std::cout << "Vitality: " << MARROW.getVitality() << std::endl;
    std::cout << "Armor: " << MARROW.getArmor() << std::endl;
    std::cout << "Level: " << MARROW.getLevel() << std::endl;
    std::cout << "Enemy: " << (MARROW.isEnemy() ? "TRUE" : "FALSE") << std::endl;
    const std::vector<Arrows>& arrows = MARROW.getArrows();
    for (const Arrows& arrow : arrows) {
        std::cout << "Vector of arrows: " << arrow.type_ << ", " << arrow.quantity_ << std::endl;
    }
    std::cout << "Affinities:";
    const std::vector<std::string>& affinities = MARROW.getAffinities();
    for (const std::string& affinity : affinities) {
    std::cout << "," << affinity ;
    }
    std::cout << std::endl;
    std::cout << "Animal Companion: " << (MARROW.getCompanion() ? "TRUE" : "FALSE") << std::endl << std::endl;
    
    Barbarian barbarian = Barbarian();
    barbarian.setName("defaultBarbarian");
    barbarian.setRace("HUMAN");
    barbarian.setVitality(10);
    barbarian.setArmor(5);
    barbarian.setLevel(5);
    barbarian.setEnemy();
    
    std::cout << "Name: " << barbarian.getName() << std::endl;
    std::cout << "Race: " << barbarian.getRace() << std::endl;
    std::cout << "Vitality: " << barbarian.getVitality() << std::endl;
    std::cout << "Armor: " << barbarian.getArmor() << std::endl;
    std::cout << "Level: " << barbarian.getLevel() << std::endl;
    std::cout << "Enemy: " << (barbarian.isEnemy() ? "TRUE" : "FALSE") << std::endl<<std::endl;
    
    Barbarian BONK("BONK", "HUMAN", 11, 5, 5,true, "MACE", "ANOTHERMACE", true);
    std::cout << "Name: " << BONK.getName() << std::endl;
    std::cout << "Race: " << BONK.getRace() << std::endl;
    std::cout << "Vitality: " << BONK.getVitality() << std::endl;
    std::cout << "Armor: " << BONK.getArmor() << std::endl;
    std::cout << "Level: " << BONK.getLevel() << std::endl;
    std::cout << "Enemy: " << (BONK.isEnemy() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "School of Magic: " << BONK.getMainWeapon() << std::endl;
    std::cout << "Weapon: " << BONK.getSecondaryWeapon() << std::endl;
    std::cout << "Summon Incarnate: " << (BONK.getEnraged() ? "TRUE" : "FALSE") << std::endl<<std::endl;
    
    return 0;
}
