# XML Validator Console Application - Explanation

## Project Overview

This Java console application validates XML strings to ensure they are well-formed. It checks if every starting element has a corresponding ending element and ensures that elements are properly nested.

## File Descriptions

### 1. `BoostDraftCodingAssignment.java`

This file contains the `BoostDraftCodingAssignment` class, which serves as the main entry point of the application.

#### Key Components:

- **Main Method**: 
  - Initializes a list of `TestCase` objects. Each test case contains an XML string and the expected validation result.
  - Iterates through the list, validates each XML string using the `SimpleXmlValidator`, and compares the result with the expected output.
  - Prints whether each test case passed or failed.
  - Displays a summary of the number of passing and failing test cases.

- **Test Case Initialization**:
  - Includes various test scenarios such as correctly formed XML, mismatched tags, and attributes within tags.

### 2. `TestCase.java`

This file defines the `TestCase` class, which is used to represent individual test cases.

#### Key Components:

- **Fields**:
  - `input`: A string representing the XML input.
  - `expectedOutput`: A boolean indicating whether the XML should be considered valid (`true`) or invalid (`false`).

- **Constructor**:
  - Initializes the `input` and `expectedOutput` fields.

### 3. `SimpleXmlValidator.java`

This file contains the `SimpleXmlValidator` class, which provides the XML validation logic.

#### Key Components:

- **`determineXml` Method**:
  - Uses a stack to keep track of opening tags.
  - Iterates through the XML string:
    - Identifies opening tags (e.g., `<tag>`), pushes them onto the stack.
    - Identifies closing tags (e.g., `</tag>`), checks if they match the most recent opening tag on the stack.
    - Handles invalid XML by returning `false` for cases with unmatched tags or invalid tag formats.
  - Ensures that all tags are properly closed by verifying that the stack is empty at the end of the string.

## How It Works

1. **Validation Logic**:
   - The `SimpleXmlValidator` class reads through the XML string, processes each tag, and maintains a stack to ensure proper nesting and matching of tags.
   - The method `determineXml` performs the core validation, checking both the structure of tags and the absence of attributes.

2. **Testing**:
   - The `BoostDraftCodingAssignment` class runs several test cases to validate the correctness of the `SimpleXmlValidator`.
   - The results are compared against expected outcomes, and a summary is printed to the console.

## Example Usage

To compile and run the application:

1. **Navigate to the `src` Directory**:

   ```bash
   cd src
   ```

2. **Compile the Java Files**:

   ```bash
   javac boostdraftcodingassignment/BoostDraftCodingAssignment.java xmlvalidatorlibrary/SimpleXmlValidator.java boostdraftcodingassignment/TestCase.java
   ```

3. **Run the Application**:

   ```bash
   java boostdraftcodingassignment.BoostDraftCodingAssignment
   ```

The output will show the result of each test case, indicating whether the XML strings are valid or invalid, and provide a summary of the test results.

## Contribution

Feel free to fork the repository, make improvements, and submit pull requests. Ensure any contributions adhere to the coding style and constraints outlined.
