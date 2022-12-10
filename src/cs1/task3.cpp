#include <stack>
#include <string>

bool readAndDelete(std::stack<char> &letters, std::string word)
{
    if (word.empty()) {
        return true;
    }

    std::stack<char> helperStack;
    while (!letters.empty()) {
        char current = letters.top();
        letters.pop();

        if (current == word[0]) {
            word = word.substr(1);
            continue;
        }
        helperStack.push(current);
    }
    while (!helperStack.empty()) {
        char current = helperStack.top();
        helperStack.pop();
        letters.push(current);
    }

    return word.empty();
}
