#include <iostream>
using namespace std;

typedef struct tree
{
    int data;
    struct tree* left, * right;  //分別指向左右子樹的指標    
}treeNode, * treeLink;

treeLink root = NULL;

void insert(int k)
{
    treeLink newNode, now;
    int insert = 0;                     //判斷是否插入新節點  

    newNode = new treeNode;   			//配置新節點記憶體 
    newNode->data = k;                  //建立節點內容
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
        root = newNode;                 //建立根節點
    else
    {
        now = root;
        while (!insert)                //比較節點值
        {
            if ()
            {
                if (now->left == NULL)
                {

                }
                else

            }
            else
            {
                if (now->right == NULL)   //是否是最右節點  
                {

                }
                else
 
            }
        }
    }
}

int search(int d)
{
    treeLink ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == d)            //找到所要尋找的值 
            return 1;
        else
        {
            if (d < ptr->data)          //比較資料 

            else

        }
    }
    return 0;
}


void print(treeLink ptr)
{
    if (ptr == NULL)                     //若樹為空的 
        return;
    else
    {
        cout << ptr->data;             //走訪到的元素先印出來 
                                        //再依照前序走訪的方式加上括號和逗號
        if (ptr->left)                   //左邊有元素
        {
            cout << "(";
            print(ptr->left);
        }

        else if (ptr->left == NULL)      //左邊走到底了,再往右邊走 
        {
            if (ptr->right)
                cout << "(";
        }

        if (ptr->right)                  //右邊有元素 
        {
            if (ptr->left)
                cout << ",";

            print(ptr->right);
            cout << ")";
        }

        else if (ptr->right == NULL)     //右邊走到底了, 再往左邊走 
        {
            if (ptr->left)
                cout << ")";
        }
    }
}

int main()
{
    int data, sel;
    do
    {
        system("cls");

        cout << "請選擇所需要執行的動作" << endl;
        cout << "(1)新增一筆資料\n(2)刪除一筆資料\n(3)查詢某筆資料" << endl;
        cout << "(4)印出整棵樹\n(5)結束\n" << endl;

        cout << "所要執行的動作: ";
        cin >> sel;
        cout << endl;

        switch (sel)
        {
        case 1:

            cout << "輸入0以終止" << endl;

            do
            {
                cout << "輸入新增的值: ";
                cin >> data;

                if (search(data))
                    cout << "\n資料重複\n" << endl;

                else if (data != 0)
                    insert(data);

            } while (data != 0);

            system("pause");
            break;

        case 2:

            cout << "請輸入欲刪除的值: ";
            cin >> data;

            //deleted(data);

            system("pause");
            break;

        case 3:

            cout << "請輸入欲查詢的值: ";
            cin >> data;

            if (search(data))
                cout << "\n該值存在\n" << endl;
            else
                cout << "\n該值不存在\n" << endl;

            system("pause");
            break;

        case 4:

            cout << "(";
            print(root);
            cout << ")\n" << endl;

            system("pause");
            break;

        case 5:

            cout << "程式結束" << endl;
            break;

        default:

            cout << "輸入指令錯誤" << endl;
            system("pause");
            break;
        }
    } while (sel != 5);

    system("pause");
    return 0;
}
