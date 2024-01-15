/*
CSCI235 Fall 2023
Project 6 - Tavern Class
Georgina Woo
June 20 2023
Edited by: Guan Ying Goh
This is the modified Tavern.cpp
Taven.cpp declares the Tavern class along with its private and public members
*/
#include "Tavern.hpp"
#include <queue>
#include <algorithm>
#include <stack>
#include <limits> 


/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}
{
}



/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows:
      Name: An uppercase string
      Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
      Vitality/Armor/Level: A positive integer
      Enemy: 0 (False) or 1 (True)
    
    @post: Each line of the input file corresponds to a Character that enters the Tavern.
  */
    Tavern::Tavern(const std::string& filename)
    {
      std::ifstream fin(filename);
      std::string line;
      std::getline(fin, line);
      std::string name, race, string_vitality, string_armor, string_level, string_enemy;
      int vitality, armor, level;
      bool enemy;
      
      while(std::getline(fin, line))
      {
        std::istringstream iss(line);
        std::getline(iss, name, ',');
        std::getline(iss, race, ',');

        std::getline(iss, string_vitality, ',');
        std::istringstream(string_vitality) >> vitality;

        std::getline(iss, string_armor, ',');
        std::istringstream(string_armor) >> armor;

        std::getline(iss, string_level, ',');
        std::istringstream(string_level) >> level;

        std::getline(iss, string_enemy, ',');
        std::istringstream(string_enemy) >> enemy;
        Character* character = new Character(name, race, vitality, armor, level, enemy);
        enterTavern(character);
      }
    }


/** 
    @param:   A reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to items_, false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(Character* a_character)
{
  if(add(a_character))
  {
    level_sum_ += a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_++;
     
    return true;
  }
  else
  {
    return false;
  }
}

/** @param:   A reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from items_, false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(Character* a_character)
{
  if(remove(a_character))
  {
    level_sum_ -= a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_--;
      
    return true;
  }
  return false;
}


/** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int Tavern::getLevelSum()
    {
      return level_sum_;
    }



/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, and returns the integer value.
**/
int Tavern::calculateAvgLevel()
{
   return (level_sum_>0) ? round(double(level_sum_) / item_count_) : 0.0;

}



/** 
    @return:  The integer enemy count of the Tavern
    **/
    int Tavern::getEnemyCount()
    {
      return num_enemies_;
    }



/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, and returns the double value.
**/
double Tavern::calculateEnemyPercentage()
{
  double enemy_percent = (num_enemies_>0) ?  (double(num_enemies_) / item_count_) * 100: 0.0;
  return std::ceil(enemy_percent*100.0) / 100.0; //round up to to decimal places
 
}


/** 
    @param:   A string reference to a race 
    @return:  An integer tally of the number of characters in the Tavern of the given race
**/
int Tavern::tallyRace(const std::string &race)
{
  int frequency = 0;
  int curr_index = 0;   
  while (curr_index < item_count_)
  {
    if (items_[curr_index]->getRace() == race)
    {
      frequency++;
    } 

    curr_index++; 
  }

  return frequency;
}


/**
  @post:    Outputs a report of the characters currently in the tavern in the form:
  "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n\n"

  Example output: 
  Humans: 5
  Elves: 8
  Dwarves: 3
  Lizards: 7
  Undead: 2

  The average level is: 16
  24% are enemies.
*/
void Tavern::tavernReport()
{
  int humans = tallyRace("HUMAN");
  int elves = tallyRace("ELF");
  int dwarves = tallyRace("DWARF");
  int lizards = tallyRace("LIZARD");
  int undead = tallyRace("UNDEAD");
  
  std::cout << "Humans: " << humans << std::endl;
  std::cout << "Elves: " << elves << std::endl;
  std::cout << "Dwarves: " << dwarves << std::endl;
  std::cout << "Lizards: " << lizards << std::endl;
  std::cout << "Undead: " << undead << std::endl;
  std::cout << "\nThe average level is: " << calculateAvgLevel() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << calculateEnemyPercentage() << "% are enemies.\n\n";
}


/**
    @post: For every character in the tavern, displays each character's information
*/
void Tavern::displayCharacters()
{
  for(int i = 0; i < item_count_; i++)
  {
    items_[i]->display();
  }
}


/**
    @param: a string reference to a race
    @post: For every character in the tavern of the given race, displays each character's information
*/
void Tavern::displayRace(const std::string &race)
{
  for(int i = 0; i < item_count_; i++)
  {
    if(items_[i]->getRace() == race)
    {
      items_[i]->display();
    }
  }
}


