#ifndef CODESIGNAL_ARRAYS_H
#define CODESIGNAL_ARRAYS_H

#include <string>
#include <vector>

namespace interview {
    int firstDuplicate(std::vector<int> a);

    // Note: Write a solution that only iterates over the string once and uses O(1) additional memory,
    // since this is what you would be asked to do during a real interview.
    // Given a string s consisting of small English letters,
    // find and return the first instance of a non-repeating character in it. If there is no such character, return '_'.
    char firstNotRepeatingCharacter(const std::string& s);
}
#endif
