#include <fstream>
#include <iostream>

#include "AProgCalc.h"
#include "Interface.h"
#include "Instruction.h"


bool Interface::inputFile(std::string cmd)
{
    pc -> reset();

    unsigned first = cmd.find("<");
    unsigned last = cmd.find(">");
    std::string file_name = cmd.substr(first+1, last-first-1);
    //std::cout << file_name << std:: endl;;
    int count{1};
    std::string input_line;
    std::ifstream file(file_name);
    if(file.is_open())
    {
        std::cout << "Input file contains: " << std::endl;
        std::string line;
        while(std::getline(file, line))
        {
            input_line = std::to_string(count) + ": " + line;
            pc->addMemData(input_line);
            std::cout << "\t" << input_line << std::endl;
            count++;
        }
        pc->addMemData("HLT");
    }
    else
    {
        std::cout << "Error while opening the file" << std::endl;
    }
    file.close();
    return true;
}

void Interface::printState()
{
  // Print em all
  printMemory();
  printReg();
  //printBits();
}

void Interface::printMemory()
{
  // Print program memory contents
  int counter = 0;
  Inst *instr = pc->getMemData(counter);

  std::cout << std::endl;
  std::cout << "********************" << std::endl;
  std::cout << "PROGRAM MEMORY" << std::endl;

  while (instr) {
    std::cout << instr->toString() << std::endl;
    instr = pc->getMemData(++counter);
  }
}

bool Interface::runDebug()
{
    if(pc -> isHalted())
    {
        return true;
    }
    const int pcount = pc -> getPC();
    //std::cout << "pcount: " << pcount << std:: endl;;
    Inst *instr = pc -> getMemData(pcount);
    //std::cout << "check1 " << std::endl;
    //std::cout << instr << std:: endl;;
    if(!instr)
    {
        printReg();
        return true;
    }
    //std::cout << "check2 " << std::endl;
    instr -> execute(*pc);
    //std::cout << "check3 " << std::endl;
    printReg();
    return false;
}

bool Interface::runAll()
{
    int count = 0;
    if(pc -> isHalted())
    {
        return true;
    }
    int pcount = pc -> getPC();
    while(!pc-> isHalted())
    {
        count = count + 1;
        //std::cout << count << std::endl;
        if(count == 100)
        {
            break;
        }
        Inst *instr = pc -> getMemData(pcount);
        if(!instr)
        {
            printReg();
            return true;
        }
        instr -> execute(*pc);
        pcount = pc -> getPC();
    }
    printReg();
    return false;
}

bool Interface::runContinue()
{
    int count = 0;
    if(pc -> isHalted())
    {
        return true;
    }
    int pcount = pc -> getPC();
    while(!pc-> isHalted())
    {
        count = count + 1;
        //std::cout << count << std::endl;
        if(count == 100)
        {
            break;
        }
        Inst *instr = pc -> getMemData(pcount);
        if(!instr)
        {
            printReg();
            return true;
        }
        instr -> execute(*pc);
        pcount = pc -> getPC();
    }
    printReg();
    return false;
}

void Interface::printReg()
{
    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "REGISTERS VALUE: " << std::endl;

    std::cout << "Register X: " << pc->getRegX() << std::endl;
    std::cout << "Register Y: " << pc->getRegY() << std::endl;
    std::cout << "Register W: " << pc->getRegW() << std::endl;
    std::cout << "Register Z: " << pc->getRegZ() << std::endl;
}


void Interface::runCommands()
{
    bool check = false;
    std::string cmd_string{};
    char cmd = '0';
    while(true)
    {
        std::cout << std:: endl<< "Commands:" << std::endl;
        std::cout << "i <filename> : Input file" << std::endl;
        std::cout << "\t   d : Debug - Execute instruction one by one" << std::endl;
        std::cout << "\t   r : Run - 100 instructions" << std::endl;
        std::cout << "\t   c : Continue Execution" << std::endl;
        std::cout << "\t   p : Print" << std::endl;
        std::cout << "\t   q : Quit" << std::endl << std::endl;
        std::cout << "Please enter your desired commands." << std::endl;
        getline(std::cin, cmd_string);
        //std::cout << cmd_string << std:: endl;;
        cmd = cmd_string[0];
        //std::cout << cmd << std:: endl;;
        if(cmd == 'i')
        {
            inputFile(cmd_string);
        }
        if(cmd == 'd')
        {
            runDebug();
        }
        else if(cmd == 'r')
        {
            check = true;
            runAll();
        }
        else if(cmd == 'c')
        {
            if(check == true)
            {
                runContinue();
            }
        }
        else if(cmd == 'p')
        {
            printState();
        }
        else if(cmd == 'q')
        {
            break;
        }
        else
        {
            std::cout << "Unknown selection, please try again" << std::endl << std::endl;
        }
    }
}
