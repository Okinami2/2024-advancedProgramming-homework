
#include<iostream>

using namespace std;

int main()
{
    cout << "ÇëÊäÈë[1-100ÒÚ£©Ö®¼äµÄÊý×Ö:" << endl;
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


    cout << "´óÐ´½á¹ûÊÇ:" << endl;

    bool flag = true;

    switch (sy) {
        case 9:
            cout << "¾ÁÊ°";
            break;
        case 8:
            cout << "¾ÁÊ°";
            break;
        case 7:
            cout << "¾ÁÊ°";
            break;
        case 6:
            cout << "Â½Ê°";
            break;
        case 5:
            cout << "ÎéÊ°";
            break;
        case 4:
            cout << "ËÁÊ°";
            break;
        case 3:
            cout << "ÈþÊ°";
            break;
        case 2:
            cout << "·¡Ê°";
            break;
        case 1:
            cout << "Ò¼Ê°";
            break;
        case 0:
            flag = 0;
            break;
    }
    switch (y) {
        case 9:
            cout << "¾ÁÒÚ";
            break;
        case 8:
            cout << "¾ÁÒÚ";
            break;
        case 7:
            cout << "¾ÁÒÚ";
            break;
        case 6:
            cout << "Â½ÒÚ";
            break;
        case 5:
            cout << "ÎéÒÚ";
            break;
        case 4:
            cout << "ËÁÒÚ";
            break;
        case 3:
            cout << "ÈþÒÚ";
            break;
        case 2:
            cout << "·¡ÒÚ";
            break;
        case 1:
            cout << "Ò¼ÒÚ";
            break;
        case 0:
            if (flag) {
                cout << "ÒÚ";
            }
            break;
    }

    switch (qw) {
        case 9:
            cout << "¾ÁÇª";
            break;
        case 8:
            cout << "¾ÁÇª";
            break;
        case 7:
            cout << "¾ÁÇª";
            break;
        case 6:
            cout << "Â½Çª";
            break;
        case 5:
            cout << "ÎéÇª";
            break;
        case 4:
            cout << "ËÁÇª";
            break;
        case 3:
            cout << "ÈþÇª";
            break;
        case 2:
            cout << "·¡Çª";
            break;
        case 1:
            cout << "Ò¼Çª";
            break;
        case 0:
            if (!flag && y != 0) {
                flag = 1;
            }
            if (flag && bw + sw + w != 0) {
                cout << "Áã";
                flag = 0;
            }
            break;
    }

    switch (bw) {
        case 9:
            cout << "¾Á°Û";
            break;
        case 8:
            cout << "¾Á°Û";
            break;
        case 7:
            cout << "¾Á°Û";
            break;
        case 6:
            cout << "Â½°Û";
            break;
        case 5:
            cout << "Îé°Û";
            break;
        case 4:
            cout << "ËÁ°Û";
            break;
        case 3:
            cout << "Èþ°Û";
            break;
        case 2:
            cout << "·¡°Û";
            break;
        case 1:
            cout << "Ò¼°Û";
            break;
        case 0:
            if (!flag && qw != 0) {
                flag = 1;
            }
            if (flag && sw + w != 0) {
                cout << "Áã";
                flag = 0;
            }
            break;
    }

    switch (sw) {
        case 9:
            cout << "¾ÁÊ°";
            break;
        case 8:
            cout << "¾ÁÊ°";
            break;
        case 7:
            cout << "¾ÁÊ°";
            break;
        case 6:
            cout << "Â½Ê°";
            break;
        case 5:
            cout << "ÎéÊ°";
            break;
        case 4:
            cout << "ËÁÊ°";
            break;
        case 3:
            cout << "ÈþÊ°";
            break;
        case 2:
            cout << "·¡Ê°";
            break;
        case 1:
            cout << "Ò¼Ê°";
            break;
        case 0:
            if (!flag && bw != 0) {
                flag = 1;
            }
            if (flag && w != 0) {
                cout << "Áã";
                flag = 0;
            }
            break;
    }
    switch (w) {
        case 9:
            cout << "¾ÁÍò";
            break;
        case 8:
            cout << "¾ÁÍò";
            break;
        case 7:
            cout << "¾ÁÍò";
            break;
        case 6:
            cout << "Â½Íò";
            break;
        case 5:
            cout << "ÎéÍò";
            break;
        case 4:
            cout << "ËÁÍò";
            break;
        case 3:
            cout << "ÈþÍò";
            break;
        case 2:
            cout << "·¡Íò";
            break;
        case 1:
            cout << "Ò¼Íò";
            break;
        case 0:
            if (qw + bw + sw != 0) {
                cout << "Íò";
            }
            if (!flag && sw != 0) {
                flag = 1;
            }
            break;
    }
    switch (q) {
        case 9:
            cout << "¾ÁÇª";
            break;
        case 8:
            cout << "¾ÁÇª";
            break;
        case 7:
            cout << "¾ÁÇª";
            break;
        case 6:
            cout << "Â½Çª";
            break;
        case 5:
            cout << "ÎéÇª";
            break;
        case 4:
            cout << "ËÁÇª";
            break;
        case 3:
            cout << "ÈþÇª";
            break;
        case 2:
            cout << "·¡Çª";
            break;
        case 1:
            cout << "Ò¼Çª";
            break;
        case 0:
            if (!flag && w != 0) {
                flag = 1;
            }
            if (flag && b + s + g != 0) {
                cout << "Áã";
                flag = 0;
            }
            break;
    }
    switch (b) {
        case 9:
            cout << "¾Á°Û";
            break;
        case 8:
            cout << "¾Á°Û";
            break;
        case 7:
            cout << "¾Á°Û";
            break;
        case 6:
            cout << "Â½°Û";
            break;
        case 5:
            cout << "Îé°Û";
            break;
        case 4:
            cout << "ËÁ°Û";
            break;
        case 3:
            cout << "Èþ°Û";
            break;
        case 2:
            cout << "·¡°Û";
            break;
        case 1:
            cout << "Ò¼°Û";
            break;
        case 0:
            if (!flag && q != 0) {
                flag = 1;
            }
            if (flag && s + g != 0) {
                cout << "Áã";
                flag = 0;
            }
            break;
    }
    switch (s) {
        case 9:
            cout << "¾ÁÊ°";
            break;
        case 8:
            cout << "¾ÁÊ°";
            break;
        case 7:
            cout << "¾ÁÊ°";
            break;
        case 6:
            cout << "Â½Ê°";
            break;
        case 5:
            cout << "ÎéÊ°";
            break;
        case 4:
            cout << "ËÁÊ°";
            break;
        case 3:
            cout << "ÈþÊ°";
            break;
        case 2:
            cout << "·¡Ê°";
            break;
        case 1:
            cout << "Ò¼Ê°";
            break;
            if (!flag && b != 0) {
                flag = 1;
            }
            if (flag && g != 0) {
                cout << "Áã";
                flag = 0;
            }
            break;
    }


    switch (g) {
        case 9:
            cout << "¾ÁÔ²";
            break;
        case 8:
            cout << "¾ÁÔ²";
            break;
        case 7:
            cout << "¾ÁÔ²";
            break;
        case 6:
            cout << "Â½Ô²";
            break;
        case 5:
            cout << "ÎéÔ²";
            break;
        case 4:
            cout << "ËÁÔ²";
            break;
        case 3:
            cout << "ÈþÔ²";
            break;
        case 2:
            cout << "·¡Ô²";
            break;
        case 1:
            cout << "Ò¼Ô²";
            break;
        case 0:
            if (sy + y + qw + bw + sw + w + q + b + s != 0) {
                cout << "Ô²";
            }
            else if (jiao + fen == 0) {
                cout << "ÁãÔ²";
            }
            if (!flag && s != 0) {
                flag = 1;
            }

            break;
    }

    switch (jiao) {
        case 9:
            cout << "¾Á½Ç";
            break;
        case 8:
            cout << "¾Á½Ç";
            break;
        case 7:
            cout << "¾Á½Ç";
            break;
        case 6:
            cout << "Â½½Ç";
            break;
        case 5:
            cout << "Îé½Ç";
            break;
        case 4:
            cout << "ËÁ½Ç";
            break;
        case 3:
            cout << "Èþ½Ç";
            break;
        case 2:
            cout << "·¡½Ç";
            break;
        case 1:
            cout << "Ò¼½Ç";
            break;
        case 0:
            if (!flag && g != 0) {
                flag = 1;
            }
            if (flag && fen != 0) {
                cout << "Áã";
                flag = 0;
            }
            break;
    }

    if (fen == 0) {
        cout << "Õû"<<endl;
        return 0;
    }

    switch (fen) {
        case 9:
            cout << "¾Á·Ö";
            break;
        case 8:
            cout << "°Æ·Ö";
            break;
        case 7:
            cout << "Æâ·Ö";
            break;
        case 6:
            cout << "Â½·Ö";
            break;
        case 5:
            cout << "Îé·Ö";
            break;
        case 4:
            cout << "ËÁ·Ö";
            break;
        case 3:
            cout << "Èþ·Ö";
            break;
        case 2:
            cout << "·¡·Ö";
            break;
        case 1:
            cout << "Ò¼·Ö";
            break;
        case 0:
            break;
    }
    cout <<endl;

    return 0;

}