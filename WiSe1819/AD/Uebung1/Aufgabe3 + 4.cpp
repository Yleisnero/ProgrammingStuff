#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

//DANKESCHÖÖÖÖN

using namespace std;

void penetrationAdd(int);

class Matrix{
    unsigned int rows, columns;
    vector<vector<int>> data;
    public:
    void init(){
        cout << "Größe der Matrix angeben: " << endl;
        cin >> rows;
        cin >> columns;
    }

    void init(unsigned int r, unsigned int c){
        rows = r;
        columns = c;
    }

    void input(){
        int in;
        for(int i = 0; i < rows; i++){ //i = m
            vector<int> row;
            for(int j = 0; j < columns; j++){ //j = n
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

    Matrix add(Matrix b){
        Matrix matrixResult;
        int steps = 0; //One Step for every Addition

        if(rows == b.rows && columns == b.columns){ //Add them
            vector<vector<int>> result;
            for(int i = 0; i < columns; i++) {
               vector<int> row = data[i];
               vector<int> rowB = b.data[i];
               vector<int> rowResult;
               for(int j = 0; j < rows; j++){
                   rowResult.push_back(row[j] + rowB[j]);
                   steps++;
               }
               result.push_back(rowResult);
            }
            matrixResult.init(rows, columns);
            matrixResult.input(result);

            cout << endl << "addition needed " << steps << " steps" << endl;
        }else{
            cout << "Matrix must have same dimensions" << endl;
        }
        return matrixResult;
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
    /*
    Matrix m;
    m.init();
    m.input();
    m.print();

    Matrix b;
    b.init();
    b.input();
    b.print();

    Matrix addM;
    addM = m.add(b);
    addM.print();

    addM = m.mul(b);
    addM.print();
*/
    penetrationAdd(1);
    return 0;
}

void penetrationAdd(int maxTime){
    long long int elapsed_seconds = 0;
    Matrix a, b;
    unsigned int rowCol = 2;
    chrono::time_point<std::chrono::system_clock> start, end;

        while(elapsed_seconds/60 < maxTime){

            start = chrono::system_clock::now();

            a.init(rowCol, rowCol);
            b.init(rowCol, rowCol);

            a.inputRand();
            b.inputRand();

            Matrix x = a.add(b);

            //x.print();

            rowCol++;

            end = chrono::system_clock::now();
            elapsed_seconds = chrono::duration_cast<chrono::seconds>(end-start).count();
            cout << "\nTime needed: " << elapsed_seconds << endl;
            cout << "\n\n   Matrix got size of: " << rowCol << "x" << rowCol << endl;
        }

        cout << "\n\n   Matrix got size of: " << rowCol << "x" << rowCol << endl;
}