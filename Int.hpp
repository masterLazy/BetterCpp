#pragma once

namespace bettercpp {
	class Integer : Object, Number<int32_t>, Comparable<Integer>,
		Comparator<Integer> {
	public:
		Integer() {}
		Integer(const int value) {
			self.value = value;
		}
		Integer(const String& s) {
			value = parseInt(s);
		}
		operator const int() const {
			return value;
		}

		bool equals(const Object& anObject) const override {
			auto* p = dynamic_cast<const Integer*>(&anObject);
			if (p == nullptr)return false;
			return value == p->value;

		}
		int hashCode() override {
			return value;
		}
		std::string toString() const override {
			return std::to_string(value);
		}

		int compareTo(const Integer& o) const override {
			return compare(self, o);
		}
		static int compare(const Integer& o1, const Integer& o2) {
			return o1.value - o2.value;
		}

		/* Custom methods */

		static Integer valueOf(const String s) {
			return parseInt(s);
		}
		static Integer valueOf(const String s, int radix) {
			return parseInt(s, radix);
		}
		static int32_t parseInt(const String s) {
			return std::stoi(s);
		}
		static int32_t parseInt(const String s, int radix) {
			return std::stoi(s, nullptr, radix);
		}
	};
}