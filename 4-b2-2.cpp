/* 2352219 ��Ӧ�� ��11 */
#include <iostream>
#include<limits>

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

int main()
{

    int year, month, day;
    while (true) {
        cout << "��������[1900-2100]���¡��գ�" << endl;
        cin >> year>>month>>day;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ

        // �ж������Ƿ�Ϊ����
        if (cin.fail()) {
            cin.clear(); // ��������־
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �����������е������ַ�ֱ����һ�����з�
            cout << "�����������������" << endl;
            continue;
        }
        if (year <= 2100 && year >= 1900) {
            if (month <= 12 && month >= 1) {
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 && (day >= 1 && day <= 31))
                    break;
                else if (month == 2) {
                    int flag = 0;
                    if (year % 400 == 0) {
                        flag = 1;
                    }
                    else if (year % 4 == 0 && year % 100 != 0) {
                        flag = 1;
                    }
                    if (flag && day <= 29 && day >= 1)
                        break;
                    else if (!flag && day <= 28 && day >= 1)
                        break;
                }
                else if(day<=30&&day>=1){
                    break;

                }
                cout << "�ղ���ȷ������������" << endl;
            }
            else {
                cout << "�·ݲ���ȷ������������" << endl;
            }
            
        }
        else {
            cout << "��ݲ���ȷ������������" << endl;
        }
    }

    switch (zeller(year, month, day)) {
        case 0:
            cout << "������" << endl;
            break;
        case 1:
            cout << "����һ" << endl;
            break;

        case 2:
            cout << "���ڶ�" << endl;
            break;

        case 3:
            cout << "������" << endl;
            break;

        case 4:
            cout << "������" << endl;
            break;

        case 5:
            cout << "������" << endl;
            break;

        case 6:
            cout << "������" << endl;
            break;
    }

	return 0;
}
