#include <iostream>
#include <fstream>
#include <vector>
int main(){

    std::vector<std::string> bwoah;
    bwoah.push_back("hello");
    bwoah.push_back("world");

    std::ofstream outfile("vectorContents.txt");
    for (const auto& i : bwoah) {
       outfile << i << "\n";
    }

    return 0;
}