#include <set>
#include "intro.h"
#include <algorithm>

int Intro::Level1::add(int param1, int param2) {
    return param1 + param2;
}

int Intro::Level1::century_from_year(int year) {
    if(year % 100 == 0){
        return year / 100;
    }
    else{
        return (year / 100) + 1;
    }
}

bool Intro::Level1::check_palindrome(std::string inputString) {
    for(size_t front = 0, back = inputString.size() - 1; back > front; front++, back--){
        if(inputString[front] != inputString[back]){
            return false;
        }
    }
    return true;
}

int Intro::Level2::adjacentElementsProduct(std::vector<int> inputArray) {
    int product = inputArray[0] * inputArray[1];
    for(size_t i = 0; i < inputArray.size() - 1; i++){
        int newProduct = inputArray[i] * inputArray[i+1];
        if(newProduct > product) {
            product = newProduct;
        }
    }
    return product;
}

int Intro::Level2::shapeArea(int n) {
    int equator = n + (n - 1);
    int area = equator;
    for(auto i = 1; i != equator; i += 2) {
        area += 2 * i;
    }
    return area;
}

int Intro::Level2::makeArrayConsecutive2(std::vector<int> statues) {
    std::sort(statues.begin(), statues.end());

    int statuesNeeded = 0;
    for(size_t i = 1; i < statues.size(); i++) {
        int diff = statues[i] - statues[i - 1];
        if(diff > 1){
            statuesNeeded += diff - 1;
        }
    }
    return statuesNeeded;
}
int removeLeft(std::vector<int>& sequence){
    int problemsFound = 0;

    for (size_t i = 0; i < sequence.size() - 1; i++) {
        if(sequence[i] > sequence[i + 1]) {
            sequence.erase(sequence.begin() + i);
            problemsFound++;
            i = -1;
        }
    }
    return problemsFound;
}

int removeRight(std::vector<int>& sequence){
    int problemsFound = 0;

    for (size_t i = 1; i < sequence.size(); i++) {
        if(sequence[i] < sequence[i - 1]){
            sequence.erase(sequence.begin() + (i));
            i--;
            problemsFound++;
        }
    }
    return problemsFound;
}

int removeDuplicates(std::vector<int>& sequence){
    int removed = 0;
    std::set<int> counts;

    for(size_t i = 0; i < sequence.size(); i++){
        if(counts.end() == counts.find(sequence[i])){
            counts.insert(sequence[i]);
        }
        else{
            sequence.erase(sequence.begin() + i);
            i--;
            removed++;
        }
    }
    return removed;
}

bool Intro::Level2::almostIncreasingSequence(std::vector<int> sequence) {
    std::vector<int> sequence2 = sequence;
    int problemsFound = removeLeft(sequence);
    int moreProblemsFound = removeRight(sequence2);

    problemsFound += removeDuplicates(sequence);
    moreProblemsFound += removeDuplicates(sequence2);

    return problemsFound <= 1 || moreProblemsFound <= 1;
}

int Intro::Level2::matrixElementsSum(std::vector<std::vector<int>> matrix) {
    int sum = 0;
    std::set<int> hauntedCols;

    for(size_t i = 0; i < matrix.size(); i++){
        for(size_t j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 0){
                hauntedCols.insert(j);
            }
            else if(hauntedCols.end() == hauntedCols.find(j)){
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

std::vector<std::string> Intro::Level3::allLongestStrings(std::vector<std::string> inputArray) {
    std::vector<std::string> result;
    std::sort(inputArray.begin(), inputArray.end(), [](const std::string &a, const std::string &b) {
        return a.size() > b.size();
    });

    auto targetSize = inputArray[0].size();
    for (auto &item: inputArray) {
        if (item.size() == targetSize) {
            result.push_back(item);
        } else {
            break;
        }
    }
    return result;
}

int Intro::Level3::commonCharacterCount(std::string s1, std::string s2) {
    return 0;
}
