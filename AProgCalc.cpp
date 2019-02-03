#include <sstream>
#include <iostream>
#include "Command.h"
#include "AProgCalc.h"

void AProgCalculator::reset()
{
    setRegX(0);
    setRegY(0);
    setRegW(0);
    setRegZ(0);
    setHalt(false);

    memory.clear();
    symTable.clear();
}

void AProgCalculator::addSymbol(const std::string data, const int address)
{
  symTable.insert(std::make_pair(data, address));
}

Inst* AProgCalculator::getMemData(const int address) const
{
  // Must check for valid address
  if (address < int(memory.size())) {
    return memory.at(address);
  } else {
    return nullptr;
  }
}

void AProgCalculator::addMemData(std::string data)
{
    //std::stringstream ss(data);

    std::string command;
    //std::string arg;
    int size_data = data.size();
    //std::cout << "Size: " <<size_data << std::endl;
    //std::cout << data.at(9) <<size_data << std::endl;
    if(data != "HLT")
    {
        if(size_data <=10)
        {
        //std::cout << "Error" << std::endl;
            command = data.at(5);
        }
        else
        {
            if(data.at(9) == '+')
            {
            //std::cout << "Error add" << std::endl;
                command = data.at(9);
            }
            else if((data.at(9) == '*') && (data.at(10) == '*'))
            {
            //std::cout << "Error5" << std::endl;
                command = "**";
            }
            else if(data.at(9) == '-')
            {
            //std::cout << "Error2" << std::endl;
                command = data.at(9);
            }
            else if(data.at(9) == '*')
            {
            //std::cout << "Error3" << std::endl;
                command = data.at(9);
            }
            else if(data.at(9) == '/')
            {
            //std::cout << "Error4" << std::endl;
                command = data.at(9);
            }
            else
            {
            //std::cout << "Error6" << std::endl;
                command = "=";
            }
        }

    }
    else
    {
        command = "HLT";
    }

  if (command == "+") {
    memory.push_back( new ADD(data) );
  }
  else if (command == "-") {
    memory.push_back( new SUB(data) );
  }
  else if (command == "*") {
    memory.push_back( new MUL(data) );
  }
  else if (command == "**") {
    //std::cout << "check hello" << std::endl;
    memory.push_back( new POW(data) );
  }
  else if (command == "/") {
    memory.push_back( new DIV(data) );
  }
  else if (command == "=") {
    memory.push_back( new EQU(data) );
  }
  else if (command == "?") {
    memory.push_back(new JMP(data));
  }
  else if (command == "HLT") {
    memory.push_back(new HLT());
  }
  else {
    return;
  }
}

std::string AProgCalculator::getSymbol(std::string symbol) const
{
  return (symbol);
}
