#include <string>
#include <vector>
#include <queue>

using std::string;
using std::vector;

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k)
    {
        if (k <= 0 || (signed)strarr.size() < k) {
            return "";
        }
        std::queue<int> lengths;
        int max_length = 0;
        int max_pos = 0;
        int current_length = 0;
        for (int i = 0; i < k; i++) {
            lengths.push(strarr[i].length());
            current_length += strarr[i].length();
        }
        max_length = current_length;
        for (int i = k; i < (signed)strarr.size(); i++) {
            current_length -= lengths.front();
            lengths.pop();
            current_length += strarr[i].length();
            lengths.push(strarr[i].length());
            if (current_length > max_length) {
                max_length = current_length;
                max_pos = i - k + 1;
            }
        }
        string result;
        for (int i = max_pos; i < max_pos + k; i++) {
            result += strarr[i];
        }
        return result;
    }
};

//------- CUT HERE ------

#include <iostream>

int main()
{

    // test 1
    vector<string> v = { "ana", "are", "mere", "acre" };
    int k = 2;
    std::cout << LongestConsec::longestConsec(v, k) << std::endl;

}
