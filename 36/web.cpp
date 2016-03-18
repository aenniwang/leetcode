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

