# Postfix Expression Evaluator

## Overview

This C program is designed to evaluate postfix expressions (Reverse Polish Notation) and translate them into a sequence of machine instructions. The target machine for these instructions has a single register and supports six basic operations:

- `LD A` (Load): Loads the value of `A` into the register.
- `ST A` (Store): Stores the current register value into `A`.
- `AD A` (Add): Adds the value of `A` to the register.
- `SB A` (Subtract): Subtracts the value of `A` from the register.
- `ML A` (Multiply): Multiplies the register value by `A`.
- `DV A` (Divide): Divides the register value by `A`.

The program processes a given postfix expression and generates the corresponding machine instruction sequence.

## Features

- **Expression Handling:** Supports postfix expressions with single-letter operands and four arithmetic operators: `+`, `-`, `*`, and `/`.
- **Temporary Variables:** Utilizes temporary variables (`TEMP1`, `TEMP2`, etc.) to store intermediate results during the evaluation process.
- **Stack Management:** Includes checks for overflow and underflow conditions to ensure the stack's integrity during evaluation.

## Usage Instructions

1. **Compilation:**
   - To compile the program, use the following command:
     ```bash
     gcc -o postfix_expression_evaluator postfix_expression_evaluator.c
     ```

2. **Execution:**
   - Run the compiled executable using the following commands:
     - **Windows:**
       ```bash
       ./postfix_expression_evaluator.exe
       ```
     - **Linux:**
       ```bash
       ./postfix_expression_evaluator
       ```

## Example

Given the postfix expression `ABC*+DE-/`, the program generates the following sequence of machine instructions:

```plaintext
LD  B
ML  C
ST  TEMP1
LD  A
AD  TEMP1
ST  TEMP2
LD  D
SB  E
ST  TEMP3
LD  TEMP2
DV  TEMP3
ST  TEMP4
