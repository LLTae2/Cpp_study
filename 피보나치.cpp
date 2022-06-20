#include<iostream>
using namespace std;
int Fi(int n){
    int numList[100];
    numList[1] = 1;
    numList[2] = 1;
    for(int i = 3;i<=n;i++){
        numList[i] = numList[i-2] + numList[i-1];
    }
    return numList[n];
}
int main(void){
    for(int i = 1;i<=10;i++){
        cout<<i<<"번째 항 : "<<Fi(i)<<endl;
    }
    return 0;
}