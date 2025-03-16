# ISA Imitation Simulator

Welcome to the **ISA Imitation Simulator**, a simple yet powerful tool designed to help you understand the inner workings of a basic Instruction Set Architecture (ISA) simulator. The simulator, inspired by the Von Neumann Architecture, mimics a basic CPU cycle with a set of predefined instructions and allows you to load, execute, and view the state of a program running on a simulated processor.

---

## Features

- **Memory Initialization**: Random values are assigned to memory at the start of each run.
- **Basic Instructions**: Supports a small set of operations like `ADD`, `SUB`, `MUL`, `DIV`, `LOAD`, `STORE`, and `HALT`.
- **Register Monitoring**: View the current state of important registers (Program Counter, Memory Address Register, Memory Data Register, Accumulator).
- **Memory Visualization**: View the current state of memory after executing instructions.
- **Interactive Command Line**: Commands to load a program, run it, inspect the state, and quit.

---

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
  - [Available Commands](#available-commands)
  - [Instruction Set](#instruction-set)
- [Program Workflow](#program-workflow)
- [License](#license)

---

## Installation

To use this simulator, clone the repository and compile the code. Here are the steps to get started:

### Prerequisites:
- A C++ compiler (like `g++` or `clang`).
- A Linux-based system is assumed, but it should work on other Unix-based systems as well.

### Steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/TheLeopard65/ISA-Imitation.git
   cd ISA-Imitation
   ```

2. Compile the C++ program:
   ```bash
   g++ Simulator.cpp -o simulator
   ```

3. Run the program:
   ```bash
   ./simulator
   ```

Now, you're ready to start using the simulator!

---

## Usage

Once you've compiled and started the simulator, you'll be presented with a command prompt where you can interact with the simulator.

### Available Commands

- **LOAD**: Allows you to load a program into the simulator. You'll be prompted to enter instructions one by one. Type `done` to finish loading the program.
- **RUN**: Executes the loaded program. The program will run from the first instruction and stop if a `HALT` instruction is encountered or the end of the program is reached.
- **STATE**: Displays the current state of the simulator, including the values of the Program Counter (PC), Memory Address Register (MAR), Memory Data Register (MDR), Accumulator (AC), and the Instruction Register (IR). It will also show the current state of memory.
- **HELP**: Displays a list of available commands.
- **QUIT**: Exits the simulator.

### Instruction Set

The simulator supports the following instructions:

- **ADD <address>**: Adds the value stored at the specified memory address to the Accumulator (AC).
- **SUB <address>**: Subtracts the value at the specified memory address from the Accumulator (AC).
- **MUL <address>**: Multiplies the value at the specified memory address by the Accumulator (AC).
- **DIV <address>**: Divides the value at the specified memory address by the Accumulator (AC). If division by zero occurs, an error message will be shown.
- **LOAD <address>**: Loads the value from the specified memory address into the Accumulator (AC).
- **STORE <address>**: Stores the value in the Accumulator (AC) to the specified memory address.
- **HALT**: Stops the execution of the program.

---

## Program Workflow

1. **Loading a Program**: You start by entering a series of instructions. These instructions will be stored in temporary memory for execution later. Type `done` when you've finished entering instructions.

2. **Running the Program**: After loading the program, you can execute it with the `RUN` command. The simulator will run the program step-by-step, updating the registers and memory according to the instructions.

3. **Inspecting the State**: You can view the state of the simulator at any time using the `STATE` command. This will show the current values of registers and the memory, helping you track the progress of your program.

4. **Exiting the Simulator**: When you're done, simply type `QUIT` to exit the simulator.

---

## Example Usage

### Step 1: Load a Program

```bash
TICS-OS #> LOAD
***** Enter Instructions on each line ('Done' to Finish) *****
ADD 5
SUB 10
MUL 3
DIV 2
HALT
Done
```

### Step 2: Run the Program

```bash
TICS-OS #> RUN
PROCESS #> Executing the loaded Program
*************** REGISTER VALUES FOR PC : 0 ***************
PC: 1		MAR: 5		MDR: 5		AC: 5		IR: ADD
*************** REGISTER VALUES FOR PC : 1 ***************
PC: 2		MAR: 10		MDR: 10		AC: -5		IR: SUB
*************** REGISTER VALUES FOR PC : 2 ***************
PC: 3		MAR: 3		MDR: 3		AC: -15		IR: MUL
*************** REGISTER VALUES FOR PC : 3 ***************
PC: 4		MAR: 2		MDR: 2		AC: -7		IR: DIV
*************** REGISTER VALUES FOR PC : 4 ***************
PC: 5		MAR: 0		MDR: 0		AC: -7		IR: HALT
```

### Step 3: Inspect the State

```bash
TICS-OS #> STATE
************ CURRENT MEMORY VALUES ************
...
************ CURRENT PROGRAM VALUES ************
```

### Step 4: Quit

```bash
TICS-OS #> QUIT
```

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to experiment with this simulator to better understand the basic principles of how a CPU executes instructions. Happy coding!
