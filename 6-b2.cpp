/* 2352219 ��Ӧ�� ��11 */
#include <iostream>
#include<cstring>


using namespace std;

int isCricle(const char * in) {
    int len = strlen(in);
    const char* p = in;
    const char* q = in + len - 2;
    while (p < q) {
        if (*p != *q)
            break;
        p++;
        q--;
    }
    return *p == *q ? 1: 0;
}

int main() {

	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	char in[81] = { 0 };
	fgets(in,81, stdin);
    cout <<(isCricle(in) ? "yes" : "no")<<endl;
	return 0;
}
