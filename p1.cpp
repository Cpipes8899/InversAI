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


	 // create two sparse matrices and insert values 
    Matrix a(4, 4); 
    Matrix b(4, 4); 
  
     a.insert(1, 2, 10); 
     a.insert(1, 4, 12); 
     a.insert(3, 3, 5); 
     a.insert(4, 1, 15); 
     a.insert(4, 2, 12); 
    b.insert(1, 3, 8); 
    b.insert(2, 4, 23); 
    b.insert(3, 3, 9); 
    b.insert(4, 1, 20); 
    b.insert(4, 2, 25); 
  

  cout << "Print A" << endl;
   
    a.print();

    cout << "Print B" << endl;

    b.print();

    // Output result 
   cout << "Addition: "; 
    a.add(b); 
   // cout << "\nMultiplication: "; 
    //a.multiply(b); 
    //cout << "\nTranspose: "; 
    //Matrix atranspose = a.transpose(); 
    //atranspose.print(); 


	return EXIT_SUCCESS;
}