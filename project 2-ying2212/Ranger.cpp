/*************************************************
 * @author:  Guan Ying Goh       
 * @date:  09-13-23
 * @discription:  Ranger.cpp
 * @instructor:   Professor Ligorio
 ************************************************/

#include "Ranger.hpp"

#include <string>

#include <cctype>

#include <vector>

/**
Default constructor.
Default-initializes all private members. Default character name: "NAMELESS". 
Booleans are default-initialized to False. 
*/
Ranger::Ranger() {
    this->name_ = "NAMELESS";
    this->race_ = "NONE";
    this->vitality_ = 0;
    this->level_ = 0;
    this->armor_ = 0;
    this->enemy_ = false;
    this->has_companion_ = false;
}

/**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false
    @param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Invalid arrows are those with non-positive quantities or invalid types.
                If the vector contains invalid arrows, those arrows are discarded. 
                Default to empty vector
    @param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
                String inputs can be in lowercase, but must be converted to uppercase.
                If the vector contains invalid affinities, those affinities are discarded.
                Default to empty vector
    @param      : A flag indicating whether the character is able to recruit an animal companion. 
                Default to false
    @post       : The private members are set to the values of the corresponding parameters
*/
Ranger::Ranger(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::vector<Arrows>& arrows, const std::vector<std::string>& affinities, bool companion){
    setName (name);
    setRace (race);
    setVitality (vitality);
    setArmor (armor);
    setLevel (level);
    enemy_ = enemy;
    setCompanion(companion);

    for (const Arrows& arrow : arrows) {
        std::string new_arrow = arrow.type_;
        
        for (char& c : new_arrow) {
            c = std::toupper(c);
        }

        if (arrow.quantity_ > 0 && (new_arrow == "WOOD" || new_arrow == "FIRE" || new_arrow == "WATER" || new_arrow == "POISON" || new_arrow == "BLOOD")) {
            this->arrows_.push_back(arrow);
        }
    }

    for (const std::string& affinity : affinities) {
        std::string new_Affinity = affinity;

        for (char& c : new_Affinity) {
            c = std::toupper(c);
        }

        if (new_Affinity == "FIRE" || new_Affinity == "WATER" || new_Affinity == "POISON" || new_Affinity == "BLOOD") {
            this->affinities_.push_back(new_Affinity);
        }
    }
}

        
/**
      @return     : a vector of the Character's arrows
**/
std::vector<Arrows> Ranger::getArrows() const{
    return arrows_;
}
        
/**
    @param    : a reference to string representing the arrow type
    @param    : a reference to an integer quantity
    @post     : If the character already has that type of arrow, the quantity in the vector 
                is updated. If not, the arrow is added to the vector. 
                Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Quantity of arrows must be greater than 0
                Invalid arrows are those with non-positive quantities or invalid types.
                If the arrows are invalid, they are not added.
    @return   : True if the arrows were added successfully, false otherwise
**/
bool Ranger::addArrows(const std::string& arrow, int quantity) {
    std::string new_arrow;
    for (int i = 0; i < arrow.length(); i++) {
        char c = arrow[i];
        new_arrow += std::toupper(c);
    }
    
    if (quantity > 0 && (new_arrow == "WOOD" || new_arrow == "FIRE" || new_arrow == "WATER" || new_arrow == "POISON" || new_arrow == "BLOOD")) {
        for (size_t i = 0; i < arrows_.size(); i++) { // Change arrows to arrows_
            if (arrows_[i].type_ == new_arrow) { // Change arrows to arrows_
                arrows_[i].quantity_ += quantity; // Change arrows to arrows_
                return true;
            }
        }
        Arrows newArrow;
        newArrow.type_ = new_arrow;
        newArrow.quantity_ = quantity;
        arrows_.push_back(newArrow); // Change arrows to arrows_
        return true; 
    }
    return false; 
}

/**
    @param    : a reference to string representing the arrow type
    @post     : If the character has the listed arrow AND enough arrows to fire one, 
            the quantity of remaining arrows in the vector is updated.
    @return   : True if the character had the listed arrow AND enough arrows, False otherwise.
**/
bool Ranger::fireArrow(const std::string& arrow) {
    std::string new_arrow;
    for (int i = 0; i < arrow.length(); i++) {
        char c = arrow[i];
        new_arrow += std::toupper(c);
    }
    
    for (size_t i = 0; i < this->arrows_.size(); i++) {
        if (this->arrows_[i].type_ == new_arrow && this->arrows_[i].quantity_ >= 1) {
            this->arrows_[i].quantity_ -= 1;
            return true;
        }
    }
    return false;
}

/**
    @param  : a reference to string representing an affinity 
    @post   : If the affinity does not already exist in the vector, add it to the vector.
              Valid Affinities: [FIRE, WATER, POISON, BLOOD] 
              String inputs can be in lowercase, but must be converted to uppercase when 
              setting the variable.
              There should be no duplicate affinities.
              If the affinity is invalid, it is NOT added.
    @return : True if the affinity was added successfully, false otherwise
**/
bool Ranger::addAffinity(const std::string& affinity) {
    std::string new_affinity;
    for (int i = 0; i < affinity.length(); i++) {
        char c = affinity[i];
        new_affinity += std::toupper(c);
    }
    
    if (new_affinity == "FIRE" || new_affinity == "WATER" || new_affinity == "POISON" || new_affinity == "BLOOD") {
        for (const std::string& existing_affinity : this->affinities_) {
            if (existing_affinity == new_affinity) {
                return false; // Affinity already exists, do not add.
            }
        }
        this->affinities_.push_back(new_affinity);
        return true;
    }
    return false;
}

/**
    @return     : a vector of the Character's affinities
**/
std::vector<std::string> Ranger::getAffinities() const {
    return affinities_;
}
        
/**
    @param    : a reference to a boolean indicating whether the character is able to recruit 
                an animal companion
    @post     : sets the private member variable to the value of the parameter.
**/
void Ranger::setCompanion(bool companion){
    has_companion_ = companion;
}

/**
    @return   : a boolean indicating whether the character is able to recruit an animal companion
**/
bool Ranger::getCompanion() const {
    return has_companion_;
}

