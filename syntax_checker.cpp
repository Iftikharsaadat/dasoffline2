#include <stack>
#include <string>
using namespace std;

/**
 * Helper function to check if an opening bracket matches a closing bracket
 * @param opening: The opening bracket character
 * @param closing: The closing bracket character
 * @return true if they form a matching pair, false otherwise
 */
bool isMatchingPair(char opening, char closing) {

    // TODO: Implement this helper function
    if (opening == '(' && closing == ')') return true;
    if (opening == '[' && closing == ']') return true;
    if (opening == '{' && closing == '}') return true;

    // Check if opening and closing brackets match
    // Valid pairs: (), [], {}
    return false; // Replace this with your implementation
}

/**
 * Checks if brackets in an arithmetic expression are properly matched
 * @param expression: A string containing an arithmetic expression
 * @return true if all brackets are properly matched and balanced, false otherwise
 */
bool isValidExpression(const string& expression) {
    // TODO: Implement the syntax checker using std::stack
    stack<char> bracketStack;
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            bracketStack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (bracketStack.empty() || !isMatchingPair(bracketStack.top(), ch)) {
                return false;
            }
            bracketStack.pop();
        }
    }

    if (bracketStack.empty()) {
        return true;
    } else {
        return false;
    }
    
    return false; // Replace this with your implementation
}
