/*************************************************
 * @author:  Guan Ying Goh       
 * @date:  09-13-23
 * @discription:  Scoundrel.hpp
 * @instructor:   Professor Ligorio
 ************************************************/

#ifndef SCOUNDREL_HPP
#define SCOUMDREL_HPP
#include "Character.hpp"
#include <string>

enum Dagger {WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE};

class Scoundrel: public Character{
    private:
        /**
        - A dagger
        - A string that represents their Faction
        - A boolean indicating if they have a disguise
        **/
        std::string name_;
        std::string race_;
        int vitality_;
        int armor_;
        int level_;
        bool enemy_;
        std::string dagger_;
        std::string faction_;
        bool has_disguise_;
        
    public:
        /**
        Default constructor.
        Default-initializes all private members. 
        Default character name: "NAMELESS". Booleans are default-initialized to False. 
        Default dagger: WOOD. Default faction: "NONE". 
        */
        Scoundrel();
        
        
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
        Scoundrel(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0,
              bool enemy = false, const std::string& dagger = "WOOD", const std::string& faction = "NONE",
              bool disguise = false);
        
        /**
           @param     : a reference to a string representing the dagger type
           @post      : sets the private member variable to the value of the parameter. 
                        String inputs can be in lowercase, but must be converted to 
                        uppercase when setting the variable.
                        If the dagger type is not valid (i.e, is one of the following: 
                        [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                        the variable should be set to WOOD. 
        **/
        void setDagger(const std::string& dagger);
        
        /**
          @return     : the string indicating the character's dagger type
        **/
        std::string getDagger() const;
        
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
        bool setFaction(const std::string& faction);
        
        
        /**
          @return  : the string indicating the character's Faction
        **/
        std::string getFaction() const;

        /**
          @param  : a reference to boolean
          @post   : sets the private member variable indicating whether the character has a disguise
        **/
        void setDisguise(bool& disguise);
        
        /**
          @return  : the visual aid flag
        **/
        bool hasDisguise() const;


};

#endif

