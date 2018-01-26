#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <stdint.h>
using namespace std;

map<string, char> genTranslateList()
{
    //Define the character conversion
    map<string, char> traslateList;
    traslateList["BANANAS"] = 'a';
    traslateList["BANANAs"] = 'b';
    traslateList["BANANaS"] = 'c';
    traslateList["BANANas"] = 'd';
    traslateList["BANAnAS"] = 'e';
    traslateList["BANAnAs"] = 'f';
    traslateList["BANAnaS"] = 'g';
    traslateList["BANAnas"] = 'h';
    traslateList["BANaNAS"] = 'i';
    traslateList["BANaNAs"] = 'j';
    traslateList["BANaNaS"] = 'k';
    traslateList["BANaNas"] = 'l';
    traslateList["BANanAS"] = 'm';
    traslateList["BANanAs"] = 'n';
    traslateList["BANanaS"] = 'o';
    traslateList["BANanas"] = 'p';
    traslateList["BAnANAS"] = 'q';
    traslateList["BAnANAs"] = 'r';
    traslateList["BAnANaS"] = 's';
    traslateList["BAnANas"] = 't';
    traslateList["BAnAnAS"] = 'u';
    traslateList["BAnAnAs"] = 'v';
    traslateList["BAnAnaS"] = 'w';
    traslateList["BAnAnas"] = 'x';
    traslateList["BAnaNAS"] = 'y';
    traslateList["BAnaNAs"] = 'z';

    traslateList["BAnaNaS"] = 'A';
    traslateList["BAnaNas"] = 'B';
    traslateList["BAnanAS"] = 'C';
    traslateList["BAnanAs"] = 'D';
    traslateList["BAnanaS"] = 'E';
    traslateList["BAnanas"] = 'F';
    traslateList["BaNANAS"] = 'G';
    traslateList["BaNANAs"] = 'H';
    traslateList["BaNANaS"] = 'I';
    traslateList["BaNANas"] = 'J';
    traslateList["BaNAnAS"] = 'K';
    traslateList["BaNAnAs"] = 'L';
    traslateList["BaNAnaS"] = 'M';
    traslateList["BaNAnas"] = 'N';
    traslateList["BaNaNAS"] = 'O';
    traslateList["BaNaNAs"] = 'P';
    traslateList["BaNaNaS"] = 'Q';
    traslateList["BaNaNas"] = 'R';
    traslateList["BaNanAS"] = 'S';
    traslateList["BaNanAs"] = 'T';
    traslateList["BaNanaS"] = 'U';
    traslateList["BaNanas"] = 'V';
    traslateList["BanANAS"] = 'W';
    traslateList["BanANAs"] = 'X';
    traslateList["BanANaS"] = 'Y';
    traslateList["BanANas"] = 'Z';

    traslateList["BanAnAS"] = ' ';
    traslateList["BanAnAs"] = '\n';

    traslateList["BanAnaS"] = '0';
    traslateList["BanAnas"] = '1';
    traslateList["BanaNAS"] = '2';
    traslateList["BanaNAs"] = '3';
    traslateList["BanaNaS"] = '4';
    traslateList["BanaNas"] = '5';
    traslateList["BananAS"] = '6';
    traslateList["BananAs"] = '7';
    traslateList["BananaS"] = '8';
    traslateList["Bananas"] = '9';

    traslateList["bANANAS"] = ',';
    traslateList["bANANAs"] = '.';
    traslateList["bANANaS"] = '/';
    traslateList["bANANas"] = ';';
    traslateList["bANAnAS"] = '\'';
    traslateList["bANAnAs"] = '[';
    traslateList["bANAnaS"] = ']';
    traslateList["bANAnas"] = '=';
    traslateList["bANaNAS"] = '-';
    traslateList["bANaNAs"] = '`';
    traslateList["bANaNaS"] = '~';
    traslateList["bANaNas"] = '!';
    traslateList["bANanAS"] = '@';
    traslateList["bANanAs"] = '#';
    traslateList["bANanaS"] = '$';
    traslateList["bANanas"] = '%';
    traslateList["bAnANAS"] = '^';
    traslateList["bAnANAs"] = '&';
    traslateList["bAnANaS"] = '*';
    traslateList["bAnANas"] = '(';
    traslateList["bAnAnAS"] = ')';
    traslateList["bAnAnAs"] = '_';
    traslateList["bAnAnaS"] = '+';
    traslateList["bAnAnas"] = '{';
    traslateList["bAnaNAS"] = '}';
    traslateList["bAnaNAs"] = '|';
    traslateList["bAnaNaS"] = '\\';
    traslateList["bAnaNas"] = ':';
    traslateList["bAnanAS"] = '"';
    traslateList["bAnanAs"] = '?';
    traslateList["bAnanaS"] = '>';
    traslateList["bAnanas"] = '<';

    return traslateList;
}

vector<vector<string>> getScript(const string& filename)
{
    // open the file
    ifstream file(filename);
    if (!file)
        std::exit(1);

    // build file
    string line = "";
    vector<vector<string>> program;
    while(getline( file, line ))
    {
        //Make sure line isn't empty
        if (line.length() == 0)
            continue;

        //String for each element in a line
        string element;

        //Vector for each element of a line
        vector<string> elements;

        //Make a stream to digest each line
        istringstream elementStream(line);
        while (elementStream >> element)
            elements.push_back(element);

        program.push_back(elements);
    }

    return program;
}

//banaScript To English
string bs2e(const vector<string>& text, const size_t start, map<string, char>& translateList)
{
    string theString = "";
    for (size_t i = start; i < text.size(); i++)
        theString += translateList[text[i]];

    return theString;
}

string bs2e(const string& bananaString, map<string, char>& translateList)
{
    if (bananaString.length() == 0)
        return "";

    istringstream bananaStream(bananaString);

    string convertedString = "";
    string bananaCase = "";
    while(bananaStream >> bananaCase)
        convertedString += translateList[bananaCase];

    return convertedString;
}

