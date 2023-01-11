#include <iostream>
using namespace std;

#define MAX_ELEMENTS 200

int heap[MAX_ELEMENTS];
int num; 

void insert(int val){  
    int i;
    
    if (num >= MAX_ELEMENTS) 
        cout << "Heap滿了 " << endl; 
        
    i=  ++num;                  /* 先將num+1以後傳給i 讓樹根為heap[1] */

    /* 確定樹有值,要加入的數小於它的parent */
    while ()   
    {
        /* parent的值下移到空位 */
        /* parent上移 */
    }

    /* 樹為空 或 要加入的數小於它的parent */
    heap[i] = val;      
}

void deleteMin(){
    int parent, child, temp;
    
    if (num == 0)   
    {
        cout << "Heap是空的 " << endl;  
        return;
    }

    temp = heap[num--];         /* 令temp為heap的最後一個數 */

    parent = 1;
    child = 2;
    cout << "刪除 " << heap[parent] << endl; 

    while (child <= num)        
    {
        /* 不是最後一個數 且 左子樹>右子樹 */


        /* 如果最後一個數較小 跳出while迴圈 */
        
        /* child的值放到parent指的位子 */
        /* 原本的child變parent */
        /* 新的child下移 */
    }

    heap[parent] = temp;            /* 最後一個數為樹的最小值，直接放到樹根 */
}

void printHeap(){
    int i;

    if (num == 0)
    {
        cout << "Heap是空的 " << endl; 
        return;
    }

    for (i = 1; i <= num; i++)     
        cout << "欄位 "<< i << " 為 " << heap[i] << endl; 

}

int main(){

    int input;
    int val;    
    num = 0;    
        
    do
    {
        system("cls");   /* 清空畫面 */

        cout << endl; 
        cout << "這是一個最小堆積的程式:" << endl; 
        cout << "(1)新增一個值<insert>" << endl; 
        cout << "(2)刪除最小值<deleteMax>" << endl; 
        cout << "(3)列印整個堆積<printHeap>" << endl; 
        cout << "(4)離開程式<Exit>" << endl; 
        
        cout << "輸入要執行的選項:" ; 
        cin >> input;
        cout << endl;

        switch (input)
        {
            case 1: 
                cout << "輸入0以終止" << endl; 
                    
                do{
                    cout << " 輸入新增的值: ";
                    cin >> val;
                    
                    if(val!=0)
                        insert(val);        

                }while(val!=0);
                
                system("PAUSE");
                break;

            case 2:         

                deleteMin();      
                cout << endl;
                system("PAUSE");
                break;

            case 3:         

                printHeap();
                cout << endl;
                system("PAUSE");
                break;

            case 4:     
                break;  

            default:    
                cout << " 請輸入1-4的數字 " << endl;
                system("PAUSE");
        }
    } while (input != 4);

    return 0;
}