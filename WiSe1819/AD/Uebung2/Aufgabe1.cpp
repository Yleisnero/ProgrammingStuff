#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

enum class Command{LDK, STA, LDA, MUL, ADD, SUB, JGE, OUT, HLT};


class Instruction{

private:
    string command;
    int number; //address or constant

public:
    explicit Instruction(string &input){
        command = input.substr(0, input.find(' '));
        string numberString = input.substr(input.find(' ') + 1, input.find_last_of("/\\"));
        stringstream geek(numberString);
        geek >> number; //Stream String into integer (Maybe use atoi() ??)
    }

    void print(){
        cout << command << " " << number << endl;
    }

    string getCommand(){
        return command;
    }

    int getNumber(){
        return number;
    }
};


//Class RegistermachineSimulator
class RegSim{

private:
    vector<Instruction> instructions;   //vector, which contains all instructions
    int regi[100];                      //regi[0] is the akku
    int pc;                             //Program counter
    map<string, Command> mapCommands;   //Map to connect string with enum Command (to use it for switch later)

public:
    explicit RegSim(vector<Instruction> &instr) : instructions(instr), pc(0){
        for(int i = 0; i < sizeof(regi) / sizeof(int); i++){
            regi[i] = 0;
        }

        mapCommands["LDK"] = Command::LDK;
        mapCommands["STA"] = Command::STA;
        mapCommands["LDA"] = Command::LDA;
        mapCommands["MUL"] = Command::MUL;
        mapCommands["ADD"] = Command::ADD;
        mapCommands["SUB"] = Command::SUB;
        mapCommands["JGE"] = Command::JGE;
        mapCommands["OUT"] = Command::OUT;
        mapCommands["HLT"] = Command::HLT;
    };

    void printAll();

    void simulate();

};


int main() {

    ifstream inFile;
    inFile.open("C:\\Users\\Jonas\\CLionProjects\\RegistermaschinenSimulator\\SumQuadrat.txt");
    if(!inFile){
        cerr << "Unable to open file";
        exit(1);
    }

    string line;
    vector<Instruction> instructions;
    while(getline(inFile, line)){
        Instruction inst(line);
        instructions.push_back(inst);
    }

    RegSim simulator(instructions);
    simulator.printAll();
    cout << endl;
    simulator.simulate();

    return 0;
}


//Print all instructions
void RegSim::printAll(){
    for(Instruction i : instructions){
        i.print();
    }
}


//Simulate all instructions
void RegSim::simulate(){
    for(int progCount = pc; progCount < instructions.size(); progCount++){
        Instruction ins = instructions[progCount];
        string cmd = ins.getCommand();
        switch(mapCommands[cmd]){
            case Command::LDK: regi[0] = ins.getNumber(); break;

            case Command::STA: regi[ins.getNumber()] = regi[0]; break;

            case Command::LDA: regi[0] = regi[ins.getNumber()]; break;

            case Command::MUL: regi[0] = regi[0] * regi[ins.getNumber()]; break;

            case Command::ADD: regi[0] = regi[0] + regi[ins.getNumber()]; break;

            case Command::SUB: regi[0] = regi[0] - regi[ins.getNumber()]; break;

            case Command::JGE:
                if(regi[0] > 0) {
                    progCount = regi[ins.getNumber()];
                    break;
                }
                break;

            case Command::OUT: cout << "Result: " << regi[ins.getNumber()] << endl; break;

            case Command::HLT: exit(ins.getNumber());

            default: cerr << "Command not found"; exit(2);
        }
    }
}
