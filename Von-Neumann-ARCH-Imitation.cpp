#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MEMORY_SIZE = 1024, STORAGE_SIZE = 100;
int memory[MEMORY_SIZE] = {0};
string tempOpcode[STORAGE_SIZE], opcode, IR;
int tempAddress[STORAGE_SIZE];
int MAR = 0, MDR = 0, AC = 0, PC = 0, address, tempCount = 0;

void initializeMemory() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        memory[i] = rand() % 100;
    }
}

void ADD(int& value) { AC += value; MDR = value; }
void SUB(int& value) { AC -= value; MDR = value; }
void MUL(int& value) { AC *= value; MDR = value; }
void DIV(int& value) {
    MDR = value; 
    if (value != 0) {   AC = AC / value;  }
    else {  cout << "ERROR: Division by ZERO!" << endl; }
}

void executeInstruction() {
    MAR = address;
    int value = memory[address];
    if (opcode == "ADD") { ADD(value); }
    else if (opcode == "SUB") { SUB(value); }
    else if (opcode == "MUL") { MUL(value); }
    else if (opcode == "DIV") { DIV(value); }
    else if (opcode == "LOAD") {
        MAR = address;
        MDR = memory[MAR];
        AC = MDR;
    } else if (opcode == "STORE") {
        MAR = address;
        MDR = AC;
        memory[MAR] = MDR;
    } else if (opcode == "HALT") {
        PC = MEMORY_SIZE;
    } else {
        cout << "ERROR: Invalid OPCode: " << opcode << endl;
    }
}

void printstate() {
    cout << "*************** REGISTER VALUES FOR PC : " << PC << " ***************" << endl;
    cout << "PC: " << PC << "\t\tMAR: " << MAR << "\t\tMDR: " << MDR << "\t\tAC: " << AC  << "\t\tIR: " << IR << endl;
}

void printmemory(){
    cout << "*************** REGISTER VALUES FOR PC : " << PC << " ***************" << endl;
    cout << "PC: " << PC << "\t\tMAR: " << MAR << "\t\tMDR: " << MDR << "\t\tAC: " << AC  << "\t\tIR: " << IR << endl;
    cout << "************ CURRENT MEMORY VALUES ************" << endl;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            cout << memory[i * 32 + j] << " ";
        }
        cout << endl;
    }
    cout << "************ CURRENT PROGRAM VALUES ************" << endl;
}

void loadProgram() {
    string input;
    cout << "***** Enter Instructions on each line ('Done' to Finish) *****" << endl;
    while (true) {
        getline(cin, input);
        if (input == "done" || input == "DONE" || input == "Done"){
            break;
        }
        istringstream stream(input);
        stream >> opcode >> address;
        if (tempCount < STORAGE_SIZE) {
            tempOpcode[tempCount] = opcode;
            tempAddress[tempCount] = address;
            tempCount++;
        } else {
            cout << "ERROR: Temporary storage full!" << endl;
        }
    }
}

void runProgram() {
    PC = 0;
    while (PC < tempCount) {
        opcode = tempOpcode[PC];
        address = tempAddress[PC++];
        IR = opcode;
        executeInstruction();
        if (opcode == "HALT") break;
        printstate();
    }
}

void printHelp() {
    cout << "********** AVAILABLE COMMANDS **********" << endl;
    cout << "LOAD - Loads program into temporary storage" << endl;
    cout << "RUN - Executes the loaded program" << endl;
    cout << "STATE - Prints current register values" << endl;
    cout << "QUIT - Exits the ISA Simulator" << endl;
    cout << "********** AVAILABLE COMMANDS **********" << endl;
}

int main() {
    initializeMemory();
    string command;
    printHelp();
    while (true) {
        cout << "TICS-OS #> ";
        cin >> command;
        cin.ignore();
        if (command == "LOAD" || command == "load") {
            loadProgram();
        } else if (command == "RUN" || command == "run" || command == "r") {
            cout << "PROCESS #> Executing the loaded Program " << endl;
            runProgram();
        } else if (command == "STATE" || command == "state") {
            printmemory();
        } else if (command == "HELP" || command == "help") {
            printHelp();
        } else if (command == "QUIT" || command == "quit" || command == "EXIT" || command == "exit") {
            break;
        } else {
            cout << "ERROR #> Unknown command: " << command << endl;
        }
    }
    return 0;
}
