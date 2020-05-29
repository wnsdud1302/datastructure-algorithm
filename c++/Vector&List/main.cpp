#include<iostream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    int a[6] = {12,14,15,17,18,20};
    vector<int> v(a, a+6);
    cout << "int vector" << endl;
    cout << v.size() << endl;
    v.pop_back();
    cout << v.size() << endl;
    v.push_back(19);
    cout << v.front() << endl;
    for(vector<int>::iterator p = v.begin(); p != v.end(); ++p)
        cout << *p << " ";
    cout << endl;
    cout << VectorSum1(v) << endl;
    cout << VectorSum2(v) << endl;

    char c[] = "bravo";
    vector<char> VC(c, c+6);
    random_shuffle(VC.begin(), VC.end());
    for(vector<char>::iterator p = VC.begin(); p != VC.end(); ++p){
        cout << *p << " ";
    }
    cout << endl;

    list<int> l(a, a+6);
    cout << "int list" << endl;
    cout << l.size() << endl;
    l.pop_front();
    cout << l.size() << endl;
    l.push_back(32);
    cout << l.size() << endl;
    sort(l.begin(), l.end());
    for(list<int>::iterator p = l.begin(); p != l.end(); ++p){
        cout << *p << " ";
    }
    return 0;
}

int VectorSum1(vector<int> V){
    typedef vector<int>::iterator Iterator;
    int sum = 0;
    for(Iterator p = V.begin(); p != V.end(); ++p){
        sum += *p;
    }
    return sum;
}

int VectorSum2(const vector<int> &V){
    typedef vector<int>::const_iterator ConstIterator;
    int sum = 0;
    for(ConstIterator p = V.begin(); p != V.end(); ++p){
        sum += *p;
    }
    return sum;
}
