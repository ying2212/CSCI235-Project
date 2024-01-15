/*
CSCI235 Summer 2023
Project 2 - Derived Classes
Georgina Woo
Jun 14 2023
Modified by: Guan Ying Goh
Scoundrel.cpp defines the constructors and private and public function implementation of the Scoundrel class
*/

#include "Scoundrel.hpp"

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
*/
Scoundrel::Scoundrel() : Character(), faction_{"NONE"}, has_disguise_{false}, dagger_{Dagger::WOOD}
{
}

/**
    Parameterized constructor.
           @param      : The name of the character (a const string reference)
           @param      : The race of the character (a const string reference)
           @param      : The character's vitality (an integer)
           @param      : The character's max armor level (an integer)
           @param      : The character's level (an integer)
           @param      : A flag indicating whether the character is an enemy
           @param      : The character's dagger type (a const string reference).
    					String inputs can be in lowercase, but must be converted to 
						uppercase when setting the dagger enum.
           @param      : The character's Faction (a const string reference). 
						Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
						String inputs can be in lowercase, but must be converted to 
						uppercase when setting the variable.
           @param      : A flag indicating whether the character has a disguise
          @post        : The private members are set to the values of the corresponding 
						parameters.
 						If the dagger type is not provided or invalid, the variable should 
						be set to WOOD. 
    	                If the Faction is not provided or invalid, the variable should be 
						set to "NONE". 
*/
Scoundrel::Scoundrel(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& dagger, const std::string& faction, bool has_disguise) 
: Character(name, race, vitality, armor, level, enemy), has_disguise_{has_disguise}
{
    setDagger(dagger);
    if(!setFaction(faction))
    {
        faction_ = "NONE";
    }
}
/**
    @param  : a reference to a string representing the dagger type
    @post   : sets the private member variable to the value of the parameter. 
            : If the dagger type is not valid (i.e, is one of the following: [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), the variable should be set to WOOD. 
**/
void Scoundrel::setDagger(const std::string& dagger)
{
    std::string dagger_upper = dagger;
    for(int i = 0; i < dagger_upper.length(); i++)
    {
        if(isalpha(dagger_upper[i]))
        {
            dagger_upper[i] = toupper(dagger_upper[i]);
        }
    }
    if(dagger_upper == "BRONZE")
    {
        dagger_ = Dagger::BRONZE;
    }
    else if(dagger_upper == "IRON")
    {
        dagger_ = Dagger::IRON;
    }
    else if(dagger_upper == "STEEL")
    {
        dagger_ = Dagger::STEEL;
    }
    else if(dagger_upper == "MITHRIL")
    {
        dagger_ = Dagger::MITHRIL;
    }
    else if(dagger_upper == "ADAMANT")
    {
        dagger_ = Dagger::ADAMANT;
    }
    else if(dagger_upper == "RUNE")
    {
        dagger_ = Dagger::RUNE;
    }
    else
    {
        dagger_ = Dagger::WOOD;
    }
}


/**
    @return  : the string indicating the character's dagger type
**/
std::string Scoundrel::getDagger() const
{
    if(dagger_ == Dagger::WOOD)
    {
        return "WOOD";
    }
    else if(dagger_ == Dagger::BRONZE)
    {
        return "BRONZE";
    }
    else if(dagger_ == Dagger::IRON)
    {
        return "IRON";
    }
    else if(dagger_ == Dagger::STEEL)
    {
        return "STEEL";
    }
    else if(dagger_ == Dagger::MITHRIL)
    {
        return "MITHRIL";
    }
    else if(dagger_ == Dagger::ADAMANT)
    {
        return "ADAMANT";
    }
    else
    {
        return "RUNE";
    }
}


