#include <catch2/catch_test_macros.hpp>

#include "Lcs.h"
// #include "Kmp.h"
#include "integradora1.h"

TEST_CASE("longest_common_substring")
{
    REQUIRE(longest_common_substring("hello world", "hello") == "hello");
    REQUIRE_THROWS_AS(longest_common_substring("abcdef", "ghijkl"),
                      std::invalid_argument);
    REQUIRE(longest_common_substring("Hola", "o1243154145234la") == "la");
    REQUIRE(longest_common_substring("Hola", "o1243154145234LA") == "o");
}

TEST_CASE("lcs") 
{
    REQUIRE(algorithms::longestCommonSubstring("abc", "abc") == {1,3});
    REQUIRE(algorithms::longestCommonSubstring("startingpoint", "start") == {1,5});
    REQUIRE(algorithms::longestCommonSubstring("abcabc", "bcabc") == {2,6}); 
}

// TEST_CASE("KMP Algorithm Tests") {
//     algorithms algo;

//     SECTION("Single match") {
//         std::string text = "ababcabcababc";
//         std::string pattern = "abc";
//         std::vector<int> lps = algo.preprocess(pattern);
//         std::vector<int> result = algo.containsText(text, pattern, lps);

//         REQUIRE(result == std::vector<int>{2, 5, 10});
//     }

//     SECTION("Multiple matches") {
//         std::string text = "aaaaa";
//         std::string pattern = "aa";
//         std::vector<int> lps = algo.preprocess(pattern);
//         std::vector<int> result = algo.containsText(text, pattern, lps);

//         REQUIRE(result == std::vector<int>{0, 1, 2, 3});
//     }

//     SECTION("No match") {
//         std::string text = "abcdef";
//         std::string pattern = "gh";
//         std::vector<int> lps = algo.preprocess(pattern);
//         std::vector<int> result = algo.containsText(text, pattern, lps);

//         REQUIRE(result.empty());
//     }

//     SECTION("Pattern equals text") {
//         std::string text = "exact";
//         std::string pattern = "exact";
//         std::vector<int> lps = algo.preprocess(pattern);
//         std::vector<int> result = algo.containsText(text, pattern, lps);

//         REQUIRE(result == std::vector<int>{0});
//     }
// }