# 📚 CPP Module 00 | 42 School

> **Introduction to C++98 language** : classes, objects, encapsulation, static variables  
> A progressive 3-exercise module to master the fundamentals of OOP in C++

[![C++](https://img.shields.io/badge/C++-98-blue.svg?style=for-the-badge&logo=cplusplus)](https://en.cppreference.com/)
[![42 School](https://img.shields.io/badge/42-School-orange.svg?style=for-the-badge)](https://42.fr/)
[![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg?style=for-the-badge)](https://github.com/nassimfx/CPP-Module-00)
[![License](https://img.shields.io/badge/License-42-black.svg?style=for-the-badge)](https://github.com/nassimfx/CPP-Module-00/blob/main/LICENSE)
[![Made with ❤️](https://img.shields.io/badge/Made%20with-❤️-red.svg?style=for-the-badge)](https://github.com/nassimfx)

---

<div align="center">

### 🎯 **Module Objective**
Discover **object-oriented programming** in C++98 through concrete and progressive projects

[🚀 **Quick Start**](#-installation--usage) • [📖 **Documentation**](#-useful-resources) • [🎓 **Objectives**](#-educational-objectives)

</div>

---

## 📊 Project Overview

<div align="center">

| Metric | Value |
|--------|-------|
| **📁 Exercises** | 3 (Ex00, Ex01, Ex02) |
| **📝 Source Files** | 11 C++ files |
| **🏗️ Classes** | 3 (Contact, PhoneBook, Account) |
| **⚡ Lines of Code** | ~800 LOC |
| **🎯 Compliance** | 100% C++98 |

</div>

---

## 📂 Table of Contents

| Exercise | Description | Key Concepts | Difficulty |
|----------|-------------|--------------|------------|
| **[Ex00 — Megaphone](#ex00--megaphone)** | Uppercase conversion | Arguments, loops | ⭐ |
| **[Ex01 — PhoneBook](#ex01--phonebook)** | Phone directory | Classes, encapsulation | ⭐⭐ |
| **[Ex02 — Account](#ex02--account)** | Bank account management | Static variables, logs | ⭐⭐⭐ |

---

## 🚀 Installation & Usage

### 📋 Prerequisites
- **C++98 Compiler** : `g++` or `clang++`
- **Make** : Build system
- **Terminal** : Command line interface

### ⚡ Quick Compilation
```bash
# Clone the repository
git clone https://github.com/nassimfx/CPP-Module-00.git
cd CPP-Module-00

# Compile all exercises
for dir in ex00 ex01 ex02; do
    echo "🔨 Compiling $dir..."
    cd $dir && make && cd ..
done
```

### 🎮 Quick Test
```bash
# Test Ex00
cd ex00 && ./megaphone "Hello World"  # → HELLO WORLD

# Test Ex01  
cd ex01 && ./bin/phonebook  # Interactive interface

# Test Ex02
cd ex02 && ./account_tests | cat -e  # Formatted logs
```

### 🖼️ Demonstration

<details>
<summary><b>🔊 Ex00 - Megaphone in Action</b></summary>

```bash
$ ./megaphone "hello world from 42"
HELLO WORLD FROM 42

$ ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

</details>

<details>
<summary><b>📱 Ex01 - PhoneBook Interface</b></summary>

```bash
╔══════════════════════════════════════╗
║      📱 My Awesome PhoneBook 📱      ║
╚══════════════════════════════════════╝

Available commands:
  ADD    - Add a new contact
  SEARCH - Search contacts  
  EXIT   - Quit program

PhoneBook> ADD
👤 Enter first name: John
👤 Enter last name: Doe
🏷️  Enter nickname: johndoe
📞 Enter phone number: 0123456789
🤫 Enter darkest secret: I love C++
✅ Contact added successfully!

PhoneBook> SEARCH
     INDEX|FIRST NAME| LAST NAME|  NICKNAME|
----------|----------|----------|----------|
         0|      John|       Doe|   johndoe|
Enter index (0-0): 0
👤 First Name: John
👤 Last Name: Doe
🏷️  Nickname: johndoe
📞 Phone Number: 0123456789
🤫 Darkest Secret: I love C++
```

</details>

<details>
<summary><b>🏦 Ex02 - Account System Logs</b></summary>

```bash
[20250127_184455] index:0;amount:42;created
[20250127_184455] index:1;amount:54;created
[20250127_184455] index:2;amount:957;created
[20250127_184455] accounts:3;total:1053;deposits:0;withdrawals:0
[20250127_184455] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[20250127_184455] index:1;p_amount:54;withdrawal:refused
[20250127_184455] index:0;amount:47;closed
[20250127_184455] index:1;amount:54;closed
[20250127_184455] index:2;amount:957;closed
```

</details>

---

## 🔊 Ex00 — Megaphone

<div align="center">

**🎯 Objective** : Create a program that converts arguments to **UPPERCASE**

![Megaphone Demo](https://img.shields.io/badge/Conversion-UPPERCASE-yellow.svg?style=for-the-badge)

</div>

### 💡 Concept
The first contact with **command line arguments** and string manipulation in C++98.

### 🚀 Usage
```bash
cd ex00
make

# With arguments
./megaphone "shhhh... students are asleep"
# Output: SHHHH... STUDENTS ARE ASLEEP

# Without arguments
./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### ✨ Features
- ✅ **Automatic conversion** to uppercase (`std::toupper`)
- ✅ **Multiple arguments handling** (concatenation)
- ✅ **Default message** if no argument provided
- ✅ **Special characters handling** and accents

### 🧠 Concepts Learned
- Arguments `argc` and `argv`
- `for` loops with index
- Character functions (`toupper`)
- Simple conditions

---

## 📱 Ex01 — PhoneBook

<div align="center">

**🎯 Objective** : Create an interactive phone directory with **8 contacts maximum**

![PhoneBook Demo](https://img.shields.io/badge/Interface-Interactive-green.svg?style=for-the-badge)
![Ring Buffer](https://img.shields.io/badge/Algorithm-Ring%20Buffer-blue.svg?style=for-the-badge)

</div>

### 💡 Concept
Introduction to **object-oriented programming** : classes, encapsulation, and state management.

### 🎮 Interface
```
╔══════════════════════════════════════╗
║      📱 My Awesome PhoneBook 📱      ║
╚══════════════════════════════════════╝

Available commands:
  ADD    - Add a new contact
  SEARCH - Search contacts  
  EXIT   - Quit program

PhoneBook> 
```

### 🚀 Usage
```bash
cd ex01
make
./bin/phonebook
```

### ✨ Features
- ✅ **Interactive interface** with ANSI colors and emojis
- ✅ **Robust validation** of user inputs
- ✅ **Smart ring buffer** : replaces oldest contact
- ✅ **Formatted display** : 10-character columns right-aligned
- ✅ **Error handling** : EOF, empty inputs, invalid indexes
- ✅ **Intuitive search** by index with validation

### 🎯 SEARCH Display Rules
| Field | Width | Alignment | Truncation |
|-------|-------|-----------|------------|
| Index | 10 | Right | - |
| First Name | 10 | Right | `.` |
| Last Name | 10 | Right | `.` |
| Nickname | 10 | Right | `.` |

### 🧠 Concepts Learned
- **Classes and objects** (`Contact`, `PhoneBook`)
- **Encapsulation** : private members with getters/setters
- **Constructors/destructors**
- **Data algorithms** : ring buffer
- **User interface** : interactive input/output
- **Input validation** and error handling

---

## 🏦 Ex02 — Account

<div align="center">

**🎯 Objective** : Implement a banking system with **static variables** and **logging**

![Banking System](https://img.shields.io/badge/System-Banking-gold.svg?style=for-the-badge)
![Static Variables](https://img.shields.io/badge/Concept-Static%20Members-purple.svg?style=for-the-badge)

</div>

### 💡 Concept
Master **static class variables** : state sharing between all instances.

### 🏗️ Architecture
```cpp
class Account {
private:
    // STATIC Variables (shared between all instances)
    static int _nbAccounts;        // Total number of accounts
    static int _totalAmount;       // Total amount of all accounts
    static int _totalNbDeposits;   // Total number of deposits
    static int _totalNbWithdrawals; // Total number of withdrawals
    
    // INSTANCE Variables (specific to each account)
    int _accountIndex;    // Unique account index
    int _amount;          // Current balance
    int _nbDeposits;      // Number of deposits on this account
    int _nbWithdrawals;   // Number of withdrawals on this account
};
```

### 🚀 Usage
```bash
cd ex02
make
./account_tests | cat -e
```

### 📊 Log Examples
```bash
[20250127_184455] index:0;amount:42;created
[20250127_184455] index:1;amount:54;created
[20250127_184455] accounts:2;total:96;deposits:0;withdrawals:0
[20250127_184455] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[20250127_184455] index:0;p_amount:47;withdrawal:refused
[20250127_184455] index:0;amount:47;closed
```

### ✨ Features
- ✅ **Multi-account management** with automatic index
- ✅ **Secure deposits** with statistics update
- ✅ **Controlled withdrawals** : refusal if insufficient balance
- ✅ **Global statistics** in real-time
- ✅ **Timestamped logs** : format `[YYYYMMDD_HHMMSS]`
- ✅ **Clean destruction** with automatic counting

### 🎯 Strict Log Format
| Event | Format | Example |
|-------|--------|---------|
| Creation | `index:X;amount:Y;created` | `index:0;amount:42;created` |
| Deposit | `index:X;p_amount:Y;deposit:Z;amount:W;nb_deposits:N` | `index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1` |
| Withdrawal OK | `index:X;p_amount:Y;withdrawal:Z;amount:W;nb_withdrawals:N` | `index:0;p_amount:47;withdrawal:5;amount:42;nb_withdrawals:1` |
| Withdrawal Refused | `index:X;p_amount:Y;withdrawal:refused` | `index:0;p_amount:42;withdrawal:refused` |
| Closure | `index:X;amount:Y;closed` | `index:0;amount:42;closed` |
| Global Info | `accounts:X;total:Y;deposits:Z;withdrawals:W` | `accounts:8;total:19349;deposits:8;withdrawals:8` |

### 🧠 Concepts Learned
- **Static variables** : state sharing between instances
- **Static methods** : access to global data
- **Timestamping** : manipulation of `std::time` and `std::strftime`
- **Memory management** : constructors/destructors
- **Structured logging** : strict output format
- **Business validation** : banking rules (sufficient balance)

---

## ⚙️ Technical Stack & Architecture

### 🛠️ Technologies Used
| Component | Version | Description |
|-----------|---------|-------------|
| **Language** | C++98 | ISO/IEC 14882:1998 Standard |
| **Compiler** | `c++` | Flags: `-Wall -Wextra -Werror -std=c++98` |
| **Build System** | Make | Rules: `all`, `clean`, `fclean`, `re` |
| **Architecture** | OOP | Classes, encapsulation, inheritance |

### 📁 File Organization
```
CPP-Module-00/
├── ex00/
│   ├── megaphone.cpp
│   └── Makefile
├── ex01/
│   ├── Contact.hpp/cpp
│   ├── PhoneBook.hpp/cpp
│   ├── main.cpp
│   ├── Makefile
│   ├── obj/          # Object files (.o)
│   └── bin/          # Executable
├── ex02/
│   ├── Account.hpp/cpp
│   ├── tests.cpp
│   ├── Makefile
│   └── obj/          # Object files (.o)
└── README.md
```

### ✅ Quality Standards Respected
- **🚫 No `using namespace std;`** : Explicit use of `std::`
- **🔒 Include guards** : Protection against multiple inclusions
- **📝 Clean headers** : Declarations only, no implementation
- **📐 Strict format** : Exact compliance with output specifications
- **🗂️ Organization** : Clear separation of object files and executables
- **⚡ Performance** : Optimized compilation with security flags
- **🧹 Clean code** : Explicit variable names, relevant comments

### 🎯 42 Compliance
- ✅ **C++98 standard** strictly followed
- ✅ **Compilation flags** : `-Wall -Wextra -Werror`
- ✅ **File structure** compliant with requirements
- ✅ **Output format** identical to specifications
- ✅ **Error handling** robust and consistent

---

## 📖 Resources & Documentation

### 🔗 Useful Links
- **[C++98 Reference](https://en.cppreference.com/)** - Official documentation
- **[42 Subject PDF](https://cdn.intra.42.fr/pdf/pdf/5/cpp_module_00.en.pdf)** - Official subject
- **[Professional README Guide](https://coding-boot-camp.github.io/full-stack/github/professional-readme-guide/)** - Writing guide

### 📚 In-Depth Concepts
- **[Static Variables in C++](https://en.cppreference.com/w/cpp/language/static)** - Detailed documentation
- **[Ring Buffer Algorithm](https://en.wikipedia.org/wiki/Circular_buffer)** - Algorithmic principle
- **[ANSI Escape Codes](https://en.wikipedia.org/wiki/ANSI_escape_code)** - Terminal color codes

---

## 🎯 Educational Objectives

<div align="center">

### 🎓 **Skills Acquired**

| Concept | Description | Exercise |
|---------|-------------|----------|
| **🔤 CLI Arguments** | `argc`/`argv` management | Ex00 |
| **🏗️ Classes** | Definition and instantiation | Ex01 |
| **🔒 Encapsulation** | Private/public members | Ex01 |
| **⚡ Static Variables** | Global state sharing | Ex02 |
| **🎮 User Interface** | Interactive input/output | Ex01 |
| **📊 Algorithms** | Ring buffer, validation | Ex01-02 |
| **📝 Logging** | Formatting and timestamping | Ex02 |

</div>

### 🚀 Learning Progression

1. **Ex00** : **Basics** - Arguments, loops, string manipulation
2. **Ex01** : **OOP** - Classes, objects, encapsulation, algorithms
3. **Ex02** : **Advanced** - Static variables, logging, architecture

### 💡 Added Value
- ✅ **Production-ready code** with robust error handling
- ✅ **Clean architecture** respecting C++98 standards
- ✅ **Modern user interface** with colors and emojis
- ✅ **Complete documentation** for easier maintenance

---

---

*Developed with ❤️ as part of the 42 School curriculum - C++ Module 00*
