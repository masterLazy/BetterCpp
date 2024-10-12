#pragma once

#include <string>

namespace bettercpp {
	class Object {
	public:
		virtual bool equals(const Object& anObject) const = 0;
		virtual int hashCode() = 0;
		virtual std::string toString() const = 0;
	};
}