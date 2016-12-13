#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ALPHABETS 26
using namespace std;
#define DEBUG(n, m)// cout<< "DEBUG(code " << n << ") " << m ;

struct node
{
	public:
		char me;
		struct node *parent;
		struct node *children[ALPHABETS];
		string word = "";
		bool ep = false;        // Endpoint?
};
struct puzzle
{
	public:
		int dimension = 0;
		vector< vector<char> > board;
		void clear_board(int d);
		void display(int n);
};

int solve_controller(puzzle *puz,
		node *trie,
		vector<int> lengths,
		map<int, char> sol,
		vector<string> *words);
node * root;
void puzzle::clear_board(int d)
{
	dimension = d;
	board.clear();
	board.resize(dimension, vector<char>(d, 0));
}

int load_puzzle(puzzle *puz)
{
	puz->clear_board(5);
	puz->board[0] = {'v','i','t','t','m'};
	puz->board[1] = {'a','p','o','s','i'};
	puz->board[2] = {'n','v','a','m','i'};
	puz->board[3] = {'m','e','r','e','p'};
	puz->board[4] = {'o','o','r','d','b'};
	reverse(puz->board[0].begin(), puz->board[0].end());
	reverse(puz->board[1].begin(), puz->board[1].end());
	reverse(puz->board[2].begin(), puz->board[2].end());
	reverse(puz->board[3].begin(), puz->board[3].end());
	reverse(puz->board[4].begin(), puz->board[4].end());
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
	map< int, char > tsol;
	tsol.insert(sol->begin(), sol->end());
	(tsol)[cellx+celly*puz->dimension] = trie->me;
	DEBUG(1337, trie->me);
	for (const auto &p : (*sol)) 
	if(trie->ep)
	{
		DEBUG(1338, trie->word << endl);
		vector<int> tlengths = lengths;
		tlengths.erase(tlengths.begin());
		vector<string> twords = *words;
		twords.push_back(trie->word);
		DEBUG(1102,"twords is");
		for (const auto &p : (twords)) 
		if(solve_controller(puz, root, tlengths, tsol, &twords))
		{
			*words = twords;
			*sol = tsol;
			return true;
		}
		else
			return false;
	}
	int minx =  (cellx -1 > 0) ? cellx -1: 0;
	int miny =  (celly -1 > 0) ? celly -1: 0;
	int maxx =  (cellx +1 < puz->dimension) ? cellx +1: puz->dimension-1;
	int maxy =  (celly +1 < puz->dimension) ? celly +1: puz->dimension-1;
	for(int x = minx; x <= maxx; x++) 
	{
		for(int y = miny; y <= maxy; y++) 
		{
			if(tsol.count(x+y*puz->dimension)) 
				continue;
			char c;
			try{
				c = puz->board.at(x).at(y);
			}
			catch(std::out_of_range)
			{
				continue;
			}
			if(trie->children[c-'a']){
				if(solve_puzzle(puz, lengths, trie->children[puz->board.at(x).at(y)-'a'] , &tsol, x, y, words))
				{
					sol->insert(tsol.begin(), tsol.end());
					return true;
				}
			}
		}
	}
	return false;
}

int solve_controller(puzzle *puz,
		node *trie,
		vector<int> lengths,
		map<int, char> sol,
		vector<string> *words)
{
	if(lengths.size() == 0)
	{
		return true;
	}
	puzzle tpuz = *puz;
	DEBUG(17000, "");
	for (std::map<int,char>::reverse_iterator it=sol.rbegin(); it!=sol.rend(); ++it)
	{
		tpuz.board[it->first%tpuz.dimension].erase(tpuz.board[it->first%tpuz.dimension].begin() + it->first/tpuz.dimension);
	}
	for(int x=0; x < tpuz.board.size(); x++)
	{
		for(int y=0; y < tpuz.board.at(x).size(); y++){
			DEBUG(1200,"L"<<lengths.front()<<": Checking " << x << ", " << y <<  " " << tpuz.board.at(x).at(y) <<  endl);
			map< int, char > tsol; 
			vector<string> twords = *words;
			if(solve_puzzle(&tpuz, lengths, trie->children[lengths.front()]->children[tpuz.board.at(x).at(y)-'a'], &tsol, x, y, &twords))
			{
				*words = twords;
				DEBUG(17000,"words is");
				tpuz.display(17004+lengths.front());
				return true;
			}
		}
	}
	return false;
}

int load_dictionary(string fn, node *trie)
{ 
	ifstream infile(fn);
	string s;
	int count;
	while( infile >> s )
	{
		if(s.length() > ALPHABETS)
			continue;
		count++;
		if(trie->children[s.length()] == NULL)
		{
			trie->children[s.length()] = new node;
			trie->children[s.length()]->parent = trie;
			trie->children[s.length()]->me = '0' + s.length(); 
		}
		node * traverse = trie->children[s.length()];
		for(auto c: s)
		{
			if(traverse->children[c-'a'] == NULL)
			{
				traverse->children[c-'a'] = new node;
				traverse->children[c-'a']->parent = traverse;
				traverse->children[c-'a']->me = c; 
			}
			traverse = traverse->children[c-'a'];
		}
		traverse->ep = true;
		traverse->word= s;
	}
	return count;
}

int main()
{
	puzzle puz = puzzle();
	load_puzzle(&puz);
	node trie = node();
	load_dictionary("mega_word_list.txt", &trie);
	root = &trie;
	map< int, char > sol;
	vector<int> lengths = {4,7,7,7};
	vector<string> words;
	solve_controller(&puz, &trie, lengths, sol, &words);
	for (const auto &p : words) 
		cout << p <<" " ;
	cout <<  endl;
}
