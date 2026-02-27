//
// Created by Joaquin Eid Mier on 2/26/26.
//


#include "MarkovChain.h"
#include <iostream>
#include <vector>
#include <random>
#include <ostream>

using namespace std;

MarkovChain::MarkovChain(const Matrix &TransitionMatrix){
    P = TransitionMatrix;
    n = P.rows();
    random_device rd;
    rng = mt19937(rd());
}

Matrix MarkovChain::getP() {
    return P;
}

int MarkovChain::getN() {
    return n;
}

int MarkovChain::nextState(int currentState) {
    vector<double> Row = P.getRow(currentState);

    discrete_distribution<int> Distribution(Row.begin(), Row.end());

    int nextState = Distribution(rng);

    return nextState;
}

vector<int> MarkovChain::simulate(int startState, int steps) {
    vector<int> Trajectory;
    int curentState = startState;
    Trajectory.push_back(curentState);
    while (steps > 0) {
        curentState = nextState(curentState);
        Trajectory.push_back(curentState);
        steps--;
    }
    return Trajectory;
}

vector<double> MarkovChain::empiricalDistribution(int startState, int steps) {
    vector<int> Trajectory = simulate(startState, steps);
    vector<int> counts(n, 0);

    for (auto state : Trajectory) {

        if (state < 0 || state >= n) {
            cout << "Invalid state: " << state << endl;
            exit(1);
        }

        counts[state]++;
    }

    vector<double> empirical(n, 0.0);

    double Total = Trajectory.size();

    for (int i = 0; i < n; i++) {
        empirical[i] = counts[i] / Total;
    }

    return empirical;
}

vector<double> MarkovChain::runningTotalVariation(int startState, int steps) {

    vector<int> trajectory = simulate(startState, steps);
    vector<double> theoretical = P.stationaryDistribution();

    vector<double> tvDistances;
    vector<int> counts(n, 0);

    // Progressive empirical distribution
    for (size_t t = 0; t < trajectory.size(); ++t) {

        int state = trajectory[t];
        counts[state]++;

        // Compute empirical distribution at time t
        vector<double> empirical(n, 0.0);
        for (int i = 0; i < n; ++i) {
            empirical[i] = static_cast<double>(counts[i]) / (t + 1);
        }

        // Compute total variation distance
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += std::abs(empirical[i] - theoretical[i]);
        }

        tvDistances.push_back(0.5 * sum);
    }

    return tvDistances;
}


