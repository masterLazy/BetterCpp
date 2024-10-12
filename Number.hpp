#pragma once

namespace bettercpp {
	class Number {
	public:
		virtual int16_t shortValue() const = 0;
		virtual int32_t intValue() const = 0;
		virtual int64_t longValue() const = 0;
		virtual float floatValue() const = 0;
		virtual double doubleValue() const = 0;
	};
}