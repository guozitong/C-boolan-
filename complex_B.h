#ifndef __COMPLEX_B_H__
#define __COMPLEX_B_H__


template<typename T>		//定义模板 typename is T

class complex			/*	复数类	*/
{
public:
	complex(T r = 0, T i =0) : re(r), im(i)
	{
		;
	}
	complex& operator += (const complex&);	//成员函数
	complex& operator -= (const complex&);
	complex& operator *= (const complex&);
	complex& operator /= (const complex&);
	complex& operator = (const complex&);	//赋值运算符重载函数
	T real() const { return re; }
	T imag() const { return im; }

private:
	T re, im;

	friend complex& __doadd(complex *, const complex&);
	friend complex& __dosub(complex *, const complex&);
	friend complex& __domul(complex *, const complex&);
	friend complex& __dodiv(complex *, const complex&);
	friend complex& __doequ(complex*, const complex&);	//赋值实际运算函数

};

/************	全局函数声明区	***************/

double real(const complex<double>& x);	//取对象的实部（全局函数），不用在类外专门定义传参数
double imag(const complex<double>& x);	//取对象的虚部（全局函数），不用在类外专门定义传参数
inline complex<double>& __doequ(complex<double>* ths, const complex<double>& r);	//赋值实际运算函数

/**************************************************************************************************************************************************************/


/************			+= -= *= /=			***************************************************************************************************************************/
/*	复数 += 的实际运算函数	*/
inline complex<double>& 
__doadd(complex<double>* ths, const complex<double>& r)	
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

/*	函数名 ooerator+=	运算符重载	*/
inline complex<double>&
complex<double>::operator +=(const complex<double>& r)
{
	return __doadd(this, r);
}

/*	复数 -= 的实际运算函数	*/
inline complex<double>&
__dosub(complex<double>* ths, const complex<double>& r)	
{
	ths->re -= r.re;
	ths->im -= r.im;
	return *ths;
}

/*	函数名 ooerator-=	*/
inline complex<double>&
complex<double>::operator -=(const complex<double>& r)
{
	return __dosub(this, r);
}

/*	复数 *= 的实际运算函数	*/
inline complex<double>&
__domul(complex<double>* ths, const complex<double>& r)
{
	ths->re *= r.re;
	ths->im *= r.im;
	return *ths;
}

/*	函数名 ooerator*=	*/
inline complex<double>&
complex<double>::operator *=(const complex<double>& r)
{
	return __domul(this, r);
}

/*	复数 /= 的实际运算函数	*/
inline complex<double>&
__dodiv(complex<double>* ths, const complex<double>& r)
{
	ths->re /= r.re;
	ths->im /= r.im;
	return *ths;
}

/*	函数名 ooerator/=	*/
inline complex<double>&
complex<double>::operator/=(const complex<double>& r)
{
	return __dodiv(this, r);
}

/*	复数	赋值（=）	实际运算函数	*/
inline complex<double>&
__doequ(complex<double>* ths, const complex<double>& r)
{
	ths->re = r.re;
	ths->im = r.im;
	return *ths;
}

/*	函数名 ooerator=	复数赋值（=）	*/
inline complex<double>&
complex<double>::operator=(const complex<double>& r)
{
	return __doequ(this, r);
}


/**************************************************************************************************************************************************************/

/*	函数名 ooerator+（复数，复数）	*/
inline complex<double>
operator+(const complex<double>& x, const complex<double>& y)
{
	return complex<double> (real(x) + real(y), imag(x) + imag(y));
}

/*	函数名 ooerator+（复数，double）	*/
inline complex<double>
operator+(const complex<double> x, double y)
{
	return complex<double>(real(x) + y, imag(x));
}

/*	函数名 ooerator+（double，复数）	*/
inline complex<double>
operator+(double x, const complex<double> y)
{
	return complex<double>(x + real(y), imag(y));
}



/*	函数名 ooerator-（复数，复数）	*/
inline complex<double>
operator-(const complex<double> x, const complex<double> y)
{
	return complex<double>(real(x) - real(y), imag(x) - imag(y));
}

/*	函数名 ooerator-（复数，double）	*/
inline complex<double>
operator-(const complex<double> x, double y)
{
	return complex<double>(real(x) - y, imag(x));
}

/*	函数名 ooerator-（double，复数）	*/
inline complex<double>
operator-(double x, const complex<double> y)
{
	return complex<double>(x - real(y), imag(y));
}



/*	函数名 ooerator*（复数，复数）	*/
inline complex<double>
operator*(const complex<double> x, const complex<double> y)
{
	return complex<double>(real(x) * real(y), imag(x) * imag(y));
}

/*	函数名 ooerator*（复数，double）	*/
inline complex<double>
operator*(const complex<double> x, double y)
{
	return complex<double>(real(x) * y, imag(x));
}

/*	函数名 ooerator*（double，复数）	*/
inline complex<double>
operator*(double x, const complex<double> y)
{
	return complex<double>(x * real(y), imag(y));
}


/*	函数名 ooerator/（复数，复数）	*/
inline complex<double>
operator/(const complex<double> x, const complex<double> y)
{
	return complex<double>(real(x) / real(y), imag(x) / imag(y));
}

/*	函数名 ooerator/（复数，double）	*/
inline complex<double>
operator/(const complex<double> x, double y)
{
	return complex<double>(real(x) / y, imag(x));
}

/*	函数名 ooerator/（double，复数）	*/
inline complex<double>
operator/(double x, const complex<double> y)
{
	return complex<double>(x / real(y), imag(y));
}

/*		函数名 ooerator==（复数，复数）	判断两个复数是否相等     重载		*/
inline bool
operator==(const complex<double>& x, const complex<double>& y)
{
	return  real(x) == real(y) && imag(x) == imag(y);
}





/*	函数名 ooerator+（复数）	+正数	*/
inline complex<double>
operator+ (const complex<double>& x)
{
	return x;
}

/*	函数名 ooerator-（复数）	-复数	*/
inline complex<double>
operator- (const complex<double>& x)
{
	return complex<double>(-real(x), -imag(x));
}











inline double real(const complex<double>& x)	//取对象的实部（全局函数），不用在类外专门定义传参数
{
	return x.real();
}

inline double imag(const complex<double>& x)	//取对象的虚部（全局函数），不用在类外专门定义传参数
{
	return x.imag();
}


#endif