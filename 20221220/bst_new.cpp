#include <iostream>
using namespace std;

typedef struct tree           
{ 
    int data;
    struct tree *left, *right;  //���O���V���k�l�𪺫���    
}treeNode, *treeLink; 

treeLink root = NULL;

void insert(int k)
{
    treeLink newNode, now;
    int insert = 0;                     //�P�_�O�_���J�s�`�I  
    
    newNode = new treeNode;   			//�t�m�s�`�I�O���� 
    newNode->data = k;                  //�إ߸`�I���e
    newNode->left = NULL;
    newNode->right = NULL;
    
    if(root == NULL)
        root = newNode;                 //�إ߮ڸ`�I
    else
    {
        now = root;
        while(!insert)                //����`�I��
        { 
            if(now->data > newNode->data)
            {
                if(now->left == NULL)
                {
                    now->left = newNode;     //�إ��쵲 
                    insert = 1;   
                }
                else
                    now = now->left;       //���l�� 
            }
            else                       
            { 
                if(now->right == NULL)   //�O�_�O�̥k�`�I  
                {
                    now->right = newNode;    //�إ��쵲 
                    insert = 1;      
                }
                else
                    now = now->right;      //�k�l��    
            }   
        }        
    }
}        

int search(int d)
{
    treeLink ptr = root;
    while(ptr != NULL)
    {
        if(ptr->data == d)            //���ҭn�M�䪺�� 
            return 1;
        else
        {
            if(d < ptr->data)          //������ 
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
    int find = 0;                                   //�O�_���R���`�I   
    ptr_f = ptr = root;                             //��M�R���`�I�M����`�I���� 
  
    while(ptr != NULL && !find )
    { 
        if()   
                                         //���R���`�I
        else
        {
                                     //�O�d���`�I����         
            if()                      //������
                
            else
                
        }       
    }  
        
    if ( ptr == NULL )                              //�S�����R���`�I
    {
        cout << "\n���R�����Ȥ��s�b" << endl;   
        return;
    } 
    
    if(ptr->left == NULL && ptr->right == NULL )    //�n�R���ƬO���`�I
    {         
        if()
            
        else if()                 //�n�R���ƬO�����`�I
            
        else                                        //�n�R���ƬO�k���`�I
                               
            
        ptr = NULL;                                 //���^�`�I�O����
        
        cout << "\n���R�����Ȥw�R��" << endl; 
    }
  
    else if()                      //�n�R���ƨS�����l������k�l�� 
    {      
        if()                             //�n�R���ƬOroot 
                
        else if()                 //�n�R���ƬO���`�I�����l�� 
                           //���`�I�����l����V�n�R���ƪ��k�l�� 
        else                                        //�n�R���ƬO���`�I���k�l�� 
           	            //���`�I���k�l����V�n�R���ƪ��k�l��
                                                    
        ptr = NULL;           
                            
        cout << "\n���R�����Ȥw�R��" << endl; 
    }
  
    else if()                     //�n�R���ƨS���k�l��������l��
    {
        if()                             //�n�R���ƬOroot
                             
        else if()                 //�n�R���ƬO���`�I�����l�� 
                          //���`�I�����l����V�n�R���ƪ����l�� 
        else                                        //�n�R���ƬO���`�I���k�l�� 
                          //���`�I���k�l����V�n�R���ƪ����l��
         
        ptr = NULL;                              
        
        cout << "\n���R�����Ȥw�R��" << endl; 
    } 
    
    else                                            //�n�R���Ʀ��k�l��M���l��
    {                                               
        ptr_f = ptr;                                //�O�d���`�I���� 
        ptr_c = ptr->right;                         //�q�k�l���̤p��
    
        while()                  //���l�`�I�٦��k�l�� 
        {
                                     //�O�d���`�I����
                                //�����l���̤p�� 
        }
    
                            //�Q�R�����ƪ���l�Q�k�l�𤤪��̤p�Ȩ��N 
  
        if()                   //�p�G�n�R�����ƪ��k�p�ĴN�O�̤p�� 
                        //�N�쥻�̤p�Ȫ��k�l��W�� 
        else                                            
                        //��쥻�̤p�Ȫ��k�l��W����k�p�Ī����l��  
  
        ptr_c = NULL;                              
        cout << "\n���R�����Ȥw�R��" << endl; 
    }
}

void print(treeLink ptr)
{
    if(ptr == NULL)                     //�Y�𬰪Ū� 
        return ;
    else
    {    
        cout << ptr->data ;             //���X�쪺�������L�X�� 
                                        //�A�̷ӫe�Ǩ��X���覡�[�W�A���M�r��
        if(ptr->left)                   //���䦳����
        {
            cout << "(";
            print(ptr->left);                   
        }
        
        else if(ptr->left == NULL)      //���䨫�쩳�F,�A���k�䨫 
        {
            if(ptr->right)
                cout << "(";
        }
    
        if(ptr->right)                  //�k�䦳���� 
        {
            if(ptr->left)
                cout << ",";
            
            print(ptr->right);
            cout << ")";
        }
        
        else if(ptr->right == NULL)     //�k�䨫�쩳�F, �A�����䨫 
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
        
        cout << "�п�ܩһݭn���檺�ʧ@"<< endl;
        cout << "(1)�s�W�@�����\n(2)�R���@�����\n(3)�d�߬Y�����"<< endl;
        cout << "(4)�L�X��ʾ�\n(5)����\n"<< endl;

        cout << "�ҭn���檺�ʧ@: " ;
        cin >> sel;
        cout << endl;
    
        switch(sel)
        {
            case 1:
                
                cout <<"��J0�H�פ�"<<endl;
                
                do
                {
                    cout <<"��J�s�W����: ";
                    cin >> data;
                
                    if(search(data))
                        cout <<"\n��ƭ���\n"<<endl;
                
                    else if(data!=0)
                        insert(data);   
                    
                }while(data!=0);
            
                system("pause");
                break;
      
            case 2:
                
                cout <<"�п�J���R������: ";
                cin >> data;
                
                deleted(data);
    
                system("pause");
                break;
                 
            case 3:
                
                cout <<"�п�J���d�ߪ���: ";
                cin >> data;
        
                if(search(data))
                    cout <<"\n�ӭȦs�b\n"<<endl;
                else
                    cout <<"\n�ӭȤ��s�b\n"<<endl;
        
                system("pause");
                break;
        
            case 4:
        
                cout <<"(";
                print(root);
                cout <<")\n"<<endl;
        
                system("pause");
                break;
                
            case 5:
        
                cout <<"�{������"<<endl;
                break;
      
            default:
            
                cout <<"��J���O���~"<<endl;
                system("pause");
                break;
        }
    }while(sel!=5);    
  
    system("pause");
    return 0;
}
