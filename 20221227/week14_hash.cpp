#include <iostream>
using namespace std;
#define num 37
#define p 31

int a,col,Hash[num];

void DoubleH(int a, int val) {
	col = 0;   //�p��ĴX���I��	
	while(1)
	{
		if (Hash[a] == 0) //�p�GHash[a]�ȬO�Ū��N��ǨӪ��ȥN�J
		{
			Hash[a] = val;
			break;
		}
		col++;	//�p�GHash�̦��ȤF�A�I�����ƦA+1
		cout << "== �o�Ͳ� "<< col <<"���I�� ==" << endl; 
		a=??? ; //�p��hash 
	}
}

void Search(int a, int val) {
	col = 0;
	while(1)
	{
		if (Hash[a] == val)
		{
			cout << "\n�ӭȦ��� "<< a+1 <<"�Ӧ�l" << endl; 		
			break;
		}

		col++;	
		a = ???; //�p�� 

		if(Hash[a] == 0)
		{
			cout << "\n�䤣���" << endl; 	
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

  		cout << "�п�ܩһݭn���檺�ʧ@" << endl; 
  		cout << "(1)�s�W\n(2)�d��" << endl; 
  		cout << "(3)�L�X\n(4)����" << endl; 
  		cout << "�ҭn���檺�ʧ@: " ; 
  		cin >> sel;
  		cout << endl; 
	
		switch(sel)
  		{
  			case 1:
  	  			
  	  			cout << "��J0�H�פ�" << endl; 
				do
				{	
					cout << "��J�s�W����: "; 
					cin >> data ;

					if(data!=0)
					{
						a = data % num;	//�Ȱ��Htable�j�p���l�ƥN��n�s�J����m
						DoubleH(a, data);	
					}
							
				}while(data!=0);
				cout << endl; 
				
				break;
      
	  		case 2:
	  			
	  			cout << "��J���d�ߪ���: "; 
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
	    		cout <<"�{������\n"<<endl; 
  			    break;
        		
	  		default:
	    		cout <<"��J���O���~"<<endl; 
			 	break;
		}
  	}while(sel!=4);    
	
	return 0;
}
