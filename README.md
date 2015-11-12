# XnOs
XnOs(also known as Xs and Os) is a 2-player strategy game played on 4 X 4 board in which a player
has to get 4 stones of his color in a row either horizontally, vertically or diagonally
in order to win. Here we have 'X' as black stone and '0' as white stone.

##Build

XnOs is build on ncurses graphics library, So you'll be needing ```ncurses-devel``` library
[if you already have it, you can skip step 2]

 - Open terminal (Gnome) or Konsole (KDE)
 - Copy and paste this command:
	```sudo apt-get install ncurses-dev```
	or
	```sudo aptitude install libncurses5-dev```
 - compile using
    ```g++ *.cpp -lncurses -o XnOs```
 - run command ``./XnOs```
 - select "play" from <main menu>
 - choose your mode: easy/hard  
 - play the game


NOTE: You may optionally follow [these](http://geeksww.com/tutorials/operating_systems/linux/tools/how_to_download_compile_and_install_gnu_ncurses_on_debianubuntu_linux.php) instructions to build ncurses from source ;)


##What is it?

XnOs ia a varient of m,n,k game in which two players take turns in placing a stone/symbol of 
their color on an m×n board, the winner being the player who first gets k stones of their own color/symbol 
in a row, horizontally, vertically, or diagonally. m,n,k-game is also called a k-in-a-row game on m×n board. 
Thus,tic-tac-toe is the 3,3,3-game and XnOs is a 4-4-4 game.

##Rules

 - Player X plays first placing a “X” at any cell on the board.
 - Player 0 plays next placing a “0” at any unoccupied cell.
 - Each player takes turns in placing the respective symbol on the unoccupied cells.
 - The player with 4 crosses (X) or 4 zeroes (0) along a row either horizontally, vertically or diagonally wins the game.
 - If no such occurrence takes place, the game ends in a draw.

##Board Description

A typical board for XnOs is as shown below:

[<img src="https://www.googledrive.com/host/0B4MMNHlRfGSzYmVpbG94bkg0WlE">](Output)

The board contains 4 rows and 4 columns respectively, with a total of 16 cells in it. Each
player is supposed to place his symbol in the respective cell.

##Logic

This game is primarily developed on the brute-force-approach. The Computer that plays against a human user, basically finds each and
every possible move and makes final decision to place his symbol. Current game has 2 possible modes.

 - easy
 - hard

In EASY mode, computer simply finds all the possible empty cells and 'randomly' put his symbol on any of them thus making a good chance for human user to win. 
The mode was build during the initial development phase so I decided to keep it in the final version as well. 
Hard mode is a more sophisticated stage that could increase the sense of competitiveness.
Approach followed to implement the same is described below.

##Approach

Since the board size is small, I included some variables to represent both player's and computer's statistics

| Variable  | Represents    |  Variable | Represents       |  Variable | Represents        |
|-----------|---------------|-----------|------------------|-----------|-------------------|
| pr1       |  Player's-row-1 | pc1       |  Player's-column-1 | pd1       | Player's-diagonal-1 |
| Pr2       |  Player's-row-2 | pc2       |  Player's-column-1 | pd2       | Player's-diagonal-2 |
| pr3       |  Player's-row-3 | pc3       |  Player's-column-1 |
| pr4       |  Player's-row-4 | pc4       |  Player's-column-1 |


| Variable  | Represents        |  Variable | Represents           |  Variable | Represents            |
|-----------|-------------------|-----------|----------------------|-----------|-----------------------|
| cr1       |  Computer's-row-1 | cc1       |  Computer's-column-1 | cd1       | Computer's-diagonal-1 |
| cr2       |  Computer's-row-2 | cc2       |  Computer's-column-1 | cd2       | Computer's-diagonal-2 |
| cr3       |  Computer's-row-3 | cc3       |  Computer's-column-1 |
| cr4       |  Computer's-row-4 | Cc4       |  Computer's-column-1 |

[<img src="https://www.googledrive.com/host/0B4MMNHlRfGSzVHAyVVBEVU96X3M">](Output)


Now the human-user will win if any of these conditions are fulfilled.
```
pr1= =4||pr2= =4||pr3= =4||pr4= =4
or
pc1= =4||pc2= =4||pc3= =4||pc4= =4
or
pd1= =4||pd2= =4
```
and the computer will win if any these conditions are fulfilled.
```
cr1= =4||cr2= =4||cr3= =4||cr4= =4
or
cc1= =4||cc2= =4||cc3= =4||cc4= =4
or
cd1= =4||cd2= =4
```

**for example:**

if ```pr1= = 4``` that would mean, player's row 1 is full and player has WON the game. Likewise,

if ```cd1= = 4``` that would mean, computer's diagonal 1 is full and computer has WON the
game.

## Deciding computer's current move:

The computer will decide its current move according to following criteria:

- Initially, it'll find the maximum value out of set ```s1={pr1,pr2,pr3,pr4,pc1,pc2,pc3,pc4,pd1,pd2}```
- it will then place its symbol to any of the cell which is 'vacant' and which belongs to
the element whose value is maximum out the set.

## Illustration

[<img src="https://www.googledrive.com/host/0B4MMNHlRfGSzelVhaFZMcVFETTQ">](Output)

The 8th move of game is supposed to be played from computer's side.
For this, it selects the maximum element from set, which is pr1 and places its symbol on
any of the cell which is empty i.e. 14. Thats how the entire Decision Making is achieved.

## Contributions

1. [**Fork**](https://help.github.com/articles/fork-a-repo) XnOs and clone it on your system.
2. Create a new branch out off `master` for your fix/feature. `git checkout new-feature master`
3. Add/Modify code.
4. Write equivalent documentation.
5. Push your branch.
6. Pull request. :)

