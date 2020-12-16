/******************************************************************************
* File: frequency.c
* Purpose: This program preforms frequency analtsis on a text file
* 
* SOURCE LANGUAGE:  C
* COMPILER OPTIONS REQUIRED: NONE
* 
* ORIGINAL RELEASE 
*   AUTHOR: Jim Maroulis        
*   DATE:   March 2007
******************************************************************************/

#include <vector>
#include <fstream>
#include <iostream>

int main() {
    std::vector<char> data;

    int counts[26];
    std::ofstream outFile("test.txt");
    std::ifstream inFile("skilltest.txt");

    if(!inFile.is_open()) {
        puts("Cannot open encrypted file for reading");
        return -1;
    }

    if(!outFile.is_open()) {
        puts("Cannot open compressed file for reading");
        return -1;
    }

    while(!inFile.eof()) {
        char ch;
        inFile >> ch;
        data.emplace_back(ch);
        counts[ch - 'a']++;
    }

    std::cout << "The file size is = " << data.size() << std::endl;

    for(int i = 0; i < 26; i++) {
        outFile << "\"The count for " << i + 'a' << " = " << counts[i] << std::endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
