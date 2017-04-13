#ifndef __COMPLEX_B_H__
#define __COMPLEX_B_H__


template<typename T>		//����ģ�� typename is T

class complex			/*	������	*/
{
public:
	complex(T r = 0, T i =0) : re(r), im(i)
	{
		;
	}
	complex& operator += (const complex&);	//��Ա����
	complex& operator -= (const complex&);
	complex& operator *= (const complex&);
	complex& operator /= (const complex&);
	complex& operator = (const complex&);	//��ֵ��������غ���
	T real() const { return re; }
	T imag() const { return im; }

private:
	T re, im;

	friend complex& __doadd(complex *, const complex&);
	friend complex& __dosub(complex *, const complex&);
	friend complex& __domul(complex *, const complex&);
	friend complex& __dodiv(complex *, const complex&);
	friend complex& __doequ(complex*, const complex&);	//��ֵʵ�����㺯��

};

/************	ȫ�ֺ���������	***************/

double real(const complex<double>& x);	//ȡ�����ʵ����ȫ�ֺ�����������������ר�Ŷ��崫����
double imag(const complex<double>& x);	//ȡ������鲿��ȫ�ֺ�����������������ר�Ŷ��崫����
inline complex<double>& __doequ(complex<double>* ths, const complex<double>& r);	//��ֵʵ�����㺯��

/**************************************************************************************************************************************************************/


/************			+= -= *= /=			***************************************************************************************************************************/
/*	���� += ��ʵ�����㺯��	*/
inline complex<double>& 
__doadd(complex<double>* ths, const complex<double>& r)	
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

/*	������ ooerator+=	���������	*/
inline complex<double>&
complex<double>::operator +=(const complex<double>& r)
{
	return __doadd(this, r);
}

/*	���� -= ��ʵ�����㺯��	*/
inline complex<double>&
__dosub(complex<double>* ths, const complex<double>& r)	
{
	ths->re -= r.re;
	ths->im -= r.im;
	return *ths;
}

/*	������ ooerator-=	*/
inline complex<double>&
complex<double>::operator -=(const complex<double>& r)
{
	return __dosub(this, r);
}

/*	���� *= ��ʵ�����㺯��	*/
inline complex<double>&
__domul(complex<double>* ths, const complex<double>& r)
{
	ths->re *= r.re;
	ths->im *= r.im;
	return *ths;
}

/*	������ ooerator*=	*/
inline complex<double>&
complex<double>::operator *=(const complex<double>& r)
{
	return __domul(this, r);
}

/*	���� /= ��ʵ�����㺯��	*/
inline complex<double>&
__dodiv(complex<double>* ths, const complex<double>& r)
{
	ths->re /= r.re;
	ths->im /= r.im;
	return *ths;
}

/*	������ ooerator/=	*/
inline complex<double>&
complex<double>::operator/=(const complex<double>& r)
{
	return __dodiv(this, r);
}

/*	����	��ֵ��=��	ʵ�����㺯��	*/
inline complex<double>&
__doequ(complex<double>* ths, const complex<double>& r)
{
	ths->re = r.re;
	ths->im = r.im;
	return *ths;
}

/*	������ ooerator=	������ֵ��=��	*/
inline complex<double>&
complex<double>::operator=(const complex<double>& r)
{
	return __doequ(this, r);
}


/**************************************************************************************************************************************************************/

/*	������ ooerator+��������������	*/
inline complex<double>
operator+(const complex<double>& x, const complex<double>& y)
{
	return complex<double> (real(x) + real(y), imag(x) + imag(y));
}

/*	������ ooerator+��������double��	*/
inline complex<double>
operator+(const complex<double> x, double y)
{
	return complex<double>(real(x) + y, imag(x));
}

/*	������ ooerator+��double��������	*/
inline complex<double>
operator+(double x, const complex<double> y)
{
	return complex<double>(x + real(y), imag(y));
}



/*	������ ooerator-��������������	*/
inline complex<double>
operator-(const complex<double> x, const complex<double> y)
{
	return complex<double>(real(x) - real(y), imag(x) - imag(y));
}

/*	������ ooerator-��������double��	*/
inline complex<double>
operator-(const complex<double> x, double y)
{
	return complex<double>(real(x) - y, imag(x));
}

/*	������ ooerator-��double��������	*/
inline complex<double>
operator-(double x, const complex<double> y)
{
	return complex<double>(x - real(y), imag(y));
}



/*	������ ooerator*��������������	*/
inline complex<double>
operator*(const complex<double> x, const complex<double> y)
{
	return complex<double>(real(x) * real(y), imag(x) * imag(y));
}

/*	������ ooerator*��������double��	*/
inline complex<double>
operator*(const complex<double> x, double y)
{
	return complex<double>(real(x) * y, imag(x));
}

/*	������ ooerator*��double��������	*/
inline complex<double>
operator*(double x, const complex<double> y)
{
	return complex<double>(x * real(y), imag(y));
}


/*	������ ooerator/��������������	*/
inline complex<double>
operator/(const complex<double> x, const complex<double> y)
{
	return complex<double>(real(x) / real(y), imag(x) / imag(y));
}

/*	������ ooerator/��������double��	*/
inline complex<double>
operator/(const complex<double> x, double y)
{
	return complex<double>(real(x) / y, imag(x));
}

/*	������ ooerator/��double��������	*/
inline complex<double>
operator/(double x, const complex<double> y)
{
	return complex<double>(x / real(y), imag(y));
}

/*		������ ooerator==��������������	�ж����������Ƿ����     ����		*/
inline bool
operator==(const complex<double>& x, const complex<double>& y)
{
	return  real(x) == real(y) && imag(x) == imag(y);
}





/*	������ ooerator+��������	+����	*/
inline complex<double>
operator+ (const complex<double>& x)
{
	return x;
}

/*	������ ooerator-��������	-����	*/
inline complex<double>
operator- (const complex<double>& x)
{
	return complex<double>(-real(x), -imag(x));
}











inline double real(const complex<double>& x)	//ȡ�����ʵ����ȫ�ֺ�����������������ר�Ŷ��崫����
{
	return x.real();
}

inline double imag(const complex<double>& x)	//ȡ������鲿��ȫ�ֺ�����������������ר�Ŷ��崫����
{
	return x.imag();
}


#endif