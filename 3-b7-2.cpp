/*2352219 ��Ӧ�� ��11*/

#include<iostream>

using namespace std;

int main()
{
	cout << "����������ֵ��" << endl;

	double money;
	cin >> money;
	money += 0.001;
	int fiftyCount = 0, twentyCount = 0, tenCount = 0, fiveYuanCount = 0, yuanCount = 0��
	int fiveJiaoCount = 0, jiaoCount = 0,fiveFenCount = 0, twoFenCount = 0, fenCount = 0;
	
	fiftyCount = (int)money / 50;
	money -= fiftyCount * 50;
	twentyCount = (int)money / 20;
	money -= twentyCount * 20;
	tenCount = (int)money / 10;
	money -= tenCount * 10;
	fiveYuanCount = (int)money / 5;
	money -= fiveYuanCount * 5;
	yuanCount = (int)money / 1;
	money -= yuanCount * 1;
	
	fiveJiaoCount = (int)(money / 0.5);
	money -= fiveJiaoCount * 0.5;
	jiaoCount = (int)(money / 0.1);
	money -= jiaoCount * 0.1;
	
	fiveFenCount = (int)(money / 0.05);
	money -= fiveFenCount * 0.05;
	twoFenCount = (int)(money / 0.02);
	money -= twoFenCount * 0.02;
	fenCount = (int)(money / 0.01);
	money -= fenCount * 0.01;
	
	
	int count = fiftyCount+twentyCount+tenCount+fiveYuanCount+yuanCount+fiveJiaoCount+jiaoCount+ fiveFenCount+twoFenCount+fenCount;

	cout << "��" << count << "�����㣬�������£�" << endl;
	if (fiftyCount){
		cout << "50Ԫ : " << fiftyCount <<"��" << endl;
	}
		
	if (twentyCount){
		cout << "20Ԫ : " << twentyCount <<"��" << endl;
	}
	
	if (tenCount){
		cout << "10Ԫ : " << tenCount <<"��" << endl;
	}
	if (fiveYuanCount){
		cout << "5Ԫ  : " << fiveYuanCount << "��" << endl;
	}
	if (yuanCount){
		cout << "1Ԫ  : " << yuanCount << "��" << endl;
	}
	if (fiveJiaoCount){
		cout << "5��  : " << fiveJiaoCount << "��" << endl;
	}
	if (jiaoCount){
		cout << "1��  : " << jiaoCount << "��" << endl;
	}
	if (fiveFenCount){
		cout << "5��  : " << fiveFenCount << "��" << endl;
	}
	if (twoFenCount){
		cout << "2��  : " << twoFenCount << "��" << endl;
	}
	if (fenCount){
		cout << "1��  : " << fenCount << "��" << endl;
	}

	return 0;

}
