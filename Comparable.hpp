#pragma once

namespace bettercpp {
	template<typename T> class Comparable {
	public:
		virtual int compareTo(const T& o) const = 0;
	};
}