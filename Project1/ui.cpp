#include "base.h"
#include "ui.h"
#include "openlink.h"
#include <iostream>
#include <sstream>
#include <algorithm>

namespace bub {

	ui::ui(const tutorial_controller& c) :
		controller(c) {}

	void ui::start() {
		if (this->controller.get_all().size() == 0) {
			this->controller.add_tutorial("Learn Python - Full Course for Beginners", "freeCodeCamp.org", 4 * 60 + 26, 51, 795000, "https://www.youtube.com/watch?v=rfscVS0vtbw");
			this->controller.add_tutorial("C Programming Tutorial for Beginners", "freeCodeCamp.org", 3 * 60 + 46, 13, 127000, "https://www.youtube.com/watch?v=KJgsSFOSQv0");
			this->controller.add_tutorial("BrainF*uck Tutorial", "Tech With Tim", 27, 33, 134000, "https://www.youtube.com/watch?v=G-tuXeMyb58");
			this->controller.add_tutorial("Rust Crash Course | Rustlang", "Traversy Media", 1 * 60 + 50, 43, 453536, "https://www.youtube.com/watch?v=zF34dRivLOw");
			this->controller.add_tutorial("C# - Full Tutorial for Beginners", "freeCodeCamp.org", 4 * 60 + 31, 29, 2342000, "https://www.youtube.com/watch?v=GhQdlIFylQ8");
			this->controller.add_tutorial("Learn Go Programming | Golang Tutorial for Beginners", "freeCodeCamp.org", 6 * 60 + 39, 58, 2352000, "https://www.youtube.com/watch?v=YS4e4q9oBaU");
			this->controller.add_tutorial("Perl Tutorial", "Derek Banas", 67, 24, 245000, "https://www.youtube.com/watch?v=WEghIXs8F6c");
			this->controller.add_tutorial("Ruby Programming Language Full Course", "freeCodeCamp.org", 242, 23, 356000, "https://www.youtube.com/watch?v=t_ispmWmdjY");
			this->controller.add_tutorial("Bash Programming Course", "linuxhint", 183, 23, 35000, "https://www.youtube.com/watch?v=e7BufAVwDiM");
			this->controller.add_tutorial("Learning Awk is Essential for Linux Users", "DistroTube", 20, 2, 240000, "https://www.youtube.com/watch?v=9YOZmI-zWok");
		}
		while (1) {
			this->print_menu();
			auto option = this->input("option> ");
			if (option == "x")
				break;
			int opt = this->to_int(option);
			switch (opt) {
			case 1: this->do_option_1(); break;
			case 2: this->do_option_2(); break;
			}
		}
		std::cout << "Exiting" << std::endl;
	}

	void ui::print_menu() {
		std::cout
			<< std::endl << std::endl
			<< "Select mode:" << std::endl
			<< "1. Administrator Mode" << std::endl
			<< "2. User mode" << std::endl
			<< "x. Exit" << std::endl;
	}

	void ui::print_admin_menu() {
		std::cout
			<< std::endl << std::endl
			<< "What do you want to do?" << std::endl
			<< "1. Add tutorial" << std::endl
			<< "2. Edit tutorial" << std::endl
			<< "3. Remove tutorial" << std::endl
			<< "4. View all tutorials" << std::endl
			<< "5. Output CSV" << std::endl
			<< "6. Output HTML" << std::endl
			<< "7. Open CSV" << std::endl
			<< "8. Open HTML" << std::endl
			<< "b. Go back" << std::endl;
	}

	void ui::print_user_menu() {
		std::cout
			<< std::endl << std::endl
			<< "What do you want to do?" << std::endl
			<< "1. Explore" << std::endl
			<< "2. Remove from watchlist" << std::endl
			<< "3. See the entire watchlist" << std::endl
			<< "b. Go back" << std::endl;
	}

	std::string ui::input(std::string prompt) {
		std::string inp;
		std::cout << prompt;
		std::getline(std::cin, inp);
		return inp;
	}

	int ui::to_int(std::string str) {
		std::stringstream ss;
		int out;
		ss << str;
		ss >> out;
		return out;
	}

