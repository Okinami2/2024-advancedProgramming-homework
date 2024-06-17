
#include <iostream>
using namespace std;

int main()
{
	int arr[1000];
    cout << "请输入成绩（最多1000个），负数结束输入" << endl;

    int i = 0;
    for (i; i < 1000; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            i--;
            break;
        }
    }
    cout << "输入的数组为:" << endl;
    for (int j = 0; j <= i; )
    {
        cout<<arr[j]<<' ';
        j++;
        if (j % 10 == 0 && j <= i) {
            cout << endl;
        }
    }
    cout << endl;
    int sum = 1;
    cout<<"分数与名次的对应关系为:"<<endl;
    for (int j = 0; j <= i; j++) {
        if (arr[j] == -1)
            continue;
        int count = 0, max = 0;
        for (int k = 0; k <= i; k++) {
            if (arr[k] > max) {
                max = arr[k];
            }
        }
        for (int k = 0; k <= i; k++) {
            if (arr[k] == max) {
                cout << max << " " << sum << endl;
                arr[k] = -1;
                count++;
            }
        }
        sum += count;
    }

	return 0;

}