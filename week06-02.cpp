/* ѧ�� ���� �༶ */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* ������� */
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
	daxie(sy, 0);
	if(sy != 0)
	cout << "ʰ";
	daxie(y, 0);
	if (y + sy != 0)
	cout << "��";

	daxie(qw, y != 0);
	if (qw != 0)
	cout << "Ǫ";
	daxie(bw, qw != 0);
	if (bw != 0)
	cout << "��";
	daxie(sw, bw != 0);
	if (sw != 0)
	cout << "ʰ";
	daxie(w, 0);
	if (qw + bw+sw+w != 0)
	cout << "��";

	daxie(q, qw + bw + sw + w != 0);
	if (q != 0)
	cout << "Ǫ";
	daxie(b, q != 0);
	if (b != 0)
	cout << "��";
	daxie(s, b != 0);
	if (s != 0)
	cout << "ʰ";
	daxie(g, 0);
	if (q + b + s + g != 0)
	cout << "Բ";
	if (jiao == 0 && fen == 0) {
		cout << "��";
		return 0;
	}
	daxie(jiao, q + b + s + g != 0);
	if (jiao != 0)
	cout << "��";
	if (fen == 0) {
		cout << "��";
		return 0;
	}
	daxie(fen, jiao != 0);
	cout << "��";

	return 0;
}