	// admin mode
	void ui::do_option_1() {
		while (1) {
			try {
				this->print_admin_menu();
				auto option = this->input("option> ");
				if (option == "b")
					break;
				int opt = this->to_int(option);
				switch (opt) {
				case 1: this->do_option_1_1(); break;
				case 2: this->do_option_1_2(); break;
				case 3: this->do_option_1_3(); break;
				case 4: this->do_option_1_4(); break;
				case 5: this->do_option_1_5(); break;
				case 6: this->do_option_1_6(); break;
				case 7: this->do_option_1_7(); break;
				case 8: this->do_option_1_8(); break;
				}
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
		}
	}

	void ui::do_option_1_1() {
		std::cout << "Adding new Tutorial" << std::endl;
		std::string title = this->input("Title: ");
		std::string presenter = this->input("Presenter: ");
		int min = this->to_int(this->input("Duration>Minutes: "));
		int sec = this->to_int(this->input("Duration>Seconds: "));
		int likes = this->to_int(this->input("Likes: "));
		std::string link = this->input("Link: ");
		this->controller.add_tutorial(
			title,
			presenter,
			min, sec,
			likes,
			link
		);
		std::cout << "Tutorial successfully added.";
	}

	void ui::do_option_1_2() {
		std::cout << "Editing Tutorial" << std::endl;
		std::string title = this->input("Title to edit: ");
		tutorial& tut = this->controller.edit_start(title);

		std::cout << "Now editing" << std::endl << tut << std::endl;
		std::string newTitle = this->input("New title: ");
		std::string newPresenter = this->input("New presenter: ");
		int newMin = this->to_int(this->input("New Duration>Minutes: "));
		int newSec = this->to_int(this->input("New Duration>Seconds: "));
		int newLikes = this->to_int(this->input("New likes: "));
		std::string newLink = this->input("New link: ");
		this->controller.edit_end(
			tut,
			newTitle,
			newPresenter,
			newMin, newSec,
			newLikes,
			newLink
		);
		std::cout << "Successfully updated." << std::endl;
	}

	void ui::do_option_1_3() {
		std::cout << "Removing a Tutorial" << std::endl;
		std::string title = this->input("Title to remove: ");
		this->controller.remove(title);
		std::cout << "Successfully removed." << std::endl;
	}

	void ui::do_option_1_4() {
		std::cout << "Viewing all Tutorials" << std::endl;
		for (auto tut : this->controller.get_all()) {
			std::cout << tut.toString() << std::endl;
		}
	}

	void ui::do_option_1_5() {
		std::cout << "Outputting CSV" << std::endl;
		this->controller.output_csv();
	}

	void ui::do_option_1_6() {
		std::cout << "Outputting HTML" << std::endl;
		this->controller.output_html();
	}

	void ui::do_option_1_7() {
		std::cout << "Opening CSV" << std::endl;
		this->controller.open_csv();
	}

	void ui::do_option_1_8() {
		std::cout << "Opening HTML" << std::endl;
		this->controller.open_html();
	}

	void ui::do_option_2() {
		while (1) {
			try {
				this->print_user_menu();
				auto option = this->input("option> ");
				if (option == "b")
					break;
				int opt = this->to_int(option);
				switch (opt) {
				case 1: this->do_option_2_1(); break;
				case 2: this->do_option_2_2(); break;
				case 3: this->do_option_2_3(); break;
				}
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
		}
	}

	void ui::do_option_2_1() {
		auto presenterFilter = this->input("Enter presenter filter (or x): ");
		auto filtered = this->controller.get_all();
		if (presenterFilter != "x") {
			for (int i = filtered.size() - 1; i >= 0; i--) {
				if (filtered[i].get_presenter() != presenterFilter)
					filtered.erase(filtered.begin() + i);
			}
		}
		bool exit = false;
		while (1) {
			for (tutorial& tut : filtered) {
				std::cout << "Currently at tutorial" << std::endl
					<< tut.get_title() << " by " << tut.get_presenter() << std::endl
					<< tut.get_duration().m << ":" << tut.get_duration().s << std::endl
					<< tut.get_likes() << " likes" << std::endl
					<< tut.get_link() << std::endl;
				std::cout << "What do you want to do?" << std::endl
					<< "1. Open link" << std::endl
					<< "2. Add to watchlist" << std::endl
					<< "3. Skip" << std::endl
					<< "b. Exit Explore" << std::endl;
				auto option = this->input("option> ");
				if (option == "1")
					open_link(tut.get_link());
				else if (option == "2")
					this->watchlist.push_back(tut);
				else if (option == "3")
					; // do nothing
				else if (option == "b")
					exit = true;
				if (exit) break;

				std::cout << std::endl << std::endl;
			}
			if (exit) break;
			std::cout << "Reached end of tutorials, restarting" << std::endl;
		}
	}

	void ui::do_option_2_2() {
		auto title = this->input("Title of tutorial: ");
		auto liked = this->input("Like? y/n: ");
		// find tut
		for (int i = 0; i < this->watchlist.size(); i++) {
			if (this->watchlist[i].get_title() == title) {
				if (liked == "y") {
					// do edit
					tutorial& tut = this->controller.edit_start(title);
					tut.inc_likes();
				}
				this->watchlist.erase(this->watchlist.begin() + i);
				break;
			}
		}
	}

	void ui::do_option_2_3() {
		std::cout << "Watchlist" << std::endl;
		for (auto tut : this->watchlist) {
			std::cout << tut << std::endl;
		}
	}

}