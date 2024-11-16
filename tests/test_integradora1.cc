#include <catch2/catch_test_macros.hpp>

#include "LCS.h"

TEST_CASE("lcs") {
    REQUIRE(longestCommonSubstring("abc", "abc") == {1,3});
    REQUIRE(longestCommonSubstring("startingpoint", "start") == {1,5});
    REQUIRE(longestCommonSubstring("abcabc", "bcabc") == {2,6}); 
}
