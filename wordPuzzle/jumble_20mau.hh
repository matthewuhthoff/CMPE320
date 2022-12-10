#include <iostream>
class JumblePuzzle{
    private:
        std::string difficulty;
        std::string keyword;
        char direction;
        int boardSize;
        int rowPosition;
        int colPosition;
        char** jumbleBoard;
        void createJumble(); // helper function to create the board

    public:
        JumblePuzzle(std::string keyword, std::string difficulty);
        JumblePuzzle(JumblePuzzle &JP);
        ~JumblePuzzle(); // big 3 included
        JumblePuzzle& operator= (JumblePuzzle &JP);
        char** getJumble();
        const int getSize();
        int getRowPos();
        const int getColPos();
        const char getDirection();
};




class BadJumbleException : std::exception{
    public:
        BadJumbleException() = default;
        std::string what();
};