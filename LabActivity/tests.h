#pragma once
#include "comparator.h"
#include <vector>
#include <cassert>

namespace laur {

	void test_all() {

		std::vector<tutorial> v;
		v.push_back(laur::tutorial{ "Tutorial 1", 134 });
		v.push_back(laur::tutorial{ "Tutorial 5", 143 });
		v.push_back(laur::tutorial{ "Tutorial 3", 563 });
		v.push_back(laur::tutorial{ "Tutorial 2", 937 });
		v.push_back(laur::tutorial{ "Tutorial 4", 823 });

		std::vector<tutorial> v1 = v; // copy
		comparator<tutorial>* comparator_title = new tutorial_by_title{};

		sort_by_comparator(v1, comparator_title);
		assert(v1[0].title == "Tutorial 1");
		assert(v1[1].title == "Tutorial 2");
		assert(v1[2].title == "Tutorial 3");
		assert(v1[3].title == "Tutorial 4");
		assert(v1[4].title == "Tutorial 5");

		delete comparator_title;

		std::vector<tutorial> v2 = v; // copy
		comparator<tutorial>* comparator_likes = new tutorial_by_likes{};

		sort_by_comparator(v2, comparator_likes);
		assert(v2[0].likes == 134);
		assert(v2[1].likes == 143);
		assert(v2[2].likes == 563);
		assert(v2[3].likes == 823);
		assert(v2[4].likes == 937);

		delete comparator_likes;

	}

}