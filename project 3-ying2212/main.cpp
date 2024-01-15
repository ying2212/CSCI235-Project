#include <iostream>
#include "Character.hpp"
#include "ArrayBag.hpp"
#include "Tavern.hpp"

int main() {
    // Create an ArrayBag of Characters
    ArrayBag<Character> characterBag;

    // Create some Character objects
    Character character1("Alice", "HUMAN", 10, 100, 37, false);
    Character character2("Bob", "DWARF", 8, 90, 60, true);
    Character character3("Charlie", "ELF", 12, 120, 40, true);
    // Character character4("Charlie", "ELF", 12, 120, 40, false);
    
    // character1.display();
    // std::cout<< std::endl;
    // character2.display();
    // std::cout<< std::endl;
    // character3.display();
    // std::cout<< std::endl;
    // character3.display();
    // std::cout<< std::endl;

    // Add characters to the ArrayBag
    // characterBag.add(character1);
    // characterBag.add(character2);
    // characterBag.add(character3);
    // characterBag.add(character4);

    // Demonstrate the usage of == and != operators
    // if (character1 == character2) {
    //     std::cout << "Character 1 is equal to Character 2." << std::endl;
    // } else {
    //     std::cout << "Character 1 is not equal to Character 2." << std::endl;
    // }
    // if (character3 == character4) {
    //     std::cout << "Character 3 is equal to Character 4." << std::endl;
    // } else {
    //     std::cout << "Character 3 is not equal to Character 4." << std::endl ;
    // }
    std::cout << std::endl;
    // Create a Tavern object
    Tavern tavern;
    tavern.tavernReport();

    // Add characters to the tavern
    tavern.enterTavern(character1);
    tavern.enterTavern(character2);
    tavern.enterTavern(character3);
    // tavern.enterTavern(character4);
    
    //Print the characters' level
    // std::cout << "The Sum of Level is: " << tavern.getLevelSum() << std::endl << std::endl;

    // Display the characters' information in the tavern
    // std::cout << "Characters in the Tavern:" << std::endl;
    tavern.tavernReport();
    
    std::cout<<std::endl<<std::endl<<tavern.getCurrentSize()<< std::endl<<std::endl;
    
    tavern.exitTavern(character1);

    std::cout<<std::endl<<std::endl<<tavern.getCurrentSize()<< std::endl<<std::endl;

    
    tavern.tavernReport();


    return 0;
}