#pragma once

namespace bettercpp {
	template <typename T> class Number {
	protected:
		T value = 0;
	public:
		virtual int16_t shortValue() const{
			return value;
		}
		virtual int32_t intValue() const{
			return value;
		}
		virtual int64_t longValue() const{
			return value;
		}
		virtual float floatValue() const{
			return value;
		}
		virtual double doubleValue() const{
			return value;
		}
	};
}