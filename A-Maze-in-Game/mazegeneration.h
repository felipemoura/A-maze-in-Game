#ifndef MAZEGENERATION_H
#define MAZEGENERATION_H

#define MAZE_SIZE 30

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

    // Getters
    int **getMaze() const;
    int getSize() const;

    //Setters
    void setSize(int value);
};

#endif // MAZEGENERATION_H