string e2bs(const string& englishString)
{
    map<char, string> translateList;
    translateList['a'] = "BANANAS";
    translateList['b'] = "BANANAs";
    translateList['c'] = "BANANaS";
    translateList['d'] = "BANANas";
    translateList['e'] = "BANAnAS";
    translateList['f'] = "BANAnAs";
    translateList['g'] = "BANAnaS";
    translateList['h'] = "BANAnas";
    translateList['i'] = "BANaNAS";
    translateList['j'] = "BANaNAs";
    translateList['k'] = "BANaNaS";
    translateList['l'] = "BANaNas";
    translateList['m'] = "BANanAS";
    translateList['n'] = "BANanAs";
    translateList['o'] = "BANanaS";
    translateList['p'] = "BANanas";
    translateList['q'] = "BAnANAS";
    translateList['r'] = "BAnANAs";
    translateList['s'] = "BAnANaS";
    translateList['t'] = "BAnANas";
    translateList['u'] = "BAnAnAS";
    translateList['v'] = "BAnAnAs";
    translateList['w'] = "BAnAnaS";
    translateList['x'] = "BAnAnas";
    translateList['y'] = "BAnaNAS";
    translateList['z'] = "BAnaNAs";
    translateList['A'] = "BAnaNaS";
    translateList['B'] = "BAnaNas";
    translateList['C'] = "BAnanAS";
    translateList['D'] = "BAnanAs";
    translateList['E'] = "BAnanaS";
    translateList['F'] = "BAnanas";
    translateList['G'] = "BaNANAS";
    translateList['H'] = "BaNANAs";
    translateList['I'] = "BaNANaS";
    translateList['J'] = "BaNANas";
    translateList['K'] = "BaNAnAS";
    translateList['L'] = "BaNAnAs";
    translateList['M'] = "BaNAnaS";
    translateList['N'] = "BaNAnas";
    translateList['O'] = "BaNaNAS";
    translateList['P'] = "BaNaNAs";
    translateList['Q'] = "BaNaNaS";
    translateList['R'] = "BaNaNas";
    translateList['S'] = "BaNanAS";
    translateList['T'] = "BaNanAs";
    translateList['U'] = "BaNanaS";
    translateList['V'] = "BaNanas";
    translateList['W'] = "BanANAS";
    translateList['X'] = "BanANAs";
    translateList['Y'] = "BanANaS";
    translateList['Z'] = "BanANas";
    translateList[' '] = "BanAnAS";

    translateList['0'] = "BanAnaS";
    translateList['1'] = "BanAnas";
    translateList['2'] = "BanaNAS";
    translateList['3'] = "BanaNAs";
    translateList['4'] = "BanaNaS";
    translateList['5'] = "BanaNas";
    translateList['6'] = "BananAS";
    translateList['7'] = "BananAs";
    translateList['8'] = "BananaS";
    translateList['9'] = "Bananas";

    translateList[','] = "bANANAS";
    translateList['.'] = "bANANAs";
    translateList['/'] = "bANANaS";
    translateList[';'] = "bANANas";
    translateList['\''] = "bANAnAS";
    translateList['['] = "bANAnAs";
    translateList[']'] = "bANAnaS";
    translateList['='] = "bANAnas";
    translateList['-'] = "bANaNAS";
    translateList['`'] = "bANaNAs";
    translateList['~'] = "bANaNaS";
    translateList['!'] = "bANaNas";
    translateList['@'] = "bANanAS";
    translateList['#'] = "bANanAs";
    translateList['$'] = "bANanaS";
    translateList['%'] = "bANanas";
    translateList['^'] = "bAnANAS";
    translateList['&'] = "bAnANAs";
    translateList['*'] = "bAnANaS";
    translateList['('] = "bAnANas";
    translateList[')'] = "bAnAnAS";
    translateList['_'] = "bAnAnAs";
    translateList['+'] = "bAnAnaS";
    translateList['{'] = "bAnAnas";
    translateList['}'] = "bAnaNAS";
    translateList['|'] = "bAnaNAs";
    translateList['\\'] = "bAnaNaS";
    translateList[':'] = "bAnaNas";
    translateList['"'] = "bAnanAS";
    translateList['?'] = "bAnanAs";
    translateList['>'] = "bAnanaS";
    translateList['<'] = "bAnanas";

    if (englishString.length() == 0)
        return "";
    istringstream englishStream(englishString);

    string bananaString = "";
    char englishChar = ' ';
    while(englishStream >> englishChar)
        bananaString += translateList[englishChar] + ' ';

    bananaString.pop_back();
    return bananaString;
}


