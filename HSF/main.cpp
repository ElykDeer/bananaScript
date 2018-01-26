
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <stdint.h>
using namespace std;

#include "banana.defs"

map<string, string> genTranslateList()
{
    //Define the character conversion
    map<string, string> translateList;
    #include "banana.config"

    return translateList;
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
string bs2e(const vector<string>& text, const size_t start, map<string, string>& translateList)
{
    string theString = "";
    for (size_t i = start; i < text.size(); i++)
        theString += translateList[text[i]];

    return theString;
}

string bs2e(const string& bananaString, map<string, string>& translateList)
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
    map<string, string> translateList = genTranslateList();

    if (englishString.length() == 0)
        return "";
    istringstream englishStream(englishString);

    string bananaString = "";
    char englishChar = ' ';
    while(englishStream >> englishChar)
        bananaString += translateList[string(1, englishChar)] + ' ';

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
    map<string, string> translateList = genTranslateList();

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
        string* extendP = new string(EXTEND);
        string* ifP = new string(IF);
        string* writeP = new string(WRITE);
        string* readP = new string(READ);

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

                if (program[lineNumber][3] == Reg1)
                {
                    reg1 = &iReg1;
                }
                else if (program[lineNumber][3] == Reg2)
                {
                    reg1 = &iReg2;
                }
                else if (program[lineNumber][3] == Reg3)
                {
                    reg1 = &iReg3;
                }
                else if (program[lineNumber][3] == Reg4)
                {
                    reg1 = &iReg4;
                }
                else if (program[lineNumber][3] == Reg5)
                {
                    reg1 = &iReg5;
                }
                else if (program[lineNumber][3] == Reg6)
                {
                    reg1 = &iReg6;
                }
                else if (program[lineNumber][3] == Reg7)
                {
                    reg1 = &iReg7;
                }
                else if (program[lineNumber][3] == Reg8)
                {
                    reg1 = &iReg8;
                }

                if (program[lineNumber][6] == Reg1)
                {
                    reg2 = &iReg1;
                }
                else if (program[lineNumber][6] == Reg2)
                {
                    reg2 = &iReg2;
                }
                else if (program[lineNumber][6] == Reg3)
                {
                    reg2 = &iReg3;
                }
                else if (program[lineNumber][6] == Reg4)
                {
                    reg2 = &iReg4;
                }
                else if (program[lineNumber][6] == Reg5)
                {
                    reg2 = &iReg5;
                }
                else if (program[lineNumber][6] == Reg6)
                {
                    reg2 = &iReg6;
                }
                else if (program[lineNumber][6] == Reg7)
                {
                    reg2 = &iReg7;
                }
                else if (program[lineNumber][6] == Reg8)
                {
                    reg2 = &iReg8;
                }

                bool result = false;

                // determine the operator
                if (program[lineNumber][4] == NEQ)
                {
                    result = (reg1->size() != reg2->size());
                }
                else if (program[lineNumber][4] == DEQ)
                {
                    result = (reg1->size() == reg2->size());
                }

                if (!result)
                {
                    lineNumber += 1;
                }

            }

            // int reg /=;*=;+=;-=;<<;>>:&=;|=;^=;=
            else if (program[lineNumber][1] == REGISTER1 ||program[lineNumber][1] == REGISTER2 || program[lineNumber][1] == REGISTER3 || program[lineNumber][1] == REGISTER4 || program[lineNumber][1] == REGISTER5 || program[lineNumber][1] == REGISTER6 || program[lineNumber][1] == REGISTER7 || program[lineNumber][1] == REGISTER8)
            {
                //determine the register
                string* reg = nullptr;

                if (program[lineNumber][1] == Reg1)
                {
                    reg = &iReg1;
                }
                else if (program[lineNumber][1] == Reg2)
                {
                    reg = &iReg2;
                }
                else if (program[lineNumber][1] == Reg3)
                {
                    reg = &iReg3;
                }
                else if (program[lineNumber][1] == Reg4)
                {
                    reg = &iReg4;
                }
                else if (program[lineNumber][1] == Reg5)
                {
                    reg = &iReg5;
                }
                else if (program[lineNumber][1] == Reg6)
                {
                    reg = &iReg6;
                }
                else if (program[lineNumber][1] == Reg7)
                {
                    reg = &iReg7;
                }
                else if (program[lineNumber][1] == Reg8)
                {
                    reg = &iReg8;
                }

                //reassign
                if (program[lineNumber][2] == EQ)
                {
                    if (program[lineNumber][3] != EXTEND)
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

                        if (program[lineNumber][3] != EXTEND)
                            exit(1);

                        if (program[lineNumber][4] == Reg1)
                        {
                            reg2 = &iReg1;
                        }
                        else if (program[lineNumber][4] == Reg2)
                        {
                            reg2 = &iReg2;
                        }
                        else if (program[lineNumber][4] == Reg3)
                        {
                            reg2 = &iReg3;
                        }
                        else if (program[lineNumber][4] == Reg4)
                        {
                            reg2 = &iReg4;
                        }
                        else if (program[lineNumber][4] == Reg5)
                        {
                            reg2 = &iReg5;
                        }
                        else if (program[lineNumber][4] == Reg6)
                        {
                            reg2 = &iReg6;
                        }
                        else if (program[lineNumber][4] == Reg7)
                        {
                            reg2 = &iReg7;
                        }
                        else if (program[lineNumber][4] == Reg8)
                        {
                            reg2 = &iReg8;
                        }

                        (*reg) = (*reg2);
                    }
                }
                else
                {
                    if (program[lineNumber][3] != EXTEND)
                        exit(1);

                    //determine the register
                    string* reg2 = nullptr;

                    if (program[lineNumber][4] == Reg1)
                    {
                        reg2 = &iReg1;
                    }
                    else if (program[lineNumber][4] == Reg2)
                    {
                        reg2 = &iReg2;
                    }
                    else if (program[lineNumber][4] == Reg3)
                    {
                        reg2 = &iReg3;
                    }
                    else if (program[lineNumber][4] == Reg4)
                    {
                        reg2 = &iReg4;
                    }
                    else if (program[lineNumber][4] == Reg5)
                    {
                        reg2 = &iReg5;
                    }
                    else if (program[lineNumber][4] == Reg6)
                    {
                        reg2 = &iReg6;
                    }
                    else if (program[lineNumber][4] == Reg7)
                    {
                        reg2 = &iReg7;
                    }
                    else if (program[lineNumber][4] == Reg8)
                    {
                        reg2 = &iReg8;
                    }
                    else
                    {
                        exit(1);
                    }

                    if (program[lineNumber][2] == DIV) // int divide
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
                    else if (program[lineNumber][2] == MUL) // int *
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
                    else if (program[lineNumber][2] == ADD) // int +
                    {
                        if ((*reg2)[0] == NEGATIVE[0] && (*reg2)[1] == NEGATIVE[1] && (*reg2)[2] == NEGATIVE[2] && (*reg2)[3] == NEGATIVE[3] && (*reg2)[4] == NEGATIVE[4] && (*reg2)[5] == NEGATIVE[5] && (*reg2)[6] == NEGATIVE[6])
                        {
                            (*reg) = NEGATIVE + (*reg);
                            for (size_t i = 8; i < reg2->size(); ++i)
                                (*reg) += (*reg2)[i];
                        }
                        else
                            (*reg) += " " + *reg2;
                    }
                    else if (program[lineNumber][2] == SUB) // int -
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
                            newReg = string(NEGATIVE, 1) + string(" ", 1) + newReg + (*reg2);
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
                    if (program[lineNumber][2] == REGISTER1 ||program[lineNumber][2] == REGISTER2 || program[lineNumber][2] == REGISTER3 || program[lineNumber][2] == REGISTER4 || program[lineNumber][2] == REGISTER5 || program[lineNumber][2] == REGISTER6 || program[lineNumber][2] == REGISTER7 || program[lineNumber][2] == REGISTER8)
                    {
                        //determine the register
                        string* reg = nullptr;

                        if (program[lineNumber][2] == Reg1)
                        {
                            reg = &iReg1;
                        }
                        else if (program[lineNumber][2] == Reg2)
                        {
                            reg = &iReg2;
                        }
                        else if (program[lineNumber][2] == Reg3)
                        {
                            reg = &iReg3;
                        }
                        else if (program[lineNumber][2] == Reg4)
                        {
                            reg = &iReg4;
                        }
                        else if (program[lineNumber][2] == Reg5)
                        {
                            reg = &iReg5;
                        }
                        else if (program[lineNumber][2] == Reg6)
                        {
                            reg = &iReg6;
                        }
                        else if (program[lineNumber][2] == Reg7)
                        {
                            reg = &iReg7;
                        }
                        else if (program[lineNumber][2] == Reg8)
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
                    if (program[lineNumber][3] == REGISTER1 ||program[lineNumber][3] == REGISTER2 || program[lineNumber][3] == REGISTER3 || program[lineNumber][3] == REGISTER4 || program[lineNumber][3] == REGISTER5 || program[lineNumber][3] == REGISTER6 || program[lineNumber][3] == REGISTER7 || program[lineNumber][3] == REGISTER8)
                    {
                        //determine the register
                        string* reg = nullptr;

                        if (program[lineNumber][3] == Reg1)
                        {
                            reg = &iReg1;
                        }
                        else if (program[lineNumber][3] == Reg2)
                        {
                            reg = &iReg2;
                        }
                        else if (program[lineNumber][3] == Reg3)
                        {
                            reg = &iReg3;
                        }
                        else if (program[lineNumber][3] == Reg4)
                        {
                            reg = &iReg4;
                        }
                        else if (program[lineNumber][3] == Reg5)
                        {
                            reg = &iReg5;
                        }
                        else if (program[lineNumber][3] == Reg6)
                        {
                            reg = &iReg6;
                        }
                        else if (program[lineNumber][3] == Reg7)
                        {
                            reg = &iReg7;
                        }
                        else if (program[lineNumber][3] == Reg8)
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
                    //determine the register
                    string* reg = nullptr;

                    if (program[lineNumber][2] == Reg1)
                    {
                        reg = &iReg1;
                    }
                    else if (program[lineNumber][2] == Reg2)
                    {
                        reg = &iReg2;
                    }
                    else if (program[lineNumber][2] == Reg3)
                    {
                        reg = &iReg3;
                    }
                    else if (program[lineNumber][2] == Reg4)
                    {
                        reg = &iReg4;
                    }
                    else if (program[lineNumber][2] == Reg5)
                    {
                        reg = &iReg5;
                    }
                    else if (program[lineNumber][2] == Reg6)
                    {
                        reg = &iReg6;
                    }
                    else if (program[lineNumber][2] == Reg7)
                    {
                        reg = &iReg7;
                    }
                    else if (program[lineNumber][2] == Reg8)
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
                else if(program[lineNumber][2] == *extendP)
                {
                    //determine the register
                    string* reg = nullptr;

                    if (program[lineNumber][3] == Reg1)
                    {
                        reg = &iReg1;
                    }
                    else if (program[lineNumber][3] == Reg2)
                    {
                        reg = &iReg2;
                    }
                    else if (program[lineNumber][3] == Reg3)
                    {
                        reg = &iReg3;
                    }
                    else if (program[lineNumber][3] == Reg4)
                    {
                        reg = &iReg4;
                    }
                    else if (program[lineNumber][3] == Reg5)
                    {
                        reg = &iReg5;
                    }
                    else if (program[lineNumber][3] == Reg6)
                    {
                        reg = &iReg6;
                    }
                    else if (program[lineNumber][3] == Reg7)
                    {
                        reg = &iReg7;
                    }
                    else if (program[lineNumber][3] == Reg8)
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

                if (program[lineNumber][1] == Reg1)
                {
                    reg1 = &sReg1;
                }
                else if (program[lineNumber][1] == Reg2)
                {
                    reg1 = &sReg2;
                }
                else if (program[lineNumber][1] == Reg3)
                {
                    reg1 = &sReg3;
                }
                else if (program[lineNumber][1] == Reg4)
                {
                    reg1 = &sReg4;
                }
                else if (program[lineNumber][1] == Reg5)
                {
                    reg1 = &sReg5;
                }
                else if (program[lineNumber][1] == Reg6)
                {
                    reg1 = &sReg6;
                }
                else if (program[lineNumber][1] == Reg7)
                {
                    reg1 = &sReg7;
                }
                else if (program[lineNumber][1] == Reg8)
                {
                    reg1 = &sReg8;
                }

                if (program[lineNumber][3] == Reg1)
                {
                    reg2 = &sReg1;
                }
                else if (program[lineNumber][3] == Reg2)
                {
                    reg2 = &sReg2;
                }
                else if (program[lineNumber][3] == Reg3)
                {
                    reg2 = &sReg3;
                }
                else if (program[lineNumber][3] == Reg4)
                {
                    reg2 = &sReg4;
                }
                else if (program[lineNumber][3] == Reg5)
                {
                    reg2 = &sReg5;
                }
                else if (program[lineNumber][3] == Reg6)
                {
                    reg2 = &sReg6;
                }
                else if (program[lineNumber][3] == Reg7)
                {
                    reg2 = &sReg7;
                }
                else if (program[lineNumber][3] == Reg8)
                {
                    reg2 = &sReg8;
                }

                bool result = false;

                // determine the operator
                if (program[lineNumber][2] == NEQ) // !=
                {
                    result = (*reg1 != *reg2);
                }
                else if (program[lineNumber][2] == DEQ) // ==
                {
                    result = (*reg1 == *reg2);
                }
                else if (program[lineNumber][2] == MORE) // >
                {
                    //convert strings to numbers to compare >/<
                    int64_t num1 = 0;
                    unsigned int numOneTotal = 0;
                    for (size_t i = 0; i < reg1->size(); ++i)
                    {
                        if ((*reg1)[i] == 'B' || (*reg1)[i] == 'A' || (*reg1)[i] == 'N' || (*reg1)[i] == 'S')
                        {
                            num1 <<= 1;
                            num1 ^= 1;
                        }
                        else if ((*reg1)[i] == 'b' || (*reg1)[i] == 'a' || (*reg1)[i] == 'n' || (*reg1)[i] == 's')
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
                else if (program[lineNumber][2] == LESS) // <
                {
                    //convert strings to numbers to compare >/<
                    int64_t num1 = 0;
                    int64_t numOneTotal = 0;
                    for (size_t i = 0; (i < 64) && (i < reg1->size()); ++i)
                    {
                        if ((*reg1)[i] == 'B' || (*reg1)[i] == 'A' || (*reg1)[i] == 'N' || (*reg1)[i] == 'S')
                        {
                            num1 <<= 1;
                            num1 ^= 1;
                        }
                        else if ((*reg1)[i] == 'b' || (*reg1)[i] == 'a' || (*reg1)[i] == 'n' || (*reg1)[i] == 's')
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
                if (program[lineNumber][1] == REGISTER1 ||program[lineNumber][1] == REGISTER2 || program[lineNumber][1] == REGISTER3 || program[lineNumber][1] == REGISTER4 || program[lineNumber][1] == REGISTER5 || program[lineNumber][1] == REGISTER6 || program[lineNumber][1] == REGISTER7 || program[lineNumber][1] == REGISTER8)
                {
                    //determine the register
                    string* reg = nullptr;

                    if (program[lineNumber][1] == Reg1)
                    {
                        reg = &sReg1;
                    }
                    else if (program[lineNumber][1] == Reg2)
                    {
                        reg = &sReg2;
                    }
                    else if (program[lineNumber][1] == Reg3)
                    {
                        reg = &sReg3;
                    }
                    else if (program[lineNumber][1] == Reg4)
                    {
                        reg = &sReg4;
                    }
                    else if (program[lineNumber][1] == Reg5)
                    {
                        reg = &sReg5;
                    }
                    else if (program[lineNumber][1] == Reg6)
                    {
                        reg = &sReg6;
                    }
                    else if (program[lineNumber][1] == Reg7)
                    {
                        reg = &sReg7;
                    }
                    else if (program[lineNumber][1] == Reg8)
                    {
                        reg = &sReg8;
                    }

                    cout << bs2e(*reg, translateList) << endl;
                }
                else if (program[lineNumber][1] == EXTEND)
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

                if (program[lineNumber][1] == Reg1)
                {
                    reg = &sReg1;
                }
                else if (program[lineNumber][1] == Reg2)
                {
                    reg = &sReg2;
                }
                else if (program[lineNumber][1] == Reg3)
                {
                    reg = &sReg3;
                }
                else if (program[lineNumber][1] == Reg4)
                {
                    reg = &sReg4;
                }
                else if (program[lineNumber][1] == Reg5)
                {
                    reg = &sReg5;
                }
                else if (program[lineNumber][1] == Reg6)
                {
                    reg = &sReg6;
                }
                else if (program[lineNumber][1] == Reg7)
                {
                    reg = &sReg7;
                }
                else if (program[lineNumber][1] == Reg8)
                {
                    reg = &sReg8;
                }
                else if (program[lineNumber][1] == EXTEND)
                {
                    goto extendedRead;
                }

                getline(cin, *reg);

                *reg = e2bs(*reg);
            }

            // reg /=;*=;+=;-=;<<;>>:&=;|=;^=;=
            else if (program[lineNumber][0] == REGISTER1 ||program[lineNumber][0] == REGISTER2 || program[lineNumber][0] == REGISTER3 || program[lineNumber][0] == REGISTER4 || program[lineNumber][0] == REGISTER5 || program[lineNumber][0] == REGISTER6 || program[lineNumber][0] == REGISTER7 || program[lineNumber][0] == REGISTER8)
            {
                //determine the register
                string* reg = nullptr;

                if (program[lineNumber][0] == Reg1)
                {
                    reg = &sReg1;
                }
                else if (program[lineNumber][0] == Reg2)
                {
                    reg = &sReg2;
                }
                else if (program[lineNumber][0] == Reg3)
                {
                    reg = &sReg3;
                }
                else if (program[lineNumber][0] == Reg4)
                {
                    reg = &sReg4;
                }
                else if (program[lineNumber][0] == Reg5)
                {
                    reg = &sReg5;
                }
                else if (program[lineNumber][0] == Reg6)
                {
                    reg = &sReg6;
                }
                else if (program[lineNumber][0] == Reg7)
                {
                    reg = &sReg7;
                }
                else if (program[lineNumber][0] == Reg8)
                {
                    reg = &sReg8;
                }

                if (program[lineNumber][2] == REGISTER1 ||program[lineNumber][2] == REGISTER2 || program[lineNumber][2] == REGISTER3 || program[lineNumber][2] == REGISTER4 || program[lineNumber][2] == REGISTER5 || program[lineNumber][2] == REGISTER6 || program[lineNumber][2] == REGISTER7 || program[lineNumber][2] == REGISTER8)
                {
                    string* reg2 = nullptr;

                    if (program[lineNumber][2] == Reg1)
                    {
                        reg2 = &sReg1;
                    }
                    else if (program[lineNumber][2] == Reg2)
                    {
                        reg2 = &sReg2;
                    }
                    else if (program[lineNumber][2] == Reg3)
                    {
                        reg2 = &sReg3;
                    }
                    else if (program[lineNumber][2] == Reg4)
                    {
                        reg2 = &sReg4;
                    }
                    else if (program[lineNumber][2] == Reg5)
                    {
                        reg2 = &sReg5;
                    }
                    else if (program[lineNumber][2] == Reg6)
                    {
                        reg2 = &sReg6;
                    }
                    else if (program[lineNumber][2] == Reg7)
                    {
                        reg2 = &sReg7;
                    }
                    else if (program[lineNumber][2] == Reg8)
                    {
                        reg2 = &sReg8;
                    }
                    else
                        exit(1);

                    /*if (program[lineNumber][1] == DIV)
                    {
                        *reg = int2bs(bs2int(reg, translateList) / bs2int(reg2, translateList));
                    }
                    else if (program[lineNumber][1] == MUL)
                    {
                        *reg = int2bs(bs2int(reg, translateList) * bs2int(reg2, translateList));
                    }
                    else */if (program[lineNumber][1] == ADD) // add
                    {
                        string newReg = "";
                        int place = 0;
                        bool carry = false;

                        for (size_t i = 0; (i < reg->length()) && (i < reg2->length()); ++i)
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

                        for (size_t i = newReg.length(); i < reg->length(); ++i)
                        {
                            newReg = (*reg)[(reg->length()-1)-i] + newReg;
                        }

                        (*reg) = newReg;
                    }/*
                    else if (program[lineNumber][1] == SUB) // sub
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
                    if (program[lineNumber][1] == EQ)
                    {
                        (*reg) = "";
                        for (size_t i = 2; i < program[lineNumber].size(); ++i)
                            (*reg) += program[lineNumber][i] + " ";//bs2e(program[lineNumber], 2, translateList);
                        (*reg).pop_back();
                    }
                }
            }

            //jump
            else if (program[lineNumber][0] == JUMP)
            {
                if (program[lineNumber][1] != *extendP)
                    exit(1);

                //determine the register
                string* reg = nullptr;

                if (program[lineNumber][2] == Reg1)
                {
                    reg = &iReg1;
                }
                else if (program[lineNumber][2] == Reg2)
                {
                    reg = &iReg2;
                }
                else if (program[lineNumber][2] == Reg3)
                {
                    reg = &iReg3;
                }
                else if (program[lineNumber][2] == Reg4)
                {
                    reg = &iReg4;
                }
                else if (program[lineNumber][2] == Reg5)
                {
                    reg = &iReg5;
                }
                else if (program[lineNumber][2] == Reg6)
                {
                    reg = &iReg6;
                }
                else if (program[lineNumber][2] == Reg7)
                {
                    reg = &iReg7;
                }
                else if (program[lineNumber][2] == Reg8)
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
