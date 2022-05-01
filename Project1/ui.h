#pragma once
#include "controller.h"

namespace bub {

	class ui {
	private:
		tutorial_controller controller;
		std::vector<tutorial> watchlist;

		int to_int(std::string str);
		std::string input(std::string prompt);
		void print_menu();
		void print_admin_menu();
		void print_user_menu();
		void do_option_1();
		void do_option_2();
		void do_option_1_1();
		void do_option_1_2();
		void do_option_1_3();
		void do_option_1_4();
		void do_option_1_5();
		void do_option_1_6();
		void do_option_1_7();
		void do_option_1_8();
		void do_option_2_1();
		void do_option_2_2();
		void do_option_2_3();
	public:

		ui(const tutorial_controller&);
		void start();

	};

}