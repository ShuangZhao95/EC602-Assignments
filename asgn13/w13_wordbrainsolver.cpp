/*
 * =====================================================================================
 *
 *       Filename:  w13_wordbrainsolver.cpp
 *
 *    Description:  WordBrain game solver
 *
 *        Version:  1.0
 *        Created:  12/08/2016 08:46:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexander Oleinik (ax), alxndr@bu.edu
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
using namespace std;
/*
 * Gameboard Structure:
 * 4 e a v c
 * 3 v c s e
 * 2 e s v z
 * 1 w e f v
 *   1 2 3 4
*/
struct puzzle
{
    public:
        int dimension = 0;
        vector< vector<char> > board;
        void clear_board(int d);
};

void puzzle::clear_board(int d)
{
    dimension = d;
    board.clear();
    board.resize(dimension, vector<char>(d, 0));
}

int load_puzzle(puzzle *puz)
{
    puz->clear_board(4);
    puz->board[0] = {'n', 'i', 'b', 'a'};
    puz->board[1] = {'c', 'a', 'p', 't'};
    puz->board[2] = {'n', 'i', 'b', 'a'};
    puz->board[3] = {'n', 'w', 'm', 'n'};
    std::reverse(puz->board[0].begin(), puz->board[0].end());
    std::reverse(puz->board[1].begin(), puz->board[1].end());
    std::reverse(puz->board[2].begin(), puz->board[2].end());
    std::reverse(puz->board[3].begin(), puz->board[3].end());
}
int solve_puzzle(puzzle *puz,                   //The puzzle board 
                vector<int> *checkvec,          //The list of possible words 
                vector< pair<int, int> > sol,   //The list of cells used to solve
                int l,                          //The length of the search word
                int cellx, int celly            //The coordinate of the current cell
                )
{
    solve_puzzle(&puz, &checkvec, &sol, 
}
