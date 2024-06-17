/* 2352219 陈应波 信11 */
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

	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	char in[81] = { 0 };
	fgets(in,81, stdin);
    cout <<(isCricle(in) ? "yes" : "no")<<endl;
	return 0;
}
