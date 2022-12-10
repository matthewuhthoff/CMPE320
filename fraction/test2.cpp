#include <iostream>
#include <fstream>
int main(int argc, char** argv){

    std::cout<< "Test2\n";
    std::ofstream outfile ("temperrrrr.txt");
    std::string temper = argv[1];
    //std::string temper = "ajj";
    outfile << "image file would be: " << temper << std::endl;
    outfile.close();
    return 0;
}