/**
    @post: all characters leave the tavern
*/
void Tavern::emptyTavern()
{
  for(int i = 0; i < item_count_; i++)
  {
    delete items_[i];
    items_[i] = nullptr;
  }
  item_count_ = 0;
}

/**
  @param: a Character pointer 
  @post: sets the Tavern's main character to the pointer that is given
*/
void Tavern::setMainCharacter(Character* character){
    main_character_ = character;
}

/**
  @return: a pointer to the main character in the Tavern, nullptr if there is no main character
*/
Character* Tavern::getMainCharacter() const{
  return main_character_;
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's level is less than the rhs Character's level
*/
bool Tavern::levelIsLess(Character* a, Character* b)const {
    if(a->getLevel() < b->getLevel()){
      return true;
    }
    return false;
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's level is greater than the rhs Character's level
*/

bool Tavern::levelIsGreater(Character* a, Character* b)const {
    if(a->getLevel() > b->getLevel()){
      return true;
    }
    return false; 
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's vitality is less than the rhs Character's vitality
*/
bool Tavern::vitalityIsLess(Character* a, Character* b) const{
    if(a->getVitality() < b->getVitality()){
      return true;
    }
    return false;
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's vitality is more than the rhs Character's vitality
*/
bool Tavern::vitalityIsGreater(Character* a, Character* b)const {
    if(a->getVitality() > b->getVitality()){
      return true;
    }
    return false;
}

/**
  @pre  : The combat queue should be emptied before the characters are added to the queue
  @param  : A string reference to a sorting filter with a default value of "NONE"
  @post   : With default filter "NONE": add every character marked as an enemy to the combat queue
    : With the filter "LVLASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their level.
    : With the filter "LVLDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their level.
    : With the filter "HPASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their vitality.
    : With the filter "HPDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their vitality.
*/
void Tavern::createCombatQueue(const std::string& filter) {
    combat_queue_ = std::queue<Character*>();
    std::vector<Character*> enemies;
    for (int i = 0; i < item_count_; ++i) {
        if (items_[i]->isEnemy()) {
            enemies.push_back(items_[i]);
        }
    }
    std::sort(enemies.begin(), enemies.end(), [this, filter](Character* a, Character* b) {
        return compareCharacters(a, b, filter);
    });
    for (Character* enemy : enemies) {
        combat_queue_.push(enemy);
    }
}

bool Tavern::compareCharacters(Character* a, Character* b, const std::string& filter) const {
    if (filter == "LVLASC") {
        return levelIsLess(a, b);
    } else if (filter == "LVLDES") {
        return levelIsGreater(a, b);
    } else if (filter == "HPASC") {
        return vitalityIsLess(a, b);
    } else if (filter == "HPDES") {
        return vitalityIsGreater(a, b);
    }
    return false;
}

/**
  @post   : returns a pointer to the Character at the front of the Combat Queue. 
          : If there are no characters in the queue, return nullptr
*/
Character* Tavern::getTarget() {
    if(!combat_queue_.empty()){
      return combat_queue_.front();
    } else{
      return nullptr;
    }
}

/**
  @post : Prints the details of each character in the combat queue in the following form:
        : (ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
*/
void Tavern::printCombatQueue() {
    while (!combat_queue_.empty()) {
        Character* enemy = combat_queue_.front(); 
        combat_queue_.pop(); 
        std::cout << "(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". \nVITALITY: " << enemy->getVitality() << " \nARMOR: " << enemy->getArmor() << "\n";
    }
}


/** 
        @post : If there are no enemies in the combat queue, do nothing.
              : Otherwise do all of the following
              :     - The action queue must be emptied before the new actions are added.
              :     - Print out the start of turn and details of the target enemy in the form:
                      : YOUR TURN\n
                      : (ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n\n 
    
              :     - Repeat the following process thrice (i.e. read three actions from input): 
              :           - Print the actions that are available to the main character, and read 
                            a non-negative number from input, corresponding to an action. 
                            Printing the available options should be of the following form. 
                            You may consider writing a helper function for this.
                            :Choose an action(1-4):\n1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n
              :           - If the input is invalid (valid inputs will be 1,2,3, or 4 only.), 
                          keep prompting for a non-negative number that is within range, by
                          printing "Invalid input. Please enter a number between 1 and 4 inclusive.\n" and prompt for input again.
              :           - When a valid action is read, 
                          it is added to the main character's action queue.    
*/
void Tavern::actionSelection() {
    if (combat_queue_.empty()) {
        return;
    }
    while (!main_character_->getActionQueue().empty()) {
      main_character_->getActionQueue().pop();
    }
    
    std::cout << "YOUR TURN\n";
    Character* targetEnemy = combat_queue_.front();
    std::cout << "(ENEMY) " << targetEnemy->getName() << ": LEVEL " << targetEnemy->getLevel()
              << " " << targetEnemy->getRace() << ". \nVITALITY: " << targetEnemy->getVitality()
              << "\nARMOR: " << targetEnemy->getArmor() << "\n\n";
    // Repeat thrice
    for (int i = 0; i < 3; i++) {
        int action;
        std::cout << "Choose an action (1-4):\n1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n";
        std::cin >> action;
        while (action < 1 || action > 4) {
            std::cout << "Invalid input. Please enter a number between 1 and 4 inclusive.\n";
            std::cin >> action;
        }
        Action actionEnum;
        switch (action) {
            case 1: actionEnum = BUFF_Heal; break;
            case 2: actionEnum = BUFF_MendMetal; break;
            case 3: actionEnum = ATT_Strike; break;
            case 4: actionEnum = ATT_ThrowTomato; break;
        }
        main_character_->getActionQueue().push(actionEnum);
    }

}



/**
        @post : If there are no actions in the main character's action queue, 
                or there are no enemies in the combat queue, do nothing.
                
                Otherwise do all of the following:            
                
                1. If the Buff stack is not empty, apply the buff once and decrement the turns.
                   Any time a Buff's turns_ goes to zero, it is removed
                   from the stack. Print out the results of the action as described below.
                2. While there are actions on the action queue:
                - take the next action off the queue
                - if the next action is  a buff, apply once and push it onto the buff stack after 
                  decrementing the turns. 
                  BUFF_Heal lasts for 3 turns in total, while BUFF_MendMetal lasts
                  for 2 turns in total. Print out the results of the action as described below.
                - if the next action is an attack, execute it against the enemy at the front of
                  the combat queue. Print out the results of the action as described below. 
                 - if after this action there are no more enemies to fight, clear the action
                   queue and return.
                3. Print "END OF YOUR TURN\n" 

          
            : More details:
        
            : After applying each action, print out the results of the action as follows:
            : [MAINCHARACTER NAME] used [ACTION NAME]!
            : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
            : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 

             Where [ACTION NAME] is one of [Heal, MendMetal, Strike, ThrowTomato]
            
            :   Whenever an enemy's vitality becomes <=0 after an attack, also print out 
                "[CHARACTER NAME] DEFEATED\n" 
                and remove the enemy from the combat queue AND let them exit the tavern. 
                Then carry out the remaining actions, if any, against the next enemy on the
                combat queue.
**/
void Tavern::turnResolution() {
  if (main_character_->getActionQueue().empty() || combat_queue_.empty()) {
    return;
  }

  if (!main_character_->getBuffStack().empty()) {
    Buff buff = main_character_->getBuffStack().top();
    main_character_->applyBuff(main_character_, buff);
    main_character_->getBuffStack().top().turns_ --;
    if (main_character_->getBuffStack().top().turns_ == 0) {
      main_character_->getBuffStack().pop();
    }
    Character* enemy = combat_queue_.front();
    std::cout << "\n(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \nVITALITY: " << main_character_->getVitality() << "\nARMOR: " << main_character_->getArmor() << "\n";
    std::cout << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". \nVITALITY: " << enemy->getVitality() << "\nARMOR: " << enemy->getArmor() << "\n\n";
  }
  while (!main_character_->getActionQueue().empty()) {
    Action nextAction = static_cast<Action>(main_character_->getActionQueue().front());
    main_character_->getActionQueue().pop();

    if (nextAction == BUFF_Heal) {
      Buff buff1{"BUFF_HEAL", 3};
      main_character_->getBuffStack().push(buff1);
      main_character_->getBuffStack().top().turns_--;
      main_character_->heal();
      std::cout << main_character_->getName() << " used " << "Heal" << "!";
      printCharacterDetails(combat_queue_.front());

    } else if (nextAction == BUFF_MendMetal) {
      Buff buff2{"BUFF_MendMetal", 2};
      main_character_->getBuffStack().push(buff2);
      main_character_->getBuffStack().top().turns_--;
      main_character_->mendMetal();
      std::cout << main_character_->getName() << " used " << "MendMetal" << "!";
      printCharacterDetails(combat_queue_.front());

    } else if (nextAction == ATT_Strike) {
      Character* target = combat_queue_.front();
        main_character_->strike(target);
        std::cout << main_character_->getName() << " used " << "Strike" << "!";
        printCharacterDetails(target);

        if (target->getVitality() <= 0) {
          std::cout << target->getName() << " DEFEATED\n";
          combat_queue_.pop();
          exitTavern(target);
        }
        if(combat_queue_.empty()){
          while (!main_character_->getActionQueue().empty()){
            main_character_->getActionQueue().pop();
          }
          return;
        }
    } else if (nextAction == ATT_ThrowTomato) {
      Character* target = combat_queue_.front();
        main_character_->throwTomato(target);        
        std::cout << main_character_->getName() << " used " << "ThrowTomato" << "!";
        printCharacterDetails(target);
        
        // Handle defeated enemy
        if (target->getVitality() <= 0) {
          std::cout << target->getName() << " DEFEATED\n";
          combat_queue_.pop();
          exitTavern(target);
        }
        //if no enemy, clear the action queue and return
        if(combat_queue_.empty()){
          while (!main_character_->getActionQueue().empty()){
            main_character_->getActionQueue().pop();
          }
          return;
        }
    }
  }
  std::cout << "END OF YOUR TURN\n\n" ;
}


/**
        @param  : A pointer to the enemy
        @post   : Do all of the following:
                : 1. If the enemy's buff stack is not empty, apply buff once and decrement the
                  turns. Any time a Buff's turns_ goes to zero, it is removed
                  from the stack. Print out the results of the action as described below.
                : 2. Pick a random Action 
                    (one of BUFF_Heal, BUFF_MendMetal, ATT_Strike, ATT_ThrowTomato). 
                : If the selected action is a buff, apply once immediately and add it to the 
                  enemy's buff stack, performing the necessary turns update. 
                  Print out the results of the action as described below.
                : If the selected action is an attack, execute it against the main character.
                  Print out the results of the action as described below. 
                : More details:
                
                : After applying each action, print out the results of the action as follows:
                : [ENEMY NAME] used [ACTION NAME]!
                : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
                : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
*/
void Tavern::enemyTurn(Character* enemy) {
  if (combat_queue_.empty()) {
    return; 
  }
  std::cout << "ENEMY TURN\n";
  if (!enemy->getBuffStack().empty()) {
    enemy->applyBuff(enemy, enemy->getBuffStack().top());
    Buff buff = enemy->getBuffStack().top();
    --buff.turns_;
    if (buff.turns_ == 0) {
      enemy->getBuffStack().pop();
      combat_queue_.pop();
    }
    printCharacterDetails(enemy);
  }
  int action = rand() % 4 + 1; // Generates a random number between 1 and 4
  std::string actionString;
  if (action == 1) {
    actionString = "BUFF_Heal";
    enemy->heal();
    enemy->getBuffStack().push({"BUFF_Heal",3});
    std::cout << enemy->getName() << " used " << "Heal" << "!";
    printCharacterDetails(enemy);
  } else if (action == 2) {
    actionString = "BUFF_MendMetal";
    enemy->mendMetal();
    enemy->getBuffStack().push({"BUFF_MendMetal",2});
    std::cout << enemy->getName() << " used " << "MendMetal" << "!";
    printCharacterDetails(enemy);
  } else if (action == 3) {
    actionString = "ATT_Strike";
    main_character_->strike(enemy);
    std::cout << enemy->getName() << " used " << "Strike" << "!";
    printCharacterDetails(enemy);
  } else if (action == 4) {
    actionString = "ATT_ThrowTomato";
    main_character_->throwTomato(enemy);
    std::cout << enemy->getName() << " used " << "ThrowTomato" << "!";
    printCharacterDetails(enemy);
  }
  std::cout << "END OF ENEMY TURN";
}

void Tavern::printCharacterDetails(Character* enemy){
  std::cout << "\n(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \nVITALITY: " << main_character_->getVitality() << "\nARMOR: " << main_character_->getArmor() << "\n";
  std::cout << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". \nVITALITY: " << enemy->getVitality() << "\nARMOR: " << enemy->getArmor() << "\n\n";
}

/**
        @post : While the main character's vitality is > 0, and there are still enemies 
                  in the combat queue, do the following:
              :     - Call actionSelection()
                    - Call turnResoluthtion()
                    - Call enemyTurn() with a pointer to the first enemy on combat queue.

              : If the main character's vitality has fallen to 0, print "YOU HAVE PERISHED."
              : If there are no more enemies in the combat queue, print "NO MORE ENEMIES."
*/
void Tavern::combat(){
  while (main_character_->getVitality()>0 && !(combat_queue_.empty())){
    actionSelection();
    turnResolution();
    if(!(combat_queue_.empty())){
      enemyTurn(combat_queue_.front());
    }
  }
  if(main_character_->getVitality() <= 0){
    std::cout << "YOU HAVE PERISHED.\n";
  }
  if(combat_queue_.empty()){
    std::cout << "NO MORE ENEMIES.\n";
  }
}