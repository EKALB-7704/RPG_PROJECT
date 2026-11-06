#include "doctest.h"
#include "Io.h"
#include "ScriptedIo.h"


static int countOf(const std::string& haystack, const std::string& needle) {
    int count = 0;
    for (auto pos = haystack.find(needle); pos != std::string::npos;
         pos = haystack.find(needle, pos + needle.size()))
        ++count;
    return count;
}

TEST_CASE("readInt rejects bad input until it gets a number in range") {
    ScriptedIo io({"abc", "5x", "99", "3"});

    CHECK(io.readInt("> ", 1, 3) == 3);
    // one error message per rejected line
    CHECK(countOf(io.output(), "Please enter a number") == 3);
}

TEST_CASE("readYesNo rejects bad input until it gets Y or N") {
    ScriptedIo io({"", "maybe", "n"});

    CHECK_FALSE(io.readYesNo(">"));
    CHECK(countOf(io.output(), "Please enter Y or N.\n") == 2);
}

TEST_CASE("readYesNo accepts lowercase y as yes") {
    ScriptedIo io({"y"});

    CHECK(io.readYesNo(">"));
    CHECK(io.output().empty());   // accepted first time, no error printed
}

TEST_CASE("readYesNo throws when the script runs out of input") {
    ScriptedIo io({});

    CHECK_THROWS_AS(io.readYesNo(">"), std::runtime_error);
}