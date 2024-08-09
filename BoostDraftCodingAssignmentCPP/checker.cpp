#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "simple_validator.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // Predefined test cases for validation
    vector<tuple<string, bool>> test_cases = {
        {"<Design><Code>hello world</Code></Design>", true},           // normal case
        {"<Design><Code>hello world</Code></Design><People>", false},  // no closing tag for "People"
        {"<People><Design><Code>hello world</People></Code></Design>", false}, // improper nesting
        {"<People age='1'>hello world</People>", false},               // attributes in tag
    };

    int failed_count = 0;
    for (const auto& test_case : test_cases) {
        const string& input = get<0>(test_case);
        bool expected = get<1>(test_case);

        bool result = DetermineXml(input);
        string result_str = result ? "Valid" : "Invalid";

        if (result == expected) {
            cout << "OK ";
        } else {
            cout << "NG ";
            failed_count++;
        }
        cout << input << ": " << result_str << endl;
    }

    cout << "Result: " << (test_cases.size() - failed_count) << "/" << test_cases.size() << endl;

    return 0;
}
