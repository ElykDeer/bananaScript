from random import *
import re
from subprocess import call

flag = "flag{N0w_y0u_d0nt_s33_m3_4sking_YOU_why_I_cr34t3d_b4n4n4Scr1pt_Only_th3_truly_3nl1ght3n3d_c4n_und3rst4nd_th3_p0wer_w1th1n_b4n4n4Scr1pt}"

scriptNumber = 0

def phase3():
    #This will be written to a file
    f = open("muchbetterBible", "r") # Generated with www.github.com/KyleMiles/ScrapBook/BibleParser
    messyLines = list(f)

    cleanLines = []

    for line in messyLines:
        toCleanLine = line

        #Clean up the lines
        e = re.compile(r"(?:\~{5}).*?(?=~)")
        listOfMatches = e.findall(line)
        if (len(listOfMatches) > 0):
            e = re.compile(r".*?(?=~{5})")
            toCleanLine = e.findall(line)[0]

        myCleanLine = ""
        for char in toCleanLine:
            if char ==  '~':
                char = ' '
            if char == '\n':
                char = ''

            myCleanLine += char
        cleanLines.append(myCleanLine)

    return cleanLines

def bs2num(bs):
    num = ""
    for letter in bs:
        if letter.isupper():
            num += "1"
        elif not letter == ' ':
            num += "0"

    return num

def binToBS(bin):
    #For the place in each "bananas"
    place = 0
    #bananaScriptString:
    BSS = ""
    for digit in bin[::-1]:
        #Check if we're between bananaBytes
        if (len(BSS) % 8 == 0):
            BSS = " " + BSS
            place = 0

        #Uppercase is one in bananaScript
        if digit == '1':
            if place == 0:
                BSS = "S" + BSS
            elif place == 1 or place == 3 or place == 5:
                BSS = "A" + BSS
            elif place == 2 or place == 4:
                BSS = "N" + BSS
            elif place == 6:
                BSS = "B" + BSS

        #Lower case is zero in bananaScript
        elif digit == '0':
            if place == 0:
                BSS = "s" + BSS
            elif place == 1 or place == 3 or place == 5:
                BSS = "a" + BSS
            elif place == 2 or place == 4:
                BSS = "n" + BSS
            elif place == 6:
                BSS = "b" + BSS

        place += 1

    return BSS[:-1]

for char, place in zip(flag, range(len(flag))):
    theBibe = phase3()
    ourLine = randint(0, len(theBibe))
    line = theBibe[ourLine]
    theBibe[ourLine] = str(char) + " is in place " + str(place) + " of the flag"

    theBibe = " ".join(theBibe)
