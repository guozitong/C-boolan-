#include<iostream>
#include"complex_B.h"
#include<windows.h>

using namespace std;

/*	对 cout<< complex 类型的重载    ostream 是 cout的类	*/
ostream& operator<<(ostream& os, const complex<double>& x)
{

	return os << '(' << real(x) << ',' << imag(x) << ')';
	//return os << '(' << x.real() << ',' << x.imag() << ')';	//直接调用成员函数 real() 和 imag()  不必在
}


int main(void)
{
	complex<double> c1(2, 1);
	complex<double> c2(4, 0);
	complex<double> c3(-1, 1);
	complex<double> c4;		//c4未初始化（构造函数会赋初值0）


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

	cout << "+c3" << +c3 << endl;	//测试运算符  +
	cout << "-c3" << -c3 << endl << endl;	//测试运算符  -


	c3 = complex<double>(1, -1);	// 运算符 =   （赋值）
	cout << "c3=(1,-1)" << endl;
	cout << "c3=" << c3 << endl;	// 测试运算符 = （赋值）		复数变量=临时复数
	c3 = c4;
	cout << "c3=c4" << endl;
	cout << "c3=" << c3 << endl << endl;	// 测试运算符 = （赋值）		复数变量1=复数变量2
	

	//cout << "(c1 += c2)="  << (c1 += c2) << endl;
/*	
	c1 += c2
	相当于c1.operator+=(c2)
	也就是c1调用的+=，所以this指向c1
*/
	//cout << "(c1 -= c2)="   << (c1 -= c2) << endl;
	//cout << "(c1 *= c2)=" << (c1 *= c2) << endl;
	cout << "(c1 /= c2)=" << (c1 /= c2) << endl;

	







	system("pause");

	return 0;
}

