/**This is a header file Matrix.h
 *
 *@author Cameron Pipes cdp39123@uga.edu
 */
#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <initializer_list>

using namespace std;

typedef unsigned int uint;
typedef std::initializer_list<std::initializer_list<double>> i_list;

class Matrix {
  
public:
  
Matrix(uint rows, uint cols); // constructor (all elements initialized to 0)
Matrix(const i_list & list); // constructor (using initializer list)
Matrix(const Matrix & m); // copy constructor
~Matrix(); // destructor
 
Matrix add(double s) const; // add scalar to this matrix
Matrix add(const Matrix & m) const; // add this matrix and another matrix
 
Matrix subtract(double s) const; // subtract scalar from this matrix
Matrix subtract(const Matrix & m) const; // subtract another matrix from this matrix
 
Matrix multiply(double s) const; // multiply this matrix by a scaler
Matrix multiply(const Matrix & m) const; // multiply this matrix by another matrix
 
Matrix divide(double s) const; // divide this matrix by a scaler
Matrix t() const; // transpose of this matrix
 
const uint numRows() const; // returns the number of rows
const uint numCols() const; // returns the number of cols
 
double & at(uint row, uint col); // get/set element at row,col
const double & at (uint row, uint col) const; // get element at row,col (when using a const object)


     /**
 * Outstream operator overload
 * 
 * @param the matrix to be printed
 * 
 */
  friend std::ostream &operator<<(std::ostream &out, const Matrix & m){

   for(uint i = 0; i < m.numRows(); i++){
     out << "[";
    for(uint j = 0; j < m.numCols(); j++){

      out << m.at(i,j);
      if(j+1 < m.numCols()){

	out << ", ";

      }
	
      }
    out << "]" << std::endl;
     }
   return out;
  }

   /**
 * add operator overload
 * 
 * @param the matrix to be added
 * 
 */
  Matrix operator+(const Matrix & m) {

    Matrix mat(numRows(),numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] + m.at(i,j));
	
      }
     }

  return mat;
    
  }
   /**
 * add operator overload
 * 
 * @param the double to be added
 * 
 */
  Matrix operator+(double s) {

      Matrix mat(numRows(),numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] + s);
    
	
      }
     }
  
  
  return mat;


  }


   /**
 * subtraction operator overload
 * 
 * @param the matrix to be subtracted
 * 
 */
  Matrix operator-(const Matrix & m) {

    Matrix mat(numRows(),numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] - m.at(i,j));
	
      }
     }

  return mat;
    
  }
   /**
 * subtraction operator overload
 * 
 * @param the double to be subtraction
 * 
 */
  Matrix operator-(double s) {

      Matrix mat(numRows(),numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] - s);
    
	
      }
     }
  
  
  return mat;

  }

   /**
 * multiplication operator overload
 * 
 * @param the double to be multiplied
 * 
 */
  Matrix operator* (double s){

     Matrix mat(numRows(),numCols());

 
  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] * s);
    
	
      }
     }
  
 
  return mat;
  }
  
   /**
 * multiplication operator overload
 * 
 * @param the matrix to be multiplied
 * 
 */
  Matrix operator* (const Matrix & m){

  Matrix mat(numRows(),m.numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < m.numCols(); j++){
      for(uint k = 0; k < numCols(); k++){

	mat.at(i,j) += (mArray[i][k] * m.at(k,j));

	
       }
      }
     }

  
  return mat;


  }

   /**
 * division operator overload
 * 
 * @param the double to be divided
 * 
 */
  Matrix operator/ (double s){

 Matrix mat(numRows(),numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] / s);
    
	
      }
     }

  return mat;

  }

   /**
 * function call operator overload
 * 
 * @param the row and column of the element requested
 * 
 */
  double & operator() (uint row, uint col){


    return mArray[row][col];

  }


   /**
 * assignment operator overload
 * 
 * @param the matrix to be assigned
 * 
 */
  Matrix operator= (const Matrix & m){


     uint nRows = m.numRows();
 uint nCols = m.numCols();

 rLength = nRows; //
 cLength = nCols; //

  mArray = new double*[nRows];
  for(uint k = 0; k < nRows; k++) {

    mArray[k] = new double[nCols];
    
  }

     for(uint i = 0; i < nRows; i++){
      for(uint j = 0; j < nCols; j++){

	mArray[i][j] = m.at(i, j);
	
      }
     }
  

  }

   /**
 * negate operator overload
 * 
 * 
 * 
 */
  Matrix operator- (){

     Matrix mat(numRows(),numCols());

 
  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] * (-1));
    
	
      }
     }
  
  
  return mat;

  }



     /**
 * add operator overload
 * 
 * @param the double to be added
 * @param the matrix to be added
 */
  friend Matrix operator+(double s, const Matrix & m) {

      Matrix mat(m.numRows(),m.numCols());

  for(uint i = 0; i < m.numRows(); i++){
    for(uint j = 0; j < m.numCols(); j++){

      mat.at(i,j) = (m.at(i,j) + s);
    
	
      }
     }

   return mat;

  }

       /**
 * subtraction operator overload
 * 
 * @param the double to be subtracted
 * @param the matrix to be subtracted
 */
 friend Matrix operator-(double s, const Matrix & m) {

      Matrix mat(m.numRows(),m.numCols());

  for(uint i = 0; i < m.numRows(); i++){
    for(uint j = 0; j < m.numCols(); j++){

      mat.at(i,j) = (s - m.at(i,j));
    
	
      }
     }

  
  return mat;


 }

     /**
 * multiplictation operator overload
 * 
 * @param the double to be multiplied
 * @param the matrix to be multiplied
 */
 friend Matrix operator*(double s, const Matrix & m) {

      Matrix mat(m.numRows(),m.numCols());

  for(uint i = 0; i < m.numRows(); i++){
    for(uint j = 0; j < m.numCols(); j++){

      mat.at(i,j) = ( s * m.at(i,j));
    
	
      }
     }

  
  return mat;


 }

     /**
 * division operator overload
 * 
 * @param the double to be divided
 * @param the matrix to be divided
 */
 friend Matrix operator/(double s, const Matrix & m) {

      Matrix mat(m.numRows(),m.numCols());

  for(uint i = 0; i < m.numRows(); i++){
    for(uint j = 0; j < m.numCols(); j++){

      mat.at(i,j) = (s / m.at(i,j));
    
	
      }
     }

  
  return mat;


 }


  

  double** mArray; //underlying pointer multidementional array
  uint rLength; //used for numRows
  uint cLength; //used for numCols
  
}; // Matrix

#endif