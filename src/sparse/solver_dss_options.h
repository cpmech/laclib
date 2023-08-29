#pragma once

#include <memory>

struct DssOptions {
    bool symmetric;
    bool positive_definite;

    inline static std::unique_ptr<DssOptions> make_new(bool symmetric = false, bool positive_definite = false) {
        return std::unique_ptr<DssOptions>{new DssOptions{
            symmetric,
            positive_definite,
        }};
    };
};
