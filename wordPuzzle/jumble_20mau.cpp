#include "jumble_20mau.hh"
#include <random>
#include <ctime>
JumblePuzzle::JumblePuzzle(std::string findWord, std::string challenge){
    keyword = findWord;
    difficulty = challenge;
    if (keyword.length() < 3 || keyword.length() > 10)
        throw BadJumbleException();
    if (difficulty != "easy" && difficulty != "medium" && difficulty != "hard")
        throw BadJumbleException();
    createJumble();
}

JumblePuzzle::~JumblePuzzle(){
    for (int i = 0; i < boardSize; ++i){
        delete[] jumbleBoard[i];
    }
    delete[] jumbleBoard;
    jumbleBoard = nullptr;
}

JumblePuzzle::JumblePuzzle(JumblePuzzle &JP){
    rowPosition = JP.getRowPos();
    colPosition = JP.getColPos();
    direction = JP.getDirection();
    boardSize = JP.getSize();


    jumbleBoard = new char*[boardSize];
    for (int i = 0; i < boardSize; i++) {
        jumbleBoard[i] = new char[boardSize];
        for (int j = 0; j < boardSize; j++) {
            jumbleBoard[i][j] = JP.jumbleBoard[i][j];
        }
    }
}


char** JumblePuzzle::getJumble(){
    char** tempJumble = new char*[boardSize];
    for (int i = 0; i < boardSize; i++) {
        tempJumble[i] = new char[boardSize];
        for (int j = 0; j < boardSize; j++) {
            tempJumble[i][j] = jumbleBoard[i][j];
        }
    }
    return tempJumble;
}

JumblePuzzle& JumblePuzzle::operator=(JumblePuzzle &JP){
    if (this != &JP){
        for (int i = 0; i < boardSize; ++i){
            delete[] jumbleBoard[i];
        }
        delete[] jumbleBoard;


        rowPosition = JP.getRowPos();
        colPosition = JP.getColPos();
        direction = JP.getDirection();
        boardSize = JP.getSize();

        jumbleBoard = new char*[boardSize];
        for (int i = 0; i < boardSize; ++i){
            jumbleBoard[i] = new char[boardSize];
            for (int j = 0; j < boardSize; ++j){
                jumbleBoard[i][j] = JP.jumbleBoard[i][j];
            }
        }
    }
    return *this;
}

void JumblePuzzle::createJumble(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    boardSize = keyword.length();
    if (difficulty == "easy")
        boardSize *= 2;
    else if (difficulty == "medium")
        boardSize *= 3;
    else if (difficulty == "hard")
        boardSize *= 4;
    else {
        std::cout << "Should never get here\n";
        exit(0);
    }
    bool valid = false;
    do {
        rowPosition = std::rand() % boardSize;
        colPosition = std::rand() % boardSize;
        int dir = std::rand() % 4;
        switch (dir){
            case 0:
                direction = 'n';
                if (rowPosition - keyword.length() > 0)
                    valid = true;
                break;
            case 1:
                direction = 'e';
                if (colPosition + keyword.length() < boardSize)
                    valid = true;
                break;
            case 2:
                direction = 's';
                if (rowPosition + keyword.length() < boardSize)
                    valid = true;
                break;
            case 3:
                direction = 'w';
                if (colPosition - keyword.length() > 0)
                    valid = true;
                break;
            default:
                exit(0);
        }
    } while(!valid);

    jumbleBoard = new char*[boardSize];
    for (int i = 0; i < boardSize; ++i){
        jumbleBoard[i] = new char[boardSize];
        for (int j = 0; j < boardSize; ++j){
            char temp = static_cast<char> (97 + std::rand() % 26);
            jumbleBoard[i][j] = temp;
        }
    }
    int row = rowPosition;
    int col = colPosition;
    for (int i = 0; i < keyword.length(); ++i){
        jumbleBoard[row][col] = keyword[i];
        switch(direction){
            case 'n':
                --row;
                break;
            case 'e':
                ++col;
                break;
            case 's':
                ++row;
                break;
            case 'w':
                --col;
                break;
            default:
                exit(0);
        }
    }
}

const int JumblePuzzle::getSize(){
    return boardSize;
}

int JumblePuzzle::getRowPos(){
    return rowPosition;
}

const int JumblePuzzle::getColPos(){
    return colPosition;
}

const char JumblePuzzle::getDirection(){
    return direction;
}


std::string BadJumbleException::what(){
    return "Invalid input\n";
}