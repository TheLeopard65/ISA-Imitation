# Von-Neumann Architecture Imitation
This repository contains a simple C++ implementation of a Von-Neumann architecture simulator. The program mimics the behavior of a basic computer architecture that uses a single memory space for both instructions and data. Users can load programs, execute them, and view the current state of the memory and registers.

## Features

- **Basic Operations**: Supports addition, subtraction, multiplication, division, loading from memory, and storing to memory.
- **Instruction Set**: Implements a simple instruction set with commands like `ADD`, `SUB`, `MUL`, `DIV`, `LOAD`, `STORE`, and `HALT`.
- **Memory Initialization**: Initializes memory with random values on startup.
- **Interactive Command Line Interface**: Users can load programs, run them, and inspect the system's state through an interactive console.

## Getting Started

### Prerequisites

- A C++ compiler (like g++, clang++).
- A basic understanding of C++ and command-line usage.

### Compilation

To compile the program, use the following command:

```bash
g++ Von-Neumann-ARCH-Imitation.cpp -o von_neumann_simulator
```

### Usage

1. **Run the Simulator**:

   Execute the compiled program:

   ```bash
   ./von_neumann_simulator
   ```

2. **Commands**:
   - **LOAD**: Input your instructions line by line. Type `done` to finish inputting.
   - **RUN**: Execute the loaded program.
   - **STATE**: Display the current register values and memory state.
   - **HELP**: Show available commands.
   - **QUIT**: Exit the simulator.

### Example Usage

```plaintext
TICS-OS #> LOAD
ADD 5
SUB 3
MUL 2
DIV 4
done

TICS-OS #> RUN
```

## Implementation Details

- The simulator initializes a memory space of 1024 integers and supports up to 100 temporary instructions.
- Registers include Memory Address Register (MAR), Memory Data Register (MDR), Accumulator (AC), and Program Counter (PC).
- The state of the system is printed after each executed instruction for better visibility.

## License

This project is open source and available under the MIT License. Feel free to use and modify it as needed.

## Acknowledgments

Thanks to the contributors and the programming community for their invaluable resources and inspiration.
