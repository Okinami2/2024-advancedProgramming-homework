/*陈应波 信11 2352219*/
#include <iostream>
using namespace std;

int main()
{
    int n = 0, v = 0, co = 0;
    int arr[10000];
    cout << "请输入数据的个数[1..10000]" << endl;
    cin >> n;
    cout << "请输入" << n << "个正整数" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "请输入数码[0..9]" << endl;
    cin >> v;
    for (int i = 0; i < n; i++) {
        int temp = arr[i];
        while (temp > 0) {
            if (temp % 10 == v) {
                co++;
            }
            temp /= 10;
        }
    }
    cout << n << "个数中含有" << v << "的个数 : " << co << endl;
    return 0;
}
