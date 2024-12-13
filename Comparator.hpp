#pragma once

namespace bettercpp {
	template<typename T> class Comparator {
	public:
		static int compare(const T& o1, const T& o2);
	};
}