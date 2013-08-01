struct node {
    char c;
    int ind;
    node(char _c, int _ind): c(_c), ind(_ind){};
};

class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<node> parent;
        int len = s.size(), res = 0;
        parent.push(node(')', -1));
        
        for (int i = 0; i != len; i++){
            if (s[i] == '('){
                parent.push(node('(', i));
            }else{
                node top = parent.top();
                if (top.c == '('){
                    parent.pop();
                    res = max(res, i - parent.top().ind);
                }else{
                    parent.push(node(')', i));
                }
            }
        }
        return res;
    }
};