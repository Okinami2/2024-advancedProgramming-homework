
#include <iostream>
#include<limits>

using namespace std;

int main()
{
    int x;
    while (true) {
        cout << "������x��ֵ[0-100] : ";
        cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ

        // �ж������Ƿ�Ϊ����
        if (cin.fail()) {
            cin.clear(); // ��������־
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �����������е������ַ�ֱ����һ�����з�
        }
        else if (x >= 0 && x <= 100) {
            break;
        }
    }
    cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

    return 0;
}
