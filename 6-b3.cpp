
#include <iostream>
#include<cstring>


using namespace std;

unsigned int count(const char * in) {
    int len = strlen(in);
	int sum = 0;
    const char* p = in;
	for (int i = 0; i < len - 1; i++)
	{
		sum += (int)(*(p + i) - '0') * pow(2, len - 2 - i);
	}
    return sum;
}

int main() {

	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	char in[34] = { 0 };
	fgets(in,34, stdin);
    cout <<count(in)<<endl;
	return 0;
}