int main(int argc, char* argv[])
{
    //First things frist, open the file
    vector<vector<string>> program;
    if (argc == 2)
        program = getScript(argv[1]);
    else
    {
        cout << "usage: monkeyDo [script]\n";
        exit(1);
    }

    //Define the character conversion
    map<string, char> translateList = genTranslateList();

    //String regs
    string sReg1 = "";
    string sReg2 = "";
    string sReg3 = "";
    string sReg4 = "";
    string sReg5 = "";
    string sReg6 = "";
    string sReg7 = "";
    string sReg8 = "";

    //int regs
    string iReg1 = "";
    string iReg2 = "";
    string iReg3 = "";
    string iReg4 = "";
    string iReg5 = "";
    string iReg6 = "";
    string iReg7 = "";
    string iReg8 = "";

    // Interpreter Variables
    size_t lineNumber = 0;

    //while loop for the interpreter
    while (lineNumber < program.size())
    {
        // make some pointers to strings that are commands
        string* extendP = new string("bananAS");
        string* ifP = new string("banaNAS");
        string* writeP = new string("bananas");
        string* readP = new string("bananaS");

        if (program[lineNumber][0] == *extendP)
        {
            // if (==/!=/>/<)
            if (program[lineNumber][1] == *ifP)
            {
                //Evaluate expression, if not true skip the next line
                  //Expressions have the following format:
                    //if reg expression reg

                if (program[lineNumber][2] != *extendP)
                    exit(1);
                if (program[lineNumber][5] != *extendP)
                    exit(1);

                //determine the registers
                string* reg1 = nullptr;
                string* reg2 = nullptr;

                if (program[lineNumber][3] == "banANAS")
                {
                    reg1 = &iReg1;
                }
                else if (program[lineNumber][3] == "banANAs")
                {
                    reg1 = &iReg2;
                }
                else if (program[lineNumber][3] == "banANaS")
                {
                    reg1 = &iReg3;
                }
                else if (program[lineNumber][3] == "banANas")
                {
                    reg1 = &iReg4;
                }
                else if (program[lineNumber][3] == "banAnAS")
                {
                    reg1 = &iReg5;
                }
                else if (program[lineNumber][3] == "banAnAs")
                {
                    reg1 = &iReg6;
                }
                else if (program[lineNumber][3] == "banAnaS")
                {
                    reg1 = &iReg7;
                }
                else if (program[lineNumber][3] == "banAnas")
                {
                    reg1 = &iReg8;
                }

                if (program[lineNumber][6] == "banANAS")
                {
                    reg2 = &iReg1;
                }
                else if (program[lineNumber][6] == "banANAs")
                {
                    reg2 = &iReg2;
                }
                else if (program[lineNumber][6] == "banANaS")
                {
                    reg2 = &iReg3;
                }
                else if (program[lineNumber][6] == "banANas")
                {
                    reg2 = &iReg4;
                }
                else if (program[lineNumber][6] == "banAnAS")
                {
                    reg2 = &iReg5;
                }
                else if (program[lineNumber][6] == "banAnAs")
                {
                    reg2 = &iReg6;
                }
                else if (program[lineNumber][6] == "banAnaS")
                {
                    reg2 = &iReg7;
                }
                else if (program[lineNumber][6] == "banAnas")
                {
                    reg2 = &iReg8;
                }

                bool result = false;

                // determine the operator
                if (program[lineNumber][4] == "baNANAS")
                {
                    result = (reg1->size() != reg2->size());
                }
                else if (program[lineNumber][4] == "baNanaS")
                {
                    result = (reg1->size() == reg2->size());
                }

                if (!result)
                {
                    lineNumber += 1;
                }

            }

            // int reg /=;*=;+=;-=;<<;>>:&=;|=;^=;=
            else if (program[lineNumber][1][0] == 'b' && program[lineNumber][1][1] == 'a' && program[lineNumber][1][2] == 'n' && program[lineNumber][1][3] == 'A')
            {
                //determine the register
                string* reg = nullptr;

                if (program[lineNumber][1] == "banANAS")
                {
                    reg = &iReg1;
                }
                else if (program[lineNumber][1] == "banANAs")
                {
                    reg = &iReg2;
                }
                else if (program[lineNumber][1] == "banANaS")
                {
                    reg = &iReg3;
                }
                else if (program[lineNumber][1] == "banANas")
                {
                    reg = &iReg4;
                }
                else if (program[lineNumber][1] == "banAnAS")
                {
                    reg = &iReg5;
                }
                else if (program[lineNumber][1] == "banAnAs")
                {
                    reg = &iReg6;
                }
                else if (program[lineNumber][1] == "banAnaS")
                {
                    reg = &iReg7;
                }
                else if (program[lineNumber][1] == "banAnas")
                {
                    reg = &iReg8;
                }

                //reassign
                if (program[lineNumber][2] == "baNanas")
                {
                    if (program[lineNumber][3] != "bananAS")
                    {
                        (*reg) = "";
                        for (size_t i = 3; i < program[lineNumber].size(); ++i)
                            (*reg) += program[lineNumber][i] + ' ';
                        (*reg).pop_back();
                    }
                    else
                    {
                        //determine the register
                        string* reg2 = nullptr;

                        if (program[lineNumber][3] != "bananAS")
                            exit(1);

                        if (program[lineNumber][4] == "banANAS")
                        {
                            reg2 = &iReg1;
                        }
                        else if (program[lineNumber][4] == "banANAs")
                        {
                            reg2 = &iReg2;
                        }
                        else if (program[lineNumber][4] == "banANaS")
                        {
                            reg2 = &iReg3;
                        }
                        else if (program[lineNumber][4] == "banANas")
                        {
                            reg2 = &iReg4;
                        }
                        else if (program[lineNumber][4] == "banAnAS")
                        {
                            reg2 = &iReg5;
                        }
                        else if (program[lineNumber][4] == "banAnAs")
                        {
                            reg2 = &iReg6;
                        }
                        else if (program[lineNumber][4] == "banAnaS")
                        {
                            reg2 = &iReg7;
                        }
                        else if (program[lineNumber][4] == "banAnas")
                        {
                            reg2 = &iReg8;
                        }

                        (*reg) = (*reg2);
                    }
                }
                else
                {
                    if (program[lineNumber][3] != "bananAS")
                        exit(1);

                    //determine the register
                    string* reg2 = nullptr;

                    if (program[lineNumber][4] == "banANAS")
                    {
                        reg2 = &iReg1;
                    }
                    else if (program[lineNumber][4] == "banANAs")
                    {
                        reg2 = &iReg2;
                    }
                    else if (program[lineNumber][4] == "banANaS")
                    {
                        reg2 = &iReg3;
                    }
                    else if (program[lineNumber][4] == "banANas")
                    {
                        reg2 = &iReg4;
                    }
                    else if (program[lineNumber][4] == "banAnAS")
                    {
                        reg2 = &iReg5;
                    }
                    else if (program[lineNumber][4] == "banAnAs")
                    {
                        reg2 = &iReg6;
                    }
                    else if (program[lineNumber][4] == "banAnaS")
                    {
                        reg2 = &iReg7;
                    }
                    else if (program[lineNumber][4] == "banAnas")
                    {
                        reg2 = &iReg8;
                    }
                    else
                    {
                        exit(1);
                    }

                    if (program[lineNumber][2] == "baNAnAS") // int divide
                    {
                        if ((*reg2).length() > 9)
                        {
                            exit(1);
                        }

                        istringstream stringStream((*reg));

                        string word = "";
                        string newReg = "";
                        while (stringStream >> word)
                            if (word != (*reg2))
                                newReg += word + " ";

                        newReg.pop_back();

                        (*reg) = newReg;
                    }
                    else if (program[lineNumber][2] == "baNAnAs") // int *
                    {
                        //translate bananaStream internal representation into a number
                        istringstream numberThing(bs2e(*reg2, translateList));
                        unsigned int repeatNumber;
                        numberThing >> repeatNumber;

                        if (repeatNumber == 0)
                            (*reg) = "";
                        else
                        {
                            string toRepeat = *reg;

                            for (int64_t i = 1; i < repeatNumber; ++i)
                                (*reg) += " " + toRepeat;
                        }
                    }
                    else if (program[lineNumber][2] == "baNAnas") // int +
                    {
                        if ((*reg2)[0] == 'b' && (*reg2)[1] == 'A' && (*reg2)[2] == 'N' && (*reg2)[3] == 'a' && (*reg2)[4] == 'N' && (*reg2)[5] == 'A' && (*reg2)[6] == 'S')
                        {
                            (*reg) = "bANaNAS" + (*reg);
                            for (size_t i = 8; i < reg2->size(); ++i)
                                (*reg) += (*reg2)[i];
                        }
                        else
                            (*reg) += " " + *reg2;
                    }
                    else if (program[lineNumber][2] == "baNAnaS") // int -
                    {
                        if ((*reg2).length() > 9)
                        {
                            exit(1);
                        }

                        istringstream stringStream((*reg));

                        string word = "";
                        string newReg = "";
                        bool notBefore = true;
                        while (stringStream >> word)
                        {
                            if (notBefore && word == (*reg2))
                                notBefore = false;
                            else
                                newReg += word + " ";
                        }

                        if (notBefore)
                            newReg = "bANaNAS " + newReg + (*reg2);
                        else
                            newReg.pop_back();

                        (*reg) = newReg;
                    }
                }
            }

            // write
            else if (program[lineNumber][1] == *writeP)
            {
                //ExtendedWrite
                extendedWrite:

                if (program[lineNumber][1] == *extendP)
                {
                    if (program[lineNumber][2][0] == 'b' && program[lineNumber][2][1] == 'a' && program[lineNumber][2][2] == 'n' && program[lineNumber][2][3] == 'A')
                    {
                        //determine the register
                        string* reg = nullptr;

                        if (program[lineNumber][2] == "banANAS")
                        {
                            reg = &iReg1;
                        }
                        else if (program[lineNumber][2] == "banANAs")
                        {
                            reg = &iReg2;
                        }
                        else if (program[lineNumber][2] == "banANaS")
                        {
                            reg = &iReg3;
                        }
                        else if (program[lineNumber][2] == "banANas")
                        {
                            reg = &iReg4;
                        }
                        else if (program[lineNumber][2] == "banAnAS")
                        {
                            reg = &iReg5;
                        }
                        else if (program[lineNumber][2] == "banAnAs")
                        {
                            reg = &iReg6;
                        }
                        else if (program[lineNumber][2] == "banAnaS")
                        {
                            reg = &iReg7;
                        }
                        else if (program[lineNumber][2] == "banAnas")
                        {
                            reg = &iReg8;
                        }
                        else
                        {
                            exit(1);
                        }

                        cout << bs2e(*reg, translateList) << endl;
                    }
                }
                else if(program[lineNumber][2] == *extendP)
                {
                    if (program[lineNumber][3][0] == 'b' && program[lineNumber][3][1] == 'a' && program[lineNumber][3][2] == 'n' && program[lineNumber][3][3] == 'A')
                    {
                        //determine the register
                        string* reg = nullptr;

                        if (program[lineNumber][3] == "banANAS")
                        {
                            reg = &iReg1;
                        }
                        else if (program[lineNumber][3] == "banANAs")
                        {
                            reg = &iReg2;
                        }
                        else if (program[lineNumber][3] == "banANaS")
                        {
                            reg = &iReg3;
                        }
                        else if (program[lineNumber][3] == "banANas")
                        {
                            reg = &iReg4;
                        }
                        else if (program[lineNumber][3] == "banAnAS")
                        {
                            reg = &iReg5;
                        }
                        else if (program[lineNumber][3] == "banAnAs")
                        {
                            reg = &iReg6;
                        }
                        else if (program[lineNumber][3] == "banAnaS")
                        {
                            reg = &iReg7;
                        }
                        else if (program[lineNumber][3] == "banAnas")
                        {
                            reg = &iReg8;
                        }

                        cout << bs2e(*reg, translateList) << endl;
                    }
                }
                else
                {
                    cout << bs2e(program[lineNumber], 3, translateList) << endl;
                }
            }

            // read
            else if (program[lineNumber][1] == *readP)
            {
                //ExtendedWrite
                extendedRead:

                if (program[lineNumber][1] == *extendP)
                {
                    if (program[lineNumber][2][0] == 'b' && program[lineNumber][2][1] == 'a' && program[lineNumber][2][2] == 'n' && program[lineNumber][2][3] == 'A')
                    {
                        //determine the register
                        string* reg = nullptr;

                        if (program[lineNumber][2] == "banANAS")
                        {
                            reg = &iReg1;
                        }
                        else if (program[lineNumber][2] == "banANAs")
                        {
                            reg = &iReg2;
                        }
                        else if (program[lineNumber][2] == "banANaS")
                        {
                            reg = &iReg3;
                        }
                        else if (program[lineNumber][2] == "banANas")
                        {
                            reg = &iReg4;
                        }
                        else if (program[lineNumber][2] == "banAnAS")
                        {
                            reg = &iReg5;
                        }
                        else if (program[lineNumber][2] == "banAnAs")
                        {
                            reg = &iReg6;
                        }
                        else if (program[lineNumber][2] == "banAnaS")
                        {
                            reg = &iReg7;
                        }
                        else if (program[lineNumber][2] == "banAnas")
                        {
                            reg = &iReg8;
                        }
                        else
                        {
                            exit(1);
                        }

                        getline(cin, *reg);

                        *reg = e2bs(*reg);
                    }
                    else
                    {
                        exit(1);
                    }
                }
                else if(program[lineNumber][2] == *extendP)
                {
                    if (program[lineNumber][3][0] == 'b' && program[lineNumber][3][1] == 'a' && program[lineNumber][3][2] == 'n' && program[lineNumber][3][3] == 'A')
                    {
                        //determine the register
                        string* reg = nullptr;

                        if (program[lineNumber][3] == "banANAS")
                        {
                            reg = &iReg1;
                        }
                        else if (program[lineNumber][3] == "banANAs")
                        {
                            reg = &iReg2;
                        }
                        else if (program[lineNumber][3] == "banANaS")
                        {
                            reg = &iReg3;
                        }
                        else if (program[lineNumber][3] == "banANas")
                        {
                            reg = &iReg4;
                        }
                        else if (program[lineNumber][3] == "banAnAS")
                        {
                            reg = &iReg5;
                        }
                        else if (program[lineNumber][3] == "banAnAs")
                        {
                            reg = &iReg6;
                        }
                        else if (program[lineNumber][3] == "banAnaS")
                        {
                            reg = &iReg7;
                        }
                        else if (program[lineNumber][3] == "banAnas")
                        {
                            reg = &iReg8;
                        }
                        else
                        {
                            exit(1);
                        }

                        getline(cin, *reg);

                        *reg = e2bs(*reg);
                    }
                    else
                    {
                        exit(1);
                    }
                }
                else
                {
                    exit(1);
                }

            }
        }
        else
        {
            // if (==/!=/>/<)
            if (program[lineNumber][0] == *ifP)
            {
                //Evaluate expression, if not true skip the next line
                  //Expressions have the following format:
                    //if reg expression reg

                //determine the registers
                string* reg1 = nullptr;
                string* reg2 = nullptr;

                if (program[lineNumber][1] == "banANAS")
                {
                    reg1 = &sReg1;
                }
                else if (program[lineNumber][1] == "banANAs")
                {
                    reg1 = &sReg2;
                }
                else if (program[lineNumber][1] == "banANaS")
                {
                    reg1 = &sReg3;
                }
                else if (program[lineNumber][1] == "banANas")
                {
                    reg1 = &sReg4;
                }
                else if (program[lineNumber][1] == "banAnAS")
                {
                    reg1 = &sReg5;
                }
                else if (program[lineNumber][1] == "banAnAs")
                {
                    reg1 = &sReg6;
                }
                else if (program[lineNumber][1] == "banAnaS")
                {
                    reg1 = &sReg7;
                }
                else if (program[lineNumber][1] == "banAnas")
                {
                    reg1 = &sReg8;
                }

                if (program[lineNumber][3] == "banANAS")
                {
                    reg2 = &sReg1;
                }
                else if (program[lineNumber][3] == "banANAs")
                {
                    reg2 = &sReg2;
                }
                else if (program[lineNumber][3] == "banANaS")
                {
                    reg2 = &sReg3;
                }
                else if (program[lineNumber][3] == "banANas")
                {
                    reg2 = &sReg4;
                }
                else if (program[lineNumber][3] == "banAnAS")
                {
                    reg2 = &sReg5;
                }
                else if (program[lineNumber][3] == "banAnAs")
                {
                    reg2 = &sReg6;
                }
                else if (program[lineNumber][3] == "banAnaS")
                {
                    reg2 = &sReg7;
                }
                else if (program[lineNumber][3] == "banAnas")
                {
                    reg2 = &sReg8;
                }

                bool result = false;

                // determine the operator
                if (program[lineNumber][2] == "baNANAS") // !=
                {
                    result = (*reg1 != *reg2);
                }
                else if (program[lineNumber][2] == "baNanaS") // ==
                {
                    result = (*reg1 == *reg2);
                }
                else if (program[lineNumber][2] == "baNANAs") // >
                {
                    //convert strings to numbers to compare >/<
                    int64_t num1 = 0;
                    unsigned int numOneTotal = 0;
                    for (size_t i = 0; i < reg1->size(); ++i)
                    {
                        if ((*reg1)[i] == 'B' || (*reg1)[i] == 'A' || (*reg1)[i] == 'N' || (*reg2)[i] == 'S')
                        {
                            num1 <<= 1;
                            num1 ^= 1;
                        }
                        else if ((*reg1)[i] == 'b' || (*reg1)[i] == 'a' || (*reg1)[i] == 'n' || (*reg2)[i] == 's')
                        {
                            num1 <<= 1;
                        }
                        if ((*reg1)[i] == ' ')
                        {
                            numOneTotal += num1;
                            num1 = 0;
                        }
                    }

                    int64_t num2 = 0;
                    unsigned int numTwoTotal = 0;
                    for (size_t i = 0; (i < 64) && (i < reg2->size()); ++i)
                    {
                        if ((*reg2)[i] == 'B' || (*reg2)[i] == 'A' || (*reg2)[i] == 'N' || (*reg2)[i] == 'S')
                        {
                            num1 <<= 1;
                            num2 ^= 1;
                        }
                        else if ((*reg2)[i] == 'b' || (*reg2)[i] == 'a' || (*reg2)[i] == 'n' || (*reg2)[i] == 's')
                        {
                            num1 <<= 1;
                        }
                        if ((*reg2)[i] == ' ')
                        {
                            numTwoTotal += num2;
                            num2 = 0;
                        }
                    }

                    result = (numOneTotal > numTwoTotal);
                }
                else if (program[lineNumber][2] == "baNANaS") // <
                {
                    //convert strings to numbers to compare >/<
                    int64_t num1 = 0;
                    int64_t numOneTotal = 0;
                    for (size_t i = 0; (i < 64) && (i < reg1->size()); ++i)
                    {
                        if ((*reg1)[i] == 'B' || (*reg1)[i] == 'A' || (*reg1)[i] == 'N' || (*reg2)[i] == 'S')
                        {
                            num1 <<= 1;
                            num1 ^= 1;
                        }
                        else if ((*reg1)[i] == 'b' || (*reg1)[i] == 'a' || (*reg1)[i] == 'n' || (*reg2)[i] == 's')
                        {
                            num1 <<= 1;
                        }
                        if ((*reg1)[i] == ' ')
                        {
                            numOneTotal += num1;
                            num1 = 0;
                        }
                    }
                    numOneTotal += num1;

                    int64_t num2 = 0;
                    int64_t numTwoTotal = 0;
                    for (size_t i = 0; (i < 64) && (i < reg2->size()); ++i)
                    {
                        if ((*reg2)[i] == 'B' || (*reg2)[i] == 'A' || (*reg2)[i] == 'N' || (*reg2)[i] == 'S')
                        {
                            num2 <<= 1;
                            num2 ^= 1;
                        }
                        else if ((*reg2)[i] == 'b' || (*reg2)[i] == 'a' || (*reg2)[i] == 'n' || (*reg2)[i] == 's')
                        {
                            num2 <<= 1;
                        }
                        if ((*reg2)[i] == ' ')
                        {
                            numTwoTotal += num2;
                            num2 = 0;
                        }
                    }
                    numTwoTotal += num2;

                    result = (numOneTotal < numTwoTotal);
                }

                if (!result)
                {
                    lineNumber += 1;
                }
            }

            // write
            else if (program[lineNumber][0] == *writeP)
            {
                if (program[lineNumber][1][0] == 'b' && program[lineNumber][1][1] == 'a' && program[lineNumber][1][2] == 'n' && program[lineNumber][1][3] == 'A')
                {
                    //determine the register
                    string* reg = nullptr;

                    if (program[lineNumber][1] == "banANAS")
                    {
                        reg = &sReg1;
                    }
                    else if (program[lineNumber][1] == "banANAs")
                    {
                        reg = &sReg2;
                    }
                    else if (program[lineNumber][1] == "banANaS")
                    {
                        reg = &sReg3;
                    }
                    else if (program[lineNumber][1] == "banANas")
                    {
                        reg = &sReg4;
                    }
                    else if (program[lineNumber][1] == "banAnAS")
                    {
                        reg = &sReg5;
                    }
                    else if (program[lineNumber][1] == "banAnAs")
                    {
                        reg = &sReg6;
                    }
                    else if (program[lineNumber][1] == "banAnaS")
                    {
                        reg = &sReg7;
                    }
                    else if (program[lineNumber][1] == "banAnas")
                    {
                        reg = &sReg8;
                    }

                    cout << bs2e(*reg, translateList) << endl;
                }
                else if (program[lineNumber][1] == "bananAS")
                {
                    goto extendedWrite;
                }
                else
                {
                    cout << bs2e(program[lineNumber], 1, translateList) << endl;
                }
            }

            // read
            else if (program[lineNumber][0] == *readP)
            {
                //determine the register
                string* reg = nullptr;

                if (program[lineNumber][1] == "banANAS")
                {
                    reg = &sReg1;
                }
                else if (program[lineNumber][1] == "banANAs")
                {
                    reg = &sReg2;
                }
                else if (program[lineNumber][1] == "banANaS")
                {
                    reg = &sReg3;
                }
                else if (program[lineNumber][1] == "banANas")
                {
                    reg = &sReg4;
                }
                else if (program[lineNumber][1] == "banAnAS")
                {
                    reg = &sReg5;
                }
                else if (program[lineNumber][1] == "banAnAs")
                {
                    reg = &sReg6;
                }
                else if (program[lineNumber][1] == "banAnaS")
                {
                    reg = &sReg7;
                }
                else if (program[lineNumber][1] == "banAnas")
                {
                    reg = &sReg8;
                }
                else if (program[lineNumber][1] == "bananAS")
                {
                    goto extendedRead;
                }

                getline(cin, *reg);

                *reg = e2bs(*reg);
            }

            // reg /=;*=;+=;-=;<<;>>:&=;|=;^=;=
            else if (program[lineNumber][0][0] == 'b' && program[lineNumber][0][1] == 'a' && program[lineNumber][0][2] == 'n' && program[lineNumber][0][3] == 'A')
            {
                //determine the register
                string* reg = nullptr;

                if (program[lineNumber][0] == "banANAS")
                {
                    reg = &sReg1;
                }
                else if (program[lineNumber][0] == "banANAs")
                {
                    reg = &sReg2;
                }
                else if (program[lineNumber][0] == "banANaS")
                {
                    reg = &sReg3;
                }
                else if (program[lineNumber][0] == "banANas")
                {
                    reg = &sReg4;
                }
                else if (program[lineNumber][0] == "banAnAS")
                {
                    reg = &sReg5;
                }
                else if (program[lineNumber][0] == "banAnAs")
                {
                    reg = &sReg6;
                }
                else if (program[lineNumber][0] == "banAnaS")
                {
                    reg = &sReg7;
                }
                else if (program[lineNumber][0] == "banAnas")
                {
                    reg = &sReg8;
                }

                if (program[lineNumber][2][0] == 'b' && program[lineNumber][2][1] == 'a' && program[lineNumber][2][2] == 'n' && program[lineNumber][2][3] == 'A')
                {
                    string* reg2 = nullptr;

                    if (program[lineNumber][2] == "banANAS")
                    {
                        reg2 = &sReg1;
                    }
                    else if (program[lineNumber][2] == "banANAs")
                    {
                        reg2 = &sReg2;
                    }
                    else if (program[lineNumber][2] == "banANaS")
                    {
                        reg2 = &sReg3;
                    }
                    else if (program[lineNumber][2] == "banANas")
                    {
                        reg2 = &sReg4;
                    }
                    else if (program[lineNumber][2] == "banAnAS")
                    {
                        reg2 = &sReg5;
                    }
                    else if (program[lineNumber][2] == "banAnAs")
                    {
                        reg2 = &sReg6;
                    }
                    else if (program[lineNumber][2] == "banAnaS")
                    {
                        reg2 = &sReg7;
                    }
                    else if (program[lineNumber][2] == "banAnas")
                    {
                        reg2 = &sReg8;
                    }
                    else
                        exit(1);

                    /*if (program[lineNumber][1] == "baNAnAS")
                    {
                        *reg = int2bs(bs2int(reg, translateList) / bs2int(reg2, translateList));
                    }
                    else if (program[lineNumber][1] == "baNAnAs")
                    {
                        *reg = int2bs(bs2int(reg, translateList) * bs2int(reg2, translateList));
                    }
                    else */if (program[lineNumber][1] == "baNAnas") // add
                    {
                        string newReg = "";
                        int place = 0;
                        bool carry = false;
                        for (size_t i = 0; i < reg->length(); ++i)
                        {
                            if (newReg.size() % 8 == 0)
                            {
                                newReg = " " + newReg;
                                place = 0;
                            }

                            if ( (*reg)[(reg->length()-1)-i] == ' ' )
                                continue;
                            else if ( ((*reg)[(reg->length()-1)-i] != (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))]))
                            {
                                if (carry)
                                {
                                    if (place == 1 || place == 3 || place == 5)
                                        newReg = "a" + newReg;
                                    else if (place == 2 || place == 4)
                                        newReg = "n" + newReg;
                                    else if (place == 0)
                                        newReg = "s" + newReg;
                                    else if (place == 6)
                                        newReg = "b" + newReg;
                                }
                                else
                                {
                                    //uppercase:
                                    if (place == 1 || place == 3 || place == 5)
                                        newReg = "A" + newReg;
                                    else if (place == 2 || place == 4)
                                        newReg = "N" + newReg;
                                    else if (place == 0)
                                        newReg = "S" + newReg;
                                    else if (place == 6)
                                        newReg = "B" + newReg;
                                }
                            }
                            else
                            {
                                if (carry)
                                {
                                    if (((*reg)[(reg->length()-1)-i] == 'B' || (*reg)[(reg->length()-1)-i] == 'A' || (*reg)[(reg->length()-1)-i] == 'N' || (*reg)[(reg->length()-1)-i] == 'S') || ((*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'B' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'A' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'N' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'S'))
                                    {
                                        if (place == 1 || place == 3 || place == 5)
                                            newReg = "A" + newReg;
                                        else if (place == 2 || place == 4)
                                            newReg = "N" + newReg;
                                        else if (place == 0)
                                            newReg = "S" + newReg;
                                        else if (place == 6)
                                            newReg = "B" + newReg;
                                    }
                                    else
                                    {
                                        if (place == 1 || place == 3 || place == 5)
                                            newReg = "A" + newReg;
                                        else if (place == 2 || place == 4)
                                            newReg = "N" + newReg;
                                        else if (place == 0)
                                            newReg = "S" + newReg;
                                        else if (place == 6)
                                            newReg = "B" + newReg;
                                        carry = false;
                                    }
                                }

                                else
                                {
                                    if ((*reg)[(reg->length()-1)-i] == 'B' || (*reg)[(reg->length()-1)-i] == 'A' || (*reg)[(reg->length()-1)-i] == 'N' || (*reg)[(reg->length()-1)-i] == 'S' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'B' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'A' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'N' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'S')
                                    {
                                        if (place == 1 || place == 3 || place == 5)
                                            newReg = "a" + newReg;
                                        else if (place == 2 || place == 4)
                                            newReg = "n" + newReg;
                                        else if (place == 0)
                                            newReg = "s" + newReg;
                                        else if (place == 6)
                                            newReg = "b" + newReg;

                                        carry = true;
                                    }
                                    else
                                    {
                                        if (place == 1 || place == 3 || place == 5)
                                            newReg = "a" + newReg;
                                        else if (place == 2 || place == 4)
                                            newReg = "n" + newReg;
                                        else if (place == 0)
                                            newReg = "s" + newReg;
                                        else if (place == 6)
                                            newReg = "b" + newReg;
                                    }
                                }
                            }
                            ++place;
                        }

                        newReg.pop_back();
                        (*reg) = newReg;
                    }/*
                    else if (program[lineNumber][1] == "baNAnaS") // sub
                    {
                        *reg = int2bs(bs2int(reg, translateList) - bs2int(reg2, translateList));
                    }
                    else if (program[lineNumber][1] == "baNaNAs")
                    {
                        *reg = int2bs(bs2int(reg, translateList) << bs2int(reg2, translateList));
                    }
                    else if (program[lineNumber][1] == "baNaNAS")
                    {
                        *reg = int2bs(bs2int(reg, translateList) >> bs2int(reg2, translateList));
                    }*/
                    else if (program[lineNumber][1] == "baNaNaS") // string and
                    {
                        string newReg = "";
                        int place = 0;
                        for (size_t i = 0; i < reg->length(); ++i)
                        {
                            if (newReg.size() % 8 == 0)
                            {
                                newReg = " " + newReg;

                                place = 0;
                            }

                            if ( (*reg)[(reg->length()-1)-i] == ' ' )
                                continue;
                            else if ( ((*reg)[(reg->length()-1)-i] == 'B' || (*reg)[(reg->length()-1)-i] == 'A' || (*reg)[(reg->length()-1)-i] == 'N' || (*reg)[(reg->length()-1)-i] == 'S') && ((*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'B' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'A' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'N' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'S'))
                            {
                                //uppercase:
                                if (place == 1 || place == 3 || place == 5)
                                    newReg = "A" + newReg;
                                else if (place == 2 || place == 4)
                                    newReg = "N" + newReg;
                                else if (place == 0)
                                    newReg = "S" + newReg;
                                else if (place == 6)
                                    newReg = "B" + newReg;
                            }
                            else
                            {
                                //Else:
                                if (place == 1 || place == 3 || place == 5)
                                    newReg = "a" + newReg;
                                else if (place == 2 || place == 4)
                                    newReg = "n" + newReg;
                                else if (place == 0)
                                    newReg = "s" + newReg;
                                else if (place == 6)
                                    newReg = "b" + newReg;
                            }

                            ++place;
                        }

                        newReg.pop_back();
                        (*reg) = newReg;
                    }
                    else if (program[lineNumber][1] == "baNaNas")  // string or
                    {
                        string newReg = "";
                        int place = 0;
                        for (size_t i = 0; i < reg->length(); ++i)
                        {
                            if (newReg.size() % 8 == 0)
                            {
                                newReg = " " + newReg;
                                place = 0;
                            }

                            if ( (*reg)[(reg->length()-1)-i] == ' ' )
                                continue;
                            else if ((*reg)[(reg->length()-1)-i] == 'B' || (*reg)[(reg->length()-1)-i] == 'A' || (*reg)[(reg->length()-1)-i] == 'N' || (*reg)[(reg->length()-1)-i] == 'S' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'B' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'A' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'N' || (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))] == 'S')
                            {
                                //uppercase:
                                if (place == 1 || place == 3 || place == 5)
                                    newReg = "A" + newReg;
                                else if (place == 2 || place == 4)
                                    newReg = "N" + newReg;
                                else if (place == 0)
                                    newReg = "S" + newReg;
                                else if (place == 6)
                                    newReg = "B" + newReg;
                            }
                            else
                            {
                                //Else:
                                if (place == 1 || place == 3 || place == 5)
                                    newReg = "a" + newReg;
                                else if (place == 2 || place == 4)
                                    newReg = "n" + newReg;
                                else if (place == 0)
                                    newReg = "s" + newReg;
                                else if (place == 6)
                                    newReg = "b" + newReg;
                            }

                            ++place;
                        }

                        newReg.pop_back();
                        (*reg) = newReg;
                    }
                    else if (program[lineNumber][1] == "baNanAS") // string xor
                    {
                        string newReg = "";
                        int place = 0;
                        for (size_t i = 0; i < reg->length(); ++i)
                        {
                            if (newReg.size() % 8 == 0)
                            {
                                newReg = " " + newReg;
                                place = 0;
                            }

                            if ( (*reg)[(reg->length()-1)-i] == ' ' )
                                continue;
                            else if ((*reg)[(reg->length()-1)-i] != (*reg2)[(reg2->length()-1)-(i%(reg2->length()+1))])
                            {
                                //uppercase:
                                if (place == 1 || place == 3 || place == 5)
                                    newReg = "A" + newReg;
                                else if (place == 2 || place == 4)
                                    newReg = "N" + newReg;
                                else if (place == 0)
                                    newReg = "S" + newReg;
                                else if (place == 6)
                                    newReg = "B" + newReg;
                            }
                            else
                            {
                                //Else:
                                if (place == 1 || place == 3 || place == 5)
                                    newReg = "a" + newReg;
                                else if (place == 2 || place == 4)
                                    newReg = "n" + newReg;
                                else if (place == 0)
                                    newReg = "s" + newReg;
                                else if (place == 6)
                                    newReg = "b" + newReg;
                            }

                            ++place;
                        }

                        newReg.pop_back();
                        (*reg) = newReg;
                    }
                }
                else
                {
                    //re assign
                    if (program[lineNumber][1] == "baNanas")
                    {
                        (*reg) = "";
                        for (size_t i = 2; i < program[lineNumber].size(); ++i)
                            (*reg) += program[lineNumber][i] + " ";//bs2e(program[lineNumber], 2, translateList);
                        (*reg).pop_back();
                    }
                }
            }

            //jump
            else if (program[lineNumber][0] == "bananAs")
            {
                if (program[lineNumber][1] != *extendP)
                    exit(1);

                //determine the register
                string* reg = nullptr;

                if (program[lineNumber][2] == "banANAS")
                {
                    reg = &iReg1;
                }
                else if (program[lineNumber][2] == "banANAs")
                {
                    reg = &iReg2;
                }
                else if (program[lineNumber][2] == "banANaS")
                {
                    reg = &iReg3;
                }
                else if (program[lineNumber][2] == "banANas")
                {
                    reg = &iReg4;
                }
                else if (program[lineNumber][2] == "banAnAS")
                {
                    reg = &iReg5;
                }
                else if (program[lineNumber][2] == "banAnAs")
                {
                    reg = &iReg6;
                }
                else if (program[lineNumber][2] == "banAnaS")
                {
                    reg = &iReg7;
                }
                else if (program[lineNumber][2] == "banAnas")
                {
                    reg = &iReg8;
                }
                else
                {
                    exit(1);
                }

                //translate bananaStream internal representation into a number
                istringstream numberThing(bs2e(*reg, translateList));
                int skipNumber;
                numberThing >> skipNumber;

                lineNumber += skipNumber-1;
            }
        }

        ++lineNumber;
    }
}
