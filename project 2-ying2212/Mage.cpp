
/*************************************************
 * @author:  Guan Ying Goh       
 * @date:  09-13-23
 * @discription:  Mage.cpp
 * @instructor:   Professor Ligorio
 ************************************************/

#include "Mage.hpp"

#include "Character.hpp"
#include <string>

#include <cctype>

/**
 * Default constructor.
 * Default-initializes all private members.
 * Default character name: "NAMELESS". Booleans are default-initialized to False.
 * Default school of magic and weapon: "NONE".
 */
Mage::Mage() {
    this->name_ = "NAMELESS";
    this->race_ = "NONE";
    this->vitality_ = 0;
    this->level_ = 0;
    this->armor_ = 0;
    this->enemy_ = false;
    setSchool("NONE");
    setCastingWeapon("NONE");
    can_summon_incarnate = false;
}

/**
 * Parameterized constructor.
 * @param      : The name of the character (a const string reference)
 * @param      : The race of the character (a const string reference)
 * @param      : The character's vitality (an integer). Default to 0
 * @param      : The character's max armor level (an integer). Default to 0
 * @param      : The character's level (an integer). Default to 0
 * @param      : A flag indicating whether the character is an enemy. Default to false.
 * @param      : The character's school of magic (a const string reference). Valid schools:
 *                [ELEMENTAL, NECROMANCY, ILLUSION].
 *                String inputs can be in lowercase, but must be converted to
 *                uppercase when setting the variable.
 *                If the school name is invalid, set it to "NONE"
 * @param      : The character's choice of weapon (a const string reference).
 *                Valid weapons: [WAND, STAFF]
 *                String inputs can be in lowercase, but must be converted to
 *                uppercase when setting the variable.
 *                If the weapon is invalid, set it to "NONE"
 * @param      : A flag indicating whether the character is able to summon an
 *                incarnate. Default to false.
 * @post       : The private members are set to the values of the corresponding
                 parameters.
                 REMEMBER: If the school of magic or weapon is not provided or invalid, the
                 variables should be set to "NONE".
 */
Mage::Mage(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string school_of_magic, const std::string weapon, bool can_summon_incarnate)
{
    setName (name);
    setRace (race);
    setVitality (vitality);
    setArmor (armor);
    setLevel (level);
    enemy_ = enemy;
    setSchool(school_of_magic);
    setCastingWeapon(weapon);
    setIncarnateSummon(can_summon_incarnate);
}

/**
 * @param  : a reference to a string representing the school of magic
 * @post   : sets the private member variable to the value of the parameter. If
 *           the provided school of magic is not one of the following: [ELEMENTAL,
 *           NECROMANCY, ILLUSION], do nothing and return false.
 *           String inputs can be in lowercase, but must be converted to
 *           uppercase when setting the variable.
 * @return  : true if setting the variable was successful, false otherwise.
 */
bool Mage::setSchool(const std::string & magic) {
    std::string magic_;
    for (int i=0;i<magic.length();i++) {
        char c = magic[i];
        magic_ += std::toupper(c);
    }
    if (magic_ == "ELEMENTAL" || magic_ == "NECROMANCY" || magic_ == "ILLUSION") {
        school_of_magic = magic_;
        return true;
    } else {
        return false;
    }
}

/**
 * @return  : the string indicating the character's school of magic
 */
std::string Mage::getSchool() const{
    return school_of_magic;
}

/**
 * @param  : a reference to a string representing the character's weapon
 * @post   : sets the private member variable to the value of the parameter.
 *           String inputs can be in lowercase, but must be converted to
 *           uppercase when setting the variable.
 *           If the provided weapon is not one of the following:
 *           [WAND, STAFF], do nothing and return false.
 * @return  : true if setting the variable was successful, false otherwise.
 */
bool Mage::setCastingWeapon(const std::string & weapons_) {
    std::string weapons;
    for(int i=0; i<weapons_.length(); i++ ){
        char c = weapons_[i];
        weapons += std::toupper(c);
    }
    if (weapons == "WAND" || weapons == "STAFF") {
        weapon_ = weapons;
        return true;
    }
    else{
        return false;
    }
}

/**
 * @return  : the string indicating the character's weapon
 */
std::string Mage::getCastingWeapon() const{
  return weapon_;
}

/**
 * @param  : a reference to boolean
 * @post   : sets the private member variable indicating whether the character can
 *           summon an incarnate
 */
void Mage::setIncarnateSummon(bool summon_incarnate) {
    can_summon_incarnate = summon_incarnate;
}

bool Mage::hasIncarnateSummon() const {
    return can_summon_incarnate;
}
