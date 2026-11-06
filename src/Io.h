#pragma once


#include <string>

class Io {
    public:
    virtual ~Io() = default;
    virtual void print(const std::string& text) = 0;
    virtual std::string readLine(const std::string& prompt) = 0;

    int readInt(const std::string& prompt, int min, int max);
    bool readYesNo(const std::string& prompt);
};

class ConsoleIo : public Io {

    public: 
    void print(const std::string& text) override;
    std::string readLine(const std::string& prompt) override;
};