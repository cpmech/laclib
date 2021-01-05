#pragma once
#include <string>
#include <memory>
#include "triplet_for_mumps.h"

std::unique_ptr<TripletForMumps> read_matrix_for_mumps(const std::string &filename, bool use_nist_mmio = false);