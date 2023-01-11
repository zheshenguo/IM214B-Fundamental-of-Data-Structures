#include <iostream>
using namespace std;

#define MAX_ELEMENTS 200

int heap[MAX_ELEMENTS];
int num; 

void insert(int val){  
    int i;
    
    if (num >= MAX_ELEMENTS) 
        cout << "Heap���F " << endl; 
        
    i=  ++num;                  /* ���Nnum+1�H��ǵ�i ����ڬ�heap[1] */

    /* �T�w�𦳭�,�n�[�J���Ƥp�󥦪�parent */
    while ()   
    {
        /* parent���ȤU����Ŧ� */
        /* parent�W�� */
    }

    /* �𬰪� �� �n�[�J���Ƥp�󥦪�parent */
    heap[i] = val;      
}

void deleteMin(){
    int parent, child, temp;
    
    if (num == 0)   
    {
        cout << "Heap�O�Ū� " << endl;  
        return;
    }

    temp = heap[num--];         /* �Otemp��heap���̫�@�Ӽ� */

    parent = 1;
    child = 2;
    cout << "�R�� " << heap[parent] << endl; 

    while (child <= num)        
    {
        /* ���O�̫�@�Ӽ� �B ���l��>�k�l�� */


        /* �p�G�̫�@�ӼƸ��p ���Xwhile�j�� */
        
        /* child���ȩ��parent������l */
        /* �쥻��child��parent */
        /* �s��child�U�� */
    }

    heap[parent] = temp;            /* �̫�@�ӼƬ��𪺳̤p�ȡA��������� */
}

void printHeap(){
    int i;

    if (num == 0)
    {
        cout << "Heap�O�Ū� " << endl; 
        return;
    }

    for (i = 1; i <= num; i++)     
        cout << "��� "<< i << " �� " << heap[i] << endl; 

}

int main(){

    int input;
    int val;    
    num = 0;    
        
    do
    {
        system("cls");   /* �M�ŵe�� */

        cout << endl; 
        cout << "�o�O�@�ӳ̤p��n���{��:" << endl; 
        cout << "(1)�s�W�@�ӭ�<insert>" << endl; 
        cout << "(2)�R���̤p��<deleteMax>" << endl; 
        cout << "(3)�C�L��Ӱ�n<printHeap>" << endl; 
        cout << "(4)���}�{��<Exit>" << endl; 
        
        cout << "��J�n���檺�ﶵ:" ; 
        cin >> input;
        cout << endl;

        switch (input)
        {
            case 1: 
                cout << "��J0�H�פ�" << endl; 
                    
                do{
                    cout << " ��J�s�W����: ";
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
                cout << " �п�J1-4���Ʀr " << endl;
                system("PAUSE");
        }
    } while (input != 4);

    return 0;
}