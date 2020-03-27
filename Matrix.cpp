//This is Matrix.cpp
#include "Matrix.h"

typedef unsigned int uint;
typedef std::initializer_list<std::initializer_list<double>> i_list;

  
 /**
 * Constructor to initialize a Matrix
 * 
 * @param rows the length of the rows of the matrix
 * @param cols the length of the columns of the matrix
 */
// Matrix::Matrix(uint rows, uint cols){

//   rLength = rows; //
//   cLength = cols; //
  
  
//   mArray = new double*[rows];
//   for(uint k = 0; k < rows; k++) {

//     mArray[k] = new double[cols];
    
//   }
     
//     for(uint i = 0; i < rows; i++){
//       for(uint j = 0; j < cols; j++){

// 	mArray[i][j] = 0;
	
//       }
//     }
    
//   } // constructor (all elements initialized to 0)

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


    //Sparse Matrix
    Matrix::Matrix(int r, int c) 
    { 
  
        // initialize row 
        row = r; 
  
        // initialize col 
        col = c; 
  
        // initialize length to 0 
        len = 0; 
  
        //Array of Pointer to make a matrix 
        data = new int *[MAX]; 
  
        // Array representation 
        // of sparse matrix 
        //[,0] represents row 
        //[,1] represents col 
        //[,2] represents value 
        for (int i = 0; i < MAX; i++) 
            data[i] = new int[3]; 
    } 


// insert elements into sparse matrix 
    void Matrix::insert(int r, int c, int val) 
    { 
  
        // invalid entry 
        if (r > row || c > col) 
        { 
            cout << "Wrong entry"; 
        } 
        else
        { 
  
            // insert row value 
            data[len][0] = r; 
  
            // insert col value 
            data[len][1] = c; 
  
            // insert element's value 
            data[len][2] = val; 
  
            // increment number of data in matrix 
            len++; 
        } 
    } 

void Matrix::add(Matrix b) 
    { 
      cout << "Here 0" << endl;
        // if matrices don't have same dimensions 
        if (row != b.row || col != b.col) 
        { 
            cout << "Matrices can't be added"; 
        } 
  
        else
        { 
            int apos = 0, bpos = 0; 
            Matrix result(row, col); 
  
            while (apos < len && bpos < b.len) 
            { 
  
                // if b's row and col is smaller 
                if (data[apos][0] > b.data[bpos][0] || 
                   (data[apos][0] == b.data[bpos][0] && 
                    data[apos][1] > b.data[bpos][1])) 
  
                { 
                  cout <<"here 1" <<endl;
                    // insert smaller value into result 
                    result.insert(b.data[bpos][0], 
                                  b.data[bpos][1], 
                                  b.data[bpos][2]); 
  
                    bpos++; 
                } 
  
                // if a's row and col is smaller 
                else if (data[apos][0] < b.data[bpos][0] || 
                        (data[apos][0] == b.data[bpos][0] && 
                         data[apos][1] < b.data[bpos][1])) 
  
                { 
                  cout << "here 2" << endl;
                    // insert smaller value into result 
                    result.insert(data[apos][0], 
                                  data[apos][1], 
                                  data[apos][2]); 
  
                    apos++; 
                } 
  
                else
                { 
                  cout << "Here 3" << endl;
                    // add the values as row and col is same 
                    int addedval = data[apos][2] +  
                                 b.data[bpos][2]; 
  
                    if (addedval != 0) 
                        result.insert(data[apos][0], 
                                      data[apos][1], 
                                      addedval); 
                    // then insert 
                    apos++; 
                    bpos++; 
                } 
            } 
  
            // insert remaining elements 
            while (apos < len) 
                result.insert(data[apos][0], 
                              data[apos][1], 
                              data[apos++][2]); 
  
            while (bpos < b.len) 
                result.insert(b.data[bpos][0], 
                              b.data[bpos][1], 
                              b.data[bpos++][2]); 
  
            // print result 
            result.print(); 
        } 
    } 

