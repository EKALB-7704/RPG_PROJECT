#pragma once

#include <stdexcept>
#include <string>
#include <utility>
#include "Io.h"
#include <vector>

class ScriptedIo : public Io {
public:
    explicit ScriptedIo(std::vector<std::string> lines)
        : lines_(std::move(lines)) {}
    void print(const std::string& t) override { out_ += t; }
    std::string readLine(const std::string&) override {
        if (next_ >= lines_.size())
            throw std::runtime_error("script exhausted");
        return lines_[next_++];
    }
    const std::string& output() const { return out_; }
private:
    std::vector<std::string> lines_;
    std::size_t next_ = 0;
    std::string out_;
};