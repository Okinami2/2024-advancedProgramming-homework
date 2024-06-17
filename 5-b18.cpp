/* 2352219 ³ÂÓ¦²¨ ÐÅ11 */
#include <iostream>
#include<string>

static const char other[] = "!@#$%^&*-_=+,.?";

using namespace std;


int isIllegal(int len, int upper, int lower, int intiger, int others) {
    if (len < 12 || len > 16) {
        return 0;
    }
    if (upper < 2 || upper > len) {
        return 0;
    }
    if (lower < 2 || lower > len) {
        return 0;
    }
    if (intiger < 2 || intiger > len) {
        return 0;
    }
    if (others < 2 || others > len) {
        return 0;
    }
    if (upper + lower + intiger + others > len)
        return 0;
    else
        return 1;

}

int isCorrect(char passwd[], int len, int upper, int lower, int intiger, int others) {
    int lenCount = 0;
    int upperCount = 0; 
    int lowerCount = 0;
    int intigerCount = 0;
    int othersCount = 0;
    for (int i = 0; i < len; i++)
    {
        char p = passwd[i];
        if (p >= 'A' && p <= 'Z') {
            upperCount++;
        }
        else if (p >= 'a' && p <= 'z') {
            lowerCount++;
        }
        else if (p >= '0' && p <= '9') {
            intigerCount++;
        }
        else{
            int flag = 0;
            for (int j = 0; j < 15; j++)
            {
                if (p == passwd[j])
                    flag = 1;
            }
            if (flag) {
                othersCount++;
            }
            else
                return 0;
        }
    }
    if (upperCount < upper || lowerCount < lower || intigerCount < intiger || othersCount < others)
        return 0;
    else
        return 1;
}

int main() {


    int len, upper, lower, intiger, others;
    while (getchar() != '\n')
        ;
    cin >> len >> upper >> lower >> intiger >> others;
    cin.get();//³ý»»ÐÐ·û
    if (!isIllegal(len, upper, lower, intiger, others)) {
        cout << "´íÎó" << endl;
        return 0;
    }
    else {
        for (int i = 0; i < 10; i++)
        {
            char passwd[17] = { 0 };
            cin.getline(passwd,20,'\n');
            if (!isCorrect(passwd,len,upper,lower,intiger,others)) {
                cout << "´íÎó" << endl;
                return 0;
            }
        }
    }
        
    cout << "ÕýÈ·" << endl;

    return 0;
}
