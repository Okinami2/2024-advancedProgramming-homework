/* 2352219 ��Ӧ�� ��11 */
#include <iostream>
#include<string>

using namespace std;

void input(string name[10], string no[10], int grade[]) {
    for (int i = 0; i < 10; i++) {
        cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
        cin >> no[i] >> name[i] >> grade[i];
    }
}


void sort(string name[10], string no[10], int grade[]) {

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (grade[j] > grade[j + 1]) {
                swap(name[j], name[j + 1]);
                swap(no[j], no[j + 1]);
                int tmp = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = tmp;
            }
        }
    }
}

void output(string name[10], string no[10], int grade[]) {
    cout << "\n����������(�ɼ�����):" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (grade[i] < 60)
            cout << name[i] << ' ' << no[i] << ' ' << grade[i] << endl;
    }
}
int main() {

    string name[10];
    string no[10];
    int grade[10];
    input(name, no, grade);

    sort(name, no, grade);

    output(name, no, grade);

    return 0;
}
