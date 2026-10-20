# Bank Account Simulator in C++

A console-based **Bank Account Simulator** built using Object-Oriented Programming (OOP) concepts in C++. This application supports multi-account management, deposit/withdrawal operations with validation checks, transaction history tracking, and input handling.

---

## Features

- **Multi-Account Support**: Create and switch between multiple user accounts using unique account numbers.
- **Deposits & Withdrawals**: Secure financial operations with insufficient balance prevention.
- **Transaction History**: Logs transactions chronologically for individual accounts.
- **Input Validation**: Prevents invalid values or system crashes caused by unexpected user input type mismatches.
- **Menu-Driven CLI**: Clear interactive interface for fast navigation.

---

## File Structure

```text
Bank_Account_Simulator/
├── main.cpp
├── README.md
└── .gitignore
```

---

## Getting Started

### Prerequisites
- C++ Compiler (e.g., `g++`, `clang++`, or MSVC) supporting C++11 or later.

### Compilation and Execution

1. Clone the repository:
   ```bash
   git clone https://github.com/manojkr002/Bank-Account-Simulator-in-C-.git
   cd Bank-Account-Simulator-in-C-
   ```

2. Compile the source code:
   ```bash
   g++ -o bank_simulator main.cpp
   ```

3. Run the application:
   - **Linux / macOS:**
     ```bash
     ./bank_simulator
     ```
   - **Windows:**
     ```cmd
     bank_simulator.exe
     ```

---

## Resume Highlights

- Implemented standard **OOP Principles** (Encapsulation, Classes/Objects) to construct a maintainable banking architecture.
- Integrated dynamic storage using **C++ Standard Template Library (`std::vector`)** for multi-account management and dynamic transaction histories.
- Implemented robust **stream input handling** to ensure continuous execution despite user formatting errors.
