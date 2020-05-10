#include<iostream>
#include"Stack.h"
using namespace std;

int main(){
    Stack s;
    s = Stack(64);
    while (1)
    {
        int menu, x;
        cout << "현재 데이터수 : " << s.size() << "/" << s.capacity() << endl;
        cout << "1: 푸시, 2: 팝, 3:피크, 4: 출력, 0: 종료 : " ;
        cin >> menu;
        if(menu == 0) break;
        switch (menu)
        {
        case 1:
            cout << "데이터 :";
            cin >> x;
            if(s.Push(x) == -1){
                cout << "푸시에 실패하였습니다." << endl;
            }
            break;
        
        case 2:
            if (s.Pop(&x) == -1)
                cout << "\a : 푸시에 실패하였습니다." << endl;
            else
                cout << "팝 데이터는 " <<  x << " 입니다." << endl;
            break;
        
        case 3: 
            if (s.Peek(&x) == -1)
                cout << "\a : 피크에 실패하였습니다." << endl;
            else
                cout << "피크 데이터는 " <<  x << " 입니다" << endl;
            break;
        case 4:
            s.Print();
            break;
        }
    }


}
