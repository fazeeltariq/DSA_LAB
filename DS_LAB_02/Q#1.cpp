#include<bits/stdc++.h>
using namespace std;

class DynamicMatrix{
private:
    int **arr;
    int rows;
    int cols;
public:
    DynamicMatrix(int rows, int cols, int initialvalue = 0){
        this->rows = rows;
        this->cols = cols;
        arr = new int*[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = initialvalue;
            }
        }
    }

    ~DynamicMatrix(){
        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

    void resizeMatrix(int newRows, int newCols, int defaultvalue = 0){
        if(newRows == rows && newCols == cols){
            return ;
        }
        else if(newRows <= 0 || newCols <= 0){
            cout << "\nError Invalid size ! Returning the old array: ";
            return ;
        }

        int** newArray = new int*[newRows];

        for (int i = 0; i < newRows; i++) {
            newArray[i] = new int[newCols];
                for (int j = 0; j < newCols; j++)
                {
                    newArray[i][j] = defaultvalue;   
                }
        }

        // copy elements:
        int rowsLimit = rows < newRows ? rows : newRows;
        int colsLimit = cols < newCols ? cols : newCols;
        
        for (int i = 0; i < rowsLimit; i++)
        {
            for (int j = 0; j < colsLimit; j++)
            {
                newArray[i][j] = arr[i][j];
            }
        }

        // deleting old array
        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        arr = newArray;
        rows = newRows;
        cols = newCols;
        cout << "\nMatrix has been resized: \n";
    }

   void transposeMatrix() {
    cout << "\nTransposing Matrix: ";

    if (rows == cols) {
       
        for (int i = 0; i < rows; i++) {
            for (int j = i + 1; j < cols; j++) { 
                swap(arr[i][j], arr[j][i]);
            }
        }
        return;
    }

    int** transpose = new int*[cols];
    for (int i = 0; i < cols; i++) {
        transpose[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = transpose;

    swap(rows, cols);
    
    }

    void print(){
        cout << "\nPrinting elements: \n";
        int index = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (index % 2 == 1){
                   arr[i][j] += 2;
                }
                cout<< arr[i][j] << " ";
                index++;
            }
            cout << endl;
        }  
    }


};
int main()
{
    // created a matrix with 3 rows and 3 cols with intial value 1.
    cout << "\n---------- MATRIX-1 -----------\n";
    DynamicMatrix matrix1 (3,3,1);
    matrix1.print();

    // resizing matrix and intializing defalut values in matrix.
    // if new matrix size is bigger than old matrix .. then
    //I have initialize the remaining matrix with default values.

    int newrows = 4, newcols = 4;
    matrix1.resizeMatrix(newrows,newcols);

    matrix1.print();

    // transpose of matrix # 1
    matrix1.transposeMatrix();

    matrix1.print();

    // creating new matrix with initial value 12
    cout << "\n---------- MATRIX-2 -----------\n";
    DynamicMatrix matrix2 (3,3,12);
    matrix2.print();

    // now resizing matrix and making it small.
    matrix2.resizeMatrix(2,2);
    matrix2.print();
   

   return 0;
}