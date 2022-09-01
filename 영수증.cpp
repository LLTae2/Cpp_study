#include <iostream>
using namespace std;

int main() {
    int n, value, a, b, sum = 0;
    cin >> value >> n;
    for(int i = 0;i < n;i++){
        cin >> a >> b;
        sum += a * b;
    }
    if(sum == value)cout << "Yes";
    else cout << "No";
    return 0;
}