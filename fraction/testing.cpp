#include <iostream>
#include <windows.h>
int main(){
    std::cout << "Hello mum\n";
    std::string file = "iesbtygau";
    std::string command = "start D:/CMPE_320/fraction/test2.exe";
    command.append(" ");
    command.append(file);
    std::system(command.c_str());

    return 0;
}