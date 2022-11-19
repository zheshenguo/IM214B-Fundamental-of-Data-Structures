#include <iostream>  
#include <fstream>  //載入定義檔案操作的標頭檔
using namespace std;

#define Num 1000

int Max3(int A, int B, int C)
{
    if (A >= B && A >= C)
    {
        return A;
    }
    else if (B >= A && B >= C)
    {
        return B;
    }
    else       //else if( C>=A && C>=B )
    {
        return C;
    }
}

int DivideAndConquer(int a[], int left, int right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int center, i;

    if (left == right)
    {
        if (a[left] > 0)
        {
            return a[left];
        }
        else
        {
            return 0;
        }
    }

    center = (left + right) / 2;
    MaxLeftSum = DivideAndConquer(a, left, center);
    MaxRightSum = DivideAndConquer(a, center + 1, right);
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;

    /*切中間到左邊的頭*/
    for (i = center; i >= left; i--)
    {

    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    /*切中間到右邊的頭*/
    for (i = center + 1; i <= right; i++)
    {

    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int main()
{
    fstream infile; //宣告可以輸出檔案的物件
    infile.open("input-1000.txt", ios::in);

    int i, ARR[Num];
    for (i = 0; i < Num; i++)
    {
        infile >> ARR[i];
    }

    infile.close();

    int max = DivideAndConquer(ARR, 0, Num - 1);

    cout << "max =  " << max << endl;

    return 0;
}