class Solution {
private:
    unordered_set<string> validExpressions; //this is storing all the valid expressions
    int minimumRemoved;
    void reset() 
    {
        validExpressions.clear();
        minimumRemoved = INT_MAX;
    }
    //leftCount and rightCount represents left and right parentheses
    void recurse(string& s, int index, int leftCount, int rightCount, string& expression, int removedCount) {
        if (index == s.length()) // If we have reached the end of the string
        {
            if (leftCount == rightCount) // If the current expression is valid
            {
                // If the current count of removed parentheses is <= the current minimum count
                if (removedCount <= minimumRemoved) {
                    if (removedCount < minimumRemoved) 
                    {
                        validExpressions.clear();
                        minimumRemoved = removedCount;
                    }
                    validExpressions.insert(expression);//set me expression ko insert krdenge
                }
            }
            return;
        }
        char currentCharacter = s[index];
        int length = expression.length();
        // If the current character is neither '(' nor ')'
        if (currentCharacter != '(' && currentCharacter != ')') 
        {
            expression += currentCharacter;
            recurse(s, index + 1, leftCount, rightCount, expression, removedCount);
            expression.pop_back();  // Undo the append
        } 
        else 
        {
            // Recursion where we delete the current character and move forward
            recurse(s, index + 1, leftCount, rightCount, expression, removedCount + 1);
            expression += currentCharacter;

            // If it's an opening parenthesis, consider it and recurse
            if (currentCharacter == '(') 
            {
                recurse(s, index + 1, leftCount + 1, rightCount, expression, removedCount);
            } 
            else if (rightCount < leftCount) 
            {
                // For a closing parenthesis, only recurse if right < left
                recurse(s, index + 1, leftCount, rightCount + 1, expression, removedCount);
            }
            // Undo the append operation for other recursions
            expression.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        // realised it is a recursion problem as here we are not aware which bracket to remove              
        // greedily and we have to check for all
        //Steps for APPROACH- 1 Backtracking
        //TC- O(2^N)
        //SC- O(N)
        reset();
        string expression;
        recurse(s, 0, 0, 0, expression, 0);
        return vector<string>(validExpressions.begin(), validExpressions.end());
    }
};