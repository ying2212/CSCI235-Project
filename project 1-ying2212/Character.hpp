/*
Name: Guan Ying Goh
Instructor: Professor Ligorio
Course: CSCI 235
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

enum Race { NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD };

class Character {
private:
    std::string name_;
    Race race_;
    int vitality_;
    int armor_;
    int level_;
    bool enemy_;

public:
    // Constructors
    Character();
    Character(const std::string& name, Race race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false);
    
    // Mutators
    void setName(const std::string& name);
    void setRace(Race race);
    void setVitality(int vitality);
    void setArmor(int armor);
    void setLevel(int level);
    void setEnemy();

    // Accessors
    std::string getName() const;
    std::string getRace() const;
    /*
    modified the getRace() accessor method to return the character's race as a string directly 
    instead of returning the default integral value of the enum.
    */
    int getVitality() const;
    int getArmor() const;
    int getLevel() const;
    bool isEnemy() const;
};
#endif 
