#include <iostream>

#include "matrix.h"

void Matrix::print() {
    for (size_t i = 0; i < this->nrow; i++) {
        for (size_t j = 0; j < this->ncol; j++) {
            std::cout << this->data[i + j * this->nrow] << ", ";
        }
        std::cout << std::endl;
    }
}
