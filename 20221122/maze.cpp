#include<iostream>
#include <fstream>
using namespace std;

// �g�c�j�p & ���|�j�p 
#define NumRow 13
#define NumCol 17 
#define MaxStackSize 250 

typedef struct { // �O�����L���|�����| 
	int row;
	int col;
	int dir;
} element;
element stack[MaxStackSize];

int top = -1; // �w�]���Ū�stack 

typedef struct { // �w�q�i�H����8�Ӥ�V 
	int vert;
	int horiz;
} offsets;


int maze[NumRow][NumCol];
int mark[NumRow][NumCol] = { 0 }; // �O�����L���I��mark�}�C�A�S���L0�B���L1
int path[NumRow][NumCol] = { 0 }; // �O����X�����|�A���|1�B�D���|0 

void push(element item); // Stack Push
element pop(void); // Stack Pop
void MazePath(int startRow, int startCol, int exitRow, int exitCol); // ���g�c��� 

int main(void) {

	// Ū�J�g�c
	ifstream input("maze.txt", ios::in);
	if (!input) {
		cerr << "Can not open file maze.txt." << endl;  //�зǿ��~�˸m(standard error device)
		return 0;
	}
	else {
		for (int i = 0; i < NumRow; i++)
			for (int j = 0; j < NumCol; j++)
				input >> maze[i][j];
		input.close();
	}

	int startRow = 1, startCol = 1, exitRow = 11, exitCol = 15; //�]�w�_�I�P���I 
	MazePath(startRow, startCol, exitRow, exitCol);

	return 0;
}


void push(element item)
{ /* Push element�ܰ��|stack */
	if (top >= MaxStackSize - 1) {
		cout << "Stack is full.\n";
	}
	else {
		stack[++top] = item;
	}
}

element pop(void)
{ /* �۰��|stack Pop��� */
	if (top == -1) {
		cout << "Stack is empty.\n";
	}
	else {
		return stack[top--];
	}
}

void MazePath(int startRow, int startCol, int exitRow, int exitCol)
{ /* ��X�g�c���@�Ӹ��|(�p�G������) */
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
			/* �o�{�٦������N���e�� �Hdir����V���� */

			if (nextRow == exitRow && nextCol == exitCol) //������I
				found = 1;
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) { //�U�@���I�i�H���ӥB�٨S�����L

			}
			else ++dir;
		}
	}
	if (found == 1) {
		for (i = 0; i <= top; i++) { //�N���G���|�H�x�}���榡�x�s 
			int r = stack[i].row, c = stack[i].col; path[r][c] = 1;
		}
		path[row][col] = 1; path[exitRow][exitCol] = 1;
		for (i = 0; i < NumRow; i++) { //��X���| 
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