#include "simple_validator.hpp"
#include <stack>
#include <cctype>

bool DetermineXml(const std::string& xml) {
    std::stack<std::string> tagStack;
    std::string tagName;
    bool insideTag = false;
    bool closingTag = false;

    for (char ch : xml) {
        if (ch == '<') {
            insideTag = true;
            tagName.clear();
            closingTag = false;
        } else if (ch == '>') {
            if (!insideTag) {
                return false; // Invalid XML: unexpected '>'
            }
            insideTag = false;
            if (closingTag) {
                if (tagStack.empty()) {
                    return false; // Invalid XML: closing tag with no matching opening tag
                }
                if (tagStack.top() != tagName) {
                    return false; // Invalid XML: mismatched tags
                }
                tagStack.pop();
            } else {
                tagStack.push(tagName);
            }
        } else if (insideTag) {
            if (ch == '/') {
                closingTag = true;
            } else if (!std::isspace(ch) && !std::isalpha(ch) && !std::isdigit(ch)) {
                return false; // Invalid XML: unexpected character in tag name
            } else {
                tagName += ch;
            }
        }
    }

    return tagStack.empty(); // Valid if all tags are matched
}
