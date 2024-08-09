# XML Validator
## Overview

Welcome to the XML Validator project! This is a console application I created to validate XML strings. The primary goal of this project is to ensure that XML strings are well-formed by verifying that:
- Every opening tag has a corresponding closing tag.
- Tags are properly nested, meaning that tags open and close in the correct order.

I've implemented this in C# and avoided using XML libraries or regular expressions to keep things simple and in line with the project constraints.

## Project Structure

The project is divided into two main folders:

1. **`Main`**: Contains the entry point of the application.
   - **`Program.cs`**: This file includes the `Main` method that processes command-line arguments, runs validation tests, and outputs results.

2. **`SimpleXMLValidatorLibrary`**: Contains the core XML validation logic.
   - **`SimpleXmlValidator.cs`**: Contains the `DetermineXml` method which performs the XML validation based on the specified rules.

### Files Overview

- **`Program.cs`**: Manages the execution of the application, including both command-line arguments and test cases for validation.
- **`SimpleXmlValidator.cs`**: Implements the XML validation logic using a stack-based approach to ensure tags are matched and properly nested.

## How It Works

### Validation Logic

The `DetermineXml` method is designed to validate XML strings according to the following rules:

1. **Tag Parsing**: The method reads through the XML string character by character. It identifies tags by detecting the `<` and `>` characters. Tags can be opening or closing tags, distinguished by the presence of a `/` in the tag name for closing tags.

2. **Tag Matching Using Stack**:
   - **Opening Tags**: When an opening tag is encountered (e.g., `<Design>`), the tag name is extracted and pushed onto a stack. The stack helps keep track of the tags that are currently open and need to be closed.
   - **Closing Tags**: When a closing tag is found (e.g., `</Design>`), the method checks the stack to ensure that the most recent opening tag matches the closing tag. If it matches, the opening tag is removed from the stack (popped). If it does not match or if the stack is empty (indicating no corresponding opening tag), the XML string is deemed invalid.

3. **Tag Name Extraction**: To ensure that only the tag names are matched (ignoring any attributes), the method splits the tag content by spaces and takes the first part as the tag name. This approach ensures that attributes within the tags do not interfere with the validation process.

4. **Nesting Verification**:
   - **Correct Nesting**: The stack-based approach ensures that the last opened tag is the first to be closed. This validates that tags are properly nested. For example, in `<A><B></B></A>`, `<B>` is closed before `<A>`, which is correct.
   - **Invalid Nesting**: Tags are considered improperly nested if closing tags appear out of order relative to their opening tags. For example, in `<A><B></A></B>`, the tag `<A>` is closed before `<B>`, which is incorrect.

5. **Final Check**: After parsing the entire XML string, the stack is checked. If the stack is empty, it means all opened tags have matching closing tags and are properly nested, so the XML string is considered valid. If there are any tags left in the stack, it indicates that some opening tags were not closed, making the XML string invalid.

### Handling Special Cases

- **Malformed Tags**: Tags that are not properly closed (e.g., `<tag>` without a corresponding `</tag>`) are detected by the stack mechanism. If a tag is left open or if a closing tag is found without a corresponding opening tag, the XML is marked as invalid.

- **Attributes in Tags**: The implementation does not handle attributes within tags. Tags with attributes are treated as valid as long as their tag names match correctly. For instance, `<tag attribute="value">...</tag>` is processed as `<tag>...</tag>` for matching purposes.

- **Edge Cases**:
  - **Empty Strings**: An empty string is considered valid XML since there are no tags to validate.
  - **Single Tags**: Strings with only opening or only closing tags are invalid. For instance, `<tag>` or `</tag>` alone is invalid.

### Testing

The application includes a set of predefined test cases to validate the `DetermineXml` method. These test cases cover:
- **Basic Valid XML**: Correctly formed XML strings with proper nesting and matching tags.
- **Missing Closing Tags**: XML strings where closing tags are missing.
- **Improper Nesting**: XML strings with tags that are not properly nested.
- **Attributes in Tags**: XML strings with attributes, demonstrating that attributes do not affect the validation.

The `Program.cs` file runs these test cases to verify that the `DetermineXml` method behaves as expected. Each test case is evaluated, and the results are printed to the console, showing whether the XML string is valid or invalid.

## Running the Program

### Building the Project

To build the project, navigate to the project directory and run:

```bash
dotnet build
```

This command compiles the source code and generates the necessary binaries.

### Running with Command-Line Arguments

To validate an XML string, use:

```bash
dotnet run "<Your XML string here>"
```

Replace `<Your XML string here>` with the XML string you want to test. The application will output `Valid` if the XML is correctly formed or `Invalid` otherwise.

### Running with Test Cases

To execute predefined test cases for debugging purposes, run:

```bash
dotnet run
```

This command will execute the test cases defined in `Program.cs` and display the results.

## Example Commands

Here are some example commands to test the XML validator:

1. **Valid XML String:**
   ```bash
   dotnet run "<Design><Code>hello world</Code></Design>"
   ```
   **Output:** `Valid`

2. **Invalid XML String (No closing tag for "People"):**
   ```bash
   dotnet run "<Design><Code>hello world</Code></Design><People>"
   ```
   **Output:** `Invalid`

3. **Invalid XML String (Improperly nested tags):**
   ```bash
   dotnet run "<People><Design><Code>hello world</People></Code></Design>"
   ```
   **Output:** `Invalid`

4. **Invalid XML String (Attributes in tags):**
   ```bash
   dotnet run "<People age='1'>hello world</People>"
   ```
   **Output:** `Invalid`

## Development and Contribution

Feel free to fork this repository and make improvements. If you decide to contribute:
- Follow the existing code style and conventions.
- Write clear and concise commit messages.
- Test your changes thoroughly before submitting a pull request.

## Additional Notes

- **Performance**: The current implementation works well for typical XML strings. Performance may vary with extremely large XML files.
- **Error Handling**: Basic error handling is included. For more comprehensive validation, additional mechanisms could be added.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
