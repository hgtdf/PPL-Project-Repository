# Principles of Programming Language Project

This will be the repository for our codes for PPL.

alphalex is our file currently FILE handling pa lang laman niya.
lexiana has the codes we need, naiayos ko na rin yan na gumagana na yung identifier. problema lang is di pa niya nababasa yung delimiters.
alphareader keme lang to pinageexperimentuhan ko codes

Updates:
01/27/22 : alphalex.c can now read files. lahat ng content ng file naililipat na sa char array aka Strings

To be done:
- yung laman ng file seems to be not being converted in a char array (string). find a way na maging char array yung content ng file, para tanggapin siya ng lexical analyzer natin. yung identifier ng lexical analyzer fixed na (ata). try to make the file run and see ano pang kulang (transfer the contents of lexiana to alphalex). read and understand the code. refresh your knowledge in c. pasahan na ng first revision guys tomorrow. thank you :>

02/08/2022 : alphareader.c is now our primary file many features are now integrated in it. refurnishing na lang.

02/09/2022: lexiana.c is our official file that is to be passed to ma'am ria

02/10/2022: Things to be updated (from our presentation with ma'am)

            Sa document:
                - ambiguity sa identifier, walang can include digitLiteral, ang comments same syntax with integer division
                - may nakita rin ako sa Loop part sa document na sobra sobra ang lagay, di na ata need yung syntax don exampla lang ata need.
                - pakitanggal yung ibang noise words, hence na lang ang itira. so gagawa ulit tayo ng automata.
                - ipasok si true and false

            Sa Program:
                - specific file type lang dapat ang input (shane)
                - output must be a FILE (miguel)
                - gawing malloc yung size ng array (nina)
                - use finite automata (although I don't know how, let's research on this)
                    --applicable to sa lahat, lalo na at di natin mabasa yung logical operators and comments actually almost everything. major part to ng revision.     - howell, vincent, jericho
                - hiwalay ang keyword, reserved at noise words --no one
                - constants and literals
                    -- kung integer dapat int lumalabas, if float, float, long, char string ... (jessie)
                
                Syntax Analyzer or Parser(?) dapat magkaroon na ng first revision. Di ko alam anong hinahanap ni ma'am dito, can we ask other people in other groups. Baka kasi may namissout nanaman tayo sabihin na naman ni ma'am alam ng ibang group nye.

To do: (Deadline: By monday 02/15/2022)         --MAIN TASK IS TO REVISE THE DOCUMENT--
    - palitan ang comments or integer division? /- line comment /*                      - vincent
    - tanggalin yung ibang noise words itira lang hence.                                - nina
    - pakisama nga rin sa machine yung comments, pang dulo na lang siya siguro.         - vincent
    - ipasok si true and false sa reserved words.                                       - howell
    - study your respective parts sa programming then we update each everyone on monday.
    - symbol table
    - meet ulit by monday (1:30 PM NLP Time)
