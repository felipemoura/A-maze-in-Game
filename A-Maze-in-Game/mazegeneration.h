#ifndef MAZEGENERATION_H
#define MAZEGENERATION_H

#define MAZE_SIZE 30
#define NUMBER_OF_GENERATIONS 100
#define ZERO 0
#define INVALID -1

#define WALL 1
#define PATH 0

class MazeGeneration
{

private:
    int **maze;
    int size;

public:
    // Constructor
    MazeGeneration();

    // Destructor
    ~MazeGeneration();

    // Methods
    int **mazeGeneration();
    void workOnCell(int, int);
    int getPositionMaze(int,int);

    // Getters
    int **getMaze() const;
    int getSize() const;

    //Setters
    void setSize(int value);
};

#endif // MAZEGENERATION_H
