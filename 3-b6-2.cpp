
#include<iostream>

using namespace std;

int main()
{
    cout << "������[1-100�ڣ�֮�������:" << endl;
    double a;
    cin >> a;

    int g, s, b, q, w, sw, bw, qw, y, sy, jiao, fen;
    sy = (int)(a / 1000000000);
    y = (int)(a / 100000000 - sy * 10);
    qw = (int)(a / 10000000 - sy * 100 - y * 10);
    bw = (int)(a / 1000000 - sy * 1000 - y * 100 - qw * 10);
    sw = (int)(a / 100000 - sy * 10000 - y * 1000 - qw * 100 - bw * 10);
    w = (int)(a / 10000 - sy * 100000 - y * 10000 - qw * 1000 - bw * 100 - sw * 10);

    double x = (a - sy * 1000000000.0 - y * 100000000.0 - qw * 10000000.0 - bw * 1000000.0 - sw * 100000 - w * 10000) * 100;
    q = (int)(x / 100000);
    b = (int)(x / 10000 - q * 10);
    s = (int)(x / 1000 - q * 100 - b * 10);
    g = (int)(x / 100 - q * 1000 - b * 100 - s * 10);
    jiao = (int)(x / 10 - q * 10000 - b * 1000 - s * 100 - g * 10 + 0.01);
    fen = (int)(x - q * 100000 - b * 10000 - s * 1000 - g * 100 - jiao * 10 + 0.1);


    cout << "��д�����:" << endl;

    bool flag = true;

    switch (sy) {
        case 9:
            cout << "��ʰ";
            break;
        case 8:
            cout << "��ʰ";
            break;
        case 7:
            cout << "��ʰ";
            break;
        case 6:
            cout << "½ʰ";
            break;
        case 5:
            cout << "��ʰ";
            break;
        case 4:
            cout << "��ʰ";
            break;
        case 3:
            cout << "��ʰ";
            break;
        case 2:
            cout << "��ʰ";
            break;
        case 1:
            cout << "Ҽʰ";
            break;
        case 0:
            flag = 0;
            break;
    }
    switch (y) {
        case 9:
            cout << "����";
            break;
        case 8:
            cout << "����";
            break;
        case 7:
            cout << "����";
            break;
        case 6:
            cout << "½��";
            break;
        case 5:
            cout << "����";
            break;
        case 4:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 2:
            cout << "����";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 0:
            if (flag) {
                cout << "��";
            }
            break;
    }

    switch (qw) {
        case 9:
            cout << "��Ǫ";
            break;
        case 8:
            cout << "��Ǫ";
            break;
        case 7:
            cout << "��Ǫ";
            break;
        case 6:
            cout << "½Ǫ";
            break;
        case 5:
            cout << "��Ǫ";
            break;
        case 4:
            cout << "��Ǫ";
            break;
        case 3:
            cout << "��Ǫ";
            break;
        case 2:
            cout << "��Ǫ";
            break;
        case 1:
            cout << "ҼǪ";
            break;
        case 0:
            if (!flag && y != 0) {
                flag = 1;
            }
            if (flag && bw + sw + w != 0) {
                cout << "��";
                flag = 0;
            }
            break;
    }

    switch (bw) {
        case 9:
            cout << "����";
            break;
        case 8:
            cout << "����";
            break;
        case 7:
            cout << "����";
            break;
        case 6:
            cout << "½��";
            break;
        case 5:
            cout << "���";
            break;
        case 4:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 2:
            cout << "����";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 0:
            if (!flag && qw != 0) {
                flag = 1;
            }
            if (flag && sw + w != 0) {
                cout << "��";
                flag = 0;
            }
            break;
    }

    switch (sw) {
        case 9:
            cout << "��ʰ";
            break;
        case 8:
            cout << "��ʰ";
            break;
        case 7:
            cout << "��ʰ";
            break;
        case 6:
            cout << "½ʰ";
            break;
        case 5:
            cout << "��ʰ";
            break;
        case 4:
            cout << "��ʰ";
            break;
        case 3:
            cout << "��ʰ";
            break;
        case 2:
            cout << "��ʰ";
            break;
        case 1:
            cout << "Ҽʰ";
            break;
        case 0:
            if (!flag && bw != 0) {
                flag = 1;
            }
            if (flag && w != 0) {
                cout << "��";
                flag = 0;
            }
            break;
    }
    switch (w) {
        case 9:
            cout << "����";
            break;
        case 8:
            cout << "����";
            break;
        case 7:
            cout << "����";
            break;
        case 6:
            cout << "½��";
            break;
        case 5:
            cout << "����";
            break;
        case 4:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 2:
            cout << "����";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 0:
            if (qw + bw + sw != 0) {
                cout << "��";
            }
            if (!flag && sw != 0) {
                flag = 1;
            }
            break;
    }
    switch (q) {
        case 9:
            cout << "��Ǫ";
            break;
        case 8:
            cout << "��Ǫ";
            break;
        case 7:
            cout << "��Ǫ";
            break;
        case 6:
            cout << "½Ǫ";
            break;
        case 5:
            cout << "��Ǫ";
            break;
        case 4:
            cout << "��Ǫ";
            break;
        case 3:
            cout << "��Ǫ";
            break;
        case 2:
            cout << "��Ǫ";
            break;
        case 1:
            cout << "ҼǪ";
            break;
        case 0:
            if (!flag && w != 0) {
                flag = 1;
            }
            if (flag && b + s + g != 0) {
                cout << "��";
                flag = 0;
            }
            break;
    }
    switch (b) {
        case 9:
            cout << "����";
            break;
        case 8:
            cout << "����";
            break;
        case 7:
            cout << "����";
            break;
        case 6:
            cout << "½��";
            break;
        case 5:
            cout << "���";
            break;
        case 4:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 2:
            cout << "����";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 0:
            if (!flag && q != 0) {
                flag = 1;
            }
            if (flag && s + g != 0) {
                cout << "��";
                flag = 0;
            }
            break;
    }
    switch (s) {
        case 9:
            cout << "��ʰ";
            break;
        case 8:
            cout << "��ʰ";
            break;
        case 7:
            cout << "��ʰ";
            break;
        case 6:
            cout << "½ʰ";
            break;
        case 5:
            cout << "��ʰ";
            break;
        case 4:
            cout << "��ʰ";
            break;
        case 3:
            cout << "��ʰ";
            break;
        case 2:
            cout << "��ʰ";
            break;
        case 1:
            cout << "Ҽʰ";
            break;
            if (!flag && b != 0) {
                flag = 1;
            }
            if (flag && g != 0) {
                cout << "��";
                flag = 0;
            }
            break;
    }


    switch (g) {
        case 9:
            cout << "��Բ";
            break;
        case 8:
            cout << "��Բ";
            break;
        case 7:
            cout << "��Բ";
            break;
        case 6:
            cout << "½Բ";
            break;
        case 5:
            cout << "��Բ";
            break;
        case 4:
            cout << "��Բ";
            break;
        case 3:
            cout << "��Բ";
            break;
        case 2:
            cout << "��Բ";
            break;
        case 1:
            cout << "ҼԲ";
            break;
        case 0:
            if (sy + y + qw + bw + sw + w + q + b + s != 0) {
                cout << "Բ";
            }
            else if (jiao + fen == 0) {
                cout << "��Բ";
            }
            if (!flag && s != 0) {
                flag = 1;
            }

            break;
    }

    switch (jiao) {
        case 9:
            cout << "����";
            break;
        case 8:
            cout << "����";
            break;
        case 7:
            cout << "����";
            break;
        case 6:
            cout << "½��";
            break;
        case 5:
            cout << "���";
            break;
        case 4:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 2:
            cout << "����";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 0:
            if (!flag && g != 0) {
                flag = 1;
            }
            if (flag && fen != 0) {
                cout << "��";
                flag = 0;
            }
            break;
    }

    if (fen == 0) {
        cout << "��"<<endl;
        return 0;
    }

    switch (fen) {
        case 9:
            cout << "����";
            break;
        case 8:
            cout << "�Ʒ�";
            break;
        case 7:
            cout << "���";
            break;
        case 6:
            cout << "½��";
            break;
        case 5:
            cout << "���";
            break;
        case 4:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 2:
            cout << "����";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 0:
            break;
    }
    cout <<endl;

    return 0;

}