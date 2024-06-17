/*2352219 陈应波 信11*/

#include<iostream>

using namespace std;

int main()
{
	cout << "请输入找零值：" << endl;

	double money;
	cin >> money;
	money += 0.001;
	int fiftyCount = 0, twentyCount = 0, tenCount = 0, fiveYuanCount = 0, yuanCount = 0；
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

	cout << "共" << count << "张找零，具体如下：" << endl;
	if (fiftyCount){
		cout << "50元 : " << fiftyCount <<"张" << endl;
	}
		
	if (twentyCount){
		cout << "20元 : " << twentyCount <<"张" << endl;
	}
	
	if (tenCount){
		cout << "10元 : " << tenCount <<"张" << endl;
	}
	if (fiveYuanCount){
		cout << "5元  : " << fiveYuanCount << "张" << endl;
	}
	if (yuanCount){
		cout << "1元  : " << yuanCount << "张" << endl;
	}
	if (fiveJiaoCount){
		cout << "5角  : " << fiveJiaoCount << "张" << endl;
	}
	if (jiaoCount){
		cout << "1角  : " << jiaoCount << "张" << endl;
	}
	if (fiveFenCount){
		cout << "5分  : " << fiveFenCount << "张" << endl;
	}
	if (twoFenCount){
		cout << "2分  : " << twoFenCount << "张" << endl;
	}
	if (fenCount){
		cout << "1分  : " << fenCount << "张" << endl;
	}

	return 0;

}
