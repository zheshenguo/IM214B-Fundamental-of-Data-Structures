#include <iostream>
#include <fstream> 	//載入定義檔案操作的標頭檔
using namespace std;

void hanoi(fstream& os, int, char, char, char);

int main(void)
{
	fstream infile, outfile; 			//宣告可以"輸出/寫入"檔案的物件
	infile.open("input.txt", ios::in);

	int num = 0;

	if (infile.is_open())				//檔案是否開啟
		infile >> num;
	else
		cout << "Error on opening file!" << endl;

	infile.close();

	outfile.open("output.txt", ios::out);

	char a = 'a', b = 'b', c = 'c';
	if (outfile.is_open()) {
		hanoi(outfile, num, a, b, c);
		cout << "Program completed!" << endl;
	}
	else
		cout << "Program failed!" << endl;

	outfile.close();

	return 0;
}

void hanoi(fstream& os, int n, char a, char b, char c) {
	if (n == 1) {
		os << "Move disk " << n << " from " << a << " to " << c << endl;
	}
	else {
		hanoi(os, n - 1, a, c, b);
		os << "Move disk " << n << " from " << a << " to " << c << endl;
		hanoi(os, n - 1, b, a, c);
	}
}