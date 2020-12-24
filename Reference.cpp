#include <iostream>
#include <conio.h>
#include "Computer.cpp"
#include "Human.cpp"

class Reference
{
public: 
	void welcome_message() const { //method to print the welcoming message
		std::string welcome = "";
		welcome += "\t\t\tDo you want to play?\n";
		welcome += "\t\t\t1. Yes    2. No\n\n";
		welcome += "\t\t\tPlease enter your option: ";
		std::cout << welcome;
	}

	int user_option() const{ //taking the user input
		int option;
		std::cin >> option;
		return option;
	}

	void winner() const{ //print the winning message
		std::cout << "\t\t\tCongratulation! You won!\n\n";
	}

	void lose() const { //print the losing message
		std::cout << "\t\t\tYou lose!\n\n";
	}

	//method handling the error message
	void error_message(int &option) const {
		while (option != 1 && option != 2) {
			system("CLS");
			std::cout << "\t\t\t============================================================\n";
			std::cout << "\t\t\tYour option is not recognize! Please enter again! \n";
			std::cout << "\t\t\t============================================================\n\n";
			std::cout << "\t\t\tYour option: ";
			std::cin >> option;
			std::cout << "\n";
		}
	}

	void game_play() { //handling the game
		std::string welcome = "";
		welcome += "\t\t\t============================================================\n";
		welcome += "\t\t\t\tWelcome to the World of Rock Paper Scissor!\n";
		welcome += "\t\t\t============================================================\n\n";
		std::cout << welcome;
		welcome_message();
		int option = user_option();
		int human_score = 0;
		int comp_score = 0;
		system("cls");

		error_message(option); //display message and ask the input again

		while (option == 1) { //if option is equal to 1
			system("CLS");
			std::string human_choice = "";
			std::cout << "\n\t\t\tGreat! Let's play!\n\n";
			std::cout << "\t\t\tEnter rock, paper or scissor\n\n";
			std::cout << "\t\t\tPlease enter your move: ";
			std::cin >> human_choice;
			system("CLS");

			//handling un-recognize move
			while (human_choice != "Rock" && human_choice != "rock" && human_choice != "Paper" && human_choice != "paper" && human_choice != "Scissor" && human_choice != "scissor") {
				system("CLS");
				std::cout << "\t\t\t============================================================\n";
				std::cout << "\t\t\tYour move is not recognize! Please enter again\n";
				std::cout << "\t\t\t============================================================\n\n";
				std::cout << "\t\t\tYour move: ";
				std::cin >> human_choice;
				std::cout << "\n";
			}

			Computer comp;
			Human human(human_choice);
			std::string human_option = human.move();
			std::string comp_option = comp.move();

			std::cout << "\t\t\tYour move is: " << human_option << "\n\n";
			std::cout << "\t\t\t\t\tRock ... Paper ... Scissor\n\n";
			std::cout << "\t\t\t";
			system("PAUSE");
			std::cout << "\n\t\t\tComputer move is: " << comp_option << "\n\n";

			//message for determining losing or winning or draw
			if (human_option == comp_option) {
				std::cout << "\t\t\tThe game is draw! \n";
			}
			else if (human_option == "Rock") {
				if (comp_option == "Paper") {
					lose();
					comp_score++;
				}
				else {
					winner();
					human_score++;
				}
			}
			else if (human_option == "Paper") {
				if (comp_option == "Rock") {
					winner();
					human_score++;
				}
				else {
					lose();
					comp_score++;
				}
			}
			else if(human_option == "Scissor"){
				if (comp_option == "Rock") {
					lose();
					comp_score++;
				}
				else {
					winner();
					human_score++;
				}
			}
			std::cout << "\t\t\t============================================================\n";
			std::cout << "\t\t\t\t\t\tCurrent score\n\n";
			std::cout << "\t\t\t\t\tYou: \t   " << human_score << " - " << comp_score << "      :Computer score\n\n";
			std::cout << "\t\t\t============================================================\n";
			std::cout << "\t\t\t";
			system("PAUSE");
			system("CLS");
			std::cout << "\t\t\tDo you want to play again?\n\n";
			std::cout << "\t\t\t1. Yes   2. No\n\n";
			std::cout << "\t\t\tPlease enter your option: ";
			std::cin >> option;

			error_message(option);
		}

		if(option == 2) {
			system("cls");
			std::cout << "\n\t\t\tSee you again! Have a good day!\n";
		} 
	}
};

