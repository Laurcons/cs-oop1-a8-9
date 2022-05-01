#pragma once
#include <string>

namespace laur {

	class tutorial {
	public:
		std::string title;
		int likes;

		tutorial(std::string title, int likes) {
			this->title = title;
			this->likes = likes;
		}

	};

}