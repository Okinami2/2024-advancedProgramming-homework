

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{

	int x = 0;
	double result = 1;
	while (true) {

		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
		if (x < -10 || x > 65) {
			cout << "����Ƿ�������������" << endl;
		}
		else {
			break;
		}
	}
	int i =1;
	double tem = x;
	do {
		result += tem;
		tem = tem * x / ++i + 0.000000000000001;
	} while (abs(tem) >= 0.000001);
	cout << setprecision(10);
	cout << "e^" << x << "=" << result << endl;
    return 0;
}