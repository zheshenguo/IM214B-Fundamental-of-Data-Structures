#include <iostream>
#include <string>
#include <cstring>	    //strlen
using namespace std;

#define SLEN 50

struct stack {          /* 建立一個自訂struct並命名為stack */
	int item[SLEN];
	int top;            /* 宣告top為堆疊的頂端	*/
};

stack S;				/* 宣告stack結構變數s*/
int top = -1;

char input[SLEN];		/* 用來存使用者輸入的式子 */
char output[SLEN];		/* 用來存放要輸出的值 */

int operat(char ch)	    /*檢查為 運算子(回傳 1) or 左括號(回傳 -1) or 右括號(回傳 -2) or 數字(回傳 0) */
{
	if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%'))
		return 1;
	else if (ch == '(')
		return -1;
	else if (ch == ')')
		return -2;
	else
		return 0;
}

int order(char ch)		/*	判斷優先順序 */
{
	switch (ch)			/*	將每個符號指定給一個數字，數字越大優先權越大 */
	{					/*	如果*在stack裡遇到+, *必須先出來再把+放進去 */
	case '(': 	return 0;
	case '+': 	return 1;
	case '-': 	return 1;
	case '*': 	return 2;
	case '/':	return 2;
	case '%': 	return 2;
	default: 	return -1;
	}
}

void change(char* infix, char* output)					/* 中序轉後序的函數 */
{
	int i = 0, j = 0;
	char val;

	while ((val = infix[i++]) != '\0')   				/* 只要還沒到最後一個數就會執行 */
	{													/* \0字串結束字元 */
		if (operat(val) == 0)			 				/* 如果 val 是數字就放到 output */
		{
			output[j++] = val;
		}
		else if (operat(val) == -1)		 				/* 如果 val 是左括號就 push 到 stack */
		{
			S.item[++S.top] = val;                      /* 先+再存值*/
		}
		else if (operat(val) == -2)						/* 如果 val 是右括號 */
		{
			while (S.item[S.top] != '(')			 	/* 只要不遇到左括號 */
			{
				output[j++] = S.item[S.top--];          /* 將 stack 裡的數 pop 出來，將 top--(把 pop 出來的數從 stack 移除)*/
			}
			S.item[S.top--];                            /* 把 '(' 從 stack 裡刪除*/
		}
		else							 				/* 如果 val是運算元	*/
		{
			while (S.top > -1)			 				/* 如果 stack裡有東西 */
			{
				if (order(val) > order(S.item[S.top]))	/* 若 val 的優先權大於 stack 的 top */
				{
					break;                              /* 跳出此 while迴圈 */
				}
				else                                    /* 若 val 的優先權較小 */
				{
					output[j++] = S.item[S.top--];      /* 將 stack 裡的數 pop 出來，將 top--(把 pop 出來的數從 stack 移除) */
				}
			}

			S.item[++S.top] = val;						/* 如果 stack 裡原本沒東西或是 val 的優先權較大 */
			                                            /* 就 push val 到 stack */
		}
	}

	while (S.top > -1)									/* stack 裡剩下的 */
	{
		output[j++] = S.item[S.top--];					/* 將 stack 裡的數 pop 出來，將 top--(把 pop 出來的數從 stack 移除) */
	}

}

int main()
{
	cout << "此為一個中序轉後序的程式，並限制數字部分只能輸入1-9" << endl;

	int j;

	cout << "請輸入中序運算式：" << endl;
	gets_s(input);						/* 取得使用者輸入的全部字串，包括空白字元 */

	change(input, output);				/* 執行中序轉後序的函式 */

	cout << "後序表示法結果為：" << endl;

	int l = strlen(output);				// 回傳字串的長度

	for (j = 0; j <= l; j++)
	{
		cout << output[j]; 			    /* 將output的值一一輸出 */
	}
	cout << endl;
	system("PAUSE");
	return 0;
}