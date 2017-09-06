for aNum in range(2):
    aLet = ''
    if aNum == 0:
        aLet = 'B'
    if aNum == 1:
        aLet = 'b'

    for bNum in range(2):
        bLet = ''
        if bNum == 0:
            bLet = 'A'
        if bNum == 1:
            bLet = 'a'

        for cNum in range(2):
            cLet = ''
            if cNum == 0:
                cLet = 'N'
            if cNum == 1:
                cLet = 'n'


            for dNum in range(2):
                dLet = ''
                if dNum == 0:
                    dLet = 'A'
                if dNum == 1:
                    dLet = 'a'

                for eNum in range(2):
                    eLet = ''
                    if eNum == 0:
                        eLet = 'N'
                    if eNum == 1:
                        eLet = 'n'

                    for fNum in range(2):
                        fLet = ''
                        if fNum == 0:
                            fLet = 'A'
                        if fNum == 1:
                            fLet = 'a'

                        for gNum in range(2):
                            gLet = ''
                            if gNum == 0:
                                gLet = 'S'
                            if gNum == 1:
                                gLet = 's'

                            print aLet + bLet + cLet + dLet + eLet + fLet + gLet
