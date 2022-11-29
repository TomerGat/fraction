#include "fraction.h"

//main - driver program to test functions
int main() {
	//constructor tests
	std::cout << "Testing constructors:" << std::endl;
	Fraction frac = Fraction("16/40");
	frac.print_fraction();

	frac = Fraction(4, 14);
	frac.print_fraction();

	frac = Fraction(3);
	frac.print_fraction();

	frac = Fraction();
	frac.print_fraction();
	std::cout << std::endl;

	//testing arithmetic operators +, -, *, /
	std::cout << "Testing arithmetic operators (+, -, *, /):" << std::endl;
	Fraction f1 = Fraction("21/50");
	Fraction f2 = Fraction("34/92");
	std::cout << f1.str() + " + " + f2.str() + " = " + (f1 + f2).str() << std::endl; //plus operator
	std::cout << f1.str() + " - " + f2.str() + " = " + (f1 - f2).str() << std::endl; //minus operator 
	std::cout << f1.str() + " * " + f2.str() + " = " + (f1 * f2).str() << std::endl; //multiply operator
	std::cout << f1.str() + " / " + f2.str() + " = " + (f1 / f2).str() << std::endl; //divide operator 
	std::cout << std::endl;

	//testing assignment operators +=, -=, *=, /=
	std::cout << "Testing assignment operators (+=, -=, *=, /=):" << std::endl;
	std::cout << f1.str() + " + " + f2.str() + " = ";
	f1 += f2;
	std::cout << f1.str() << std::endl;

	std::cout << f1.str() + " * " + f2.str() + " = ";
	f1 *= f2;
	std::cout << f1.str() << std::endl;

	std::cout << f1.str() + " - " + f2.str() + " = ";
	f1 -= f2;
	std::cout << f1.str() << std::endl;

	std::cout << f1.str() + " / " + f2.str() + " = ";
	f1 /= f2;
	std::cout << f1.str() << std::endl;
	std::cout << std::endl;


	//testing logical operators ==, >, >=, <, <=
	std::cout << "Testing assignment operators (==, >, >=, <, <=):" << std::endl;
	//testing ==
	f1 = Fraction("16/32");
	f2 = Fraction("2/4");
	std::cout << "Is " + f1.str() + " equal to " + f2.str() + "? " << ((f1 == f2) ? ("yes") : ("no")) << std::endl;
	f1 = Fraction("16/32");
	f2 = Fraction("3/4");
	std::cout << "Is " + f1.str() + " equal to " + f2.str() + "? " << ((f1 == f2) ? ("yes") : ("no")) << std::endl;
	f1 = Fraction("8/9");
	f2 = Fraction("16/18");
	std::cout << "Is " + f1.str() + " equal to " + f2.str() + "? " << ((f1 == f2) ? ("yes") : ("no")) << std::endl;
	//testing >
	f1 = Fraction("1/2");
	f2 = Fraction("3/4");
	std::cout << "Is " + f1.str() + " greater than " + f2.str() + "? " << ((f1 > f2) ? ("yes") : ("no")) << std::endl;
	f1 = Fraction("1/2");
	f2 = Fraction("1/2");
	std::cout << "Is " + f1.str() + " greater than " + f2.str() + "? " << ((f1 > f2) ? ("yes") : ("no")) << std::endl;
	f1 = Fraction("5/6");
	f2 = Fraction("1/2");
	std::cout << "Is " + f1.str() + " greater than " + f2.str() + "? " << ((f1 > f2) ? ("yes") : ("no")) << std::endl;
	//testing >=
	f1 = Fraction("1/2");
	f2 = Fraction("3/4");
	std::cout << "Is " + f1.str() + " greater than or equal to " + f2.str() + "? " << ((f1 >= f2) ? ("yes") : ("no")) << std::endl;
	f1 = Fraction("1/2");
	f2 = Fraction("1/2");
	std::cout << "Is " + f1.str() + " greater than or equal to " + f2.str() + "? " << ((f1 >= f2) ? ("yes") : ("no")) << std::endl;
	f1 = Fraction("5/6");
	f2 = Fraction("1/2");
	std::cout << "Is " + f1.str() + " greater than or equal to " + f2.str() + "? " << ((f1 >= f2) ? ("yes") : ("no")) << std::endl;
	//testing <
	f1 = Fraction("1/2");
	f2 = Fraction("3/4");
	std::cout << "Is " + f1.str() + " smaller than " + f2.str() + "? " << ((f1 < f2) ? ("yes") : ("no")) << std::endl;
	f1 = Fraction("1/2");
	f2 = Fraction("1/2");
	std::cout << "Is " + f1.str() + " smaller than " + f2.str() + "? " << ((f1 < f2) ? ("yes") : ("no")) << std::endl;
	f1 = Fraction("5/6");
	f2 = Fraction("1/2");
	std::cout << "Is " + f1.str() + " smaller than " + f2.str() + "? " << ((f1 < f2) ? ("yes") : ("no")) << std::endl;
	//testing <=
	f1 = Fraction("1/2");
	f2 = Fraction("3/4");
	std::cout << "Is " + f1.str() + " smaller than or equal to " + f2.str() + "? " << ((f1 <= f2) ? ("yes") : ("no")) << std::endl;
	f1 = Fraction("1/2");
	f2 = Fraction("1/2");
	std::cout << "Is " + f1.str() + " smaller than or equal to " + f2.str() + "? " << ((f1 <= f2) ? ("yes") : ("no")) << std::endl;
	f1 = Fraction("5/6");
	f2 = Fraction("1/2");
	std::cout << "Is " + f1.str() + " smaller than or equal to " + f2.str() + "? " << ((f1 <= f2) ? ("yes") : ("no")) << std::endl;
	std::cout << std::endl;

	//testing print operator <<
	std::cout << "Testing print operator (<<):" << std::endl;
	std::cout << f1;
	std::cout << std::endl;
	std::cout << f2;
	std::cout << std::endl << "Print operator successful" << std::endl;

}


/*
Output from main (driver program):

Testing constructors:
2/5
2/7
3/1
0/1

Testing arithmetic operators (+, -, *, /):
21/50 + 17/46 = 454/575
21/50 - 17/46 = 29/575
21/50 * 17/46 = 357/2300
21/50 / 17/46 = 483/425

Testing assignment operators (+=, -=, *=, /=):
21/50 + 17/46 = 454/575
454/575 * 17/46 = 3859/13225
3859/13225 - 17/46 = -2057/26450
-2057/26450 / 17/46 = -94622/449650

Testing assignment operators (==, >, >=, <, <=):
Is 1/2 equal to 1/2? yes
Is 1/2 equal to 3/4? no
Is 8/9 equal to 8/9? yes
Is 1/2 greater than 3/4? no
Is 1/2 greater than 1/2? no
Is 5/6 greater than 1/2? yes
Is 1/2 greater than or equal to 3/4? no
Is 1/2 greater than or equal to 1/2? yes
Is 5/6 greater than or equal to 1/2? yes
Is 1/2 smaller than 3/4? yes
Is 1/2 smaller than 1/2? no
Is 5/6 smaller than 1/2? no
Is 1/2 smaller than or equal to 3/4? yes
Is 1/2 smaller than or equal to 1/2? yes
Is 5/6 smaller than or equal to 1/2? no

Testing print operator (<<):
5/6
1/2
Print operator successful

*/