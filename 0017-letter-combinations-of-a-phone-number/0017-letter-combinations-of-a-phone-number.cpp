class Solution {
public:
    void f(int j, string& digits, vector<string>& comb_ans, string ans,
           vector<vector<char>>& combination) {
        if (j == digits.size()) {
            comb_ans.push_back(ans);
            return;
        }
        int digitIdx = digits[j] - '2';
        for(auto c:combination[digitIdx]) {
            f(j + 1, digits, comb_ans, ans + c, combination);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> combination = {{'a', 'b', 'c'} ,{'d', 'e', 'f'} ,{
            'g', 'h', 'i'} ,{'j', 'k', 'l'} ,{'m', 'n', 'o'} ,{
            'p', 'q', 'r', 's'} ,{'t', 'u', 'v'} ,{'w', 'x', 'y', 'z'}};
        vector<string> comb_ans;
        f(0, digits, comb_ans, "", combination);
        return comb_ans;
    }
};