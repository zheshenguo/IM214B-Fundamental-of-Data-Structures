# include <iostream>
# include <cstdlib>
# include <iomanip>
using namespace std;

class LinkedList;
class ListNode {
private:
    int data;
    ListNode* next;
public:
    ListNode() :data(0), next(0) {};
    ListNode(int a) :data(a), next(0) {}

    friend class LinkedList;
};

class LinkedList {
private:
    // int size;                // size�O�ΨӰO��Linked list������, �D���n
    ListNode* first;            // list���Ĥ@��node
public:
    LinkedList() :first(0) {};
    void PrintList();           // �L�Xlist���Ҧ����
    void Insert(int x);     		// �blist�s�Wnode(�n�Ѥp�ܤj�Ƨ�)
    void Delete(int x);         // �R��list���� int x
    void Clear();               // ����list�R��
};

int main(void)
{
    LinkedList list;     // �إ�LinkedList��object
    list.PrintList();    // �ثelist�O�Ū�
    list.Delete(4);      // list�O�Ū�, �S��4
    list.Insert(5);   // list: 5
    list.Insert(3);   // list: 3 5
    list.Insert(9);  // list: 3 5 9
    list.Insert(4);   // list: 3 4 5 9
    list.PrintList();    // �L�X:  3 4 5 9
    list.Delete(3);      // list: 4 5 9
    list.PrintList();    // �L�X: 4 5 9
    list.Delete(7);		// list�S��7
    list.Insert(8);  // list: 4 5 8 9
    list.Insert(2);  // list: 2 4 5 8 9
    list.PrintList();    // �L�X:  2 4 5 8 9
    list.Clear();        // �M��list
    list.PrintList();    // �L�X: List is empty.

    return 0;
}

void LinkedList::PrintList() {

    if (first == 0) {                      // �p�Gfirst node���VNULL, ���list�S�����
        cout << "List is empty.\n";
        return;
    }

    ListNode* current = first;             // ��pointer *current�blist������
    while (current != 0) {                 // Traversal
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Insert(int x) {

    ListNode* newNode = new ListNode(x);   // �t�m�s���O����

    if (first == 0) {                      // �Ylist�S��node, �OnewNode��first
        first = newNode;
        return;
    }


    ListNode* current = first;

    if (current->data > x) {			//�p�Gfirst���쪺node�Ȥ�s�W���Ȥj���ܡA�s�W��node=first 
        newNode->next = first;
        first = newNode;
        return;
    }

    while (current->next != 0 && current->next->data < x) {           // Traversal �B �U�@�Ӫ���<�ثe�n���J���Ȯ� 
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::Delete(int x) {

    ListNode* current = first;
    ListNode* previous = 0;

    while (current != 0 && current->data != x) {  //Traversal, �ˬdlist�O�_��empty�άO�_���n�R��node


    }

    if (current == 0) {                 // list�S���n�R��node, �άOlist��empty
        cout << "There is no " << x << " in list.\n";
    }
    else if (current == first) {        //�p�G���n�R�����ܡA����ت��p�G
                                        //1. �R����node��n�blist���}�Y�G�n����first����U�@��node, �A��n�R����node�R�� 
        
        
    }
    else {                              //2. ��l���p(list�������R����node, �Bnode����first)�G��n�R�����W�@��node(�ҥH�A�e���i�H�����@�ӫ��Ы���W�@��node)����n�R�����U�@��node, �A��n�R����node�R�� 
        
        
        
    }
}

void LinkedList::Clear() {

    while (first != 0) {            // Traversal
        ListNode* current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}