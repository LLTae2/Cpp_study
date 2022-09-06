#include <iostream>
using namespace std;
int main() {
	int n, key, temp;
	cin >> n;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];	
	}
	for(int i = 0;i < n;i++){
		int min = arr[i];
		for(int j = i+1;j < n;j++){
			key = i;
			if(arr[j] < min){
				min = arr[j];
				key = j;
			}
			temp = arr[i];
			arr[i] = arr[key];
			arr[key] = temp;
		}
	}
	for(int i = 0;i < n;i++){
		cout << arr[i] << " ";	
	}
	return 0;
}