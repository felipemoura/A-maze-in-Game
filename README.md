A-maze-in-Game
==============
@Project of Software Engineering

@Authors
	Diego Lima Santana
	Felipe Moreira Moura
	Lucas Pereira Monteiro
	Stanislas Heili

CSE 361 - Software Engineering
Department of Computer Science and Engineering
University of Nebraska Lincoln
==============

THE DESCRIPITION

The A-maze-in-Game is a project of Software Engineering for the Fall Semester of 2014. 

This project consists of the development of a multiplayer game using Software Engineering Concepts. The game's proposal is a race inside a maze, between two players. The main goal of player (user) will be to get out of it as quick as possible.

Definitions, Acronyms, and Abbreviations
	*   AMIG – A-maze-in-Game

The supported OS are the following: Ubuntu, Mac OS and Windows Seven.

The project is built on the Qt Creator IDE. Therefore, to run the program it is needed to have the Qt Creator installed. After openning the IDE, import the project and then it is ready to run.

Inside the IDE, select the project folder and then hit the Run button (located in the Left side of the window for Mac's). Then, the program will invoke the main() method, located in the main.cpp file, which will start the main window.

==============
INTRUCTIONS

Two players are required.

Player 1 has the red skin character, and its movement is the arrow keys:

								UP 		= up
								DOWN 	= down
								LEFT 	= left
								RIGHT 	= right


Player 2 has the blue skin character, and its movement is the arrow keys:

								W or Z	= up
								S 		= down
								A or Q 	= left
								D		= right

Player can't walk on the wall.
Player only can walk on the path.

A path to exit is always provided.								

Both players start with no Bonus.

Player can have slow bonus, fast bonus ou no bonus. 
Player can have only one bonus per time !

If a player steps on the bonus:
								* Speed Bonus : Double the player velocity for 5 seconds
								* Slow Bonus : Divide the player velocity for 5 seconds


If a player steps on the exit the game is over.
The players who steps on the exit is the winner.

The reset button can restart the game.

Another maze will be generated if restart is pushed and players will start in the stating position again.


==============
THE CODE

Included:
			.md:
				README.md

			.h:
				mainwindow.h
				mazegeneration.h
				onmap.h
				player.h
				position.h

			.cpp:
				main.cpp
				mainwindow.cpp
				mazegeneration.cpp
				onmap.cpp
				player.cpp
				position.cpp

			.pro:
				A-Maze-in-Game.pro


How it works:

- The system starts from with the main function which calls the QApplication and them the programs starts.

- After calling the QApplication all the necessary objects are inicialized. 
- The objects are inicialized in the mainwindow class and the objects necessary are:

	-	MainWindowClass Object

	-	OnMap Object
		- Player1 Object
			- Position Object
		- Player2 Object
			- Position Object

	-	Ui Object

	-	QSet keys Object
	
- With all this object the game can works perfect.

- All the game is handled by the MainWindowClass Object which will iterate if all objects in the memory and the user interface (UI Object)

- The game will always run until the exit button is hit, or an unexpected behavior happens, or if the OS kill the process for no reason.

- Please enjoy playing, if a bug is found, report to the authors.
