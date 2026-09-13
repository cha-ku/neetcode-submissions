class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> nums;
        for (const auto& t : tokens) {
            if (t == "+") {
                int op1 = nums.top();
                nums.pop();
                int op2 = nums.top();
                nums.pop();
                nums.push(op1 + op2);
            }
            else if (t == "-") {
                int op1 = nums.top();
                nums.pop();
                int op2 = nums.top();
                nums.pop();
                nums.push(op2 - op1);
            }
            else if (t == "*") {
                int op1 = nums.top();
                nums.pop();
                int op2 = nums.top();
                nums.pop();
                nums.push(op1 * op2);
            }
            else if (t == "/") {
                int op1 = nums.top();
                nums.pop();
                int op2 = nums.top();
                nums.pop();
                nums.push(op2 / op1);
            }
            else {
                nums.push(std::stoi(t));
            }
        }
        return nums.top();
    }
};
