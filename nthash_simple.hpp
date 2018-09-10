#include <string>

using namespace std;

namespace nthash {

uint64_t h(char i) {
  switch (i) {
    case 'A':
      return 0x3c8bfbb395c60474;
    case 'C':
      return 0x3193c18562a02b4c;
    case 'G':
      return 0x20323ed082572324;
    case 'T':
      return 0x295549f54be24456;
    case 'N':
      return 0x0000000000000000;
    default:
      break;
  }
}

uint64_t rc(char i) {
  switch (i) {
    case 'A':
      return 0x295549f54be24456;
    case 'C':
      return 0x20323ed082572324;
    case 'G':
      return 0x3193c18562a02b4c;
    case 'T':
      return 0x3c8bfbb395c60474;
    case 'N':
      return 0x0000000000000000;
    default:
      break;
  }
}

uint64_t rol(uint64_t v, unsigned k) {
  return (v << k) | (v >> (64 - k));
}

inline uint64_t NT64(const char * kmerSeq, const unsigned k) {
  uint64_t hVal = 0;
  for(unsigned i=0; i < k; i++)
    hVal ^= rol(h(kmerSeq[i]), k-1-i);
  return hVal;
}

inline uint64_t NTF64(const char * kmerSeq, const unsigned k) {
  uint64_t hVal = 0;
  for(unsigned i=0; i < k; i++)
    hVal ^= rol(h(kmerSeq[i]), k-1-i);
  return hVal;
}

inline uint64_t NTR64(const char * kmerSeq, const unsigned k) {
  uint64_t hVal = 0;
  for(unsigned i=0; i < k; i++)
    hVal ^= rol(rc(kmerSeq[k-i-1]), k-1-i);
  return hVal;
}

inline uint64_t NTC64(const char * kmerSeq, const unsigned k, uint64_t& fhVal, uint64_t& rhVal) {
    fhVal=NTF64(kmerSeq, k);
    rhVal=NTR64(kmerSeq, k);
    return (rhVal<fhVal)? rhVal : fhVal;
}

}
