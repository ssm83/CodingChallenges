#include <iostream>
using namespace std;

int pathCount(int row, int col) {
    int arr[5][5];
    
    for(int i = row, j = col; j >= 0; j--) 
        arr[i][j] = 1;
    
    for(int j = col, i = row; i >= 0; i--) 
        arr[i][j] = 1;
        
    for (int i = row - 1; i >= 0; i--) {
        for (int j = col - 1; j >= 0; j--) {
            arr[i][j] = arr[i+1][j] + arr[i][j+1];
        }
    }
    
    return arr[0][0];
 }

int main() {
	// your code goes here
	cout << "Paths # from [0,0] - [2,2] -- " << pathCount(2,2) << endl;
	cout << "Paths # from [0,0] - [1,1] -- " << pathCount(1,1) << endl;
	cout << "Paths # from [0,0] - [1,4] -- " << pathCount(1,4) << endl;
	cout << "Paths # from [0,0] - [4,4] -- " << pathCount(4,4) << endl;
	return 0; 
}
