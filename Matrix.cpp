//This is Matrix.cpp
#include "Matrix.h"

typedef unsigned int uint;
typedef std::initializer_list<std::initializer_list<double>> i_list;

  
 /**
 * Constructor to initialize a Matrixs
 * 
 * @param rows the length of the rows of the matrix
 * @param cols the length of the columns of the matrix
 */
Matrix::Matrix(uint rows, uint cols){

  rLength = rows; //
  cLength = cols; //
  
  
  mArray = new double*[rows];
  for(uint k = 0; k < rows; k++) {

    mArray[k] = new double[cols];
    
  }
     
    for(uint i = 0; i < rows; i++){
      for(uint j = 0; j < cols; j++){

	mArray[i][j] = 0;
	
      }
    }
    
  } // constructor (all elements initialized to 0)

 /**
 * Constructor to initialize a matrix
 * 
 * @param list the initalizer list used to make the matrix
 * 
 */
Matrix::Matrix(const i_list & list){

  uint rows = list.size();
  uint cols = list.begin()->size();

  rLength = rows; //
  cLength = cols; //

  mArray = new double*[rows];

  for(uint k = 0; k < rows; k++) {

    mArray[k] = new double[cols];
    
  }
  uint p = 0;
    for(uint i = 0; i < rows; i++){
      for(uint j = 0; j < cols; j++){

	//cout << *((list.begin()->begin()) + ) << endl;
	mArray[i][j] = *(list.begin()->begin() + p);
	p++;
      }
    }
    
  }// constructor (using initializer list)

 /**
 * Constructor to initialize a matrix
 * 
 * @param m the matrix used for copying
 * 
 */
Matrix::Matrix(const Matrix & m){

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
  

  } // copy constructor

 /**
 * Destructor to dealocate memory
 * 
 * 
 */  
Matrix::~Matrix(){


for(uint k = 0; k < numRows(); k++) {

    delete mArray[k];
    
  }

  
  delete[] mArray;
  //  cout << "Doing Something" << endl;
  
  } // destructor

   /**
 * add function to add two matricies together
 * 
 * @param the double to be added
 * @return the new matrix
 */
Matrix Matrix::add(double s) const{

  Matrix mat(numRows(),numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] + s);
    
	
      }
     }
  
  
  return mat;
  
  }// add scalar to this matrix

   /**
 * add function to add two matricies together
 * 
 * @param the matrix to be added
 * @return the new matrix
 */
Matrix Matrix::add(const Matrix & m) const{

Matrix mat(numRows(),numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] + m.at(i,j));
	
      }
     }

  return mat;
 
  } // add this matrix and another matrix


   /**
 * subtract function to subtract a double
 * 
 * @param the double to be subtracted
 * @return the new matrix
 */
Matrix Matrix::subtract(double s) const{


 Matrix mat(numRows(),numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] - s);
    
	
      }
     }
  
 
  return mat;
 
  } // subtract scalar from this matrix


   /**
 * subtract function to add two matricies together
 * 
 * @param the matrix to be subtracted
 * @return the new matrix
 */
Matrix Matrix::subtract(const Matrix & m) const{


Matrix mat(numRows(),numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] - m.at(i,j));
	
      }
     }
  
  return mat;
 
  } // subtract another matrix from this matrix


   /**
 * multiply function to multiply a double
 * 
 * @param the double to be multiplied
 * @return the new matrix
 */
Matrix Matrix::multiply(double s) const{

  
 Matrix mat(numRows(),numCols());

 
  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] * s);
    
	
      }
     }
  
  
  return mat;
 
  } // multiply this matrix by a scaler


   /**
 * multiply function to multiply two matricies together
 * 
 * @param the matrix to be multiplied
 * @return the new matrix
 */
Matrix Matrix::multiply(const Matrix & m) const{

  Matrix mat(numRows(),m.numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < m.numCols(); j++){
      for(uint k = 0; k < numCols(); k++){

	mat.at(i,j) += (mArray[i][k] * m.at(k,j));

	
       }
      }
     }

  
  return mat;
 
  } // multiply this matrix by another matrix


   /**
 * divide function to divide a double
 * 
 * @param the double to be divided
 * @return the new matrix
 */
Matrix Matrix::divide(double s) const{



 Matrix mat(numRows(),numCols());

  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(i,j) = (mArray[i][j] / s);
    
	
      }
     }

  return mat;
  
  } // divide this matrix by a scaler


   /**
 * transpose function to transpose two matricies together
 * 
 * @param the matrix to be transposed
 * @return the new matrix
 */
Matrix Matrix::t() const{
  
 Matrix mat(numRows(),numCols());

 
  for(uint i = 0; i < numRows(); i++){
    for(uint j = 0; j < numCols(); j++){

      mat.at(j,i) = (mArray[i][j]);
    
	
      }
     }

  
  return mat;
 
  } // transpose of this matrix


   /**
 * numRows function to return the number of rows
 * 
 * 
 * @return the number of rows
 */
const uint Matrix::numRows() const{

  
  return rLength;
 
  } // returns the number of rows

    /**
 * columns function to return the number of columns
 * 
 * 
 * @return the number of columns
 */
const uint Matrix::numCols() const{

  
  return cLength;
 
  } // returns the number of cols

    /**
 * at function to return the value at a location in a matrix
 * 
 * 
 * @return the value requested
 */
double & Matrix::at(uint row, uint col){

  
  
  return mArray[row][col];
  } // get/set element at row,col

    /**
 * at function to return the value at a location in a matrix
 * 
 * 
 * @return the value requested
 */
const double & Matrix::at (uint row, uint col) const{

  
  return mArray[row][col];
 
  } // get element at row,col (when using a const object)



