#include <iostream>
#include <cmath>

const int PLAYER1 = 0;
const int PLAYER2 = 1;
const int PLAYER_EQUAL = 2;

const int ROC = 1;
const int PAP = 2;
const int CIS = 3;

int random(int min, int max) {
	return floor(rand() % (max - min + 1) + min);
}

void get_pseudo(char* pseudo) {
	std::cout << "Entrer votre pseudo: ";
	std::cin >> pseudo;
}

int get_user_choice() {
	int choice = -1;

	do {
		std::cout << "1 - Pierre\n2 - Feuille\n3 - Ciseau\n";
		std::cout << "> ";
		std::cin >> choice;
		std::cout << std::endl << std::endl;
	} while(choice != CIS && choice != ROC && choice != PAP);

	return choice;
}

int get_round_winner(int board[2][3], int round) {
	if(board[PLAYER1][round] == board[PLAYER2][round])
		return PLAYER_EQUAL;
	if(board[PLAYER1][round] == (board[PLAYER2][round] + 1) % 3)
		return PLAYER2;
	return PLAYER1;
}

int get_winner(int* win_board) {
	int p1 = 0;
	int p2 = 0;
	for(int win_index = 0; win_index < 3; win_index++)
	{
		if(PLAYER1 == win_board[win_index])
			p1++;
		else if(PLAYER2 == win_board[win_index])
			p2++;
	}

	return (p1 > p2)
		? PLAYER1
		: (p1 == p2) ? PLAYER_EQUAL : PLAYER2;
}

int main()
{
	srand((unsigned) time(0));

	int continue_playing;

	char pseudo[20];
	get_pseudo(pseudo);

	do {
		continue_playing = -1;
		int round = 0;
		int max_round = 3;

		int board[2][3] = {
			{0, 0, 0},
			{0, 0, 0}
		};

		int win_board[max_round] = {-1, -1, -1};

		do {
			board[PLAYER1][round] = get_user_choice();
			board[PLAYER2][round] = random(1, 3);
			
			win_board[round] = get_round_winner(board, round);

			std::cout << pseudo << ": " << board[PLAYER1][round] << " - ord: " << board[PLAYER2][round] << std::endl << std::endl;

			if(round > 0 && win_board[round] == win_board[round - 1] && win_board[round] != PLAYER_EQUAL)
				break;

			round++;
		} while(round != max_round);

		int winner = get_winner(win_board);

		if(winner == PLAYER1)
			std::cout << pseudo << " a gagné !" << std::endl;
		else if(winner == PLAYER2)
			std::cout << "ordinateur a gagné !" << std::endl;
		else
			std::cout << "égalité !" << std::endl;

		do {
			std::cout << "Voulez-vous rejouer ! [0 | 1]" << std::endl;
			std::cin >> continue_playing;
			std::cout << std::endl;
		} while(continue_playing != 0 && continue_playing != 1);
	} while(continue_playing);


	return 0;
}
