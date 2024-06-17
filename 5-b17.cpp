
#include <iostream>
#include<string>
#include <time.h>

static const char other[] = "!@#$%^&*-_=+,.?";

using namespace std;


int isIllegal(int len, int upper, int lower, int intiger, int others) {
    if (len < 12 || len > 16) {
        cout << "���볤��[" << len << "]����ȷ" << endl;
        return 0;
    }
    if (upper < 2 || upper > len) {
        cout << "��д��ĸ����[" << upper << "]����ȷ" << endl;
        return 0;
    }
    if (lower < 2 || lower > len) {
        cout << "Сд��ĸ����[" << lower << "]����ȷ" << endl;
        return 0;
    }
    if (intiger < 2 || intiger > len) {
        cout << "���ָ���[" << intiger << "]����ȷ" << endl;
        return 0;
    }
    if (others < 2 || others > len) {
        cout << "�������Ÿ���[" << others << "]����ȷ" << endl;
        return 0;
    }
    if (upper + lower + intiger + others != len) {
        cout << "�����ַ�����֮��[" << upper << "+" << lower << "+" << intiger << "+" << others << "]���������볤��[" << len << "]" << endl;
        return 0;
    }
    return 1;

}

void createPasswd(int len, int upper, int lower, int intiger, int others,char passwd[]) {
    int lenCount = 0;
    int upperCount = 0; 
    int lowerCount = 0;
    int intigerCount = 0;
    int othersCount = 0;
    for (int i = 0; i < len; )
    {
        int p = rand() % 93 + 33;
        if (p >= 'A' && p <= 'Z' && upperCount < upper) {
            int flag = 0;
            for (int j = 0; j < i; j++)
            {
                if (p == passwd[j])
                    flag = 1;
            }
            if (flag)
                continue;
            passwd[i++] = p;
            upperCount++;
        }
        else if (p >= 'a' && p <= 'z' && lowerCount < lower) {
            int flag = 0;
            for (int j = 0; j < i; j++)
            {
                if (p == passwd[j])
                    flag = 1;
            }
            if (flag)
                continue;
            passwd[i++] = p;
            lowerCount++;
        }
        else if (p >= '0' && p <= '9' && intigerCount < intiger) {
            int flag = 0;
            for (int j = 0; j < i; j++)
            {
                if (p == passwd[j])
                    flag = 1;
            }
            if (flag)
                continue;
            intigerCount++;
            passwd[i++] = p;
        }
        else if (othersCount < others) {
             int t = rand() % 15;
             int flag = 0;
            for (int j = 0; j < i; j++)
            {
                 if (other[t] == passwd[j])
                     flag = 1;
            }
            if (flag)
               continue;
            passwd[i++] = other[t];
            othersCount++;
        }
    }
}

int main() {

    /* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
    srand((unsigned int)(time(0)));

    int len, upper, lower, intiger, others;
    cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
    cin >> len >> upper >> lower >> intiger >> others;
    if (cin.fail()) {
        cout << "����Ƿ�" << endl;
        return -1;
    }
    if (isIllegal(len, upper, lower, intiger, others)) {
        cout << len << ' ' << upper << ' ' << lower << ' ' << intiger << ' ' << others << endl;

        for (int i = 0; i < 10; i++)
        {
            char passwd[17] = { 0 };
            createPasswd(len, upper, lower, intiger, others, passwd);
            cout << passwd << endl;
        }
    }


    return 0;
}
