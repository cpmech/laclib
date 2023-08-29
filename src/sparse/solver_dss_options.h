#pragma once

#include <memory>

struct DssOptions {
    bool symmetric;

    inline static std::unique_ptr<DssOptions> make_new(bool symmetric = false) {
        return std::unique_ptr<DssOptions>{new DssOptions{
            symmetric,
        }};
    };
};
