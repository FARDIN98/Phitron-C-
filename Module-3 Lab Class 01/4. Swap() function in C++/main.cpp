#include<bits/stdc++.h>
using namespace std;


int main(){
    int a[] = {2,4,1,5,6}, n = 5;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }

    for(int i = 0; i<n; i++){
        cout << a[i]<< " ";
    }

    return 0;
}