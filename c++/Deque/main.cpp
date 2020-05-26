#include<iostream>
#include"Deque.h"
using namespace std;

int main(){
    Deque<int> d;
    while(1){
        int menu, x;
        cout << d.size() << endl;
        cout << "1) InsertFront 2) InsertBack 3) RemoveFront 4) RemoveBack" << endl;
        cout << " 5) nth data 6) Print 7) PrintReverse 8) Clear 0) Terminate"<<endl;
        cout << "enter : ";
        cin>>menu;
        if(menu == 0) break;
        switch(menu){
            case 1:
                cout << "data : ";
                cin >> x;
                d.InsertFront(x);
                break;
            case 2:
                cout << "data : ";
                cin >> x;
                d.InsertBack(x);
                break;
            case 3:
                d.RemoveFront();
                break;
            case 4:
                d.RemoveBack();
                break;
            case 5:
                cout << "data : ";
                cin >> x;
                cout << d[x] << endl; 
                break;
            case 6:
                d.Print();
                break;
            case 7:
                d.PrintReverse();
                break;
            case 8:
                d.Clear();
                break;
        }
    }
    return 0;
}