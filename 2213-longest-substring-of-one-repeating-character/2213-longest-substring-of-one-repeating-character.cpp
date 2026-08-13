class Solution {
    struct Node {
        int max_len;
        int pref_len;
        int suff_len;
        char pref_char;
        char suff_char;
    };

    vector<Node> tree;

    void merge(Node& parent, const Node& left, const Node& right, int left_size, int right_size) {
        parent.pref_char = left.pref_char;
        parent.suff_char = right.suff_char;

        parent.pref_len = left.pref_len;
        if (left.pref_len == left_size && left.pref_char == right.pref_char) {
            parent.pref_len += right.pref_len;
        }

        parent.suff_len = right.suff_len;
        if (right.suff_len == right_size && right.suff_char == left.suff_char) {
            parent.suff_len += left.suff_len;
        }

        parent.max_len = max(left.max_len, right.max_len);
        if (left.suff_char == right.pref_char) {
            parent.max_len = max(parent.max_len, left.suff_len + right.pref_len);
        }
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        merge(tree[node], tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        merge(tree[node], tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len;
        }

        return ans;
        
    }
};