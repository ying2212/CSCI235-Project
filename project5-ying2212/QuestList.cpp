
/*
Name: Guan Ying Goh
Date: Oct 28
Professor Ligorio
Project 5 - Quest Management with Doubly Linked Lists 
Description: 
-You will implement the `QuestList ` class to store POINTERS to Quest objects as a subclass of DoublyLinkedList. 
-You will TEST the `QuestList ` class with the provided debug file debug.csv. 


*/

#include "QuestList.hpp"
#include "DoublyLinkedList.hpp"
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <sstream>%


/**
    Default Constructor
*/
QuestList::QuestList(): DoublyLinkedList<Quest*>() {}


/**
    @param: a reference to string name of an input file
    @pre: Formatting of the csv file is as follows:
        Title: A string
        Description: A string
        Completion Status: 0 (False) or 1 (True)
        Experience Points: A non negative integer
        Dependencies: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
        Subquests: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
    Notes:
        - The first line of the input file is a header and should be ignored.
        - The dependencies and subquests are separated by a semicolon and may be NONE.
        - The dependencies and subquests may be in any order.
        - If any of the dependencies or subquests are not in the list, they should be created as new quests with the following information:
            - Title: The title of the quest
            - Description: "NOT DISCOVERED"
            - Completion Status: False
            - Experience Points: 0
            - Dependencies: An empty vector
        - However, if you eventually encounter a quest that matches one of the "NOT DISCOVERED" quests while parsing the file, you should update all the quest details.
        Hint: update as needed using addQuest()

    @post: Each line of the input file corresponds to a quest to be added to the list. No duplicates are allowed.

*/
QuestList::QuestList(const std::string& fileName) : DoublyLinkedList<Quest*>() {
    std::ifstream infile(fileName);
    if (infile.fail()) {
        std::cerr << "Error: Unable to open input file" << std::endl;
        exit(1);
    }
    std::string lines;
    //Skip the first line and read the corresponding line
    getline(infile, lines); 
    while (getline(infile, lines)) {
        std::stringstream line(lines);
        std::string questTitle, questDescription, completionString, pointString, dependenciesString, subquestString;
        getline(line, questTitle, ',');
        getline(line, questDescription, ',');
        getline(line, completionString, ',');
        bool completion = (completionString == "1");
        getline(line, pointString, ',');
        int experiencePoints;

        //tested for errors while it is being executed.
        try {
            experiencePoints = std::stoi(pointString);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Failed to convert a string to an integer" << std::endl;
            completion = false;
            experiencePoints = 0;
        }
        // Extract and process quest dependencies.
        getline(line, dependenciesString, ',');
        std::vector<Quest*> newDependencies;
        if (dependenciesString != "NONE") {
            std::istringstream ss(dependenciesString);
            std::string dependency_;
            while (getline(ss, dependency_, ';')) {
                 // Skip empty or "NONE" dependencies.
                if (dependency_.empty() || dependency_ == "NONE") {
                    continue;
                }

                int pos = getPosOf(dependency_);
                Quest* dependenciesQuest;
                if (pos == -1) {
                    dependenciesQuest = new Quest(dependency_, "NOT DISCOVERED", false, 0, {}, {});
                    insert(item_count_, dependenciesQuest);
                } else {
                    dependenciesQuest = getPointerTo(pos)->getItem();
                }
                newDependencies.push_back(dependenciesQuest);
            }
        }
        // Extract and process subquests in a similar manner as dependencies.
        getline(line, subquestString, ',');
        std::vector<Quest*> newSubquests;
        if (subquestString != "NONE") {
            std::istringstream ss(subquestString);
            std::string subquest_;
            while (getline(ss, subquest_, ';')) {
                if (subquest_.empty() || subquest_ == "NONE") {
                    continue;
                }

                int pos = getPosOf(subquest_);
                Quest* subquestsQuest;
                if (pos == -1) {
                    subquestsQuest = new Quest(subquest_, "NOT DISCOVERED", false, 0, {}, {});
                    insert(item_count_, subquestsQuest);
                } else {
                    subquestsQuest = getPointerTo(pos)->getItem();
                }
                newSubquests.push_back(subquestsQuest);
            }
        }
        int pos = getPosOf(questTitle);
        Quest* newQuest;
        if (pos == -1) {
            newQuest = new Quest(questTitle, questDescription, completion, experiencePoints, newDependencies, newSubquests);
            insert(item_count_, newQuest);
        } else {
            // Update existing quest details if it was initially created as "NOT DISCOVERED."
            newQuest = getPointerTo(pos)->getItem();
            if (newQuest->description_ == "NOT DISCOVERED") {
                newQuest->description_ = questDescription;
                newQuest->completed_ = completion;
                newQuest->experience_points_ = experiencePoints;
            }

            newQuest->dependencies_ = newDependencies;
            newQuest->subquests_ = newSubquests;
        }
    }
    infile.close();
}


