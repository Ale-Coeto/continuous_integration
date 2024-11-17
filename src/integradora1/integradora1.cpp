// #include "FileReader.h"
// #include "k.h"
// #include "l.h"
// #include "Palindrome.h"
// #include <iostream>

// using namespace std;

// void containedText(vector<string> &transmissions, vector<string> &mcodes)
// {
//     vector<vector<int>> mcodesPre;

//     for (int i = 0; i < 3; i++)
//     {
//         mcodesPre.push_back(algorithms::preprocess(mcodes[i]));
//     }

//     for (auto transmission : transmissions)
//     {
//         for (int i = 0; i < mcodes.size(); i++)
//         {
//             vector<int> result =
//                 algorithms::containsText(transmission, mcodes[i], mcodesPre[i]);

//             if (result.size() <= 0)
//             {
//                 cout << "false" << endl;
//             }
//             else
//             {
//                 cout << "true ";
//                 for (auto i : result)
//                 {
//                     // 1-indexed
//                     cout << i + 1 << " ";
//                 }
//                 cout << endl;
//             }
//         }
//     }
// }

// string longest_common_substring(string str1, string str2)
// {
//     pair<int, int> indices = algorithms::longestCommonSubstring(str1, str2);
//     string res =
//         str1.substr(indices.first - 1, indices.second - indices.first + 1);
//     cout << "res: " << res << endl;
//     return res;
// }

// string largest_palindrome(string str1)
// {
//     pair<int, int> indices = algorithms::longestPalidrome(str1);
//     return str1.substr(indices.first - 1, indices.second - indices.first + 1);
// }

// bool contains_text(string str1, string pattern)
// {
//     vector<int> lps = algorithms::preprocess(pattern);
//     vector<int> result = algorithms::containsText(str1, pattern, lps);

//     return result.size() > 0;
// }

// int main() {
//     return 0;
// }