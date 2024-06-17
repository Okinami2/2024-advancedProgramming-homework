/* 学号 姓名 班级 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	cout << "请输入[1-100亿）之间的数字:" << endl;
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


	cout << "大写结果是:" << endl;
	daxie(sy, 0);
	if(sy != 0)
	cout << "拾";
	daxie(y, 0);
	if (y + sy != 0)
	cout << "亿";

	daxie(qw, y != 0);
	if (qw != 0)
	cout << "仟";
	daxie(bw, qw != 0);
	if (bw != 0)
	cout << "佰";
	daxie(sw, bw != 0);
	if (sw != 0)
	cout << "拾";
	daxie(w, 0);
	if (qw + bw+sw+w != 0)
	cout << "万";

	daxie(q, qw + bw + sw + w != 0);
	if (q != 0)
	cout << "仟";
	daxie(b, q != 0);
	if (b != 0)
	cout << "佰";
	daxie(s, b != 0);
	if (s != 0)
	cout << "拾";
	daxie(g, 0);
	if (q + b + s + g != 0)
	cout << "圆";
	if (jiao == 0 && fen == 0) {
		cout << "整";
		return 0;
	}
	daxie(jiao, q + b + s + g != 0);
	if (jiao != 0)
	cout << "角";
	if (fen == 0) {
		cout << "整";
		return 0;
	}
	daxie(fen, jiao != 0);
	cout << "分";

	return 0;
}
