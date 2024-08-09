# XML Validator

This project is a C++ console application designed to validate XML strings. It ensures that the XML strings are well-formed by verifying that all opening tags have matching closing tags and that elements are properly nested.

## Project Structure

The project consists of the following files:

- **`simple_validator.hpp`**: Header file declaring the `DetermineXml` function.
- **`simple_validator.cpp`**: Implementation of the XML validation logic.
- **`checker.cpp`**: Contains predefined test cases for validating the `DetermineXml` function.
- **`main.cpp`**: Processes command-line arguments to validate XML strings.

## How It Works

### Validation Logic

The `DetermineXml` function in `simple_validator.cpp` performs the following steps:

1. **Tag Parsing**:
   - It uses a stack to keep track of open tags. When an opening tag is encountered, it's pushed onto the stack. When a closing tag is encountered, the top of the stack is checked for a matching opening tag.

2. **Tag Matching**:
   - The function ensures that each closing tag matches the most recent opening tag from the stack. If there is a mismatch or an extra closing tag, the XML is considered invalid.

3. **Nested Structure**:
   - Properly nested tags are verified by the stack. The function returns `true` if all tags are correctly matched and nested, and `false` otherwise.

### Testing

The `checker.cpp` file contains several test cases to verify the correctness of the XML validation logic. These test cases cover various scenarios including normal cases and edge cases such as unmatched tags and incorrect nesting.

## Running the Program

### Build Instructions

To compile the program, use a C++ compiler such as `g++`. For example, you can compile the program with the following command:

```sh
g++ -o checker main.cpp simple_validator.cpp checker.cpp
```

### Example Commands

#### Valid XML

```sh
./checker "<Design><Code>hello world</Code></Design>"
```

**Output:**

```
Valid
```

#### Invalid XML (Missing Closing Tag)

```sh
./checker "<Design><Code>hello world</Code></Design><People>"
```

**Output:**

```
Invalid
```

#### Invalid XML (Improper Nesting)

```sh
./checker "<People><Design><Code>hello world</People></Code></Design>"
```

**Output:**

```
Invalid
```

#### Invalid XML (Attributes in Tag)

```sh
./checker "<People age='1'>hello world</People>"
```

**Output:**

```
Invalid
```

## Note

I have implemented this XML validator in C++ to the best of my abilities. The code ensures that the XML strings are validated correctly according to the rules specified. Please feel free to review and provide any feedback or improvements.
