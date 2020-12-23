#include <iostream>
#include <conio.h>
#include "Computer.cpp"
#include "Human.cpp"

class Reference
{
public: 
	void welcome_message() const {
		std::string welcome = "";
		welcome += "\t\t\t============================================================\n";
		welcome += "\t\t\t\tWelcome to the World of Rock Paper Scissor!\n";
		welcome += "\t\t\t============================================================\n\n";
		welcome += "\t\t\tDo you want to play the game?\n";
		welcome += "\t\t\t1. Yes    2. No\n\n";
		welcome += "\t\t\tPlease enter your option: ";
		std::cout << welcome;
	}

	int user_option() const{
		int option;
		std::cin >> option;
		return option;
	}

	void winner() const{
		std::cout << "\t\t\tCongratulation! You won!\n\n";
	}

	void lose() const {
		std::cout << "\t\t\tYou lose!\n\n";
	}

	void game_play() const{
		welcome_message();
		int option = user_option();
		system("cls");
		if (option == 1) {
			std::string human_choice = "";
			std::cout << "\n\t\t\tGreat! Let's play!\n\n";
			std::cout << "\t\t\tEnter rock, paper or scissor\n\n";
			std::cout << "\t\t\tPlease enter your move: ";
			std::cin >> human_choice;
			system("CLS");

			
			Computer comp;
			Human human(human_choice);
			std::string human_option = human.move();
			std::string comp_option = comp.move();

			std::cout << "\t\t\tYour move is: " << human_option << "\n\n";
			std::cout << "\t\t\t\t\tRock ... Paper ... Scissor\n\n";
			std::cout << "\t\t\t";
			system("PAUSE");
			std::cout << "\n\t\t\tComputer move is: " << comp_option << "\n\n";

			if (human_option == comp_option) {
				std::cout << "\t\t\tThe game is draw! \n";
			}
			else if (human_option == "Rock") {
				if (comp_option == "Paper") {
					lose();
				}
				else {
					winner();
				}
			}
			else if (human_option == "Paper") {
				if (comp_option == "Rock") {
					winner();
				}
				else {
					lose();
				}
			}
			else if(human_option == "Scissor"){
				if (comp_option == "Rock") {
					lose();
				}
				else {
					winner();
				}
			}
			else {
				std::cout << "\t\t\tSorry! We can't recognize your move, try again!\n";
			}


		}
		else {
			std::cout << "\n\t\t\tSee you again! Have a good day!\n";
		} 
	}
};

