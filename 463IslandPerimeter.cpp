#include <iostream>
#include <vector>

using namespace std;

int main(){

		vector<vector<int>> grid = {{0,1,0,0},
				{1,1,1,0},
				{0,1,0,0},
				{1,1,0,0}};

		int m = grid.size();
		int n = grid[0].size();
		int perimeter = 0;
		
		for(int i = 0 ; i < m;i++){
				for(int j = 0 ; j < n ; j++){
						if(grid[i][j] == 1){
								//left
								if(j == 0 || grid[i][j-1] == 0) perimeter++;
								//up
								if(i == 0 || grid[i-1][j] == 0) perimeter++;
								//right
								if(j == n-1 || grid[i][j+1] == 0) perimeter++;
								//down
								if(i == m-1 || grid[i+1][j] == 0) perimeter++;
						}

				}
		}

		cout << perimeter << endl;
}
