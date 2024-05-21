#include<bits/stdc++.h>
using namespace std;

int main(){
    int X,t,left=0,res;
    cin >> X >> t;

    if(X < t || X == t){
        cout << left << endl;
    }else{
        res = X - t;
        cout << res << endl;
    }
    return 0;
}