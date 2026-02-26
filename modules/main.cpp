//
// Created by Joaquin Eid Mier on 2/26/26.
//
#include <vector>
#include <Matrices.h>
#include <MarkovChain.h>

using namespace std;

int main() {
    vector<vector<double>> matrix = {{0.5, 0.3, 0.2}, {0.1, 0.6, 0.3}, {0.2, 0.3, 0.5}};
    Matrix M = Matrix(matrix);



    return 0;
}
