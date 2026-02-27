//
// Created by Joaquin Eid Mier on 2/26/26.
//

#ifndef SIMULATION_AND_CONVERGENCE_MARKOVCHAIN_H
#define SIMULATION_AND_CONVERGENCE_MARKOVCHAIN_H
#include <random>
#include <vector>
#include <Matrices.h>

using namespace std;


class MarkovChain {
private:
    Matrix P;
    int n;
    mt19937 rng;

public:
    //Constructor
    MarkovChain(const Matrix &TransitionMatrix);

    //getters
    Matrix getP();
    int getN();

    //methods
    int nextState(int currentState);
    vector<int> simulate(int startState, int steps);
    vector<double> empiricalDistribution(int startState, int steps);
};


#endif //SIMULATION_AND_CONVERGENCE_MARKOVCHAIN_H