
#include <iostream>
#include<string>
#include <time.h>

static const char other[] = "!@#$%^&*-_=+,.?";

using namespace std;


int isIllegal(int len, int upper, int lower, int intiger, int others) {
    if (len < 12 || len > 16) {
        cout << "密码长度[" << len << "]不正确" << endl;
        return 0;
    }
    if (upper < 2 || upper > len) {
        cout << "大写字母个数[" << upper << "]不正确" << endl;
        return 0;
    }
    if (lower < 2 || lower > len) {
        cout << "小写字母个数[" << lower << "]不正确" << endl;
        return 0;
    }
    if (intiger < 2 || intiger > len) {
        cout << "数字个数[" << intiger << "]不正确" << endl;
        return 0;
    }
    if (others < 2 || others > len) {
        cout << "其它符号个数[" << others << "]不正确" << endl;
        return 0;
    }
    if (upper + lower + intiger + others != len) {
        cout << "所有字符类型之和[" << upper << "+" << lower << "+" << intiger << "+" << others << "]大于总密码长度[" << len << "]" << endl;
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

    /* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
    srand((unsigned int)(time(0)));

    int len, upper, lower, intiger, others;
    cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
    cin >> len >> upper >> lower >> intiger >> others;
    if (cin.fail()) {
        cout << "输入非法" << endl;
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
