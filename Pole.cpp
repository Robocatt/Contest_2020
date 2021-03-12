#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>

//const long double M0=4.0*M_PI*pow(10.0, -7.0);
long double I;
long double R;
long double L;
long double dphi;

long double fun(long double phi);
long double function_integral(long double (*fun)(long double phi)) ;


int main(void)
{
	setlocale(LC_ALL, "RUS");
	char Ans;
	do
	{
		std::cout << "Input I, R, L, dphi (I advise you not to make dphi too small,not smaller than 10^(-8))\n";
		std::cin >> I >> R >> L >> dphi;
		std::cout << "I = " << I << "\nR = " << R << "\nL = " << L << 
		"\ndphi = " << dphi <<  "\nIf true, type 'Y'\n";
		std::cin >> Ans;
	}while(int(Ans)!=int('Y'));
	system("CLS");
	std::cout << "Integral = " << function_integral(fun) << std::endl;
	system("pause");
	return 0;
}

long double fun(long double phi)
{
	return I*R/10000000.0*abs(L*cos(phi)-R)/(L*L+R*R-2.0*L*R*cos(phi))/sqrt(L*L+R*R-2.0*L*R*cos(phi));
}

long double function_integral(long double (*fun)(long double phi)) 
{
	long long N=0;
	long double integral=.0, phi=.0;
	N=(long long)(M_PI/dphi);
	long long i=1;
	while(i<=N)
	{
		phi=((long double)(i-1))*dphi;
		integral+=fun(phi)*dphi;
		i++;
	}
	return 2.0*integral;
}
