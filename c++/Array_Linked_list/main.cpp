#include<iostream>
#include"Array_Linked_list.h"

using namespace std;

int main(){
    Arraylinkedlist al(64);
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
                al.InsertFront(&x);
                break;
            case 2:
                cout << "데이터 : ";
                cin >> x;
                al.InsertBack(&x);
                break;
            case 3:
                al.RemoveFront();
                break;
            case 4:
                al.RemoveBack();
                break;
            case 5:
                al.RemoveCurrent();
                break;
            case 6:{
                cout << "데이터 : ";
                cin >> x;
                Index srch = al.Search(&x);
                al.PrintNode(srch);
                break;
            }
            case 7:
                al.PrintCurrent();
                break;
            case 8:
                al.Print();
                break;
            case 9:
                al.Clear();
                break;
        }
    }
    return 0;
}