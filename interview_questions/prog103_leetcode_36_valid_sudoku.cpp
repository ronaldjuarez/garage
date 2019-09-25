#include <iostream>
#include <vector>
#include <cmath>

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

bool isValidSudoku(vector<vector<char>>& board) {
	int numrows = board.size();
	int numcols = board[0].size();
	int row, col;
	vector<char> candidates;
	for (int i = 0; i < numrows * numcols; i++) {
		int r = i / numcols;
		int c = i % numcols;
		if (board[c][r] == '.') {
			candidates = getValidNumbers(board, r, c);
			row = r;
			col = c;
			break;
		}
	}

	if (candidates.size() == 0) return true;

	for (int j = 0; j < candidates.size(); j++) {
		board[row][col] = candidates[j];
		if (isValidSudoku(board)) return true;
		board[row][col] = '.';
	}

	return false;
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
	vector<vector<char>> board2{ {'8','3','.','.','7','.','.','.','.'},
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
		board{row}{col} = val
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