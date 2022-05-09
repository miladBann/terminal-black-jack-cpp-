#include <iostream>
#include <string>
#include <ctime>


int main() {

	bool end = false;

	//this diclares a lambda which is the only way to have a func inside a func in c++

	auto play_again = [&]() {
		char response{ 'n' };

		std::cout << "Wanna play again? y or n:  ";
		std::cin >> response;

		if (response == 'y') {
			std::system("cls");
		}
		else if (response == 'n') {
			end = true;
			std::system("cls");
			std::cout << "THANKS FOR PLAYING!" << std::endl;
		}
	};

	while (end == false)
	{
		int user_cards[] = { 1,2,3,4,5,6,7,8,9,10,10,10,11 };
		int comp_cards[] = { 1,2,3,4,5,6,7,8,9,10,10,10,11 };

		int crr_user_cards[6];
		int crr_comp_cards[6];

		int user_total{ 0 };
		int comp_total{ 0 };

		srand(time(0));
		crr_user_cards[0] = user_cards[1 + (rand() % 11)];
		crr_user_cards[1] = user_cards[1 + (rand() % 11)];

		std::cout << "your first two cards: " << crr_user_cards[0] << ", " << crr_user_cards[1] << " witch is " << (crr_user_cards[0] + crr_user_cards[1]) << std::endl;

		crr_comp_cards[0] = comp_cards[1 + rand() % 11];
		crr_comp_cards[1] = comp_cards[1 + rand() % 11];

		std::cout << "computer's first card: " << crr_comp_cards[0] << std::endl;

		char response;

		std::cout << std::endl;

		std::cout << "would you like to draw another card? y or n?  ";

		std::cout << std::endl;

		std::cin >> response;

		if (response == 'y') {
			crr_user_cards[2] = user_cards[1 + (rand() % 11)];
			std::cout << "your final cards: " << crr_user_cards[0] << ", " << crr_user_cards[1] << ", " << crr_user_cards[2] << " witch is " << (crr_user_cards[0] + crr_user_cards[1] + crr_user_cards[2]) << std::endl;
			user_total += (crr_user_cards[0] + crr_user_cards[1] + crr_user_cards[2]);
		}
		else {
			std::cout << std::endl;
			std::cout << "your final cards: " << crr_user_cards[0] << ", " << crr_user_cards[1] << " which is " << (crr_user_cards[0] + crr_user_cards[1]) << std::endl;
			user_total += (crr_user_cards[0] + crr_user_cards[1]);

		}

		if (crr_comp_cards[0] + crr_comp_cards[1] < 12)
		{
			crr_comp_cards[2] = comp_cards[1 + (rand() % 11)];
			std::cout << "computer's final cards " << crr_comp_cards[0] << ", " << crr_comp_cards[1] << ", " << crr_comp_cards[2] << " which is " << (crr_comp_cards[0] + crr_comp_cards[1] + crr_comp_cards[2]);
			comp_total += (crr_comp_cards[0] + crr_comp_cards[1], crr_comp_cards[2]);
			std::cout << std::endl;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "computer final cards: " << crr_comp_cards[0] << ", " << crr_comp_cards[1] << " which is " << (crr_comp_cards[0] + crr_comp_cards[1]) << std::endl;
			comp_total += (crr_comp_cards[0] + crr_comp_cards[1]);
		}

		// decide the winner

		if (user_total == 21) {
			std::cout << "YOU WIN!!" << std::endl;
			std::cout << std::endl;
			play_again();
		}
		else if (comp_total == 21) {
			std::cout << "COMPUTER WINS!!" << std::endl;
			std::cout << std::endl;
			play_again();
		}
		else if (user_total > 21) {
			std::cout << "COMPUTER WINS!!" << std::endl;
			std::cout << std::endl;
			play_again();
		}
		else if (comp_total > 21) {
			std::cout << "YOU WIN!!" << std::endl;
			std::cout << std::endl;
			play_again();
		}
		else if (user_total > comp_total && user_total < 21)
		{
			std::cout << "YOU WIN!!" << std::endl;
			std::cout << std::endl;
			play_again();
		}
		else if (comp_total > user_total && comp_total < 21) {
			std::cout << "COMPUTER WINS!!" << std::endl;
			std::cout << std::endl;
			play_again();
		}
		else if (comp_total == user_total) {
			std::cout << "IT'S A DRAW!!" << std::endl;
			std::cout << std::endl;
			play_again();
		}

	}
	
	return 0;
}


