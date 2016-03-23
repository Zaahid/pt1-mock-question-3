#include <iostream>

using namespace std;

// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 



class Fraction {
public:
	Fraction(int n, int d) : num(n), denom(d) { };
	void print() { cout << num << "/" << denom; };
	

	friend bool  operator > (const Fraction& F2, const Fraction& F1);
	friend Fraction operator+(Fraction& F, int a);
	friend Fraction operator+(int a, Fraction& F);
	
	int num;				// numerator;
	int denom;              // denominator;


};

Fraction  operator+(const Fraction  &F, int a)
{
	Fraction result(0,0);
	result.denom = F.denom;
	result.num = F.num + a*F.denom;


	return result;
}

Fraction operator + (int a,  const Fraction& F)

{
	Fraction result(0, 0);
	result.denom = F.denom;
	result.num = F.num + a*F.denom;


	return result;

}




bool  operator > (const Fraction& F2 ,const Fraction& F1)
{
	int a;
	int b;
	a = F2.num / F2.denom;
	b = F1.num / F1.denom;
	if (a > b)

		return true;

	else

		return false;

}




int main()


{
	int c = 3;

	Fraction frac1(8,9);
	Fraction frac2(4,2);
	Fraction frac3(0,0);
	Fraction frac4(0, 0);

	if (frac1 > frac2)
		cout << "fraction 1 is greater than fraction2" << endl;
	else 
		cout << "fraction 2 is greater than fraction1" << endl;
	return 0;


	frac3 = frac1 + c;
	frac4 = frac2 + c;

	cout << "numerator of fraction 3 is" << frac3.num << "denominator of fraction 3 is" << frac3.denom << endl;
	cout << "numerator of fraction 4 is" << frac4.num << "denominator of fraction 4 is" << frac4.denom << endl;

}


