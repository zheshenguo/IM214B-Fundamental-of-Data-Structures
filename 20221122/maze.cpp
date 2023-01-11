#include<iostream>
#include <fstream>
using namespace std;

// 迷宮大小 & 堆疊大小 
#define NumRow 13
#define NumCol 17 
#define MaxStackSize 250 

typedef struct { // 記錄走過路徑的堆疊 
	int row;
	int col;
	int dir;
} element;
element stack[MaxStackSize];

int top = -1; // 預設為空的stack 

typedef struct { // 定義可以走的8個方向 
	int vert;
	int horiz;
} offsets;


int maze[NumRow][NumCol];
int mark[NumRow][NumCol] = { 0 }; // 記錄走過的點的mark陣列，沒走過0、走過1
int path[NumRow][NumCol] = { 0 }; // 記錄輸出的路徑，路徑1、非路徑0 

void push(element item); // Stack Push
element pop(void); // Stack Pop
void MazePath(int startRow, int startCol, int exitRow, int exitCol); // 走迷宮函數 

int main(void) {

	// 讀入迷宮
	ifstream input("maze.txt", ios::in);
	if (!input) {
		cerr << "Can not open file maze.txt." << endl;  //標準錯誤裝置(standard error device)
		return 0;
	}
	else {
		for (int i = 0; i < NumRow; i++)
			for (int j = 0; j < NumCol; j++)
				input >> maze[i][j];
		input.close();
	}

	int startRow = 1, startCol = 1, exitRow = 11, exitCol = 15; //設定起點與終點 
	MazePath(startRow, startCol, exitRow, exitCol);

	return 0;
}


void push(element item)
{ /* Push element至堆疊stack */
	if (top >= MaxStackSize - 1) {
		cout << "Stack is full.\n";
	}
	else {
		stack[++top] = item;
	}
}

element pop(void)
{ /* 自堆疊stack Pop資料 */
	if (top == -1) {
		cout << "Stack is empty.\n";
	}
	else {
		return stack[top--];
	}
}

void MazePath(int startRow, int startCol, int exitRow, int exitCol)
{ /* 輸出迷宮的一個路徑(如果有的話) */
	int i, row, col, nextRow, nextCol, dir, found = 0;
	element position;
	offsets move[8] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
	mark[startRow][startCol] = 1;
	top = 0;
	stack[0].row = startRow; stack[0].col = startCol; stack[0].dir = 0;
	while (top > -1 && found == 0) {
		position = pop();
		row = position.row;  
		col = position.col;  
		dir = position.dir;
		while (dir < 8 && found == 0) {
			/* 發現還有路走就往前走 以dir的方向移動 */

			if (nextRow == exitRow && nextCol == exitCol) //走到終點
				found = 1;
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) { //下一個點可以走而且還沒有走過

			}
			else ++dir;
		}
	}
	if (found == 1) {
		for (i = 0; i <= top; i++) { //將結果路徑以矩陣的格式儲存 
			int r = stack[i].row, c = stack[i].col; path[r][c] = 1;
		}
		path[row][col] = 1; path[exitRow][exitCol] = 1;
		for (i = 0; i < NumRow; i++) { //輸出路徑 
			for (int j = 0; j < NumCol; j++)
				if (path[i][j] == 0)
					cout << "# ";
				else
					cout << "0 ";
			cout << endl;
		}
	}
	else cout << "The maze does not have a path.\n";
}