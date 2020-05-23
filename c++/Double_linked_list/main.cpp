#include<iostream>
#include"Double_linked_list.h"
using namespace std;

int main(){
    Double_linked_list<int> l;
    while(1){
        int menu, x;
        cout <<"1. 앞쪽에 노드 삽입 2. 뒤쪽에 노드 삽입 3. 앞쪽 노드 삭제 4. 뒤쪽 노드 삭제 " << endl;
        cout << "5. 노드 검색 6. 현재노드 출력 7. 앞에서부터 출력 8. 뒤에서부터 출력 9. 모든 노드 삭제" << endl;
        cout << "10. 정렬 0. 종료 : ";
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
                cout << "데이터 : ";
                cin >> x;
                l.Search(x);
                l.Printcurrent();
                break;
            case 6:
                l.Printcurrent();
                break;
            case 7:
                l.Print();
                break;
            case 8:
                l.PrintReverse();
                break;
            case 9:
                l.Clear();
                break;
            case 10:
                cout << "데이터 : ";
                cin >> x;
                l.addSorted(x);
                break;
        }
    }
    return 0;
}