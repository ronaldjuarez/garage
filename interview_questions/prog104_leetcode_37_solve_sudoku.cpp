#include <iostream>
#include <vector>
#include <cmath>
#include "helper.h"
using namespace std;

vector<char> getValidNumbers(vector<vector<char>>& board, int row, int col) {
	vector<char> candidates;
	if (board[row][col] != '.') return candidates;
	for (char val = '1'; val <= '9'; val++) {
		bool collision = false;
		for (int i = 0; i < 9; i++) {
			if (board[row][i] == val ||
				board[i][col] == val ||
				(board[row - row % 3 + floor(i / 3)][col - col % 3 + i % 3] == val)) {
				collision = true;
				break;
			}
		}
		if (!collision)
			candidates.push_back(val);
	}
	return candidates;
}

void isValidSudoku_rec(vector<vector<char>>& board, bool &foundSol) {
	int numrows = board.size();
	int numcols = board[0].size();
	int row, col, r, c;
	bool found;
	vector<char> candidates;
	found = false;
	for (int i = 0; i < numrows * numcols; i++) {
		r = i / numcols;
		c = i % numcols;
		if (board[r][c] == '.') {
			found = true;
			vector<char> newCandidates = getValidNumbers(board, r, c);
			if (candidates.size() == 0 || newCandidates.size() < candidates.size()) {
				candidates = newCandidates;
				row = r;
				col = c;
			}
		}
	}

	if (!found) {
        foundSol = true;
		return;
	}
	else {
		if (candidates.size() == 0)
			return;
	}

	for (int j = 0; j < candidates.size(); j++) {
		board[row][col] = candidates[j];
		isValidSudoku_rec(board,foundSol);
        if (foundSol == false)
		    board[row][col] = '.';
        else
            break;
	}
}

void isValidSudoku(vector<vector<char>>& board) {
    bool foundSol = false;
    isValidSudoku_rec(board, foundSol);
}

int main() {
	vector<vector<char>> board;
	board.push_back({ '5','3','.','.','7','.','.','.','.' });
	board.push_back({ '6','.','.','1','9','5','.','.','.' });
	board.push_back({ '.','9','8','.','.','.','.','6','.' });
	board.push_back({ '8','.','.','.','6','.','.','.','3' });
	board.push_back({ '4','.','.','8','.','3','.','.','1' });
	board.push_back({ '7','.','.','.','2','.','.','.','6' });
	board.push_back({ '.','6','.','.','.','.','2','8','.' });
	board.push_back({ '.','.','.','4','1','9','.','.','5' });
	board.push_back({ '.','.','.','.','8','.','.','7','9' });
	vector<vector<char>> board2{
			{'8','3','.','.','7','.','.','.','.'},
			{'6','.','.','1','9','5','.','.','.'},
			{'.','9','8','.','.','.','.','6','.'},
			{'8','.','.','.','6','.','.','.','3'},
			{'4','.','.','8','.','3','.','.','1'},
			{'7','.','.','.','2','.','.','.','6'},
			{'.','6','.','.','.','.','2','8','.'},
			{'.','.','.','4','1','9','.','.','5'},
			{'.','.','.','.','8','.','.','7','9'}
	};


    isValidSudoku(board);
    isValidSudoku(board2);
	print2DChar(board);
    print2DChar(board2);
	return 0;
}

