/*��Ӧ�� ��11 2352219*/
#include <iostream>
using namespace std;

int main()
{
    int n = 0, v = 0, co = 0;
    int arr[10000];
    cout << "���������ݵĸ���[1..10000]" << endl;
    cin >> n;
    cout << "������" << n << "��������" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "����������[0..9]" << endl;
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
    cout << n << "�����к���" << v << "�ĸ��� : " << co << endl;
    return 0;
}
