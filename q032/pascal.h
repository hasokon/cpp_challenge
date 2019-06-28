//
// Created by keiwata on 2019-06-28.
//

#ifndef Q032_PASCAL_H
#define Q032_PASCAL_H

#include <cstdint>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>

namespace cpp_challenge::pascal {
    void print_pascal_raiangle(const uint32_t stage) {
        std::vector<uint32_t > container;
        for (int s = 1; s <= stage; ++s) {
            container.push_back(1);
            uint32_t before = 1;
            uint32_t tmp;
            for (int i = 1; i < s-1; ++i) {
                tmp = container[i];
                container[i] = before + tmp;
                before = tmp;
            }
            std::cout << std::setw((stage - s) * 2) << " ";
            std::for_each(container.begin(), container.end(), [](uint32_t e){ std::cout << std::setw(3) << e << " "; } );
            std::cout << std::endl;
        }
    }
}

#endif //Q032_PASCAL_H
