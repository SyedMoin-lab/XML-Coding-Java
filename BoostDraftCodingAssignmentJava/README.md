# XML Validator Console Application

Welcome! This project is a simple Java console application designed to validate XML strings. If you're curious about how it ensures your XML is well-formed and properly nested, read on!

## Project Structure

Here’s a quick overview of how everything is organized:

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
  - **src/**: This folder contains all the source code files.
    - **boostdraftcodingassignment/**
      - **BoostDraftCodingAssignment.java**: This is the main file that runs the application and tests the XML validator.
      - **Testcase.java**: A helper class that holds test cases for the XML validator.
    - **xmlvalidatorlibrary/**
      - **SimpleXmlValidator.java**: This is where the magic happens. It contains the logic to validate XML strings.

## How It Works

### Validation Logic

The `SimpleXmlValidator` class is the heart of our XML validation. Here’s a breakdown of what it does:

1. **Setup**:
   - It uses a stack to keep track of the tags as it processes the XML string. This helps ensure that tags are correctly nested.

2. **Processing Tags**:
   - As the XML string is read, the class looks for tags (things between `<` and `>`). When it finds an opening tag, it pushes it onto the stack. If it finds a closing tag, it checks if it matches the most recent opening tag. If not, it’s an invalid XML.

3. **Final Check**:
   - Once it has processed the entire string, the stack should be empty if all tags were properly closed. If the stack isn’t empty, it means there are unmatched opening tags, so the XML is invalid.

### Testing

The `BoostDraftCodingAssignment` class runs several tests to make sure everything is working correctly:

1. **Setup**:
   - It creates a list of test cases, each with an XML string and what the expected result should be (valid or invalid).

2. **Run Tests**:
   - It checks each XML string with the validator and compares the result to the expected outcome. It then prints out whether each test passed or failed and gives a summary at the end.

### Running the Program

To run this application in Visual Studio Code:

1. **Open Visual Studio Code**:
   - Make sure you have the Java Extension Pack installed.

2. **Navigate to the `src` Directory**:
   - Open the terminal in Visual Studio Code and change to the `src` directory:

     ```bash
     cd src
     ```

3. **Compile the Program**:
   - Use the following command to compile the Java files:

     ```bash
     javac boostdraftcodingassignment/BoostDraftCodingAssignment.java xmlvalidatorlibrary/SimpleXmlValidator.java boostdraftcodingassignment/Testcase.java
     ```

4. **Run the Program**:
   - Execute the compiled class with an XML string as a command-line argument. For example:

     ```bash
     java boostdraftcodingassignment.BoostDraftCodingAssignment "<Design><Code>hello world</Code></Design>"
     ```

   - You’ll see an output indicating whether the XML is valid or invalid.

### Example Commands

- For a valid XML:

  ```bash
  java boostdraftcodingassignment.BoostDraftCodingAssignment "<Design><Code>hello world</Code></Design>"
  ```

  **Output**:

  ```
  Valid
  ```

- For an invalid XML:

  ```bash
  java boostdraftcodingassignment.BoostDraftCodingAssignment "<Design><Code>hello world</Code></Design><People>"
  ```

  **Output**:

  ```
  Invalid
  ```

## Contributions

Feel free to contribute improvements or fix any issues you might find. Just fork the repository, make your changes, and submit a pull request. Your help is appreciated!

## License

This project is licensed under the MIT License. Check out the [LICENSE](LICENSE) file for more details.
