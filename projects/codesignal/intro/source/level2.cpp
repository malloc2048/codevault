#include <set>
#include "level2.h"
#include <algorithm>

namespace level2 {
    int adjacentElementsProduct(std::vector<int> inputArray) {
        int product = inputArray[0] * inputArray[1];
        for(int i = 0; i < inputArray.size() - 1; i++){
            int newProduct = inputArray[i] * inputArray[i+1];
            if(newProduct > product) {
                product = newProduct;
            }
        }
        return product;
    }

    int shapeArea(int n) {
        int equator = n + (n - 1);
        int area = equator;
        for(int i = 1; i != equator; i += 2) {
            area += 2 * i;
        }
        return area;
    }

    int makeArrayConsecutive2(std::vector<int> statues) {
        std::sort(statues.begin(), statues.end());

        int statuesNeeded = 0;
        for(int i = 1; i < statues.size(); i++) {
            int diff = statues[i] - statues[i - 1];
            if(diff > 1){
                statuesNeeded += diff - 1;
            }
        }
        return statuesNeeded;
    }

    int removeLeft(std::vector<int>& sequence){
        int problemsFound = 0;

        for (int i = 0; i < sequence.size() - 1; i++) {
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

        for (int i = 1; i < sequence.size(); i++) {
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

        for(int i = 0; i < sequence.size(); i++){
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

    bool almostIncreasingSequence(std::vector<int> sequence) {
        std::vector<int> sequence2 = sequence;
        int problemsFound = removeLeft(sequence);
        int moreProblemsFound = removeRight(sequence2);

        problemsFound += removeDuplicates(sequence);
        moreProblemsFound += removeDuplicates(sequence2);

        return problemsFound <= 1 || moreProblemsFound <= 1;
    }

    int matrixElementsSum(std::vector<std::vector<int>> matrix) {
        int sum = 0;
        std::set<int> hauntedCols;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
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
}
