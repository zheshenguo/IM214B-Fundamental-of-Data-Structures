#include <iostream>
using namespace std;
#define num 37
#define p 31

int a,col,Hash[num];

void DoubleH(int a, int val) {
	col = 0;   //計算第幾次碰撞	
	while(1)
	{
		if (Hash[a] == 0) //如果Hash[a]值是空的就把傳來的值代入
		{
			Hash[a] = val;
			break;
		}
		col++;	//如果Hash裡有值了，碰撞次數再+1
		cout << "== 發生第 "<< col <<"次碰撞 ==" << endl; 
		a=??? ; //計算hash 
	}
}

void Search(int a, int val) {
	col = 0;
	while(1)
	{
		if (Hash[a] == val)
		{
			cout << "\n該值位於第 "<< a+1 <<"個位子" << endl; 		
			break;
		}

		col++;	
		a = ???; //計算 

		if(Hash[a] == 0)
		{
			cout << "\n找不到值" << endl; 	
			break;	
		}
	}
}

int main()
{
	int data,sel;
	int i=0; 

  	do
  	{	
  		system("cls");

  		cout << "請選擇所需要執行的動作" << endl; 
  		cout << "(1)新增\n(2)查詢" << endl; 
  		cout << "(3)印出\n(4)結束" << endl; 
  		cout << "所要執行的動作: " ; 
  		cin >> sel;
  		cout << endl; 
	
		switch(sel)
  		{
  			case 1:
  	  			
  	  			cout << "輸入0以終止" << endl; 
				do
				{	
					cout << "輸入新增的值: "; 
					cin >> data ;

					if(data!=0)
					{
						a = data % num;	//值除以table大小的餘數代表要存入的位置
						DoubleH(a, data);	
					}
							
				}while(data!=0);
				cout << endl; 
				
				break;
      
	  		case 2:
	  			
	  			cout << "輸入欲查詢的值: "; 
				cin >> data ;
				
				a = data % num;			
				Search(a, data);
        		system("PAUSE");
				break;
				 
		 	case 3:
		
				for (i = 0; i < num; i++)	
				{
					cout << Hash[i];
					
					if(Hash[i]==0||Hash[i]<10)
						cout << " ";
						
					if(i!=0&&(i+1)%10==10)
						cout << endl; 
				}
				cout << endl;
				system("PAUSE"); 
        		break;
		
 	  		case 4:
	    		cout <<"程式結束\n"<<endl; 
  			    break;
        		
	  		default:
	    		cout <<"輸入指令錯誤"<<endl; 
			 	break;
		}
  	}while(sel!=4);    
	
	return 0;
}
