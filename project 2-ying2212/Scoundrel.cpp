/*************************************************
 * @author:  Guan Ying Goh       
 * @date:  09-13-23
 * @discription:  Scoundrel.cpp
 * @instructor:   Professor Ligorio
 ************************************************/

#include "Scoundrel.hpp"
#include <cctype>
#include <string>

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
*/
Scoundrel::Scoundrel() {
    name_ = "NAMELESS";
    race_ = "NONE";
    vitality_ = 0;
    level_ = 0;
    armor_ = 0;
    enemy_ = false;
    setDagger("WOOD");
    setFaction("NONE");
    has_disguise_ = false;
}


	/**
            Parameterized constructor.
            @param      : The name of the character (a const string reference)
            @param      : The race of the character (a const string reference)
            @param      : The character's vitality (an integer). Default to 0
            @param      : The character's max armor level (an integer). Default to 0
            @param      : The character's level (an integer). Default to 0
            @param      : A flag indicating whether the character is an enemy. Default to false.
            @param      : The character's dagger type (a const string reference).
                          String inputs can be in lowercase, but must be converted to 
                          uppercase when setting the dagger enum. Default to WOOD
            @param      : The character's Faction (a const string reference). 
                          Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
                          String inputs can be in lowercase, but must be converted to 
                          uppercase when setting the variable. Default to "NONE"
            @param      : A flag indicating whether the character has a disguise. Default to false
            @post       : The private members are set to the values of the corresponding 
                          parameters.
                         If the dagger type is not provided or invalid, the variable should 
                          be set to WOOD. 
                         If the Faction is not provided or invalid, the variable should be 
                          set to "NONE". 
        */
Scoundrel::Scoundrel(const std::string& name, const std::string& race, int vitality, int armor, int level,bool enemy, const std::string& dagger, const std::string& faction, bool disguise){
    setName (name);
    setRace (race);
    setVitality (vitality);
    setArmor (armor);
    setLevel (level);
    enemy_ = enemy;
    setDagger(dagger);
    setFaction(faction);
    setDisguise(disguise);
}

	/**
           @param     : a reference to a string representing the dagger type
           @post      : sets the private member variable to the value of the parameter. 
                        String inputs can be in lowercase, but must be converted to 
                        uppercase when setting the variable.
                        If the dagger type is not valid (i.e, is one of the following: 
                        [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                        the variable should be set to WOOD. 
        **/
void Scoundrel::setDagger(const std::string& dagger) {
    std::string new_dagger;
    for(int i = 0; i<dagger.length();i++){
        char c = dagger[i];
        new_dagger += std::toupper(c);
    }
    if (new_dagger == "WOOD" || new_dagger == "BRONZE" || new_dagger == "IRON" || new_dagger == "STEEL" ||
        new_dagger == "MITHRIL" || new_dagger == "ADAMANT" || new_dagger == "RUNE") {
        dagger_ = new_dagger;
    } else {
        dagger_ = "WOOD";
    }
}

/**
    @return     : the string indicating the character's dagger type
**/
std::string Scoundrel::getDagger() const{
    return dagger_;
}

/**
        @param    : a reference to a string representing the character's Faction
        @post     : sets the private member variable to the value of the parameter. 
                    String inputs can be in lowercase, but must be converted to 
                    uppercase when setting the variable.
                    If the provided faction is not one of the following: 
                   [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
                   do nothing and return false.
                   @return   : true if setting the variable was successful, false otherwise.
**/

bool Scoundrel::setFaction(const std::string& faction) {
    std::string factions;
    for (int i = 0; i< faction.length() ; i++) {
        char c = faction[i];
        factions += std::toupper(c);
    }
    if (factions == "NONE" || factions == "CUTPURSE" || factions == "SHADOWBLADE" || factions == "SILVERTONGUE") {
        faction_ = factions;
        return true;
    } else {
        return false;
    }
}


/**
      @return  : the string indicating the character's Faction
**/
std::string Scoundrel::getFaction () const{
    return faction_;
}

/**
      @param  : a reference to boolean
      @post   : sets the private member variable indicating whether the character has a disguise
**/
void Scoundrel::setDisguise (bool& disguise){
    has_disguise_ = disguise;
}

/**
      @return  : the visual aid flag
**/
bool Scoundrel::hasDisguise () const{
    return has_disguise_;
}
