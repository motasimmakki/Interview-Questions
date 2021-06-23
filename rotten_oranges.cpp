#include<iostream>
#include<vector>
using namespace std;

bool isAllRotten(vector<vector<int>>& grid){
        
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1)
                return false;
        }
    }
    return true;
}

int rotOranges(vector<vector<int>>& grid, int prevChanges){
    
    int originalGrid[grid.size()][grid[0].size()];
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++)
            originalGrid[i][j] = grid[i][j];
    }
    
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 2){
                if((i-1 >= 0) && (grid[i-1][j] == 1)){
                    originalGrid[i-1][j] = 2;   
                    prevChanges += 1;
                }
                if((i+1 < grid.size()) && (grid[i+1][j] == 1)){
                    originalGrid[i+1][j] = 2;
                    prevChanges += 1;
                }
                if((j-1 >= 0) && (grid[i][j-1] == 1)){
                    originalGrid[i][j-1] = 2;
                    prevChanges += 1;
                }
                if((j+1 < grid[i].size()) && (grid[i][j+1] == 1)){
                    originalGrid[i][j+1] = 2;
                    prevChanges += 1;
                }
            }
        }
    }
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++)
            grid[i][j] = originalGrid[i][j];
    }
                
    return prevChanges;
}

//Function to find minimum time required to rot all oranges. 
int orangesRotting(vector<vector<int>>& grid) {
    int unitTime = 0, prevChanges = 0;
    
    while(!isAllRotten(grid)){
        int newChanges = rotOranges(grid, prevChanges);
        if(newChanges == prevChanges)
            return -1;
        unitTime += 1;
        prevChanges = newChanges;
    }
    
    return unitTime;
}

int main(){


    return 0;
}

// Test Case:
// 10 9
// 2 1 1 1 2 1 2 0 2
// 1 2 1 1 2 1 1 2 2
// 2 2 1 2 2 1 1 2 1
// 1 0 2 0 1 2 2 1 0
// 2 0 0 2 2 2 2 0 2
// 2 1 1 1 2 0 2 1 2
// 2 2 1 1 0 0 1 2 2
// 0 2 0 2 2 2 2 2 1
// 2 0 2 0 1 2 2 2 2
// 1 1 1 2 0 1 2 2 2
// Output:
// 2

// Test Case: 02
// 1 4
// 2 2 0 1
// Output:
// -1