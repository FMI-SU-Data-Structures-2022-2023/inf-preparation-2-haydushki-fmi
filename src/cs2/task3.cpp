#include <queue>
#include <stack>
#include <string>

bool readAndDeleteQueue(std::queue<char> &letters, std::string word)
{
    if (word.empty()) {
        return true;
    }

    std::stack<char> helperStack;
    while (!letters.empty()) {
        char current = letters.front();
        letters.pop();
        if (current == word[0]) {
            word = word.substr(1);
            continue;
        }
        helperStack.push(current);
    }

    while (!helperStack.empty()) {
        letters.push(helperStack.top());
        helperStack.pop();
    }

    return word.empty();
}
