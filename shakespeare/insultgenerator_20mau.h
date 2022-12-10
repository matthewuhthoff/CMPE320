/*
 * insultgenerator_20mau.cpp
 *
 *      Author: Matthew Uhthoff
 *      20235338
 *      Header file for CMPE320 assignment 1.
 */
#include <string>
#include <vector>
class InsultGenerator final{
    private:
        const std::string startInsult = "Thou"; // constant words in each insult
        const std::string endInsult = "!";
        std::vector<std::string> adjective1; // use seperate vectors to store groups of insult adjectives
        std::vector<std::string> adjective2;
        std::vector<std::string> adjective3;

    public:
        void initialize();
        void generateAndSave(std::string filePath, int numInsults);
        std::string talkToMe();
        std::vector<std::string> generate(int numInsults);
};





class FileException : std::exception{
    private:
        std::string incorrectFileName; // store information concerning error

    public:
        FileException(std::string wrongFileName); // constructor with file name for detailed error message
        std::string what();

};



class NumInsultsOutOfBounds : std::exception{
    private:
        int incompatibleNumInsults; // store information concerning error


    public:
        NumInsultsOutOfBounds(int impossibleNumber); // contructor with number of insults for detailed error message
        std::string what();

};