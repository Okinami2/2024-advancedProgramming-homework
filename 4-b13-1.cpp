/* 2352219 ��Ӧ�� ��11 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

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
    static int count = 1;
    count++;
    if (n == 1) {
        cout << setw(5) << setfill(' ') << count <<':' << setw(3) << setfill(' ') << n << "#" << " " << src << "-->" << dst << endl;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        cout << setw(5) << setfill(' ') << count <<':' << setw(3) << setfill(' ') << n << "#" << " " << src << "-->" << dst << endl;
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
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (n <= 16 && n >= 1) {
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
    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);
}
