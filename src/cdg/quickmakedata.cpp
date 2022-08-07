#include <bits/stdc++.h>

using namespace std;

// -mi=(make_input_file) -mo=(make_output_file) -out=(data_name) -from=(number_from) -to=(number to)
string itos(int i)
{
    string s;
    while (i > 0) {
        s.push_back(static_cast<char>('0' + i % 10));
        i /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
void execute(const char* a1, const char* a2, const char* a3, const char* a4, const char* a5)
{
    string strfrom;
    for (int i = 6; a4[i]; i++) {
        strfrom.push_back(a4[i]);
    }
    int from = stoi(strfrom);
    // cout << atoi(strfrom.c_str()) << endl;
    string strTo;
    for (int i = 4; a5[i]; i++) {
        strTo.push_back(a5[i]);
    }
    int to = stoi(strTo);
    // cout << atoi(strTo.c_str()) << endl;
    string input;
    for (int i = 4; a1[i]; i++) {
        input.push_back(a1[i]);
    }
    // cout << input << endl;
    string output;
    for (int i = 4; a2[i]; i++) {
        output.push_back(a2[i]);
    }
    // cout << output << endl;
    string dataout;
    for (int i = 5; a3[i]; i++) {
        dataout.push_back(a3[i]);
    }
    // cout << dataout << endl;
    string exe;
    for (int i = from; i <= to; i++) {

        exe = input + " > " + dataout + itos(i) + ".in"; // NOLINT
        system(exe.c_str());
        cout << "execute: " << exe << endl;
        exe = output + " < " + dataout + itos(i) + ".in" + " > " + dataout + itos(i) + ".out"; // NOLINT
        system(exe.c_str());
        cout << "execute: " << exe << endl;
    }
}

void help()
{
    printf("Quick make data tool, By AndyShen2006\n");
    printf("Usage: -mi=(make_input_file) -mo=(make_output_file) -out=(data_name) -from=(number_from) -to=(number to)\n");
}

int main(int argc, char const* argv[])
{
    // printf("%d\n%s %s %s %s %s", argc, argv[1], argv[2], argv[3], argv[4], argv[5]);
    if (argc == 6) {
        execute(argv[1], argv[2], argv[3], argv[4], argv[5]);
    } else {
        help();
    }
    return 0;
}