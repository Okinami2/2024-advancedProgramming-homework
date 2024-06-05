#include<iostream>
using namespace std;
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int k = 5;
	for ( ; k > 0;k--) {
		arr[k] = arr[k - 1];
	}
	cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4];
	return 0;
}