/* 2352219 ��Ӧ�� ��11 */
#include <iostream>

using namespace std;

//count[] 0=��д,1=Сд��2=���֣�3=�ո�4=����
void co(char map[3][128], int count[]) {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 128; j++) {
            char t = map[i][j];
            if (t == '\0')
                break;
            if (t <= 'Z' && t >= 'A')
                count[0]++;
            else if (t <= 'z' && t >= 'a')
                count[1]++;
            else if (t <= '9' && t >= '0')
                count[2]++;
            else if (t == ' ')
                count[3]++;
            else
                count[4]++;
        }
    }
}

int main() {

    char map[3][128];
    for (int i = 0; i < 3; i++) {
        cout << "�������" << i+1 << "��" << endl;
        cin.getline(map[i], 127, '\n');
    }

    int count[5] = { 0 };

    co(map, count);

    cout << "��д: " << count[0] << endl;
    cout << "Сд: " << count[1] << endl;
    cout << "����: " << count[2] << endl;
    cout << "�ո�: " << count[3] << endl;
    cout << "����: " << count[4] << endl;

    return 0;
}
