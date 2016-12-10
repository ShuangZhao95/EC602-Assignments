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
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
        bool ep = false;        // Endpoint?
};
struct puzzle
{
    public:
        int dimension = 0;
        vector< vector<char> > board;
        void clear_board(int d);
};

int solve_controller(puzzle *puz,
                    node *trie,
                    vector<int> lengths,
                    map<int, char> *sol,
                    vector<string> *words);
void puzzle::clear_board(int d)
{
    dimension = d;
    board.clear();
    board.resize(dimension, vector<char>(d, 0));
}

int load_puzzle(puzzle *puz)
{
    puz->clear_board(3);
    puz->board[0] = {'h', 'o', 's'};
    puz->board[1] = {'e', 'q', 'u'};
    puz->board[2] = {'e', 'r', 'a'};
    reverse(puz->board[0].begin(), puz->board[0].end());
    reverse(puz->board[1].begin(), puz->board[1].end());
    reverse(puz->board[2].begin(), puz->board[2].end());
}
int solve_puzzle(puzzle *puz,                   //The puzzle board 
                vector<int> lengths,            //The coordinate of the current cell
                node *trie,                     //The current location in the trie
                map< int, char > *sol,          //The list of cells used to solve
                int cellx, int celly,           //The coordinate of the current cell
                vector<string> *words           //The coordinate of the current cell
                )
{
    if(!trie)return false;
    std::cout << trie->me << std::endl;
    map< int, char > tsol;
    (*sol)[cellx+celly*puz->dimension] = trie->me;
    tsol.insert(sol->begin(), sol->end());
    for (const auto &p : (*sol)) 
        std::cout << "(" << p.first << ", " << p.second << "), ";
    cout << endl;
    if(trie->ep)
    {
        vector<int> tlengths = lengths;
        tlengths.erase(tlengths.begin());
        vector<string> twords;
        solve_controller(puz, trie, tlengths, sol, &twords);  
        return true;
    }
    int minx =  (cellx -1 > 0) ? cellx -1: 0;
    int miny =  (cellx -1 > 0) ? celly -1: 0;
    int maxx =  (cellx +1 < puz->dimension) ? cellx +1: puz->dimension-1;
    int maxy =  (celly +1 < puz->dimension) ? celly +1: puz->dimension-1;
    for(int x = minx; x <= maxx; x++) 
    {
        for(int y = miny; y <= maxy; y++) 
        {
            if(tsol.count(x+y*puz->dimension)) 
            {
                cout << x << "\t" << y << "\t" << "SKIP" << endl;
                continue;
            }
            char c;
            try{
                c = puz->board.at(x).at(y);
            }
            catch(std::out_of_range)
            {
                cout << "location in map does not exist" << endl;
                continue;
            }
            cout << x << "\t" << y << "\t" << c << endl;
            if(trie->children[c-'a']){
                if(solve_puzzle(puz, lengths, trie->children[puz->board.at(x).at(y)-'a'] , &tsol, x, y, words))
                {
                    sol->insert(tsol.begin(), tsol.end());
                    return true;
                }
            }
        }
    }
    cout << "found nothing here" << endl;
    return false;
}

int solve_controller(puzzle *puz,
                    node *trie,
                    vector<int> lengths,
                    map<int, char> *sol,
                    vector<string> *words)
{
    std::cout << "looking for word length: " << lengths.front() << std::endl;
    puzzle tpuz = (*puz);
    for (std::map<int,char>::iterator it=sol->end(); it!=sol->begin(); --it)
    {
        tpuz.board[it->first%tpuz.dimension].erase(tpuz.board[it->first%tpuz.dimension].begin() + it->first/tpuz.dimension);
        std::cout << "deleting element from: " << it->first%tpuz.dimension << " " << it->first/tpuz.dimension << " " <<  it->first << std::endl;

    }
    for(int x=0; x < tpuz.board.size(); x++)
    {
        for(int y=0; y < tpuz.board.at(x).size(); y++){
            std::cout << "\033[1;31mstarting at: \033[0m" << x << " " << y  << std::endl;
            map< int, char > tsol; 
            vector<string> twords;
            if(solve_puzzle(&tpuz, lengths, trie->children[lengths.front()]->children[tpuz.board.at(x).at(y)-'a'], &tsol, x, y, &twords))
            {
                words = &twords;
                return true;
            }
        }
    }
}

int load_dictionary(string fn, node *trie)
{ 
    ifstream infile(fn);
    string s;
    int count;
    while( infile >> s )
    {
        count++;
        if(trie->children[s.length()] == NULL)
            trie->children[s.length()] = new node;
            trie->children[s.length()]->parent = trie;
            trie->children[s.length()]->me = '0' + s.length(); 
        node * traverse = trie->children[s.length()];
        for(auto c: s)
        {
//            std::cout << c << std::endl;
//            std::cout << int(c -'a') << std::endl;
            if(traverse->children[c-'a'] == NULL)
                traverse->children[c-'a'] = new node;
                traverse->children[c-'a']->parent = traverse;
                traverse->children[c-'a']->me = c; 
            traverse = traverse->children[c-'a'];
        }
        traverse->ep = true;
    }
    return count;
}

int main()
{
    puzzle puz = puzzle();
    load_puzzle(&puz);
    node trie = node();
    load_dictionary("small_word_list.txt", &trie);
    map< int, char > sol;
    vector<int> lengths = {3,6};
    vector<string> words;
    solve_controller(&puz, &trie, lengths, &sol, &words);  
    for (const auto &p : sol) 
        std::cout << "sol[" << p.first << "] = " << p.second << '\n';
    cout << &sol << endl;
}
