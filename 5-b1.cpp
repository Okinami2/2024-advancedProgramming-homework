
#include <iostream>
using namespace std;


int main()
{
    cout << "��������������������������20������0������������" << endl;
    int a[21];
    int i = 0,in;
    do{

        cin >> in;
        if (in <= 0)
        {
            break;
        }
        else {
            a[i] = in;
            i++;
        }
    } while (i<20);
    if(i==0){
        cout << "����Ч����" << endl;
        return 0;
    }
    cin.clear();
    cin.ignore(65536,'\n');
    cout << "ԭ����Ϊ��" << endl;
    for (int j = 0; j <i; j++)
    {
        cout << a[j] << " ";
    }
    cout << "\n������Ҫ�����������" << endl;
    cin >> in;
    if (in >= a[i - 1]) {
        a[i] = in;
    }
    else {
        for (int k = 0; k <i; k++)
        {
            if (a[k] >= in) {
                for (int c = 20; c > k; c--) {
                    a[c] = a[c - 1];
                }
                a[k] = in;
                break;
            }
        }
    }
    cout << "����������Ϊ��" << endl;
    for (int j = 0; j <= i; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;

    return 0;
}
