#include<iostream>
#include"complex_B.h"
#include<windows.h>

using namespace std;

/*	�� cout<< complex ���͵�����    ostream �� cout����	*/
ostream& operator<<(ostream& os, const complex<double>& x)
{

	return os << '(' << real(x) << ',' << imag(x) << ')';
	//return os << '(' << x.real() << ',' << x.imag() << ')';	//ֱ�ӵ��ó�Ա���� real() �� imag()  ������
}


int main(void)
{
	complex<double> c1(2, 1);
	complex<double> c2(4, 0);
	complex<double> c3(-1, 1);
	complex<double> c4;		//c4δ��ʼ�������캯���ḳ��ֵ0��


	cout << "c1=" << c1 << endl;
	cout << "c2=" << c2 << endl;
	cout << "c3=" << c3 << endl;
	cout << "c4=" << c4 << endl << endl;

	cout << "c1==c2  =" << (c1 == c2) << endl;

	cout << "c1+c2" << c1 + c2 << endl;
	cout << "c1+4" << c1 + 4 << endl;
	cout << "2+c2" << 2 + c2 << endl << endl;

	cout << "c1-c2" << c1 - c2 << endl;
	cout << "c1-4" << c1 - 4 << endl;
	cout << "2-c2" << 2 - c2 << endl << endl;

	cout << "c1*c2" << c1 * c2 << endl;
	cout << "c1*4" << c1 * 4 << endl;
	cout << "2*c2" << 2 * c2 << endl << endl;

	cout << "c1/c2" << c1 / c2 << endl;
	cout << "c1/4" << c1 / 4 << endl;
	cout << "2/c2" << 2 / c2 << endl << endl;

	cout << "+c3" << +c3 << endl;	//���������  +
	cout << "-c3" << -c3 << endl << endl;	//���������  -


	c3 = complex<double>(1, -1);	// ����� =   ����ֵ��
	cout << "c3=(1,-1)" << endl;
	cout << "c3=" << c3 << endl;	// ��������� = ����ֵ��		��������=��ʱ����
	c3 = c4;
	cout << "c3=c4" << endl;
	cout << "c3=" << c3 << endl << endl;	// ��������� = ����ֵ��		��������1=��������2
	

	//cout << "(c1 += c2)="  << (c1 += c2) << endl;
/*	
	c1 += c2
	�൱��c1.operator+=(c2)
	Ҳ����c1���õ�+=������thisָ��c1
*/
	//cout << "(c1 -= c2)="   << (c1 -= c2) << endl;
	//cout << "(c1 *= c2)=" << (c1 *= c2) << endl;
	cout << "(c1 /= c2)=" << (c1 /= c2) << endl;

	







	system("pause");

	return 0;
}