/**
    @param: A string reference to a quest title
    @return: The integer position of the given quest if it is in the QuestList, -1 if not found.
*/
int QuestList::getPosOf(const std::string& questTitle) const{
    Node<Quest*>* curr = first_;
    int position = 0;
    while (curr != nullptr) {
        Quest* name = curr->getItem();
        if (name->title_ == questTitle) {
            return position;
        }
        curr = curr->getNext();
        position++;
    }
    return -1;
}


/**
    @param: A string reference to a quest title
    @return: True if the quest with the given title is already in the QuestList
*/
bool QuestList::contains(const std::string& questTitle) const{
    Node<Quest*>* curr = first_;
    while (curr != nullptr) {
        if ( curr->getItem() != nullptr &&  curr->getItem()->title_ == questTitle) {
            return true;
        }
        curr = curr->getNext();
    }
    return false;
}


/**
    @pre: The given quest is not already in the QuestList
    @param:  A pointer to a Quest object
    @post:  Inserts the given quest pointer into the QuestList. Each of its dependencies and subquests are also added to the 
            QuestList IF not already in the list.
             If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. 
             (This happens when a quest has been added to the list through a dependency or subquest list)
    @return: True if the quest was added successfully, False otherwise
*/
bool QuestList::addQuest(Quest* quest) {
    int pos = getPosOf(quest->title_);
    if (pos == -1) {
        if (insert(pos, quest)) {
            for (Quest* dependency : quest->dependencies_) {
                addQuest(dependency);
            }
            for (Quest* subquest : quest->subquests_) {
                addQuest(subquest);
            }
            return true;
        }
    } else if (quest->description_ == "NOT DISCOVERED") {
        Quest* existingQuest = getPointerTo(pos)->getItem();
        if (existingQuest->description_ == "NOT DISCOVERED") {
            existingQuest->description_ = quest->description_;
            existingQuest->completed_ = quest->completed_;
            existingQuest->experience_points_ = quest->experience_points_;
        }
        for (Quest* dependency : quest->dependencies_) {
            addQuest(dependency);
        }
        for (Quest* subquest : quest->subquests_) {
            addQuest(subquest);
        }
        return true;
    }
    return false;
}


/**
    @param:  A reference to string representing the quest title
    @param:  A reference to string representing the quest description
    @param:  A reference to boolean representing if the quest is completed
    @param:  An reference to int representing experience points the quest rewards upon completion 
    @param:  A reference to vector of Quest pointers representing the quest's dependencies
    @param:  A reference to vector of Quest pointers representing the quest's subquests
    @post:   Creates a new Quest object and inserts a pointer to it into the QuestList. 
             If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
             Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
             

    @return: True if the quest was added or updated successfully, False otherwise

**/
bool QuestList::addQuest(const std::string& questTitle, const std::string& questDescription, const bool& completion, const int& experiencePoints,
                         const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquests) {
    std::vector<Quest*> newDependencies(dependencies.begin(), dependencies.end());
    std::vector<Quest*> newSubquests(subquests.begin(), subquests.end());
    Quest* newQuest = new Quest(questTitle, questDescription, completion, experiencePoints, dependencies, subquests);
    int pos = getPosOf(questTitle);
    if (!contains(questTitle)) {
        if (insert(pos, newQuest)) {
            return true;
        }
        //Prevent segmentation fault
        delete newQuest;
        return false;
    }
     Quest* existingQuest = getPointerTo(pos)->getItem();
    if (existingQuest->description_ == "NOT DISCOVERED") {
        existingQuest->title_ = questTitle;
        existingQuest->experience_points_ = experiencePoints;
        existingQuest->description_ = questDescription;
        existingQuest->completed_ = completion;

        for (Quest* dependency : dependencies) {                
            addQuest(dependency);
        }
        for (Quest* subquest : subquests) {
            addQuest(subquest);
        }
        return true;
    }
    return false;
}


