# [UltimateTicTacToe](https://github.com/PatrykFlama/UltimateTicTacToe)
## [Game rules](https://www.thegamegal.com/2018/09/01/ultimate-tic-tac-toe/)
Ultimate Tic Tac Toe (UTTT) is a modification of normal Tic Tac Toe (TTT), which puts smaller TTT boards in cells of one bigger TTT board. \
Players play in smaller boards according to normal TTT rules. The one who won game in smaller board conquers that board. To win the game you have to conquer a row/column/diagonal of smaller boards.\
Player can start the game in any of the smaller boards, and make move in it (according to normal TTT rules). Then the other player must make a move in the board positioned same way as the freshly made move.\
For example, if the first player made a move in the board in the upper right corner in the lower left cell, the second player must now play in the board in the lower left corner. If he can't do that (the gameplay of given board has already been completed), then he can choose any board.\
If small board game has been won, then the player who won it claims square with this smaller game on the big board.

## How to launch
Tested on Windows 11, version 10.0.22621 (without NCurses GUI)\
Tested on Ubuntu 22.04.1 LTS on WSL\
In termianl UI mode should work on all operating systems, in NCurses GUI mode should work on all OSs with NCurses (so not on Windows).\
To run game simply execute _run.bat [ui mode g(default)/t]_ file located in main folder. The game will compile and run. Other option is to use gcc and compile all .c files in _src_ folder.\
You can also use makefile: _make main_ or _make uttt_.

## How to 'use'
In terminal UI mode to input your move enter big board row and column followed by small board row and column.\
In NCurses GUI mode just use arrow keys to select proper small board and cell.

## Concept
Rough idea is shown with graph on the [whiteboard](#whiteboard).

## Libraries
Essential libraries for this project are: stdbool.h, stdio.h, stdlib.h, time.h\
For GUI NCurses library has been used.

## Implementation
All code has been wrote in object-like style (as far as C language allows for it), to help organize all modules and make it easier to read, debug, add features, etc. 

## Whiteboard
[Bitpaper](https://bitpaper.io/go/UltimateTicTacToe/hS4iuuHld)
