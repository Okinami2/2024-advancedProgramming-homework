
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */



void print_block(int count) {
	if (count == 0) {
		return;
	}
	if (count == 1) {
		cout << ' ';
		return;
	}
	else {
		cout << ' ';
		print_block(count - 1);
	}
}

void print_abc(char end_ch) {

	if (end_ch == 'A') {
		cout << 'A';
	}
	else {
		cout << end_ch;
		print_abc(end_ch - 1);
		cout << end_ch;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡ��ĸ��
  ���������
  �� �� ֵ��
  ˵    �����βΰ�������
			��ʾ����һ������order��ָ������/����
***************************************************************************/
void print_tower(char end_ch, bool order)
{
	static int x = end_ch - 'A';
	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */
	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */
	if (order) {
		if (end_ch != 'A') {
			print_tower(end_ch - 1, true);
		}
		print_block(x - (end_ch - 'A'));
		print_abc(end_ch);
		cout << endl;
	}
	else {
		print_block(x - (end_ch - 'A'));
		print_abc(end_ch);
		cout << endl;
		if (end_ch != 'A') {
			print_tower(end_ch - 1, false);
		}

	}


}



/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, true); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, false); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl;/* ����ĸ����������= */
	print_tower(end_ch, true);   //��ӡ A~�����ַ��������� 
	print_tower(end_ch - 1, false);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}
