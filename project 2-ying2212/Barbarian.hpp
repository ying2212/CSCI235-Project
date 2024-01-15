
/*************************************************
 * @author:  Guan Ying Goh       
 * @date:  09-13-23
 * @discription:  Barbarian.hpp
 * @instructor:   Professor Ligorio
 ************************************************/
 
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Character.hpp"
#include <string>

class Barbarian : public Character{
    private:
    /** 
        - A string representing their main weapon
        - A string representing their offhand weapon
        - A boolean indicating if they are enraged
    **/
        std::string name_;
        std::string race_;
        int vitality_;
        int armor_;
        int level_;
        bool enemy_;
        std::string main_weapon_;
        std::string secondary_weapon_;
        bool enraged_;
    
    public:
    /**
        Default constructor.
        Default-initializes all private members. Default character name: "NAMELESS". 
        Booleans are default-initialized to False. 
        Default weapons: "NONE". 
    */
        Barbarian();
        
    /**
        Parameterized constructor.
        @param      : The name of the character (a const string reference)
        @param      : The race of the character (a const string reference)
        @param      : The character's vitality (an integer). Default to 0
        @param      : The character's max armor level (an integer). Default to 0
        @param      : The character's level (an integer). Default to 0
        @param      : A flag indicating whether the character is an enemy. Default to false
        @param      : The character's main weapon (a const string reference). 
                      String inputs can be in lowercase, but must be converted to uppercase 
                      when setting the variable. Only alphabetical characters are allowed.
                      Default to "NONE"
        @param      : The character's offhand weapon (a const string reference). 
                      String inputs can be in lowercase, but must be converted to uppercase 
                      when setting the variable. Only alphabetical characters are allowed.
                      Default to "NONE"
        @param      : A flag indicating whether the character is enraged. Default to false
        @post       : The private members are set to the values of the corresponding parameters. 
                    : If the main and secondary weapons are not provided or invalid, the variables are set to "NONE".
    */
        Barbarian(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& firstWeapon, const std::string secondWeapon, bool enraged);
    
    /**
        @param    : a reference to a string representing the Character's main weapon
        @post     : sets the private member variable to the value of the parameter. 
                    Only alphabetical characters are allowed.
                    String inputs can be in lowercase, but must be converted to uppercase when 
                    setting the variable.
                    If the given input is invalid (i.e contains numbers), do nothing and return false
        @return   : true if setting the variable was successful, false otherwise.
    **/
        bool setMainWeapon(const std::string& firstWeapon);
        
        
    /**
        @return   : a string of the Character's main weapon
    **/
        std::string getMainWeapon() const;
        
    /**
        @param    : a reference to a string representing the Character's secondary weapon
        @post     : sets the private member variable to the value of the parameter. 
                    Only alphabetical characters are allowed.
                    String inputs can be in lowercase, but must be converted to uppercase when 
                    setting the variable.
                  : If the given input is invalid (i.e contains numbers), do nothing and return false
        @return   : true if setting the variable was successful, false otherwise.
    **/
        bool setSecondaryWeapon(const std::string& secondWeapon);
        
    /**
        @return    : a string of the Character's secondary weapon
    **/
        std::string getSecondaryWeapon() const;
        
    /**
        @param      : a reference to a bool
        @post       : sets the private member variable to the value of the parameter.
    **/
        void setEnrage(bool enraged);
        
        
    /**
        @return  : a boolean of whether the Character is enraged
    **/
        bool getEnraged() const;
        
    /**
        @post   : sets the enraged variable to the opposite of what it was
    **/
        void toggleEnrage();

};
#endif


