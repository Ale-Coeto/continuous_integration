#include <catch2/catch_test_macros.hpp>

#include "l.h"
#include "k.h"
#include "Palindrome.h"

TEST_CASE("palindrome") {
    SECTION("single character") {
        REQUIRE(algorithms::longestPalidrome("abaxyzzyxf") == std::pair<int, int>{4,9});
    }

    SECTION("word") {
        REQUIRE(algorithms::longestPalidrome("racecar") == std::pair<int, int>{1,7});
    }
}

TEST_CASE("lcs") 
{
    REQUIRE(algorithms::longestCommonSubstring("abcabc", "bcabc") == std::pair<int,int>{2,6});
    REQUIRE(algorithms::longestCommonSubstring("startingpoint", "start") == std::pair<int,int>{1,5});
    REQUIRE(algorithms::longestCommonSubstring("abc", "abc") == std::pair<int,int>{1,3});
}

TEST_CASE("KMP Algorithm Tests") {

    SECTION("Single match") {
        std::string text = "ababcabcababc";
        std::string pattern = "abc";
        std::vector<int> lps = algorithms::preprocess(pattern);
        std::vector<int> result = algorithms::containsText(text, pattern, lps);

        REQUIRE(result == std::vector<int>{2, 5, 10});
    }

    SECTION("Multiple matches") {
        std::string text = "aaaaa";
        std::string pattern = "aa";
        std::vector<int> lps = algorithms::preprocess(pattern);
        std::vector<int> result = algorithms::containsText(text, pattern, lps);

        REQUIRE(result == std::vector<int>{0, 1, 2, 3});
    }

    SECTION("No match") {
        std::string text = "abcdef";
        std::string pattern = "gh";
        std::vector<int> lps = algorithms::preprocess(pattern);
        std::vector<int> result = algorithms::containsText(text, pattern, lps);

        REQUIRE(result.empty());
    }

    SECTION("Pattern equals text") {
        std::string text = "exact";
        std::string pattern = "exact";
        std::vector<int> lps = algorithms::preprocess(pattern);
        std::vector<int> result = algorithms::containsText(text, pattern, lps);

        REQUIRE(result == std::vector<int>{0});
    }
}