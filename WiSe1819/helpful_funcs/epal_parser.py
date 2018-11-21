"""
Parser for epal, your friendly, new programming language!
epal code is easy to write and understand!
This parser parses epal code to c++ code and compiles it to binary
It also can be executed as pure python module
When called in CLI command should be like following example:
python [epal_file] [binary_filename]
"""
import sys
import re

def epal_parser:
    with open("test.epal", 'r') as parse_file:
        with open("tester.cpp", 'w+') as parsed_file:
            parsed_file.write("#include <iostream>\nusing namespace std;\n")
            value = 0
            variable_name = None
            keep_values_safe = False
            print_case = False
            in_loop = False
            for line in parse_file:
                index = 0
                line = line.split()
                for word in line:
                    if re.match("[0-9]", word):
                        if not keep_values_safe:
                            value = word
                            parsed_file.write(value + ";\n")
                        index += 1
                    elif word == "main":
                        parsed_file.write("int main() {\n")
                        index += 1
                    elif word == "is":
                        parsed_file.write(" = ")
                        index += 1
                    elif word == "do":
                        index += 1
                        pass
                    elif word == "loop":  # loop section
                        variable_name = line[index + 2]
                        if "for" in line:
                            parsed_file.write("\tfor (int " + variable_name + " = 0; " + variable_name
                                              + " < " + line[index + 5] + "; " + variable_name + "++) {\n\t")
                        else:
                            parsed_file.write("\n\twhile (" + variable_name + " < " + line[index + 5] + "{\n\t")
                        keep_values_safe = True
                        in_loop = True
                        index += 1
                    elif word == "for":
                        pass
                        index += 1
                    elif word == "in":
                        index += 1
                    elif word == "range":
                        index += 1
                    elif word == ":":
                        index += 1
                        pass
                    elif word == "plus":
                        parsed_file.write(" + ")
                        index += 1
                    elif word == "end":
                        parsed_file.write("\t}\n")
                        keep_values_safe = False
                        in_loop = False
                        index += 1
                    elif word == "print":
                        parsed_file.write("\tcout << " + line[index + 1] + "<< endl;\n")
                        print_case = True
                        index += 1
                    else:
                        if print_case:
                            print_case = False
                        elif not keep_values_safe:
                            variable_name = word
                            if not in_loop:
                                try:
                                    try:
                                        test_value = int(line[index + 2])
                                    except:
                                        pass
                                    if isinstance(test_value, int):
                                        parsed_file.write("\tint ")
                                        parsed_file.write(variable_name)
                                    elif isinstance(line[index + 2], str):
                                        parsed_file.write("\tchar ")
                                        parsed_file.write(variable_name)
                                        parsed_file.write("[" + str(len(word)) + "]")
                                except IndexError:
                                    parsed_file.write(variable_name)
                            else:
                                parsed_file.write("\t" + variable_name)
                        index += 1
                keep_values_safe = False
            parsed_file.write("\treturn 0;\n}")
