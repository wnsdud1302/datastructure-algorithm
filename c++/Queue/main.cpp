#include <iostream>
#include "Queue.h"
using namespace std;

int main(){
    queue q(64);
    while(1){
        int menu, x;
        cout << "현재 데이터수 : " << q.Size() << "/" << q.Capacity() << endl;
        cout << "1: 인큐, 2: 디큐, 3: 피크, 4: 검색, 5: 출력, 0: 종료 : ";
        cin >> menu;
        if(menu == 0) break;
        switch(menu){
            case 1:
                cout << "데이터 : ";
                cin >> x;
                q.Enque(x);
                break;
            case 2:
                q.Deque(&x);
                cout << "디큐 데이터는 " << x << "입니다." << endl;
                break;
            case 3:
                q.Peek(&x);
                cout << "피크 데이터는 " << x << "입니다." << endl;
                break;
            case 4:
                int idx;
                cout << "데이터 : ";
                cin >> x;
                idx = q.Search(&x);
                cout << "데이터 " << x << "는 " << idx << "에 있습니다." << endl;
                break;
            case 5:
                q.Print();
                break;
        }
    }
    return 0;
}