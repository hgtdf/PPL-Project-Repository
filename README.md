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
                - ambiguity sa identifier, walang can include digitLiteral
                - may nakita rin ako sa Loop part sa document na sobra sobra ang lagay, di na ata need yung syntax don exampla lang ata need.

            Sa Program:
                - specific file type lang dapat ang input
                - output must be a FILE
                - gawing malloc yung size ng array
                - use finite automata (although I don't know how, let's research on this)
                    --applicable to sa lahat, lalo na at di natin mabasa yung logical operators and comments actually almost everything. major part to ng revision.
                - hiwalay ang keyword, reserved at noise words
                - constants and literals
                    -- kung integer dapat int lumalabas, if float, float, long, char string ...
                
                Syntax Analyzer or Parser(?) dapat magkaroon na ng first revision. Di ko alam anong hinahanap ni ma'am dito, can we ask other people in other groups. Baka kasi may namissout nanaman tayo sabihin na naman ni ma'am alam ng ibang group nye.