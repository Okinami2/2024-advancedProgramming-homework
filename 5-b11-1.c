/* 2352219 ��Ӧ�� ��11 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
//��dst��index��ʼ������Ԫ��ȡ�����ŵ�src��
void get(int index) {
	if (index < strlen(chnstr) - 1) { 
		char t[3] = { 0 };
		t[0] = chnstr[index];
		t[1] = chnstr[index + 1];
		t[2] = '\0';
		strcat(result, t);
	}
}

void convert(int num[]) {
	int p = 0;
	int i = 0;
	int n = 0;
	if (num[i] != 0) {
		get(num[i] * 2);
		strcat(result,"ʰ");
	}
	n += num[i];
	i++;
	if (num[i] != 0) {
		get(num[i] * 2);
		strcat(result, "��");
	}
	n += num[i];
	i++;
	for (int j = 1; j < 3;j++) {
		if (num[i] != 0) {
			get(num[i] * 2);
			strcat(result, "Ǫ");
		}
		else {
			if (num[i + 1] != 0 && n) {
				get(num[i]);
			}
		}
		n += num[i];
		i++;

		if (num[i] != 0) {
			get(num[i] * 2);
			strcat(result, "��");
		}
		else {
			if (num[i + 1] != 0 && n) {
				get(num[i]);
			}
		}
		n += num[i];
		i++;
		if (num[i] != 0) {
			get(num[i] * 2);
			strcat(result, "ʰ");
		}
		else {
			if (num[i + 1] != 0 && n) {
				get(num[i]);
			}

		}
		n += num[i];
		i++;
		if (num[i] != 0) {
			get(num[i] * 2);
		}


		n += num[i];
		i++;
		switch (i)
		{
			case 6:
				if(num[2] + num[3] + num[4] + num[5] != 0)
					strcat(result, "��");
				break;
			default:
				if (n != 0)
					strcat(result, "Բ");
				break;
		}
	}

	if (num[i] + num[i + 1] == 0) {
		strcat(result, "��");
	}

	else if (num[i] == 0) {
		if(n)
			get(num[i] * 2);
		i++;
		get(num[i] * 2);
		strcat(result, "��");
	}
	else if(num[i + 1] == 0) {
		get(num[i] * 2);
		strcat(result, "����");
	}
	else {
		get(num[i++] * 2);
		strcat(result, "��");
		get(num[i] * 2);
		strcat(result, "��");

	}


}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* --���������Ҫ������ --*/
	printf("������[1-100�ڣ�֮�������:\n");
	double a;
	scanf("%lf", &a);
	int num[12] = { 0 };
	num[0] = (int)(a / 1000000000);
	num[1] = (int)(a / 100000000 - num[0] * 10);
	num[2] = (int)(a / 10000000 - num[0] * 100 - num[1] * 10);
	num[3] = (int)(a / 1000000 - num[0] * 1000 - num[1] * 100 - num[2] * 10);
	num[4] = (int)(a / 100000 - num[0] * 10000 - num[1] * 1000 - num[2] * 100 - num[3] * 10);
	num[5] = (int)(a / 10000 - num[0] * 100000 - num[1] * 10000 - num[2] * 1000 - num[3] * 100 - num[4] * 10);

	double x = (a - num[0] * 1000000000.0 - num[1] * 100000000.0 - num[2] * 10000000.0 - num[3] * 1000000.0 - num[4] * 100000 - num[5] * 10000) * 100;
	num[6] = (int)(x / 100000);
	num[7] = (int)(x / 10000 - num[6] * 10);
	num[8] = (int)(x / 1000 - num[6] * 100 - num[7] * 10);
	num[9] = (int)(x / 100 - num[6] * 1000 - num[7] * 100 - num[8] * 10);
	num[10] = (int)(x / 10 - num[6] * 10000 - num[7] * 1000 - num[8] * 100 - num[9] * 10 + 0.01);
	num[11] = (int)(x - num[6] * 100000 - num[7] * 10000 - num[8] * 1000 - num[9] * 100 - num[10] * 10 + 0.1);

	
	convert(num);

	printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
	return 0;
}