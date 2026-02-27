//
// Created by Joaquin Eid Mier on 2/26/26.
//

#ifndef SIMULATION_AND_CONVERGENCE_MATRICES_H
#define SIMULATION_AND_CONVERGENCE_MATRICES_H
#include <vector>
#include <iostream>

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
    vector<double> getRow(int i) const ;
    vector<double> getColumn(int j) const ;
    double getValue(int i, int j) const ;
    int rows() const ;
    int columns() const;

    //setters
    void setRow(vector<double> row, int i);
    void setColumn(vector<double> column, int j);

    //methods
    void checkProbs(const vector<vector<double>> &mat);
};

std::ostream& operator<<(std::ostream& out, const Matrix& M);

#endif //SIMULATION_AND_CONVERGENCE_MATRICES_H