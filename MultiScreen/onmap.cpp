#include "onmap.h"


OnMap::OnMap()
{

    heightGame=400;
    widthGame=400;
    sizeMaze=20;
    sizePlayer=20;
    player1= new Player(100, 100, 20, 20);// have to replace it with the Game value
    player2= new Player(100, 100, 20, 20);


    int i,j;
    for (i=0; i<20; i++){
        for (j=0; j<20; j++){
            CurrentMap[i][j] = 0;

        }
    }
    CurrentMap[1][1]=1;


}
void OnMap::Update()
{
//First we ask the players for where they want to go.
//Call Collide(
    player1->desiredPosition(CurrentMap);
    player2->desiredPosition(CurrentMap);
    //Where to do the collisions?

}
void OnMap::Collide()
{
    //Do for all players
        //While there is no collision for any square:
            //Do for all corner:
                //Get the square coordinates of the player.
                    //Square=Map(Corner Coordinates)
                    //if it is a wall
                        //get on wich size the player is
                        //go back to the border

                    //if it is a bonus do bonus.player(num_bonus)


}


