/**This class is a driver class for Matrix.cpp
*
* @author Cameron Pipes cdp39123@uga.edu
*/

#include "Matrix.h"

#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::endl;

int main() {


	Matrix  b = { { 1, 2, 3, 4 } ,{ 5, 6, 7, 8 } ,{ 9, 10 , 11, 12 } };
	cout << b << endl;

	//  Matrix d(2, 2);
	//     d.at(0, 0) = 1;
	//    d.at(0, 1) = 2;
	//    d.at(1, 0) = 3;
	//    d.at(1, 1) = 4;

	//    cout << d << endl;

	//     Matrix a = 12.0 / d;

	//  cout << a << endl;

	Matrix a(1, 1);
	a(0, 0) = 6;

	cout << a(0, 0) << endl;



	Matrix c(2, 2);
	c.at(0, 0) = 1;
	c.at(0, 1) = 2;
	c.at(1, 0) = 3;
	c.at(1, 1) = 4;

	cout << c << endl;

	Matrix c1 = 4.0 + c;

	cout << c1 << endl;

	Matrix c2 = 4.0 - c;

	cout << c2 << endl;

	Matrix c3 = 2.0 * c;

	cout << c3 << endl;

	Matrix c4 = 12.0 / c;

	cout << c4 << endl;


	Matrix c5(1, 2);
	c5.at(0, 0) = 1;
	c5.at(0, 1) = 2;

	cout << -c5 << endl;


	Matrix e(2, 2);
	e.at(0, 0) = 1;
	e.at(0, 1) = 2;
	e.at(1, 0) = 3;
	e.at(1, 1) = 4;

	cout << e << endl;

	Matrix ea(2, 2);
	ea.at(0, 0) = 4;
	ea.at(0, 1) = 3;
	ea.at(1, 0) = 2;
	ea.at(1, 1) = 1;

	cout << ea << endl;

	Matrix e0 = e + 5.2;

	cout << e0 << endl;

	Matrix e1 = e + e;

	cout << e1 << endl;

	Matrix e2 = e - 3.5;

	cout << e2 << endl;

	Matrix e3 = e - e;

	cout << e3 << endl;

	Matrix e4 = e * 2.1;

	cout << e4 << endl;

	Matrix e5 = e * ea;

	cout << e5 << endl;

	Matrix e6 = e / 2.0;

	cout << e6 << endl;

	Matrix f(2, 1);
	f.at(0, 0) = 1;
	f.at(0, 1) = 2;

	cout << f << endl;

	Matrix g(2, 2);
	g.at(0, 0) = 1;
	g.at(0, 1) = 2;
	g.at(1, 0) = 1;
	g.at(1, 1) = 3;

	cout << g << endl;

	Matrix h = g.multiply(f);

	cout << h << endl;

	cout << h - 5 << endl;

	cout << h * 5 << endl;

	cout << h / 2 << endl;

	Matrix i(2, 2);
	i.at(0, 0) = 1;
	i.at(0, 1) = 2;
	i.at(1, 0) = 1;
	i.at(1, 1) = 3;

	Matrix j = g.subtract(i);

	cout << j << endl;


	Matrix l = g.add(i);

	cout << l << endl;

	return EXIT_SUCCESS;
}