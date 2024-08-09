# Take-Home Coding Test: XML Validation

## Overview

Thank you for reviewing my solution to the XML validation coding test. I've put considerable effort into ensuring the application meets the provided specifications and adheres to best practices. My goal is not only to deliver a functional solution but also to demonstrate how I can contribute effectively to the team.

## Project Description

This console application validates XML strings based on the following criteria:

1. **Matching Tags**: Every opening tag must have a corresponding closing tag with the same name.
2. **Well-Nested Elements**: Tags must be well-nested, meaning the last opened tag should be the first closed.

### Requirements

- **Input**: An XML string provided as the first command line argument.
- **Output**: `Valid` if the XML string is valid; otherwise, `Invalid` on a new line.

### Examples

Here are a few examples of how the application works:

1. **Valid XML:**
    ```bash
    > checker.exe "<Design><Code>hello world</Code></Design>"
    Valid
    ```

2. **Invalid XML (Unmatched Tag):**
    ```bash
    > checker.exe "<Design><Code>hello world</Code></Design><People>"
    Invalid
    ```

3. **Invalid XML (Incorrect Nesting):**
    ```bash
    > checker.exe "<People><Design><Code>hello world</People></Code></Design>"
    Invalid
    ```

4. **Invalid XML (Tag Mismatch):**
    ```bash
    > checker.exe "<People age='1'>hello world</People>"
    Invalid
    ```

### Key Constraints

- **Libraries**: Usage of `System.XML`, other XML libraries, or regular expressions is prohibited.
- **Language**: The solution can be implemented in C#, C++, Java, or Rust.

## Pull Request Description

In this pull request, I have included:

- A console application that checks the validity of XML strings.
- Comprehensive documentation explaining the logic and structure of the code.
- Edge case handling and explanations for any non-standard cases.

### Contribution and Team Integration

By contributing this solution, I aim to:

- **Deliver High-Quality Code**: My code is designed to be functional, efficient, and easy to understand, ensuring it meets professional development standards.
- **Enhance Team Collaboration**: I value open communication and am eager to discuss and review code with team members to ensure alignment and improve overall project quality.
- **Provide Thorough Documentation**: I believe in the importance of clear and concise documentation, which helps both current and future team members understand the codebase and its functionalities.
- **Offer Insights and Suggestions**: I am proactive in identifying potential improvements or optimizations and am open to feedback to refine the solution further.

## Delivery

- **Project**: The console application project is included.
- **Zip File**: The project is zipped with the filename `BoostDraftCodingAssignment_SyedMoinuddin.zip` as requested.

**Note**: Please be aware that executables might be blocked by the mailing system. If necessary, please remove the executable files from the zip before sending.

## Conclusion

I hope this solution meets the expectations and provides a robust approach to XML validation. I am excited about the opportunity to contribute to the team and am open to any questions or feedback regarding the code.

Thank you for considering my application!
