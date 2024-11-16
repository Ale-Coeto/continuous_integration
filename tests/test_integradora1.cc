#include <catch2/catch_test_macros.hpp>

#include "LCS.h"

TEST_CASE("lcs") {
    REQUIRE(algorithms::longestCommonSubstring("abc", "abc") == {1,3});
    REQUIRE(algorithms::longestCommonSubstring("startingpoint", "start") == {1,5});
    REQUIRE(algorithms::longestCommonSubstring("abcabc", "bcabc") == {2,6}); 
}
