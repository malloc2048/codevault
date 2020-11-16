// PEP 8, Style Guide for Python Code, requires a coder to write lines no longer than 79 characters.
// Given some code line, find out if it satisfies PEP 8 requirements.

#include <map>
#include <gtest/gtest.h>
#include "code_fights.h"

bool CodeFights::pep_eight(std::string line) {
    return line.size() < 80;
}

TEST(CodeFights, PepEight) {
    ASSERT_TRUE(CodeFights::pep_eight("b = a + 4"));
}
