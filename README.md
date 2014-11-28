A-maze-in-Game
==============

@Project of Software Engineering

@Authors
	Diego Lima Santana
	Felipe Moreira Moura
	Lucas Pereira Monteiro
	Stanislas Heili

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
