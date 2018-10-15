from datetime import datetime


class machine:
    PC = 0
    end = False
    registers = [0,0,0,0,0]

    # registermachine functions
    def ADD(self, address):
        self.reg1 += self.registers[address-1]
        self.PC+=1

    def MULT(self, address):
        self.reg1 *= self.registers[address-1]
        self.PC += 1

    def SUB(self, address):
        self.reg1 -= self.registers[address-1]
        self.PC += 1

    def DIV(self, address):
        self.reg1 /= self.registers[address-1]
        self.PC += 1

    def HLT(self, exit_code):
        self.PC += 1
        self.end = True
        return exit_code

    def INP(self, var):
        self.reg1 = var
        self.PC += 1

    def OUT(self, address):
        print(self.registers[address-1])
        self.PC += 1

    def LDA(self, address):
        self.reg1 = self.registers[address-1]
        self.PC += 1

    def LDK(self, const):
        self.reg1 = const
        self.PC += 1

    def STA(self, address):
        self.registers[address-1] = self.reg1
        self.PC += 1

    def JMP(self, address):
        self.PC = address

    def JNE(self, address):
        if self.reg1 is not 0:
            self.PC = address
        else:
            self.PC += 1


if __name__ == "__main__":
    comp_time = datetime.now().microsecond
    machine = machine()
    command_set = {"INP" : machine.INP,
                   "ADD" : machine.ADD,
                   "LDK" : machine.LDK,
                   "SUB" : machine.SUB,
                   "STA" : machine.STA,
                   "MULT" : machine.MULT,
                   "LDA" : machine.LDA,
                   "JNE" : machine.JNE,
                   "OUT" : machine.OUT,
                   "HLT" : machine.HLT}

    commands = []
    command_vars = []

    with open("commands.txt", 'r') as command_file:
        for line in command_file:
            if '#' not in line:
                command = line.split(" ")
                commands.append(command_set.get(command[0]))
                command_vars.append(int(command[1].strip("\n")))

        n = 0
        while not machine.end:
            print("execution steps: " + str(n))
            n+=1
            commands[machine.PC](command_vars[machine.PC])

    print("Success! Execution needed " + str(datetime.now().microsecond - comp_time) + "ms")
