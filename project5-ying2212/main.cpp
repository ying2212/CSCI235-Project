#include "DoublyLinkedList.hpp"
#include "QuestList.hpp"
#include "Node.hpp"
#include <iostream>

int main() {
    QuestList questList("debug.csv");
    std::cout << "Testing questQuery:" << std::endl<< std::endl;
    questList.questQuery("Quest 1");
    std::cout << std::endl;
    questList.questQuery("Quest 2");
    std::cout << std::endl;
    questList.questQuery("Quest 3");
    std::cout << std::endl;
    questList.questQuery("Quest 4");
    std::cout << std::endl;
    questList.questQuery("Quest 5");
    std::cout << std::endl;
    questList.questQuery("Quest 6");
    std::cout << std::endl;
    questList.questQuery("Quest 7");
    std::cout << std::endl;
    questList.questQuery("Quest 8");
    std::cout << std::endl;
    questList.questQuery("Quest 9");
    std::cout << std::endl;
    questList.questQuery("Quest 12");

    std::cout<<std::endl;

    std::cout << "Testing printQuestDetails:" << std::endl<< std::endl;
    Quest* current1 = questList.getPointerTo(questList.getPosOf("Quest 1"))->getItem();
    questList.printQuestDetails(current1);
    Quest* current2 = questList.getPointerTo(questList.getPosOf("Quest 2"))->getItem();
    questList.printQuestDetails(current2);
    Quest* current3 = questList.getPointerTo(questList.getPosOf("Quest 3"))->getItem();
    questList.printQuestDetails(current3);
    Quest* current4 = questList.getPointerTo(questList.getPosOf("Quest 4"))->getItem();
    questList.printQuestDetails(current4);
    Quest* current5 = questList.getPointerTo(questList.getPosOf("Quest 5"))->getItem();
    questList.printQuestDetails(current5);
    Quest* current6 = questList.getPointerTo(questList.getPosOf("Quest 6"))->getItem();
    questList.printQuestDetails(current6);
    Quest* current7 = questList.getPointerTo(questList.getPosOf("Quest 7"))->getItem();
    questList.printQuestDetails(current7);
    Quest* current8 = questList.getPointerTo(questList.getPosOf("Quest 8"))->getItem();
    questList.printQuestDetails(current8);
    Quest* current9 = questList.getPointerTo(questList.getPosOf("Quest 9"))->getItem();
    questList.printQuestDetails(current9);

    std::cout << questList.calculateGainedExperience()<<std::endl;
    std::cout << questList.calculateProjectedExperience(current3)<<std::endl;
    std::cout << questList.calculatePathwayExperience(current3)<<std::endl;
    std::cout << std::endl;
    std::cout << questList.calculateProjectedExperience(current2);
    std::cout << questList.calculatePathwayExperience(current2);
    std::cout << "q3" << questList.calculatePathwayExperience(current3);
    // questList.questHistory("NONE");
    // questList.questHistory("COMPLETE");
    // questList.questHistory("INCOMPLETE");
    // questList.questHistory("AVAILABLE");
    // questList.questHistory("JIDED");

    std::cout<<std::endl;


    // questList.KyleFullDisplay();

    return 0;
}
