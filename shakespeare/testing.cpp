#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

int main(int argc, char** argv){

    std::system("D:/CMPE_320/foodPipeline/ConsoleApplication1.exe D:/CMPE_320/foodPipeline/hotdog.jpg");
    std::ifstream infile("labels.txt");
    std::vector<std::string> foodItems;
    std::string line;
    while (std::getline(infile, line)) {
       foodItems.push_back(line);
    }
    std::ofstream outfile("vectorContents.txt");
    for (const auto& i : foodItems) {
       outfile << i << "\n";
    }
    outfile << std::endl;
    outfile.close();


    return 0;
}