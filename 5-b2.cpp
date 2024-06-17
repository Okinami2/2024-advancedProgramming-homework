
#include <iostream>
using namespace std;


int main()
{
    int arr[101] = { 0 };
	for (int i = 1; i <= 100; i++){
		for (int j = i; j <= 100; )
		{
			arr[j] = arr[j]^1;
			j += i;
		}
	}
	int count = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (arr[i] == 1) {
			if (count != 0)
				cout << ' ';
			cout << i;
			count++;
		}
			
	}
    return 0;
}
