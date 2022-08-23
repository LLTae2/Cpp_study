#include <iostream>
using namespace std;
int main() {
	// 대64 소97
	int flag = 0;
	char arr1[101]={}, arr2[101]={};
	int count1[150]={}, count2[150]={};
	cin >> arr1 >> arr2;
	for(int i = 0;arr1[i] != '\0';i++){
		count1[arr1[i]]++;
		count2[arr2[i]]++;
	}
	for(int i = 47;i <= 73;i++){
		if(count1[i] == count2[i])flag = 1;
		else flag = 0;
	}
	for(int i = 96;i <= 122;i++){
		if(count1[i] == count2[i])flag = 1;
		else flag = 0;
	}
	if(flag == 1)cout << "YES";
	else cout << "NO";
	
	return 0;
}