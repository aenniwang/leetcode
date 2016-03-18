#include<iostream>
#include<vector>

using namespace std;

void getScale(int id, int &start_id, int &end_id){
	if(id%3 == 0){
		start_id = id;
		end_id = id+2;
	}else if(id%3 == 1){
		start_id = id-1;
		end_id = id+1;
	}else{
		start_id = id-2;
		end_id = id;
	}
}

bool isValidSudoku(vector<vector<char> >& board){
	vector<vector<int> > pos(10);
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(board[i][j] != '.'){
				pos[board[i][j] - '0'].push_back(i*9+j);
			}
		}
	}

	for(int i=0; i<pos.size(); i++){
		for(int j=0; j<pos[i].size(); j++){
			int row_id = pos[i][j]/9;
			int col_id = pos[i][j]%9;
			int row_start, row_end;
			int col_start, col_end;
			getScale(row_id, row_start, row_end);
			getScale(col_id, col_start, col_end);
			for(int k=j+1; k<pos[i].size(); k++){
				int row_id2 = pos[i][k]/9;
				int col_id2 = pos[i][k]%9;
				if(row_id2 == row_id || col_id2 == col_id \
					|| (row_id2 <= row_end && row_id2 >= row_start \
					&& col_id2 <= col_end && col_id2 >= col_start))
					return false;
			}
				
		}
	}
	return true;
}

int main(){
	char row1[] = {'.', '8', '7', '6', '5', '4', '3', '2', '1'};
	char row2[] = {'2', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row3[] = {'3', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row4[] = {'4', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row5[] = {'5', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row6[] = {'6', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row7[] = {'7', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row8[] = {'8', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row9[] = {'9', '.', '.', '.', '.', '.', '.', '.', '.'};
	vector<char> v_row1(row1, row1 + sizeof(row1) / sizeof(char)); 	
	vector<char> v_row2(row2, row2 + sizeof(row2) / sizeof(char)); 	
	vector<char> v_row3(row3, row3 + sizeof(row3) / sizeof(char)); 	
	vector<char> v_row4(row4, row4 + sizeof(row4) / sizeof(char)); 	
	vector<char> v_row5(row5, row5 + sizeof(row5) / sizeof(char)); 	
	vector<char> v_row6(row6, row6 + sizeof(row6) / sizeof(char)); 	
	vector<char> v_row7(row7, row7 + sizeof(row7) / sizeof(char)); 	
	vector<char> v_row8(row8, row8 + sizeof(row8) / sizeof(char)); 	
	vector<char> v_row9(row9, row9 + sizeof(row9) / sizeof(char)); 	

	vector<vector<char> > board;
	board.push_back(v_row1);
	board.push_back(v_row2);
	board.push_back(v_row3);
	board.push_back(v_row4);
	board.push_back(v_row5);
	board.push_back(v_row6);
	board.push_back(v_row7);
	board.push_back(v_row8);
	board.push_back(v_row9);

	cout << "is soudu? " << isValidSudoku(board) << endl;
	return 0;
}
