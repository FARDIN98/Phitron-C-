#include<bits/stdc++.h>
using namespace std;


int main(){
    int a,b,c;

    cin >> a >> b >> c;

    int left = b - a;
    int right = c - b;

    if(left == right){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;

}