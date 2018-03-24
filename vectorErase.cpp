#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n;
    int m;
    vector<int> v;

    cin>>n;

    for(int i =0;i<n;i++){
        cin>>m;
        v.push_back(m);
    }
    cin>>n;
    v.erase(v.begin() + n -1);

    cin>>n;
    cin>>m;
    v.erase(v.begin() + n -1,v.begin() + m -1);

    for(vector<int>::iterator it = v.begin();it != v.end();it++){
        cout<< *it <<endl;
    }

}