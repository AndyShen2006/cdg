// cdg client: A tool which can let you generate data conveniently
// This file is a part of cdg project, which provide a tool which can generate data efficiently
// Copyright (C) 2022 Andy Shen
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
#include "../../../include/information.hpp"
#include "maker.hpp"
#include <iostream>
#include <map>
#include <regex>
#include <string>
namespace basic {
void basic_info()
{
    std::cout << "cdg tool " << VERSION << ", "
              << "Last build on " << LAST_BUILD_DATE << std::endl;
    std::cout << "Author: " << AUTHOR << std::endl;
}

inline int basic_method(const std::string&& str)
{
    static std::map<std::string, int> methods = {
        { "--build", 1 }, { "-b", 1 },
        { "--check", 2 }, { "-c", 2 },
        { "--make", 3 }, { "-m", 3 }
    };
    if (methods.find(str) == methods.end()) {
        return -1;
    } else {
        return methods[str];
    }
}
enum {
    BUILD = 1,
    CHECK,
    MAKE
};
}

namespace checker {

}

namespace compiler {
// This part is very difficult, I won't finish this part at once
}

int main(int argc, char** argv)
{
    basic::basic_info();
    if (argc <= 1) {
        std::cout << "Too less arguments" << std::endl;
        exit(134);
    }
    switch (basic::basic_method(argv[1])) {
    case basic::BUILD:
        std::cout << "Mode: BUILD" << std::endl;
        break;
    case basic::CHECK:
        std::cout << "Mode: CHECK" << std::endl;
        break;
    case basic::MAKE:
        std::cout << "Mode: MAKE" << std::endl;
        if (argc == 7) {
            maker::execute(argv[2], argv[3], argv[4], argv[5], argv[6]);
        } else {
            maker::help();
        }
        break;
    default:
        std::cout << "Unknown argument named " << argv[1] << std::endl;
        exit(127);
    }
    return 0;
}