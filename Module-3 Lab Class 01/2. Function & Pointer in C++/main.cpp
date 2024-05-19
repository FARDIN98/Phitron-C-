#include<bits/stdc++.h>
using namespace std;

void print(int **x){
    **x = 2500;
}

int main(){
    int a = 10;
    int *p = &a;
    int **q = &p;
    print(q);
    cout << a << endl;

    return 0;
}