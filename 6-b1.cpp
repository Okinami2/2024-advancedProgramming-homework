/* 2352219 ��Ӧ�� ��11 */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */
using namespace std;

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	cin >> str;
	p = str;
	pa = a;
	pnum = a;

	while (pa != a + 10) {
		is_num = false;
		while (*p != '\0') {
			if (*p >= '0' && *p <= '9') {
				*pa = *pa * 10 + (*p - '0');
				is_num = true;
			}
			else
				break;
			p++;
		}
		p++;
		if(is_num)
			pa++;
		if (*p == '\0')
			break;
	}
	cout << "����"<< (pa - a) <<"������" << endl;
	for ( ; pnum < pa; ) {
		cout << *pnum << " ";
		pnum++;
	}
	
	return 0;
}
