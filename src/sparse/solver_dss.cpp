#include <memory>

#include "solver_dss.h"

void SolverDss::analyze(const std::unique_ptr<SparseTriplet> &trip,
                        bool verbose) {
    // todo
}

void SolverDss::factorize(bool verbose) {
    // todo
}

void SolverDss::analyze_and_factorize(const std::unique_ptr<SparseTriplet> &trip,
                                      bool verbose) {
    // todo
}

void SolverDss::solve(std::vector<double> &x,
                      const std::vector<double> &rhs,
                      bool verbose) {
    // todo
}
