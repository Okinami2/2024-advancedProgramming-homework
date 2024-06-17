/* 2352219 ��Ӧ�� ��11 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "read_stulist.h"
#include <iomanip>
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list;
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	int round_1 = 0;
	int round_2 = 0;
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	friend stu_list;
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void sort();
	void merge();
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */


/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
void stu_list::sort() {
	for (int i = 0; i < list_num_1 - 1; ++i) {
		for (int j = 0; j < list_num_1 - 1 - i; ++j) {
			if (list_round_1[j].no > list_round_1[j + 1].no) {
				std::swap(list_round_1[j], list_round_1[j + 1]);
			}
		}
	}

	for (int i = 0; i < list_num_2 - 1; ++i) {
		for (int j = 0; j < list_num_2 - 1 - i; ++j) {
			if (list_round_2[j].no > list_round_2[j + 1].no) {
				std::swap(list_round_2[j], list_round_2[j + 1]);
			}
		}
	}
}

void stu_list::merge() {
	int i = 0, j = 0, k = 0; // i����list_round_1�±꣬j����list_round_2�±꣬k����list_merge�±�
	while (i < list_num_1 && j < list_num_2) {
		if (list_round_1[i].no < list_round_2[j].no) {
			list_merge[k].stu_no = list_round_1[i].no;
			strcpy(list_merge[k].stu_name, list_round_1[i].name);
			list_merge[k].round_1 = 1;
			k++;
			i++;
			while (i < list_num_1 && list_round_1[i].no == list_merge[k - 1].stu_no) {
				i++;
			}
		}
		else if (list_round_1[i].no > list_round_2[j].no) {
			list_merge[k].stu_no = list_round_2[j].no;
			strcpy(list_merge[k].stu_name, list_round_2[j].name);
			list_merge[k].round_2 = 1;
			k++;
			j++;
			while (j < list_num_2 && list_round_2[j].no == list_merge[k - 1].stu_no) {
				j++;
			}
		}
		else {
			list_merge[k].stu_no = list_round_1[i].no;
			strcpy(list_merge[k].stu_name, list_round_1[i].name);
			list_merge[k].round_1 = 1;
			list_merge[k].round_2 = 1;
			k++;
			i++;
			j++;
			while (i < list_num_1 && list_round_1[i].no == list_merge[k - 1].stu_no) {
				i++;
			}
			while (j < list_num_2 && list_round_2[j].no == list_merge[k - 1].stu_no) {
				j++;
			}
		}
	}
	// ����ʣ���Ԫ��
	while (i < list_num_1) {
		list_merge[k].stu_no = list_round_1[i].no;
		strcpy(list_merge[k].stu_name, list_round_1[i].name);
		list_merge[k].round_1 = 1;
		k++;
		i++;
		while (i < list_num_1 && list_round_1[i].no == list_merge[k - 1].stu_no) {
			i++;
		}
	}
	while (j < list_num_2) {
		list_merge[k].stu_no = list_round_2[j].no;
		strcpy(list_merge[k].stu_name, list_round_2[j].name);
		list_merge[k].round_2 = 1;
		k++;
		j++;
		while (j < list_num_2 && list_round_2[j].no == list_merge[k - 1].stu_no) {
			j++;
		}
	}

	list_merge_num = k;
}
int stu_list::print(const char* prompt)
{
	if(prompt != NULL)
		cout << prompt<<endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ��� " << endl;
	cout << "============================================================" << endl;
	for (int i = 0; i < list_merge_num; i++)
	{
			cout << left;
			cout << setw(5) << i + 1 << setw(9) << list_merge[i].stu_no << setw(32) << list_merge[i].stu_name << setw(7) << 'Y';
			cout<<(list_merge[i].round_2 ? "Y" : "�˿�") << endl;
	}
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */

	list.sort();
	list.merge();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