###################################################################################3

    #Seed the shuffle
    max = 100000.0
    numbers = [i/max for i in range(0, int(max))]
    shuffle(numbers)
    seed = numbers[0]

    answer = 'y'

    part1 = "translateList[\""
    part2 = "\"] = \""
    part3 = "\""
    ending = "\n"
    cpp = False
    if answer in "yesYesyESyeSyEsYEs":
        ending = "; "
        cpp = False

    listOfLetters = [chr(i) for i in range(32,127)]
    shuffle(listOfLetters, lambda: seed)

    listOfCommands = ["NEQ", "LESS", "MORE", "MOD", "DIV", "MUL", "SUB", "ADD", "RSHIFT", "LSHIFT", "AND", "XOR", "DEQ", "EQ", "IF", "WRITE", "READ", "JUMP",
                      "Reg1", "Reg2", "Reg3", "Reg4", "Reg5", "Reg6", "Reg7", "Reg8", "EXTEND"]
    shuffle(listOfCommands)

    #Set up what this is going to generate
    commandList = {}
    config = []
    translateList = {}
    extraNaners = []
    for a in ('B', 'b'):
        for b in ('A', 'a'):
            for c in ('N', 'n'):
                for d in ('A', 'a'):
                    for e in ('N', 'n'):
                        for f in ('A', 'a'):
                            for g in ('S', 's'):
                                naner = a + b + c + d + e + f + g
                                if (len(listOfLetters)):
                                    letter = listOfLetters.pop()
                                    if letter == "\\":
                                        translateList[letter] = naner
                                        translateList[naner] = "\\\\"
                                        config.append(part1 + naner + part2 + "\\\\" + part3 + ending)
                                        config.append(part1 + "\\\\" + part2 + naner + part3 + ending)
                                    elif letter == "\"":
                                        translateList[letter] = naner
                                        translateList[naner] = "\\\""
                                        config.append(part1 + naner + part2 + "\\\"" + part3 + ending)
                                        config.append(part1 + "\\\"" + part2 + naner + part3 + ending)
                                    else:
                                        translateList[naner] = letter
                                        translateList[letter] = naner
                                        config.append(part1 + naner + part2 + letter + part3 + ending)
                                        config.append(part1 + letter + part2 + naner + part3 + ending)

                                elif (len(listOfCommands)):
                                    command = listOfCommands.pop()
                                    if letter == "\\":
                                        translateList[letter] = naner
                                        translateList[naner] = "\\\\"
                                        config.append(part1 + naner + part2 + "\\\\" + part3 + ending)
                                        config.append(part1 + "\\\\" + part2 + naner + part3 + ending)
                                    elif letter == "\"":
                                        translateList[letter] = naner
                                        translateList[naner] = "\\\""
                                        config.append(part1 + naner + part2 + "\\\"" + part3 + ending)
                                        config.append(part1 + "\\\"" + part2 + naner + part3 + ending)
                                    else:
                                        translateList[naner] = command
                                        translateList[command] = naner
                                        commandList[command] = naner
                                        config.append(part1 + naner + part2 + command + part3 + ending)
                                        config.append(part1 + command + part2 + naner + part3 + ending)

                                else:
                                    extraNaners.append(naner)

    #save

    f = open("banana.config", 'w')
    f.writelines(config)
    f.close()

    f = open("banana.defs", 'w')
    for command, nana in commandList.items():
        f.write("#define " + command + ' "' + nana + '"\n')

    f.write("#define REGISTER1 \"" + translateList["Reg1"] + '"\n')
    f.write("#define REGISTER2 \"" + translateList["Reg2"] + '"\n')
    f.write("#define REGISTER3 \"" + translateList["Reg3"] + '"\n')
    f.write("#define REGISTER4 \"" + translateList["Reg4"] + '"\n')
    f.write("#define REGISTER5 \"" + translateList["Reg5"] + '"\n')
    f.write("#define REGISTER6 \"" + translateList["Reg6"] + '"\n')
    f.write("#define REGISTER7 \"" + translateList["Reg7"] + '"\n')
    f.write("#define REGISTER8 \"" + translateList["Reg8"] + '"\n')

    f.write("#define NEGATIVE \"" + translateList["-"] + '"\n')
    f.close()

    #################
    inputString = theBibe
    translated = ""
    for command in inputString.split(' '):
        try:
            translated += commandList[command] + " "
        except:
            for char in command + " ":
                try:
                    translated += translateList[char] + " "
                except:
                    print("Could not translate character '" + char + "'.")
    bananaBibe = translated

    #part one
    inputString = "Reg1 EQ "
    translated = ""
    for command in inputString.split(' '):
        try:
            translated += commandList[command] + " "
        except:
            for char in command + " ":
                try:
                    translated += translateList[char] + " "
                except:
                    print("Could not translate character '" + char + "'.")
    partOne = translated

    #part four
    inputString = "WRITE Reg1"
    translated = ""
    for command in inputString.split(' '):
        try:
            translated += commandList[command] + " "
        except:
            for char in command + " ":
                try:
                    translated += translateList[char] + " "
                except:
                    print("Could not translate character '" + char + "'.")
    partTwo = translated

    script = partOne + bananaBibe + '\n' + partTwo + ' '

    #Save script
    f = open("HSF/banana" + str(place*place) + ".script", 'w')
    f.write(script)
    f.close()

    call(["make"])
    call(["cp", "monkeyDo", "HSF/monkeyDo" + str(randint(0, 10000000))])
    call(["make", "clean"])