Matrix Matrix::transpose() 
    { 
  
        // new matrix with inversed row X col 
        Matrix result(col, row); 
  
        // same number of elements 
        result.len = len; 
  
        // to count number of elements in each column 
        int *count = new int[col + 1]; 
  
        // initialize all to 0 
        for (int i = 1; i <= col; i++) 
            count[i] = 0; 
  
        for (int i = 0; i < len; i++) 
            count[data[i][1]]++; 
  
        int *index = new int[col + 1]; 
  
        // to count number of elements having  
        // col smaller than particular i 
  
        // as there is no col with value < 0 
        index[0] = 0; 
  
        // initialize rest of the indices 
        for (int i = 1; i <= col; i++) 
  
            index[i] = index[i - 1] + count[i - 1]; 
  
        for (int i = 0; i < len; i++) 
        { 
  
            // insert a data at rpos and  
            // increment its value 
            int rpos = index[data[i][1]]++; 
  
            // transpose row=col 
            result.data[rpos][0] = data[i][1]; 
  
            // transpose col=row 
            result.data[rpos][1] = data[i][0]; 
  
            // same value 
            result.data[rpos][2] = data[i][2]; 
        } 
  
        // the above method ensures 
        // sorting of transpose matrix 
        // according to row-col value 
        return result; 
    } 

 void Matrix::multiply(Matrix b) 
    { 
        if (col != b.row) 
        { 
  
            // Invalid multiplication 
            cout << "Can't multiply, Invalid dimensions"; 
            return; 
        } 
  
        // transpose b to compare row 
        // and col values and to add them at the end 
        b = b.transpose(); 
        int apos, bpos; 
  
        // result matrix of dimension row X b.col 
        // however b has been transposed, 
        // hence row X b.row 
        Matrix result(row, b.row); 
  
        // iterate over all elements of A 
        for (apos = 0; apos < len;) 
        { 
  
            // current row of result matrix 
            int r = data[apos][0]; 
  
            // iterate over all elements of B 
            for (bpos = 0; bpos < b.len;) 
            { 
  
                // current column of result matrix 
                // data[,0] used as b is transposed 
                int c = b.data[bpos][0]; 
  
                // temporary pointers created to add all 
                // multiplied values to obtain current 
                // element of result matrix 
                int tempa = apos; 
                int tempb = bpos; 
  
                int sum = 0; 
  
                // iterate over all elements with 
                // same row and col value 
                // to calculate result[r] 
                while (tempa < len && data[tempa][0] == r && 
                       tempb < b.len && b.data[tempb][0] == c) 
                { 
                    if (data[tempa][1] < b.data[tempb][1]) 
  
                        // skip a 
                        tempa++; 
  
                    else if (data[tempa][1] > b.data[tempb][1]) 
  
                        // skip b 
                        tempb++; 
                    else
  
                        // same col, so multiply and increment 
                        sum += data[tempa++][2] *  
                             b.data[tempb++][2]; 
                } 
  
                // insert sum obtained in result[r] 
                // if its not equal to 0 
                if (sum != 0) 
                    result.insert(r, c, sum); 
  
                while (bpos < b.len &&  
                       b.data[bpos][0] == c) 
  
                    // jump to next column 
                    bpos++; 
            } 
            while (apos < len && data[apos][0] == r) 
  
                // jump to next row 
                apos++; 
        } 
        result.print(); 
    } 



// printing matrix 
    void Matrix::print() 
    { 
        cout << "\nDimension: " << row << "x" << col; 
        cout << "\nSparse Matrix: \nRow\tColumn\tValue\n"; 
  
        for (int i = 0; i < len; i++) 
        { 
            cout << data[i][0] << "\t " << data[i][1]  
                 << "\t " << data[i][2] << endl; 
        } 
    } 



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
 * add function to add a scalar to a matrix 
 * 
 * @param the double to be added
 * @return the new matrix
 */
// Matrix Matrix::add(double s) const{

//   Matrix mat(numRows(),numCols());

//   for(uint i = 0; i < numRows(); i++){
//     for(uint j = 0; j < numCols(); j++){

//       mat.at(i,j) = (mArray[i][j] + s);
    
	
//       }
//      }
  
  
//   return mat;
  
//   }// add scalar to this matrix

//    /**
//  * add function to add two matricies together
//  * 
//  * @param the matrix to be added
//  * @return the new matrix
//  */
// Matrix Matrix::add(const Matrix & m) const{

// Matrix mat(numRows(),numCols());

//   for(uint i = 0; i < numRows(); i++){
//     for(uint j = 0; j < numCols(); j++){

//       mat.at(i,j) = (mArray[i][j] + m.at(i,j));
	
//       }
//      }

//   return mat;
 
//   } // add this matrix and another matrix













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
 
  } // multiply this matrix by a scalar


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



