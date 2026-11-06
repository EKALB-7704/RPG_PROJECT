#include "Input.h"
#include "Io.h"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>



Io& consoleIo() {
    static ConsoleIo io;
    return io;
}

std::string readLine(const std::string& prompt)
{
    return consoleIo().readLine(prompt);
}


int readInt(const std::string& prompt, int min, int max)
{
    return consoleIo().readInt(prompt, min, max);
}



bool readYesNo(const std::string& prompt)
{
    return consoleIo().readYesNo(prompt);
}