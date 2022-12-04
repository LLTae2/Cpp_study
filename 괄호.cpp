#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    string arr;
    cin >> n;
    cin.ignore();
    for(int i = 0;i < n;i++){
        int flag = 0;
        stack<int> stk;
        cin >> arr;
        for(int j = 0;arr[j] != '\0';j++){
            if(arr[j] == '(')stk.push(1);
            else {
                if(stk.empty()) {
                    cout << "NO" << '\n';
                    flag = 1;
                    break;
                } 
                else stk.pop();
            }
        }
		if(!stk.empty()) cout << "NO" << '\n';
        else if(flag == 0) cout << "YES" << '\n';
    }
    return 0;
}