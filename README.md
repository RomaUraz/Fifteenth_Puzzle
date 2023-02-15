
                     Fifteenth Puzzle
                           v. 1.0

                        done by Roman Urazbakiyev
                      (group B22, Vinnytsia IT-Academy)


                                                           task obtained: 09.01.2023
                                                           Pre-defence:
                                                           Teacher 1
                                                           Defence:
                                                           Teacher 2

                                  CONTENTS

              1. System requirements
              2. About game "Fifteenth Puzzle" (general rules)
              3. User guide
              4. Programmer instruction
              5. About the author


              1. System requirements

Operating system: DOS or Windows.

Hardware requirements: user (programmer) requires

- processor: Pentium Processor
- RAM: 640 Kb
- Hard Disc: 1 Gb

              2. About game "Fifteenth Puzzle"
                          (rules)

The game of 15 is a 4 x 4 board with 15 tiles numbered from 1 to 15. 
Cell 16 is empty. The essence of the game is to move the tiles one by one to
assemble a puzzle so that all the tiles afe located in order from 1 to 15.

The game begins with the fact that all numbers are 
located in random order on the playing field. And you have to put them in the right
position.

There are also other variations of the correct ending of the game. 
For example, you can assemble a puzzle so that each side of the product 
has the same sum.


              3. User guide
1. Find and run file "15 Puzzle" in Visual Studio or compiler.
2. On the screen will apear game board with tiles in random position.
3. Description below the board shows wich move you can do.
4. Use that hint and start the game.
5. When the puzzle is solved press "y" to play again and "n" to quit.

              4. Programmer instruction

The project was written on C++.
Advantages of C++: 
- Portability: C++ is one of the most used and portable to different platforms, 
almost any type of computer and operating system. 
- Brevity: code written in C++ is very short in comparison with other languages.
- Modular programming: applications written on C++ can be made up of several source 
code files which are compiled separately and then linked together. 
This characteristic allows to link C++ code with the one written in  other languages 
(for example, Assembler).
Speed: The resulting code from a C++ compilation is very efficient due to the reduced
size of the language itself.

Project is a single cpp-unit which contains all necessary algorithms and functions.

Find and open the file Kalah.cpp in folder Kalah. For edition, debugging and 
compiling program code you may use C++ compilers such as MS Visual Studio, 
Visual C++, C++ Builder, Borland C++, Dev C++ and similar.

Main functions
- void play() - general function responsible for activating a game;
- void createBrd() - responsible for creation and generating meanings on the field;
- void drawBrd() - making a gaming field and drawing gaming board 4 x 4;
- void move() - moving tiles on the gaming field;
- void getCandidates() - define which tiles can be moved;
- void getMove(){vector<int>;getCandidates(v) - responsible for moving tiles and
check with tile will be moved;
- void getTiles(vector<int> &p, vector<int> &v) - return tiles from the field for 
move them;
- int main(int argc, char*, argv[]) - call class p15;
- getTiles(p, v) - get tiles from the field;
- bool isDone() - check if meanings had situated in the right order and finish the 
game;


                 5. About author

 This project was done by Roman Urazbakiyev - Vinnitsya IT-Academy student
(group B22 Green, January 2023).      
























