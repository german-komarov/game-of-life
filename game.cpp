#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cstdlib>
#include "include/SDL2/SDL.h"
#include "Board.h"
#include "constants.h"

using namespace std;

bool isAlive(
        std::array<std::array<int, GAME_HEIGHT>, GAME_WIDTH>& game,
        const int x,
        const int y);


int main() {
    Board screen;
    std::array<std::array<int, GAME_HEIGHT>, GAME_WIDTH> display {};
    std::array<std::array<int, GAME_HEIGHT>, GAME_WIDTH> swap {};

    // Create random points
    //
    for(auto& row : display)
        std::generate(row.begin(), row.end(), []() { return rand() % 10 == 0 ? 1 : 0; });


    while(true)
    {
        // Check for alive points
        //
        for(int i = 0; i < GAME_WIDTH; ++i)
        {
            for(int k = 0; k < GAME_HEIGHT; ++k)
            {
                swap[i][k] = isAlive(display, i, k) ? 1 : 0;
            }
        }

        // Draw
        //
        for(int i = 0; i < GAME_WIDTH; ++i)
        {
            for(int k = 0; k < GAME_HEIGHT; ++k)
            {
                if(swap[i][k])
                {
                    screen.drawpixel(i,k);
                }
            }
        }

        // Swap buffers
        //
        std::copy(swap.begin(), swap.end(), display.begin());

        // Display to screen
        //
        screen.update();
        SDL_Delay(20);
        screen.input();
        screen.clearpixels();


    }
}


bool isAlive(
        std::array<std::array<int, GAME_HEIGHT>, GAME_WIDTH>& game,
        const int x,
        const int y)
{

    int alive = 0;

    // testing the left
    if(x > 0 && game[x-1][y] == 1) alive+=1;
    // testing the right
    if(x < GAME_WIDTH-1 && game[x+1][y] == 1) alive+=1;
    // testing top
    if(y > 0 && game[x][y-1] == 1) alive+=1;
    // testing bottom
    if(y < GAME_HEIGHT-1 && game[x][y+1] == 1) alive+=1;


    // testing top left
    if(y > 0 && x > 0 && game[x-1][y-1] == 1) alive+=1;
    // testing top right
    if(y > 0 && x < GAME_WIDTH-1 && game[x+1][y-1] == 1) alive+=1;
    // testing bottom left
    if(y < GAME_HEIGHT-1 && x > 0 && game[x-1][y+1] == 1) alive +=1;
    // testing bottom right
    if(y < GAME_HEIGHT-1 && x < GAME_WIDTH-1 && game[x+1][y+1] == 1) alive+=1;

    // alive and fewer than 2 die
    if(game[x][y] == 1 && alive < 2) return false;
    // alive and 2 or 3 then live
    if(game[x][y] == 1 && (alive == 2 || alive == 3)) return true;
    // more than 3 live die
    if(alive > 3) return false;
    // 3 alive and point is dead, come to life
    if(game[x][y] == 0 && alive == 3) return true;

    return false;

}