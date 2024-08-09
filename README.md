# XML Validator Console Application

This project is a Java-based console application designed to validate XML strings. The validation ensures that each starting element has a corresponding ending element and that the elements are well-nested.

## Project Structure

```
BoostDraftCodingAssignmentJava/
└── src/
    ├── boostdraftcodingassignment/
    │   ├── BoostDraftCodingAssignment.java
    │   └── Testcase.java
    └── xmlvalidatorlibrary/
        └── SimpleXmlValidator.java
```

### File Descriptions

- **BoostDraftCodingAssignmentJava/**
  - **src/**: Contains all the source code files.
    - **boostdraftcodingassignment/**
      - **BoostDraftCodingAssignment.java**: Main class to run the XML validation console application.
      - **Testcase.java**: Contains test cases for validating different XML strings.
    - **xmlvalidatorlibrary/**
      - **SimpleXmlValidator.java**: Provides the XML validation logic.

## How It Works

### Validation Logic

The `SimpleXmlValidator` class handles the XML validation process. It performs the following tasks:

1. **Initialization**:
   - Uses a stack data structure to track the opening tags as they are encountered in the XML string. This helps ensure that tags are properly nested and closed in the correct order.

2. **Tag Processing**:
   - As the XML string is read character by character, the class identifies the start of tags when it encounters a `<` character.
   - It then determines the end of the tag with the corresponding `>` character.

3. **Tag Handling**:
   - **Closing Tags**: Tags that start with `/` are treated as closing tags. The method checks if this closing tag matches the most recent opening tag by comparing it with the tag at the top of the stack. If there’s a mismatch or if the stack is empty when it should not be, the XML is considered invalid.
   - **Opening Tags**: Tags without a `/` are considered opening tags. The method ensures that these tags do not contain attributes or spaces, as only simple tags are supported. Valid opening tags are pushed onto the stack.

4. **Final Check**:
   - After processing all characters in the XML string, the method verifies that the stack is empty. An empty stack indicates that all opening tags had corresponding closing tags, confirming the XML’s validity.

### Testing

The `BoostDraftCodingAssignment` class is responsible for testing the `SimpleXmlValidator` class. It does the following:

1. **Setup**:
   - Initializes a list of `TestCase` objects, each holding an XML string and the expected result (true for valid, false for invalid).

2. **Validation and Output**:
   - Runs each test case through the `SimpleXmlValidator.determineXml` method.
   - Compares the validation result with the expected outcome. If they match, it prints "OK"; if not, it prints "NG" and counts the failure.
   - Outputs a summary of the number of successful tests compared to the total number of tests run.

### Test Case Management

The `TestCase` class serves as a container for test case data, simplifying the management and execution of multiple tests.

## Usage

### Command-Line Execution in Visual Studio Code

1. **Open Visual Studio Code**:
   - Ensure you have the Java Extension Pack installed for a better development experience.

2. **Navigate to the `src` Directory**:
   - Use the terminal in Visual Studio Code to change to the `src` directory:

     ```bash
     cd src
     ```

3. **Compile the Program**:
   - Compile the Java files using the following command:

     ```bash
     javac boostdraftcodingassignment/BoostDraftCodingAssignment.java xmlvalidatorlibrary/SimpleXmlValidator.java boostdraftcodingassignment/Testcase.java
     ```

4. **Run the Program**:
   - Execute the compiled class with an XML string as a command-line argument. For example:

     ```bash
     java boostdraftcodingassignment.BoostDraftCodingAssignment "<Design><Code>hello world</Code></Design>"
     ```

   - The output will indicate whether the XML is valid or invalid.

### Example Commands

- Valid XML:

  ```bash
  java boostdraftcodingassignment.BoostDraftCodingAssignment "<Design><Code>hello world</Code></Design>"
  ```

  **Output**:

  ```
  Valid
  ```

- Invalid XML:

  ```bash
  java boostdraftcodingassignment.BoostDraftCodingAssignment "<Design><Code>hello world</Code></Design><People>"
  ```

  **Output**:

  ```
  Invalid
  ```

## Contribution

Contributions to improve the project are welcome. Please ensure that any changes adhere to the existing coding style and constraints. Fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