/**
        @param  	: a reference to a string representing the character's Faction
        @post   	: sets the private member variable to the value of the parameter. 
    				String inputs can be in lowercase, but must be converted to 
					uppercase when setting the variable.
            	    If the provided faction is not one of the following: 
            	    [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
            	     do nothing and return false.
        @return  	: true if setting the variable was successful, false otherwise.
**/
bool Scoundrel::setFaction(const std::string& faction)
{
    std::string faction_upper = faction;
    for(int i = 0; i < faction_upper.length(); i++)
    {
        if(isalpha(faction_upper[i]))
        {
            faction_upper[i] = toupper(faction_upper[i]);
        }
    }
    if(faction_upper == "CUTPURSE" || faction_upper == "SHADOWBLADE" || faction_upper == "SILVERTONGUE" || faction_upper == "NONE")
    {
        faction_ = faction_upper;
        return true;
    }
    else
    {
        return false;
    }
}


/**
    @return  : the string indicating the character's Faction
**/
std::string Scoundrel::getFaction() const
{
    return faction_;
}

/**
    @param  : a reference to boolean
    @post   : sets the private member variable indicating whether the character has a disguise
**/
void Scoundrel::setDisguise(const bool& has_disguise)
{
    has_disguise_ = has_disguise;
}


/**
    @return  : the visual aid flag
**/
bool Scoundrel::hasDisguise() const
{
    return has_disguise_;
} 

/**
    @post     : displays Scoundrel data in the form:
    "[NAME] is a Level [LEVEL] [RACE] SCOUNDREL.
    \nVitality: [VITALITY]
    \nArmor: [ARMOR]
    \nThey are [an enemy/not an enemy].
    \nDagger: [DAGGER]
    \nFaction: [FACTION]
    \nDisguise: [TRUE/FALSE]
    \n\n"
    
    Example:
    FLEA is a Level 4 DWARF SCOUNDREL.
    Vitality: 6
    Armor: 4
    They are an enemy.
    Dagger: ADAMANT
    Faction: CUTPURSE
    Disguise: TRUE
*/
void Scoundrel::display() const {
    std::cout << Character::getName() << " is a Level " << Character::getLevel() << " " << Character::getRace() << " SCOUNDREL.";
    std::cout << "\nVitality: " << Character::getVitality();
    std::cout << "\nArmor: " << Character::getArmor() ;
    std::cout << "\nThey are " << (Character::isEnemy()? "an enemy." : "not an enemy.");
    std::cout << "\nDagger: " << getDagger() ;
    std::cout << "\nFaction: " << getFaction();
    std::cout << "\nDisguise: " << (hasDisguise() ? "TRUE\n\n" : "FALSE\n\n");
}

/**
    @post: 
    If the character is UNDEAD, gain 3 Vitality points. Nothing else happens. 
    
    If the character is NOT UNDEAD, their Vitality is set to 1. 
    In addition, as a Scoundrel: If the character is of the CUTPURSE faction, they steal a health potion and recover 3 Vitality points. 
    If they are of the SILVERTONGUE faction, they talk the cook into redoing their stew as follows: they have a 70% chance of recovering 4 Vitality points, but a 30% chance of resetting their Vitality to 1, and they lose their daggers, which are replaced with WOOD daggers. (If their daggers were already WOOD, nothing happens to the daggers). 
*/
void Scoundrel::eatTaintedStew(){
    if(getRace() == "UNDEAD"){
        int newVitality = Character::getVitality() +3;
        Character::setVitality(newVitality);
    }
    else{
        int newVitality = 1;
        Character::setVitality(newVitality);
        // In addition, as a Scoundrel:
        if(faction_ == "CUTPURSE"){
            int newVitality = Character::getVitality() + 3;
            Character::setVitality(newVitality);
        }
        else if(faction_ == "SILVERTONGUE"){
            int chance = rand() % 100;
            if(chance < 70){
                int newVitality = Character::getVitality() + 4;
                Character::setVitality(newVitality);
            }
            else{
                Character::setVitality(1);
                if(dagger_ != Dagger:: WOOD){
                    setDagger("WOOD");
                }
            }
        }
    }
}
