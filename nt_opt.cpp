#include "nthash.hpp"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    std::string seq = argv[1];

    uint64_t hVal, fhVal, rhVal;

    hVal = NTC64(seq.c_str(), seq.size(), fhVal, rhVal); // initial hash value
    cout << "NT64C 0x" << hex << setfill('0') << setw(16) << hVal << endl;
    cout << "fhVal 0x" << hex << setfill('0') << setw(16) << fhVal << endl;
    cout << "rhVal 0x" << hex << setfill('0') << setw(16) << rhVal << endl;

    return 0;
}
