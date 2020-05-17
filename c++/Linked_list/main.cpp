#include<iostream>
#include"Linked_list.h"
using namespace std;

int main(){
    Linked_list l;
    while(1){
        int menu, x;
        cout << "1: 앞쪽노드 삽입 2: 뒷쪽노드 삽입 3: 앞쪽노드 삭제 4: 뒤쪽노드 삭제" << endl;
        cout << "5: 현재노드 삭제 6: 검색 7: 현재노드 출력 8: 모든 노드 출력" << endl;
        cout << "9: 모든 노드 삭제 0:종료 : " ;
        cin >> menu;
        if(menu == 0) break;
        switch(menu){
            case 1:
                cout << "데이터 : ";
                cin >> x;
                l.InsertFront(x);
                break;
            case 2:
                cout << "데이터 : ";
                cin >> x;
                l.InsertBack(x);
                break;
            case 3:
                l.RemoveFront();
                break;
            case 4:
                l.RemoveBack();
                break;
            case 5:
                l.RemoveCurrent();
                break;
            case 6:{
                cout << "데이터 : ";
                cin >> x;
                Node *srch = l.Search(x);
                l.PrintNode(srch);
                break;
            }
            case 7:
                l.PrintCurrent();
                break;
            case 8:
                l.Print();
                break;
            case 9:
                l.Clear();
                break;
        }
    }
    return 0;
}