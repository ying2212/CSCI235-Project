/*************************************************
 * @author:  Guan Ying Goh       
 * @date:  09-25-23
 * @discription:  Tavern.cpp
 * @instructor:   Professor Ligorio
 ************************************************/

#include "Tavern.hpp"
#include "Character.hpp"
#include <cmath>
#include <string>
#include <iostream>

/**
    Default constructor.
    Default-initializes all private members. 
*/
Tavern::Tavern():ArrayBag<Character>(){
    sumLevels_ = 0;
    enemyCount_ = 0; 
}

/** @param:   A const reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to the tavern (i.e. items_),                 
            false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count 
              if the character is an enemy.
**/
bool Tavern::enterTavern(const Character& enterCharacter){
    if(add(enterCharacter)){
        sumLevels_ += enterCharacter.getLevel();
        if (enterCharacter.isEnemy()) {
            enemyCount_++;
        }
        return true;
    } 
    return false;
}

/** @param:   A const reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from the tavern (i.e. items_),               
            false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count
              if the character is an enemy.
**/
bool Tavern::exitTavern(const Character& exitCharacter) {
    if (remove(exitCharacter)){
        std::cout << "worked";
        sumLevels_ -= exitCharacter.getLevel();
        if(exitCharacter.isEnemy()){
            enemyCount_--;
        }
        return true;
    }
    std::cout << "didnt work";
    return false;
}
/** 
    @return:  The integer level count of all the characters currently in the Tavern
**/
int Tavern::getLevelSum() const{
    return sumLevels_;
}

/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
 **/
int Tavern::calculateAvgLevel() const {
    double sumLevel = getLevelSum() * 1.0;
    double totalCharacter = item_count_ * 1.0; 
    int roundedAverage = std::round((sumLevel / totalCharacter)/ 1.0);
    return roundedAverage;
}

/** 
    @return:  The integer enemy count of the Tavern
 **/
int Tavern::getEnemyCount() const{
    return enemyCount_;
}

/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
**/
double Tavern::calculateEnemyPercentage() const {
    double enemyPercentage = (enemyCount_ * 100.0) / item_count_;
    return std::round(enemyPercentage * 100) / 100.0; // Round to two decimal places
}


/** 
    @param:   A const reference to a string representing a character Race with value in 
              ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
    @return:  An integer tally of the number of characters in the Tavern of the given race. 
              If the argument string does not match one of the expected race values, 
              the tally is zero. NOTE: no pre-processing of the input string necessary, only                  
              uppercase input will match.
 **/
int Tavern::tallyRace(const std::string& race) const {
    int characterTally = 0;

    for (int i = 0; i < item_count_; i++) {
        if (items_[i].getRace() == race) {
            characterTally++;
        }
    }

    return characterTally;
}

/**
    @post:  Outputs a report of the characters currently in the tavern in the form:
            "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average             
            level is: [x] \n[x]% are enemies.\n"
            Note that the average level should be rounded to the NEAREST integer, and the enemy             
            percentage should be rounded to 2 decimal places.

            Example output: 
            Humans: 3
            Elves: 5
            Dwarves: 8
            Lizards: 6
            Undead: 0

            The average level is: 7
            46.67% are enemies.
*/
void Tavern::tavernReport() const {
    int human = tallyRace("HUMAN");
    int elf = tallyRace("ELF");
    int dwarf = tallyRace("DWARF");
    int lizard = tallyRace("LIZARD");
    int undead = tallyRace("UNDEAD");
    int average_level = calculateAvgLevel();
    double enemy_percentage = calculateEnemyPercentage();
    
    std::cout << "Humans: " << human << std::endl;
    std::cout << "Elves: " << elf << std::endl;
    std::cout << "Dwarves: " << dwarf << std::endl;
    std::cout << "Lizards: " << lizard << std::endl;
    std::cout << "Undead: " << undead << std::endl << std::endl;
    std::cout << "The average level is: " << average_level << std::endl;
    std::cout << enemy_percentage << "% are enemies." << std::endl;
}















