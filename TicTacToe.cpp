#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i , a , b) for(ll i = a; i <= b; ++i)
#define FORd(i , a , b) for(ll i = a; i >= b; --i)


class TicTacToe{
public:
    vector<char> board = {'1','2','3','4','5','6','7','8','9'};
	vector<int> Xstate = {0,0,0,0,0,0,0,0,0,0};
	vector<int> Ostate = {0,0,0,0,0,0,0,0,0,0};
    void Welcone(){
		printf("Welcome to Tic Tac Toe!\n");
		printf("Here's the current board:\n");
		printBoard(Xstate,Ostate);
		printf("X will play first. Enter a slot number to place X in:\n");
    }
	void printBoard(vector<int> &Xstate, vector<int> &Ostate){
		FOR(i,0,8){
			if(Xstate[i+1] == 1){
				board[i] = 'X';
			}
			else if(Ostate[i+1] == 1){
				board[i] = 'O';
			}
		}
		printf("%c | %c | %c\n",board[0],board[1],board[2]);
		printf("--|---|--\n");
		printf("%c | %c | %c\n",board[3],board[4],board[5]);
		printf("--|---|--\n");
		printf("%c | %c | %c\n",board[6],board[7],board[8]);
	}
	bool checkWin(vector<int> &state){
		if(state[1] == 1 && state[2] == 1 && state[3] == 1){
			return true;
		}
		else if(state[4] == 1 && state[5] == 1 && state[6] == 1){
			return true;
		}
		else if(state[7] == 1 && state[8] == 1 && state[9] == 1){
			return true;
		}
		else if(state[1] == 1 && state[4] == 1 && state[7] == 1){
			return true;
		}
		else if(state[2] == 1 && state[5] == 1 && state[8] == 1){
			return true;
		}
		else if(state[3] == 1 && state[6] == 1 && state[9] == 1){
			return true;
		}
		else if(state[1] == 1 && state[5] == 1 && state[9] == 1){
			return true;
		}
		else if(state[3] == 1 && state[5] == 1 && state[7] == 1){
			return true;
		}
		return false;
	}
    void gamePlay(){
		int turn = 0;
		while(true){
			printBoard(Xstate,Ostate);
			printf("It's your turn, X. Where do you want to play?\n");
			int slot;
			cin >> slot;
			if(Xstate[slot] == 1 || Ostate[slot] == 1){
				printf("Slot already taken; re-enter slot number:\n");
				continue;
			}
			Xstate[slot] = 1;
			if(checkWin(Xstate)){
				printBoard(Xstate,Ostate);
				printf("Congratulations! X has won! Thanks for playing.\n");
				break;
			}
			turn++;
			if(turn == 9){
				printBoard(Xstate,Ostate);
				printf("It's a draw! Thanks for playing.\n");
				break;
			}
			printBoard(Xstate,Ostate);
			printf("It's your turn, O. Where do you want to play?\n");
			cin >> slot;
			if(Xstate[slot] == 1 || Ostate[slot] == 1){
				printf("Slot already taken; re-enter slot number:\n");
				continue;
			}
			Ostate[slot] = 1;
			if(checkWin(Ostate)){
				printBoard(Xstate,Ostate);
				printf("Congratulations! O has won! Thanks for playing.\n");
				break;
			}
			turn++;
		}
	}
};

int32_t main(){
ios::sync_with_stdio(0); cin.tie(0);
	TicTacToe game;
	game.Welcone();
	while(true){
		game.gamePlay();
		printf("Do you want to play again (Y/N)?\n");
		char c;
		cin >> c;
		if(c == 'Y'){
			game.board = {'1','2','3','4','5','6','7','8','9'};
			game.Xstate = {0,0,0,0,0,0,0,0,0,0};
			game.Ostate = {0,0,0,0,0,0,0,0,0,0};
			continue;
		}
		else{
			break;
		}
	}
	return 0;
}