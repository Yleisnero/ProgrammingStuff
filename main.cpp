#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    unsigned int rows, columns;
    vector<vector<int>> data;
public:
    void init() {
        cout << "Größe der Matrix angeben: " << endl;
        cin >> rows;
        cin >> columns;
    }

    void init(unsigned int r, unsigned int c) {
        rows = r;
        columns = c;
    }

    void input() {
        int in;
        for (int i = 0; i < rows; i++) { //i = m
            vector<int> row;
            for (int j = 0; j < columns; j++) { //j = n
                cout << "Wert " << i << " " << j << " eintragen" << endl;
                cin >> in;
                row.push_back(in);
            }
            data.push_back(row);
        }
    }

    void input(vector<vector<int>> &d){ //pass by reference
        data = d;
    }

    void inputRand(){
        int in;
        for(int i = 0; i < rows; i++){ //i = m
            vector<int> row;
            for(int j = 0; j < columns; j++){ //j = n
                row.push_back(rand() % 10 + 1);
            }
            data.push_back(row);
        }
    }

    void print(){
        cout << endl;
        for(int i = 0; i < columns; i++){ //i = m
            vector<int> row = data[i];
            for(int el : row){
                cout << el << " ";
            }
            cout << endl;
        }
    }

    Matrix mul(Matrix b){ // ! ONLY WORKING FOR SQUARE MATRIX !
        Matrix matrixResult;
        int steps = 0; //One Step for every Addition or Multiplication

        int num;
        if(columns == b.rows){
            vector<vector<int>> result;
            for(int i = 0; i < rows; i++) { //Rows of MatrixA
                vector<int> rowA = data[i];
                vector<int> rowB;
                vector<int> rowResult;
                for(int j = 0; j < b.rows; j++){ //Columns of MatrixA = Rows of MatrixB
                    num = 0;
                    for(int k = 0; k < columns; k++) {
                        rowB = b.data[k];
                        num += rowA[k] * rowB[j];
                        steps += 2;
                    }
                    rowResult.push_back(num);
                }
                result.push_back(rowResult);
            }
            matrixResult.init(rows, columns);
            matrixResult.input(result);

            cout << endl << "multiplication needed " << steps << " steps" << endl;
        }else{
            cout << "Matrix must have same dimensions" << endl;
        }
        return matrixResult;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}