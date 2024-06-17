
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include<iomanip>
#include "5-b7.h"
static int delay = 0, show = 0;
int sum = 1, ap = 0, bp = 0, cp = 0;
int a[10] = { 0 };
int b[10] = { 0 };
int c[10] = { 0 };
using namespace std;
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

void showStatus() {
    //A:                     B:                     C:10 9 8 7 6 5 4 3 2 1
    cout<< 'A' <<":";
    if (a[0] == 0) {
        cout<<"   ";
    }
    else if (a[0] != 10) {
        cout << " " << a[0] << " ";
    }
    else {
        cout<< a[0] <<" ";
    }
    for (int i = 1; i < 10; i++) {
        if (a[i] != 0) {
            cout<< a[i] <<" ";
        }
        else {
            cout<< "  ";
        }
    }

    //b
    cout << 'B' << ":";
    if (b[0] == 0) {
        cout << "   ";
    }
    else if (b[0] != 10) {
        cout << " " << b[0] << " ";
    }
    else {
        cout << b[0] << " ";
    }
    for (int i = 1; i < 10; i++) {
        if (b[i] != 0) {
            cout << b[i] << " ";
        }
        else {
            cout << "  ";
        }
    }
    //c
    cout << 'C' << ":";
    if (c[0] == 0) {
        cout << "   ";
    }
    else if (c[0] != 10) {
        cout << " " << c[0] << " ";
    }
    else {
        cout << c[0] << " ";
    }
    for (int i = 1; i < 10; i++) {
        if (c[i] != 0) {
            cout << c[i] << " ";
        }
        else {
            cout << "  ";
        }
    }
}

void changeStatus(int n, char src, char dst) {
    //push
    if (dst == 65) {
        a[ap] = n;
        ap += 1;
    }
    else if (dst == 66) {
        b[bp] = n;
        bp += 1;
    }
    else {
        c[cp] = n;
        cp += 1;
    }
    //pop
    if (src == 65) {
        a[ap - 1] = 0;
        ap -= 1;
    }
    else if (src == 66) {
        b[bp - 1] = 0;
        bp -= 1;
    }
    else {
        c[cp - 1] = 0;
        cp -= 1;
    }
}

void showStep(int n, char src, char tmp, char dst) {
    cct_gotoxy(10, 20);
    cout << "=========================";
    cct_gotoxy(13, 21);
    cout << "A         B         C";
    //a��
    for (int i = 0; i < 10; i++) {
        if (a[i] != 0) {
            cct_gotoxy(13, 19 - i);
            cout << a[i];
        }
        else {
            cct_gotoxy(13, 19 - i);
            cout << ' ';
        }
    }
    //b��
    for (int i = 0; i < 10; i++) {
        if (b[i] != 0) {
            cct_gotoxy(23, 19 - i);
            cout << b[i];
        }
        else {
            cct_gotoxy(23, 19 - i);
            cout << ' ';
        }
    }
    //c��
    for (int i = 0; i < 10; i++) {
        if (c[i] != 0) {
            cct_gotoxy(33, 19 - i);
            cout << c[i];
        }
        else {
            cct_gotoxy(33, 19 - i);
            cout << ' ';
        }
    }

}

void initArray(int n, char src, char tmp, char dst) {
    for (int i = 0; i < n; i++)
    {
        if (src == 65) {
            a[i] = n - i;
            ap += 1;
        }
        else if (src == 66) {
            b[i] = n - i;
            bp += 1;
        }
        else {
            c[i] = n - i;
            cp += 1;
        }

    }

}

void initScren(int n, char src, char tmp, char dst) {
    cct_cls();
    cout << "��" << src << "�ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << delay;
    if (show) 
        cout << "����ʾ�ڲ�����ֵ" << endl;
    else
        cout << "������ʾ�ڲ�����ֵ" << endl;
    if (show) {
        cct_gotoxy(20, 25);
        cout << "��ʼ:                ";
        showStatus(); 
        switch (delay)
        {
            case 0:
                while (getchar() != '\n');
                break;
            default:
                Sleep(1000 - delay * 100);
                break;
        }
    }
    showStep(n,src,tmp,dst);
    
}



/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
            2������������������κ���ʽ��ѭ��
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    
    if (n == 1) {
        switch (delay)
        {
            case 0:
                while (getchar() != '\n');
                break;
            default:
                Sleep(1000 - delay * 100);
                break;
        }
        changeStatus(n, src, dst);
        cct_gotoxy(20, 25);
        cout << "��"<< sum++ <<"��("<< n <<"#: "<< src <<"-->"<< dst << ")  ";
        if (show)
            showStatus();
        showStep(n, src, tmp, dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        switch (delay)
        {
            case 0:
                while (getchar() != '\n');
                break;
            default:
                Sleep(1000 - delay * 100);
                break;
        }
        changeStatus(n, src, dst);
        cct_gotoxy(20, 25);
        cout << "��" << sum++ << "��(" << n << "#: " << src << "-->" << dst << ")  ";
        if (show)
            showStatus();
        showStep(n, src, tmp, dst);
        hanoi(n - 1, tmp, src, dst);
    }

}

int main()
{
    int n;
    char src, tmp, dst;
    while (true) {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (n <= 10 && n >= 1) {
            break;
        }

    }
    while (true) {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (src <= 67 && src >= 65) {
            break;
        }
        else if (src <= 99 && src >= 97) {
            src = src - 32;
            break;
        }

    }
    while (true) {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (dst <= 67 && dst >= 65) {
            break;
        }
        else if (dst <= 99 && dst >= 97) {
            dst = dst - 32;
            break;
        }

    }
    if (src == 65) {
        if (dst == 66)
            tmp = 67;
        else
            tmp = 66;
    }
    else if (src == 66) {
        if (dst == 67)
            tmp = 65;
        else
            tmp = 67;
    }
    else {
        if (dst == 65)
            tmp = 66;
        else
            tmp = 65;
    }

    while (true) {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> delay;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (delay <= 5 && delay >= 0) {
            break;
        }

    }

    while (true) {
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> show;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (show==1||show==0) {
            break;
        }

    }

    initArray(n,src,tmp,dst);
    initScren(n, src, tmp, dst);
    hanoi(n, src, tmp, dst);
    cct_gotoxy(1, 26);
	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
	return 0;
}
