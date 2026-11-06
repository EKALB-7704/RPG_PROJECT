#include <iostream>
#include <cctype>
#include <cstdlib>
#include <sstream>

#include "Io.h"


int Io::readInt(const std::string& prompt, int min, int max)
{
    while (true) {
        std::istringstream in(readLine(prompt));
        int value;
        char extra;
        if (in >> value && !(in >> extra) && value >= min && value <= max)
            return value;
        print("Please enter a number from " + std::to_string(min) + " to " + std::to_string(max) + ".\n");

    }
}

 bool Io::readYesNo(const std::string& prompt)
{
    while (true) {
        std::string str_in = readLine(prompt + " (Y/N): ");
        if (!str_in.empty()) {
            char c = static_cast<char>(std::toupper(static_cast<unsigned char>(str_in[0])));
            if (c == 'Y') return true;
            if (c == 'N') return false;
        }
        print("Please enter Y or N.\n");
    }
}

void ConsoleIo::print(const std::string& text) {
    std::cout << text;
}

std::string ConsoleIo::readLine(const std::string& prompt){
    std::cout << prompt;
    std::string line;
    if (!std::getline(std::cin, line)) { // Ctrl+D / closed input: otherwise loops forever
        std::cout << "\nInput closed. Exiting. \n";
        std::exit(0);
    }
    return line;
}