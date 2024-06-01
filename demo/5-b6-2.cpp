/* 2352219 ��11 ��Ӧ�� */
#include <iostream>
#include <iomanip>

int sum = 1;
int arr[3][10] = { 0 };
int stack[3] = { 1 };
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */


void init(int n, char src, char tmp, char dst) {
    //��Ӧ��ϵΪ��arr˳��ABC��num˳��src,dst,tmp
    
    for (int i = 0; i < n; i++)
    {
        arr[src - 65][i] = n - i;
    }
    stack[src - 65] = n;
    
}
void showStatus() {
    //A:                     B:                     C:10 9 8 7 6 5 4 3 2 1
    for (int i = 0; i < 3; i++)
    {
        cout << (char)(65 + i) << ':';
        if (arr[i][0]==0) {
            cout << "   ";
        }
        else if(arr[i][0]!=10) {
            cout << ' ' << arr[i][0] << ' ';
        }
        else {
            cout << arr[i][0] << ' ';
        }

        for (int j = 1; j < 10; j++)
        {
            if (arr[i][j] != 0) {
                cout << arr[i][j] << ' ';
            }
            else {
                cout << "  ";
            }
        }
    }
    cout << endl;
}

void changeStatus(int n, char src, char dst) {
    //arr[][],num[]
    //��Ӧ��ϵΪ��arr˳��ABC��stack[]ָ��
    arr[dst - 65][stack[dst - 65]] = n;
    stack[dst - 65] += 1;
    arr[src - 65][stack[src - 65] - 1] = 0;
    stack[src - 65] -= 1;


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
        cout << "��" << setw(4) << setfill(' ') << sum++ << ' ' << "��("
            << setw(2) << setfill(' ') << n << "): " <<  src << "-->" << dst << ' ';
        changeStatus(n, src, dst);
        showStatus();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        cout << "��" << setw(4) << setfill(' ') << sum++ << ' ' << "��("
            << setw(2) << setfill(' ') << n << "): " << src << "-->" << dst << ' ';
        changeStatus(n, src, dst);
        showStatus();
        hanoi(n - 1, tmp, src, dst);
    }

}



/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
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
    init(n, src, tmp, dst);
    cout << "��ʼ:                ";
    showStatus();
    hanoi(n, src, tmp, dst);
}
