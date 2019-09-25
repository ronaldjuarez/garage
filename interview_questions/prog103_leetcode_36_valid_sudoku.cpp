#include <iostream>
#include <vector>
#include <cmath>
#include "helper.h"
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col) {
	char currVal = board[row][col];
	for (int i = 0; i < 9; i++) {
		if (i != col && board[row][i] == currVal) return false;
		if (i != row && board[i][col] == currVal) return false;
		int r = row - row % 3 + floor(i / 3);
		int c = col - col % 3 + i % 3;
		if (r != row && c != col && board[r][c] == currVal) return false;
	}
	return true;;
}

bool isValidSudoku(vector<vector<char>>& board) {

	int numRows = board.size();
	if (numRows == 0) return false;
	int numCols = board[0].size();

	for ( int i = 0; i < numRows ; i++){
		for (int j = 0; j < numCols; j++){

			if (board[i][j] != '.' && !isValid(board,i,j)) return false;
		}
	}	
	return true;
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



	std::cout << isValidSudoku(board) << endl;
	std::cout << isValidSudoku(board2) << endl;
	return 0;
}


/*

https://www.youtube.com/watch?v=JzONv5kaPJM


function getCandidates(board, row, col):
	# For some empty cell board{row}{col}, what possible
	# characters can be placed into this cell
	# that aren't already placed in the same row,
	# column, and sub-board?

	# At the beginning, we don't have any candidates
	candidates = {}

	# For each character add it to the candidate list
	# only if there's no collision, i.e. that character
	# doesn't already exist in the same row, column
	# and sub-board. Notice the top-left corner of (row, col)'s
	# sub-board is (row - row%3, col - col%3).
	for chr from '1' to '9':
		collision = false;
		for i from 0 to 8:
			if (board{row}{i} == chr ||
				board{i}{col} == chr ||
				board{(row - row % 3) + floor(i / 3)}{(col - col % 3) + i % 3} == chr):
					collision = true
					break

		if (!collision):
			candidates.push(chr)

	return candidates

function sudokuSolve(board):
	# For each empty cell, consider 'newCandidates', the
	# set of possible candidate values that can
	# be placed into that cell.

	row = -1
	col = -1
	candidates = null

	for r from 0 to 8:
		for c from 0 to 8:
			if (board{r}{c} == '.'):
				newCandidates = getCandidates(board, r, c)
				# Then, we want to keep the smallest
				# sized 'newCandidates', plus remember the
				# position where it was found
				if (candidates == null OR newCandidates.size() < candidates.size()):
					candidates = newCandidates
					row = r
					col = c

	# If we have not found any empty cell, then
	# the whole board is filled already
	if (candidates == null):
		return true

	# For each possible value that can be placed
	# in position (row, col), let's
	# place that value and then recursively query
	# whether the board can be solved.  If it can,
	# we are done.
	for val in candidates:
		board[row][col] = val
		if (sudokuSolve(board)):
			return true
		# The tried value val didn't work so restore
		# the (row, col) cell back to '.'
		board{row}{col} = '.'

	# Otherwise, there is no value that can be placed
	# into position (row, col) to make the
	# board solved
	return false


*/