/**
    @param:  A Quest pointer
    @return: A boolean indicating if all the given quest's dependencies are completed
*/
bool QuestList::dependenciesComplete(Quest* quest)const {
    for (Quest* dependency : quest->dependencies_) {
        if (dependency->completed_ == false) {
            return false;
        }
    }
    return true;
} 


/**
    @param: A Quest pointer
    @return: A boolean if the given quest is available.
    Note: For a quest to be available, it must not be completed, and its dependencies must be complete.
*/
bool QuestList::questAvailable(Quest* quest)const {
    if (quest->completed_ == false && dependenciesComplete(quest)) {
        return true;
    }
    return false;
}


/**
    @param: A Quest pointer
    @post: Prints the quest title and completion status
    The output should be of the form:
    [Quest Title]: [Complete / Not Complete]
    [Quest Description]\n\n
*/
void QuestList::printQuest(Quest* quest)const{
    std::cout << quest->title_ << ": " << (quest->completed_ ? "Complete\n" : "Not Complete\n");
    std::cout << quest->description_ << std::endl << std::endl;
}


/**
    @param: A string reference to a quest title
    @post:  Prints a list of quests that must to be completed before the given quest can be started (incomplete dependencies).
            If any of the quest's incomplete dependencies have an incomplete dependency, 
            recursively print the quests that need to be done in order, indenting incomplete quests. 
            The indentation for incomplete quests is 2 spaces: "  "    
            The format of the list should be of the following forms for each different case:

            Query: [Quest Title]
            No such quest.
    
            Query: [Quest Title]
            Quest Complete
    
            Query: [Quest Title]
            Ready: [Quest Title]
    
            Query: [Quest Title]
            Ready: [Dependency0]
              [Quest Title]
            
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Quest Title]
    
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Dependency2]
              [Quest Title]
              
     If the given quest title is not found in the list, print "No such quest."
*/
void QuestList::questQuery(const std::string& questTitle)const{   
    std::cout << "Query: " << questTitle << std::endl;
    int questIndex = getPosOf(questTitle);
    /*** CASE 1 ***/
    if (questIndex == -1) {
        std::cout << "No such quest." << std::endl;
        return;
    } 
    Quest* quest = getPointerTo(questIndex)->getItem();
    /*** CASE 2 ***/
    if (quest->completed_){
        std::cout << "Quest Complete" << std::endl;
        return;
    }
    /*** CASE 3 ***/
    else {
        questQueryHelper(questTitle);
    }
}


/**
    @param: A string reference to the title of the quest being queried.
    @post This function serves as a helper function for case 3.
*/
void QuestList::questQueryHelper(const std::string& questTitle) const {
    int questIndex = getPosOf(questTitle);
    Quest* quest = getPointerTo(questIndex)->getItem();
    if (!quest->completed_ && dependenciesComplete(quest)) {
        std::cout << "Ready: " << quest->title_ << std::endl;
        return;
    }
    for (Quest* dependency : quest->dependencies_) {
        if (!dependency->completed_) {
            questQueryHelper(dependency->title_); //Recursion
        }
    }
    std::cout << "  " << quest->title_ << std::endl;
}


/**
    @return: An integer sum of all the experience gained
    Note: This should only include experience from completed quests 
*/
int QuestList::calculateGainedExperience() const{
    int experienceGained = 0;
    Node<Quest*>* curr = first_;
    while (curr != nullptr) {
        if (curr->getItem()->completed_) {
            experienceGained += curr->getItem()->experience_points_;
        }
        curr = curr->getNext();
    }
    return experienceGained;
}


