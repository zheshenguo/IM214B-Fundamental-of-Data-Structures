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
    // int size;                // size是用來記錄Linked list的長度, 非必要
    ListNode* first;            // list的第一個node
public:
    LinkedList() :first(0) {};
    void PrintList();           // 印出list的所有資料
    void Insert(int x);     		// 在list新增node(要由小至大排序)
    void Delete(int x);         // 刪除list中的 int x
    void Clear();               // 把整串list刪除
};

int main(void)
{
    LinkedList list;     // 建立LinkedList的object
    list.PrintList();    // 目前list是空的
    list.Delete(4);      // list是空的, 沒有4
    list.Insert(5);   // list: 5
    list.Insert(3);   // list: 3 5
    list.Insert(9);  // list: 3 5 9
    list.Insert(4);   // list: 3 4 5 9
    list.PrintList();    // 印出:  3 4 5 9
    list.Delete(3);      // list: 4 5 9
    list.PrintList();    // 印出: 4 5 9
    list.Delete(7);		// list沒有7
    list.Insert(8);  // list: 4 5 8 9
    list.Insert(2);  // list: 2 4 5 8 9
    list.PrintList();    // 印出:  2 4 5 8 9
    list.Clear();        // 清空list
    list.PrintList();    // 印出: List is empty.

    return 0;
}

void LinkedList::PrintList() {

    if (first == 0) {                      // 如果first node指向NULL, 表示list沒有資料
        cout << "List is empty.\n";
        return;
    }

    ListNode* current = first;             // 用pointer *current在list中移動
    while (current != 0) {                 // Traversal
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Insert(int x) {

    ListNode* newNode = new ListNode(x);   // 配置新的記憶體

    if (first == 0) {                      // 若list沒有node, 令newNode為first
        first = newNode;
        return;
    }


    ListNode* current = first;

    if (current->data > x) {			//如果first指到的node值比新增的值大的話，新增的node=first 
        newNode->next = first;
        first = newNode;
        return;
    }

    while (current->next != 0 && current->next->data < x) {           // Traversal 且 下一個的值<目前要插入的值時 
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::Delete(int x) {

    ListNode* current = first;
    ListNode* previous = 0;

    while (current != 0 && current->data != x) {  //Traversal, 檢查list是否為empty或是否有要刪的node


    }

    if (current == 0) {                 // list沒有要刪的node, 或是list為empty
        cout << "There is no " << x << " in list.\n";
    }
    else if (current == first) {        //如果有要刪除的話，有兩種狀況：
                                        //1. 刪除的node剛好在list的開頭：要先把first指到下一個node, 再把要刪除的node刪掉 
        
        
    }
    else {                              //2. 其餘情況(list中有欲刪除的node, 且node不為first)：把要刪掉的上一個node(所以你前面可以先有一個指標指到上一個node)指到要刪掉的下一個node, 再把要刪除的node刪掉 
        
        
        
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