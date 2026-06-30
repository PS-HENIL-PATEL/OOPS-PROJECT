# 🎮 E-Sports Tournament Manager

Welcome to the **E-Sports Tournament Manager**! This project is a C++ Object-Oriented Programming (OOP) application that simulates an E-Sports match with different player classes. 

## 🚀 Overview

This repository demonstrates key Object-Oriented principles in C++:
- **Encapsulation**: Using protected/private properties with public getters/setters.
- **Inheritance**: Derived classes (`Sniper`, `Support`) extending a base `Player` class.
- **Polymorphism**: Overriding pure virtual functions like `playRole()`.
- **Abstraction**: Using abstract base classes.

## 🛠️ Debugging Exercise

This project includes an intentional logic bug inside the `Support::healTeammate` function where the support character incorrectly gains energy when healing instead of losing it. 

The repository includes a detailed **Debugging Report** documenting:
1. The bug description and root cause.
2. The expected vs. actual behavior.
3. Step-by-step debugging using the **Visual Studio Debugger**.
4. The final code fix.

Read the full report here: [Debugging_Report.md](./Debugging_Report.md)

## 📁 Repository Structure

- `main.cpp` - The core application logic containing the E-Sports classes and the tournament simulation.
- `Debugging_Report.md` - A complete, formatted markdown report detailing the debugging process.
- `debugger_step_1.png` - Visual proof of the initial debugging state.
- `debugger_step_2.png` - Visual proof of the logic error occurring during execution.

## ⚙️ How to Compile & Run

Using `g++`:
```bash
g++ main.cpp -o main
./main
```

## 👨‍💻 Author

**Henil Patel**
