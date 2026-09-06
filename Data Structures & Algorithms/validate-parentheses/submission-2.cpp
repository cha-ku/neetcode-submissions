class Solution {
public:
    bool isValid(string s) {
        std::stack<char> brackets;
        for (int i = 0; i < s.size(); ++i) {
            const char b = s[i];
            if (brackets.empty() ||  b == '(' || b == '[' || b == '{' ) {
                brackets.push(b);
            }
            else if ((b == ')' && brackets.top() == '(') || (b == ']' && brackets.top() == '[') ||(b == '}' && brackets.top() == '{')) {
                brackets.pop();
            }
            else {
                return false;
            }
        }
        return brackets.empty();
    }
};