/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
    Note: Also consider the potential experience if a subquest itself has subquests.
*/
int QuestList::calculateProjectedExperience(Quest* mainQuest)const {
    int projectedExperience = 0;
    projectedExperience += mainQuest->experience_points_;
    for (Quest* subquest : mainQuest->subquests_) {
        projectedExperience += calculateProjectedExperience(subquest);
    }
    return projectedExperience;
}


/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
    Note: Also consider the experience gained if a completed subquest itself has subquests.  
*/
int QuestList::calculatePathwayExperience(Quest* mainQuest) const {
    int pathwayExperience = 0;
    if(mainQuest->completed_){
        pathwayExperience +=  mainQuest->experience_points_;
    }
    for (Quest* subquest : mainQuest->subquests_) {
        pathwayExperience += calculatePathwayExperience(subquest);
    }

    return pathwayExperience;
}


/**
    @param: A string reference to a filter with a default value of "NONE".
    @post: With default filter "NONE": Print out every quest in the list.
           With filter "COMPLETE":   Only print out the completed quests in the list.
           With filter "INCOMPLETE": Only print out the incomplete quests in the list.
           With filter "AVAILABLE":  Only print out the available quests in the list.
           If an invalid filter is passed, print "Invalid Filter\n"
    Printing quests should be of the form:
    [Quest title]: [Complete / Not Complete]  
    [Quest description]\n
*/
void QuestList::questHistory(const std::string& filter)const {
    Node<Quest*>* current = first_;

    while (current != nullptr) {
        Quest* quest = current->getItem();

        if (filter == "NONE") {
            printQuest(quest);
        } else if (filter == "COMPLETE") {
            if (quest->completed_) {
                printQuest(quest);
            }
        } else if (filter == "INCOMPLETE") {
            if (!quest->completed_) {
                printQuest(quest);
            }
        } else if (filter == "AVAILABLE") {
            if (questAvailable(quest)) {
                printQuest(quest);
            }
        } else {
            std::cout << "Invalid Filter\n";
        }
        current = current->getNext();
    }
}


/**
    @param: A quest pointer to a main quest
    @post:  Outputs subquest pathway. Print quest names with two spaces ("  ") of indentation for each subquest, recursively.
            Also print the percentage of experience gained in this pathway, rounded down to the lower integer.
            The format should be of the form:
            [Main Quest] ([Pathway XP] / [Projected XP]% Complete)
                [Subquest0]: [Complete / Not Complete]
                    [Sub-Subquest01]: [Complete / Not Complete]
                        [Sub-Subquest011]: [Complete / Not Complete]
                    [Subquest02]: [Complete / Not Complete]
            Hint: You can write a helper function to print the subquests recursively. If the given quest is already marked as completed, you can assume that all of its subquests are also completed.
*/
void QuestList::printQuestDetails(Quest* mainQuest)const{
    int pathwayExperience = calculatePathwayExperience(mainQuest);
    int projectedExperience = calculateProjectedExperience(mainQuest);
    int completionPercent = ( pathwayExperience * 100) / projectedExperience;
    if(mainQuest->completed_){
        completionPercent = 100;
    }
    std::cout << mainQuest->title_ << " (" << completionPercent << "% Complete)" << std::endl ;
    if(!mainQuest->completed_){
        printSubquests(mainQuest,1);
    }
}


/**
   @param:  A pointer to the quest whose subquests are to be printed.
   @param:  An integer indicating the level of indentation for the current subquests.
 
   @post Work as a helper function to print each subquest title with two spaces ("  ") of indentation for each level.
         Additionally, it prints whether each subquest is marked as "Complete" or "Not Complete."
 */
void QuestList::printSubquests(Quest* quest, int indent)const {
    for (int i = 0; i < quest->subquests_.size(); i++) {
        for (int i = 0; i < indent; i++) {
            std::cout << "  ";
        }
        std::cout << quest->subquests_[i]->title_ << ": " << (quest->subquests_[i]->completed_ ? "Complete" : "Not Complete") << std::endl;
        printSubquests(quest->subquests_[i],indent+1);     
    }
}