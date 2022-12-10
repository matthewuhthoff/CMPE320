/*
 * insultgenerator_20mau.cpp
 *
 *      Author: Matthew Uhthoff
 *      20235338
 *      Implementation file for CMPE320 assignment 1.
 */
#include "insultgenerator_20mau.h"
#include <iostream>
#include <fstream> // std::ifstream, std::ofstream
#include <sstream> // std::stringstream
#include <random> // std::srand, std::rand
#include <algorithm> // std::sort
#include <ctime> // std::time

void InsultGenerator::initialize(){
    std::string lineText;
    std::string fileName = "InsultsSource.txt";
    std::ifstream myFile(fileName);

    if (!myFile.is_open()) {
        throw FileException(fileName);
    }
    else {
        while (myFile.good()) {
            std::string lineAdjectives[3];
            std::getline(myFile, lineText);
            std::stringstream lineStream(lineText); // conversion for parcing of line
            int i = 0;
            while (lineStream.good() && i < 3) {
                lineStream >> lineAdjectives[i];
                lineAdjectives[i].insert(0, " "); // add to start of adjective " " for simplicity
                ++i;
            }     
            adjective1.emplace_back(lineAdjectives[0]);
            adjective2.emplace_back(lineAdjectives[1]);
            adjective3.emplace_back(lineAdjectives[2]);
        }

    }
}

/// @brief generate function that creates a random insult, checks for uniqueness and adds to existing string in alphabetical position
/// @param numInsults 
/// @return vector of unique, sorted insults
std::vector<std::string> InsultGenerator::generate(int numInsults) {
    std::vector<std::string> storedInsults;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // initializing seed
    if (numInsults < 0 || numInsults > 10000) { // bounds check
        throw NumInsultsOutOfBounds(numInsults);
    }
    else {
        storedInsults.emplace_back(talkToMe()); // need to add first insult, otherwise iterator can't work
        while (storedInsults.size() < numInsults) {
            int rando;
            std::string insult = "";
            rando = std::rand() % (adjective1.size() - 1); // generation of random number
            insult += startInsult;
            insult += adjective1.at(rando);

            rando = std::rand() % (adjective2.size() - 1);
            insult += adjective2.at(rando);

            rando = std::rand() % (adjective3.size() - 1);
            insult += adjective3.at(rando);

            insult += endInsult;

            auto addIter = std::upper_bound(storedInsults.begin(), storedInsults.end(), insult); // return iterator pointing to where new insult should join alphabetically
            if (insult != *(addIter)){ // check uniqueness
                storedInsults.insert(addIter, insult);
            }
        }
    }
    return storedInsults;
}

/*
/// @brief generate function that loops the specified number of times, creating insults without checking for uniqueness, then erase 
///        duplicates and sort alphabtically, finally if any elements were removed, fill the remaining space in the vector in the manor described in the previous 
///        version of the function
///        This version of the function is far more efficient but in my opinion less readable and maintainable
/// @param numInsults 
/// @return vector of unique, sorted insults
std::vector<std::string> InsultGenerator::generate(int numInsults) {
    std::vector<std::string> storedInsults;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    if (numInsults < 0 || numInsults > 10000) {
        throw NumInsultsOutOfBounds(numInsults);
    }
    else {
        for (int i = 0; i < numInsults; ++i) {
            int rando;
            std::string insult = "";
            rando = std::rand() % (adjective1.size() - 1);
            insult += startInsult;
            insult += adjective1.at(rando);

            rando = std::rand() % (adjective2.size() - 1);
            insult += adjective2.at(rando);

            rando = std::rand() % (adjective3.size() - 1);
            insult += adjective3.at(rando);            

            insult += endInsult;
            
            storedInsults.emplace_back(insult);
        }
    }
    storedInsults.erase(std::unique(storedInsults.begin(), storedInsults.end()), storedInsults.end());

    std::sort(storedInsults.begin(), storedInsults.end(), [](const std::string str1, const std::string str2) {
        return str2 > str1;
    });
    while (storedInsults.size() < numInsults){
        std::string addInsult = talkToMe();
        auto addIter = std::upper_bound(storedInsults.begin(), storedInsults.end(), addInsult);
        if (addInsult != *(addIter)){
            storedInsults.insert(addIter, addInsult);
        }
    }
    return storedInsults;
}
*/

/// @brief given a file path, save generated insults to a txt file
/// @param filePath 
/// @param numInsults 
void InsultGenerator::generateAndSave(std::string filePath, int numInsults) {
    std::ofstream myFile(filePath);
    std::vector<std::string> insultList = generate(numInsults);
    if (myFile.is_open()){
        for (const auto& insult : insultList){
            myFile << insult << "\n";
        }
    }
    myFile.close();
}

/// @brief method to create a unique insult
/// @return insult as string
std::string InsultGenerator::talkToMe(){
    int rando;
    std::string returnString = "";

    returnString += startInsult;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    rando = std::rand() % (adjective1.size() - 1);
    returnString += adjective1.at(rando);

    rando = std::rand() % (adjective2.size() - 1);
    returnString += adjective2.at(rando);

    rando = std::rand() % (adjective3.size() - 1); 
    returnString += adjective3.at(rando);

    returnString += endInsult;
    return returnString;
}

/// @brief constructor to retain information about error
/// @param impossibleNumber 
NumInsultsOutOfBounds::NumInsultsOutOfBounds(int impossibleNumber){
    incompatibleNumInsults = impossibleNumber;
}

/// @return string describing error
std::string NumInsultsOutOfBounds::what(){
    std::string returnString = "";
    returnString += "It it not possible to create ";
    returnString += std::to_string(incompatibleNumInsults);
    returnString += " insults";
    return returnString;
}

/// @brief constructor to retain information about error
/// @param wrongFileName 
FileException::FileException(std::string wrongFileName){
    incorrectFileName = wrongFileName;
}

/// @return string describing error
std::string FileException::what(){
    std::string returnString = "";
    returnString += "Could not open the file ";
    returnString += incorrectFileName;
    return returnString;
}