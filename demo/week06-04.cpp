/* ѧ�� ���� �༶ */
#include <iostream>

using namespace std;

int zeller(int y, int m, int d) {
    if (m==1||m==2){
        m = m + 12;
        y -= 1;
    }
    int c = y / 100;
    y = y % 100;
    int w =  y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1;
    while (w<0){
        w += 7;
    }
    return w % 7;
}

void canledar(int week,int year,int month) {
    int count = 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        count = 31;
    else
        count = 30;

    if (month == 2) {
        int flag = 0;
        if (year % 400 == 0) {
            flag = 1;
        }
        else if (year % 4 == 0 && year % 100 != 0) {
            flag = 1;
        }
        if (flag) {
            count = 29;
        }
        else {
            count = 28;
        }
    }
    cout <<endl<< year << "��" << month << "��" << endl;
    cout << "======================================================" << endl;
    cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
    cout << "======================================================" << endl;
    for (int k = 0; k < week; k++) {
        cout << "        ";
    }
    for (int i = 1; i <= count; i++) {
        cout << "  ";

        if (i < 10) {
            cout << " " << i;
        }
        else {
            cout << i;
        }
        cout << "    ";

        if ((i + week) % 7 == 0)
            cout << endl;
    }
    if ((count + week) % 7 != 0)
        cout << endl;
    cout << "======================================================" << endl;
}

int main()
{

    int year, month, day;
    while (true) {
        cout << "��������[1900-2100]���£�" << endl;
        cin >> year>>month;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ

        // �ж������Ƿ�Ϊ����
        if (cin.fail()) {
            cin.clear(); // ��������־
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �����������е������ַ�ֱ����һ�����з�
            cout << "�����������������" << endl;
            continue;
        }
        if (year <= 2100 && year >= 1900) {
            if (month <= 12 && month >= 1) {
                break;
            }
            else {
                cout << "�·ݲ���ȷ������������" << endl;
            }
            
        }
        else {
            cout << "��ݲ���ȷ������������" << endl;
        }
    }
    canledar(zeller(year, month, 1), year, month);

	return 0;
}
