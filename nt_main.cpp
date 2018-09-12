#ifndef NTHASH_OPT
  #include "nthash_simple.hpp"
  using namespace nthash;
#else
  #ifndef NTHASH_104
    #include "nthash.hpp"
  #else
    #include "nthash_104.hpp"
  #endif
#endif

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    string seq = argv[1];

    uint64_t hVal, fhVal, rhVal;

    hVal = NTC64(seq.c_str(), seq.size(), fhVal, rhVal); // initial hash value
    cout << "NTC64 0x" << hex << setfill('0') << setw(16) << hVal << endl;
    cout << "fhVal 0x" << hex << setfill('0') << setw(16) << fhVal << endl;
    cout << "rhVal 0x" << hex << setfill('0') << setw(16) << rhVal << endl;

    return 0;
}
