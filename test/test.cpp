#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "autocheck/autocheck.hpp"
#include "autocheck/check.hpp"

namespace ac = autocheck;

#include "nthash.hpp"
#include "nthash_simple.hpp"

static const char alnts[] = "ACGTN";

class seq_generator {
  public:
    typedef std::basic_string<char> result_type;

    result_type operator() (size_t size = 1) {
      result_type rv;
      rv.reserve(size);

      std::uniform_int_distribution<int> dist(0, 5);

      std::generate_n(std::back_insert_iterator<result_type>(rv), size, 
          [&]{ return alnts[dist(ac::rng())]; });

      return rv;
    }
};


struct prop_nt_oracle {
  bool operator () (const string& seq) {
    uint64_t fhVal, rhVal, hValOpt, hValArticle;

    hValOpt = NTC64(seq.c_str(), seq.size(), fhVal, rhVal);
    hValArticle = nthash::NTC64(seq.c_str(), seq.size(), fhVal, rhVal);

    return hValOpt == hValArticle;
  }
};


TEST_CASE( "oracle", "[nthash]" ) {
  ac::catch_reporter rep;

  SECTION("optimized matches simple implementation outputs?") {
    ac::check<std::string>(prop_nt_oracle(), 100,
        ac::make_arbitrary(seq_generator()), rep);
  }
}
