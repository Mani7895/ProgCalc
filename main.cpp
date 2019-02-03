#include <iostream>
#include "Command.h"
#include "Interface.h"
#include "AProgCalc.h"

using namespace std;

int main()
{
    Interface *ui = new Interface();
    cout << endl;
    cout << "Programming Calculator" << endl;
    cout << endl;

    ui->runCommands();

    cout << endl;
    cout << "Exiting program..." << endl;
    cout << "Goodbye!" << endl;

    return 0;
}
