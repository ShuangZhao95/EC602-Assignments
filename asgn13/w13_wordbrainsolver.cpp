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
#include <fstream>
#define ALPHABETS 26
using namespace std;

/*
 * Gameboard Structure:
 * 4 e a v c
 * 3 v c s e
 * 2 e s v z
 * 1 w e f v
 *   1 2 3 4
*/

//A trie:[
struct node
{
    public:
        char me;
        struct node *parent;
        struct node *children[ALPHABETS];
};
/*
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
    reverse(puz->board[0].begin(), puz->board[0].end());
    reverse(puz->board[1].begin(), puz->board[1].end());
    reverse(puz->board[2].begin(), puz->board[2].end());
    reverse(puz->board[3].begin(), puz->board[3].end());
}
int solve_puzzle(puzzle *puz,                   //The puzzle board 
                node trie,                      //The current location in the trie
                vector<int> *checkvec,          //The list of possible words 
                map< pair<int, int>, char > sol,   //The list of cells used to solve
                int l,                          //The length of the search word
                int cellx, int celly            //The coordinate of the current cell
                )
{
    map< pair<int, int>, char > tsol = sol; 
    tsol[make_pair(x, y)] = trie.me;
    for(int x = (cellx -1 > 0) ? cellx -1: 0; 
            x <= (cellx+1 < puz->dimension) ? cellx +1 : puz->dimension -1 ; 
            x++)
    {
        for(int y = (celly -1 > 0) ? celly -1: 0; 
                y <= (celly+1 < puz->dimension) ? celly +1 : puz->dimension -1 ; 
                y++)
        {
            if(tsol[make_pair(x,y)]) continue;
            try
                char c = checkvec->at(x).at(y);
            catch
                continue;
            if(trie->children[puz->at(x).at(y)]){
                solve_puzzle(&puz, &(puz->at(x).at(y)), &tsol, l-1, x, y); 
            }
        }
    }
}
*/
int load_dictionary(string fn, node *trie)
{ 
    ifstream infile(fn);
    string s;
    int count;
    while( infile >> s )
    {
        count++;
        node * traverse = trie;
        if(trie->children[s.length()] == NULL)
            trie->children[s.length()] = (node){'0'+s.length(), traverse,NULL};
        traverse = traverse->children[s.length()];
        for(auto c: s)
        {
            if(traverse->children[c] == NULL)
                traverse->children[c] = (node){c, traverse};
            traverse = traverse->children[c];
        }
    }
    return count;
}

int main()
{
    node trie;
    load_dictionary("small_word_list.txt", &trie);
}
