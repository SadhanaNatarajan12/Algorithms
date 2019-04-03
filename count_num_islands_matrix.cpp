#include <iostream>

#define ROW 5
#define COL 5

int isSafe(int arr[ROW][COL], int row, int col, bool visited[ROW][COL])
{
    if ((row >= 0) && (row < ROW) &&
	(col >= 0) && (col < COL) &&
	(arr[row][col] && !visited[row][col])) {
	return true;
    }
    return false;
}

void DFS(int arr[ROW][COL], int row, int col, bool visited[][COL])
{
    static int rowNums[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNums[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    visited[row][col] = true;

    for (int k = 0; k < 8; ++k) {
	if (isSafe(arr, row + rowNums[k], col + colNums[k], visited) ) {
	    DFS(arr, row + rowNums[k], col + colNums[k], visited);
	}
    }
}

int countNumOfIslands(int arr[ROW][COL])
{
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    int count = 0;
    for (int row = 0; row <= ROW - 1; row++) {
	for (int col = 0; col <= COL - 1; col++) {
	    if (arr[row][col] && !visited[row][col]) {
		count++;
		DFS(arr, row, col, visited);
	    }
	}
    }
    return count;
}

int main()
{
    int arr[ROW][COL]= { {1, 1, 0, 0, 0},
			 {0, 1, 0, 0, 1},
			 {1, 0, 0, 1, 1},
			 {0, 0, 0, 0, 0},
			 {1, 0, 1, 0, 1} };

    std::cout<<"Number of islands is: "<<countNumOfIslands(arr)<<std::endl;
}
