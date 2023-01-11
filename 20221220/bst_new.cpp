#include <iostream>
using namespace std;

typedef struct tree           
{ 
    int data;
    struct tree *left, *right;  //分別指向左右子樹的指標    
}treeNode, *treeLink; 

treeLink root = NULL;

void insert(int k)
{
    treeLink newNode, now;
    int insert = 0;                     //判斷是否插入新節點  
    
    newNode = new treeNode;   			//配置新節點記憶體 
    newNode->data = k;                  //建立節點內容
    newNode->left = NULL;
    newNode->right = NULL;
    
    if(root == NULL)
        root = newNode;                 //建立根節點
    else
    {
        now = root;
        while(!insert)                //比較節點值
        { 
            if(now->data > newNode->data)
            {
                if(now->left == NULL)
                {
                    now->left = newNode;     //建立鏈結 
                    insert = 1;   
                }
                else
                    now = now->left;       //左子樹 
            }
            else                       
            { 
                if(now->right == NULL)   //是否是最右節點  
                {
                    now->right = newNode;    //建立鏈結 
                    insert = 1;      
                }
                else
                    now = now->right;      //右子樹    
            }   
        }        
    }
}        

int search(int d)
{
    treeLink ptr = root;
    while(ptr != NULL)
    {
        if(ptr->data == d)            //找到所要尋找的值 
            return 1;
        else
        {
            if(d < ptr->data)          //比較資料 
                ptr = ptr->left;         
            else
                ptr = ptr->right;          
        }    
  }
  return 0;   
}

void deleted(int d)
{
    treeLink ptr,ptr_f,ptr_c;
    int find = 0;                                   //是否找到刪除節點   
    ptr_f = ptr = root;                             //找尋刪除節點和其父節點指標 
  
    while(ptr != NULL && !find )
    { 
        if()   
                                         //找到刪除節點
        else
        {
                                     //保留父節點指標         
            if()                      //比較資料
                
            else
                
        }       
    }  
        
    if ( ptr == NULL )                              //沒有找到刪除節點
    {
        cout << "\n欲刪除的值不存在" << endl;   
        return;
    } 
    
    if(ptr->left == NULL && ptr->right == NULL )    //要刪的數是葉節點
    {         
        if()
            
        else if()                 //要刪的數是左葉節點
            
        else                                        //要刪的數是右葉節點
                               
            
        ptr = NULL;                                 //釋回節點記憶體
        
        cout << "\n欲刪除的值已刪除" << endl; 
    }
  
    else if()                      //要刪的數沒有左子樹但有右子樹 
    {      
        if()                             //要刪的數是root 
                
        else if()                 //要刪的數是父節點的左子樹 
                           //父節點的左子樹指向要刪的數的右子樹 
        else                                        //要刪的數是父節點的右子樹 
           	            //父節點的右子樹指向要刪的數的右子樹
                                                    
        ptr = NULL;           
                            
        cout << "\n欲刪除的值已刪除" << endl; 
    }
  
    else if()                     //要刪的數沒有右子樹但有左子樹
    {
        if()                             //要刪的數是root
                             
        else if()                 //要刪的數是父節點的左子樹 
                          //父節點的左子樹指向要刪的數的左子樹 
        else                                        //要刪的數是父節點的右子樹 
                          //父節點的右子樹指向要刪的數的左子樹
         
        ptr = NULL;                              
        
        cout << "\n欲刪除的值已刪除" << endl; 
    } 
    
    else                                            //要刪的數有右子樹和左子樹
    {                                               
        ptr_f = ptr;                                //保留父節點指標 
        ptr_c = ptr->right;                         //從右子樹找最小值
    
        while()                  //左子節點還有右子樹 
        {
                                     //保留父節點指標
                                //往左子樹找最小值 
        }
    
                            //被刪除的數的位子被右子樹中的最小值取代 
  
        if()                   //如果要刪除的數的右小孩就是最小值 
                        //將原本最小值的右子樹上移 
        else                                            
                        //把原本最小值的右子樹上移到右小孩的左子樹  
  
        ptr_c = NULL;                              
        cout << "\n欲刪除的值已刪除" << endl; 
    }
}

void print(treeLink ptr)
{
    if(ptr == NULL)                     //若樹為空的 
        return ;
    else
    {    
        cout << ptr->data ;             //走訪到的元素先印出來 
                                        //再依照前序走訪的方式加上括號和逗號
        if(ptr->left)                   //左邊有元素
        {
            cout << "(";
            print(ptr->left);                   
        }
        
        else if(ptr->left == NULL)      //左邊走到底了,再往右邊走 
        {
            if(ptr->right)
                cout << "(";
        }
    
        if(ptr->right)                  //右邊有元素 
        {
            if(ptr->left)
                cout << ",";
            
            print(ptr->right);
            cout << ")";
        }
        
        else if(ptr->right == NULL)     //右邊走到底了, 再往左邊走 
        {
            if(ptr->left)
                cout << ")";
        }
    }   
} 

int main()
{
    int data,sel; 
    do
    {
        system("cls");
        
        cout << "請選擇所需要執行的動作"<< endl;
        cout << "(1)新增一筆資料\n(2)刪除一筆資料\n(3)查詢某筆資料"<< endl;
        cout << "(4)印出整棵樹\n(5)結束\n"<< endl;

        cout << "所要執行的動作: " ;
        cin >> sel;
        cout << endl;
    
        switch(sel)
        {
            case 1:
                
                cout <<"輸入0以終止"<<endl;
                
                do
                {
                    cout <<"輸入新增的值: ";
                    cin >> data;
                
                    if(search(data))
                        cout <<"\n資料重複\n"<<endl;
                
                    else if(data!=0)
                        insert(data);   
                    
                }while(data!=0);
            
                system("pause");
                break;
      
            case 2:
                
                cout <<"請輸入欲刪除的值: ";
                cin >> data;
                
                deleted(data);
    
                system("pause");
                break;
                 
            case 3:
                
                cout <<"請輸入欲查詢的值: ";
                cin >> data;
        
                if(search(data))
                    cout <<"\n該值存在\n"<<endl;
                else
                    cout <<"\n該值不存在\n"<<endl;
        
                system("pause");
                break;
        
            case 4:
        
                cout <<"(";
                print(root);
                cout <<")\n"<<endl;
        
                system("pause");
                break;
                
            case 5:
        
                cout <<"程式結束"<<endl;
                break;
      
            default:
            
                cout <<"輸入指令錯誤"<<endl;
                system("pause");
                break;
        }
    }while(sel!=5);    
  
    system("pause");
    return 0;
}
