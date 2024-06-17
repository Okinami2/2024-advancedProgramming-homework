/* 2352219 陈应波 信11 */
#include <iostream>

using namespace std;

//count[] 0=大写,1=小写，2=数字，3=空格，4=其它
void co(char map[3][128], int count[]) {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 128; j++) {
            char t = map[i][j];
            if (t == '\0')
                break;
            if (t <= 'Z' && t >= 'A')
                count[0]++;
            else if (t <= 'z' && t >= 'a')
                count[1]++;
            else if (t <= '9' && t >= '0')
                count[2]++;
            else if (t == ' ')
                count[3]++;
            else
                count[4]++;
        }
    }
}

int main() {

    char map[3][128];
    for (int i = 0; i < 3; i++) {
        cout << "请输入第" << i+1 << "行" << endl;
        cin.getline(map[i], 127, '\n');
    }

    int count[5] = { 0 };

    co(map, count);

    cout << "大写: " << count[0] << endl;
    cout << "小写: " << count[1] << endl;
    cout << "数字: " << count[2] << endl;
    cout << "空格: " << count[3] << endl;
    cout << "其他: " << count[4] << endl;

    return 0;
}
