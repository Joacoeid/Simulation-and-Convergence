//
// Created by Joaquin Eid Mier on 2/26/26.
//

#ifndef SIMULATION_AND_CONVERGENCE_MATRICES_H
#define SIMULATION_AND_CONVERGENCE_MATRICES_H
#include <vector>

using namespace std;


class Matrix
{
private:
    vector<vector<double>> matrix;

public:
    //constructors
    Matrix();
    Matrix(vector<vector<double>> matrix);

    //getters
    vector<double> getRow(int i);
    vector<double> getColumn(int j);
    double getValue(int i, int j);
    int rows();
    int columns();

    //setters
    void setRow(vector<double> row, int i);
    void setColumn(vector<double> column, int j);

    //methods
    void checkProbs(Matrix M);
};


#endif //SIMULATION_AND_CONVERGENCE_MATRICES_H