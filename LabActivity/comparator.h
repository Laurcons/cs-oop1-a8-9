#pragma once
#include "domain.h"
#include <vector>
#include <algorithm>

namespace laur {

	template <typename T>
	class comparator {
	public:
		virtual bool compare(const T&, const T&) = 0;
	};

	class tutorial_by_title : public comparator<tutorial> {
	public:
		virtual bool compare(const tutorial& t1, const tutorial& t2) override {
			return t1.title < t2.title;
		}
	};

	class tutorial_by_likes : public comparator<tutorial> {
	public:
		virtual bool compare(const tutorial& t1, const tutorial& t2) override {
			return t1.likes < t2.likes;
		}
	};

	template <typename T>
	void sort_by_comparator(std::vector<T>& v, comparator<T>* comparator) {
		for (size_t i = 0; i < v.size() - 1; i++) {
			for (size_t j = i + 1; j < v.size(); j++) {
				if (!comparator->compare(v[i], v[j])) {
					std::swap(v[i], v[j]);
				}
			}
		}
	}

}