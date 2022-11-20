// maker header: The maker part of cdg client
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

#include <iostream>
#include <map>
#include <regex>
#include <string>
#ifndef _MAKER_H
#define _MAKER_H
namespace maker {
// Copied from Quick Make Data
// The quality of this part isn't good
std::string itoStr(int i)
{
    std::string s;
    while (i > 0) {
        s.push_back(static_cast<char>('0' + i % 10));
        i /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
void execute(const char* a1, const char* a2, const char* a3, const char* a4, const char* a5)
{
    std::string strFrom;
    for (int i = 6; a4[i]; i++) {
        strFrom.push_back(a4[i]);
    }
    int from = stoi(strFrom);
    std::string strTo;
    for (int i = 4; a5[i]; i++) {
        strTo.push_back(a5[i]);
    }
    int to = stoi(strTo);
    std::string input;
    for (int i = 4; a1[i]; i++) {
        input.push_back(a1[i]);
    }
    std::string output;
    for (int i = 4; a2[i]; i++) {
        output.push_back(a2[i]);
    }
    std::string dataOut;
    for (int i = 5; a3[i]; i++) {
        dataOut.push_back(a3[i]);
    }
    std::string exe;
    for (int i = from; i <= to; i++) {

        exe = input + " > " + dataOut + itoStr(i) + ".in"; // NOLINT
        system(exe.c_str());
        std::cout << "execute: " << exe << std::endl;
        exe = output + " < " + dataOut + itoStr(i) + ".in" + " > " + dataOut + itoStr(i) + ".out"; // NOLINT
        system(exe.c_str());
        std::cout << "execute: " << exe << std::endl;
    }
}

void help()
{
    printf("Usage: -mi=(make_input_file) -mo=(make_output_file) -out=(data_name) -from=(number_from) -to=(number to)\n");
}
}
#endif