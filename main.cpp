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
        std::exit(0);

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



int main(int argc, char* argv[])
{
    //First things frist, open the file
    vector<vector<string>> program;
    if (argc == 2)
        program = getScript(argv[1]);
    else
    {
        cout << "usage: monkeyDo [script]\n";
        exit(0);
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

    // Interpreter Variables
    size_t lineNumber = 0;

    //while loop for the interpreter
    while (lineNumber < program.size())
    {
        // if (==/!=/>/<)
        if (program[lineNumber][0] == "banaNAS")
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
            if (program[lineNumber][2] == "baNANAS")
            {
                result = (*reg1 != *reg2);
            }
            else if (program[lineNumber][2] == "baNanaS")
            {
                result = (*reg1 == *reg2);
            }
            else if (program[lineNumber][2] == "baNANAs")
            {
                //convert strings to numbers to compare >/<
                int64_t num1 = 0;
                for (size_t i = 0; (i < 64) && (i < reg1->size()); ++i)
                {
                    if ((*reg1)[i] == 'B' || (*reg1)[i] == 'A' || (*reg1)[i] == 'N' || (*reg2)[i] == 'S')
                    {
                        num1 <<= 1;
                    }
                    else if ((*reg1)[i] == 'b' || (*reg1)[i] == 'a' || (*reg1)[i] == 'n' || (*reg2)[i] == 's')
                    {
                        num1 <<= 0;
                    }
                }

                int64_t num2 = 0;
                for (size_t i = 0; (i < 64) && (i < reg2->size()); ++i)
                {
                    if ((*reg2)[i] == 'B' || (*reg2)[i] == 'A' || (*reg2)[i] == 'N' || (*reg2)[i] == 'S')
                    {
                        num1 <<= 1;
                    }
                    else if ((*reg2)[i] == 'b' || (*reg2)[i] == 'a' || (*reg2)[i] == 'n' || (*reg2)[i] == 's')
                    {
                        num1 <<= 0;
                    }
                }

                result = (num1 > num2);
            }
            else if (program[lineNumber][2] == "baNANaS")
            {
                //convert strings to numbers to compare >/<
                int64_t num1 = 0;
                for (size_t i = 0; (i < 64) && (i < reg1->size()); ++i)
                {
                    if ((*reg1)[i] == 'B' || (*reg1)[i] == 'A' || (*reg1)[i] == 'N' || (*reg2)[i] == 'S')
                    {
                        num1 <<= 1;
                    }
                    else if ((*reg1)[i] == 'b' || (*reg1)[i] == 'a' || (*reg1)[i] == 'n' || (*reg2)[i] == 's')
                    {
                        num1 <<= 0;
                    }
                }

                int64_t num2 = 0;
                for (size_t i = 0; (i < 64) && (i < reg2->size()); ++i)
                {
                    if ((*reg2)[i] == 'B' || (*reg2)[i] == 'A' || (*reg2)[i] == 'N' || (*reg2)[i] == 'S')
                    {
                        num1 <<= 1;
                    }
                    else if ((*reg2)[i] == 'b' || (*reg2)[i] == 'a' || (*reg2)[i] == 'n' || (*reg2)[i] == 's')
                    {
                        num1 <<= 0;
                    }
                }

                result = (num1 < num2);
            }

            if (!result)
            {
                lineNumber += 2;
            }

        }

        // write
        if (program[lineNumber][0] == "bananas")
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
            else
            {
                cout << bs2e(program[lineNumber], 1, translateList) << endl;
            }
        }

        // read
        else if (program[lineNumber][0] == "bananaS")
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

            getline(cin, *reg);

            // string raw;
            // cin >> raw;
            // (*reg) = e2bs(raw);
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


            /*if (program[lineNumber][1] == "baNAnAS")
            {
                (*reg) /=
            }
            else if (program[lineNumber][1] == "baNAnAs")
            {
                (*reg) *=
            }
            else if (program[lineNumber][1] == "baNAnas")
            {
                (*reg) +=
            }
            else if (program[lineNumber][1] == "baNAnaS")
            {
                (*reg) -=
            }
            else if (program[lineNumber][1] == "baNaNAs")
            {
                (*reg) <<=
            }
            else if (program[lineNumber][1] == "baNaNAS")
            {
                (*reg) >>=
            }
            else if (program[lineNumber][1] == "baNaNaS")
            {
                (*reg) &=
            }
            else if (program[lineNumber][1] == "baNaNas")
            {
                (*reg) |=
            }
            else if (program[lineNumber][1] == "baNanAS")
            {
                (*reg) ^=
            }
            else*/ if (program[lineNumber][1] == "baNanas")
            {
                (*reg) = "";
                for (size_t i = 2; i < program[lineNumber].size(); ++i)
                    (*reg) += program[lineNumber][i] + " ";//bs2e(program[lineNumber], 2, translateList);
                (*reg).pop_back();
            }
        }

        ++lineNumber;
    }
}
