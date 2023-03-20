/*
 * TODO: these solutions do not work needs to be re-worked
 */

#include <vector>

// Problem #1
void moveZerosLeft(int* array, int size) {
    int idx1 = 0;
    int idx2 = size - 1; // 4

    while(idx1 < idx2)
    {
        while(idx1 < size && (array[idx1] != 1))
            idx1++;

        while(idx2 > 0 && array[idx2] != 0))
        idx2--;

        int temp = array[idx1];
        array[idx1] = array[idx2];
        array[idx2] = temp;

        idx1++;


        idx2--;
    }
}

// Problem #2
void countIsland(std::vector<std::vector<int>>& gridMap, int x, int y) {

}

int isIsland(std::vector<std::vector<int>>& gridMap, int x, int y) {
    if(x < 5 && y < 4) {
        if(gridMap[x][y] == 1) {
            gridMap[x][y] = -1;
            countIsland(gridMap, x+1, y);
            countIsland(gridMap, x, y+1);
        }
    }
}

int countIslands(std::vector<std::vector<int>>& gridMap) {
    int x, y  = 0;
    int islandCount = isIsland(gridMap, 0, 0);

    return islandCount;

    /* TODO: not sure what I was doing here?
    for(int x = 0; x < 5; x++)
    {
       for(int y = 0; y < 5; y++)
       {
         if(gridMap[x][y] == 1) // is an island
         {
           int tempX = x;
           for(int i = 0; i < 5; i++)
             if(!isIsland(x+i, y))
               x = i;

           int tempY = y;
            if(isIsland(x, y+1))
              tempY++;
         }
         x = tempX;
         y = tempY;
       }
    }
    */
}

int main() {
    return 0;
}
