#pragma once

namespace bettercpp {
	class String :Object {
		std::string value;
		int hash = 0;
	public:
		String() {}
		String(const std::string& value) :value(value) {}
		operator const std::string& () const {
			return value;
		}
		// Not recommended
		String(const char* value) :value(value) {}

		bool equals(const Object& anObject) const override {
			auto* p = dynamic_cast<const String*>(&anObject);
			if (p == nullptr)return false;
			return value == p->value;
		}
		int hashCode() override {
			if (hash == 0 && value.size() > 0) {
				for (int i = 0; i < value.size(); i++) {
					hash = 31 * hash + value[i];
				}
			}
			return hash;
		}
		std::string toString() const override {
			return value;
		}

		/* Custom methods */

		template<typename T>
		static String valueOf(T data) {
			return std::to_string(data);
		}

		bool equals(const String& anotherString) const {
			return value == anotherString.value;
		}
		bool equalsIgnoreCase(const String& anotherString) const {
			return self.toLowerCase().equals(anotherString.toLowerCase());
		}

		bool isEmpty() const {
			return value.empty();
		}
		bool isBlank() const {
			for (unsigned char c : value) {
				if (!std::isspace(c)) {
					return false;
				}
			}
			return true;
		}

		bool startWith(const String& prefix) const {
			if (prefix.length() > self.length())return false;
			for (size_t i = 0; i < prefix.length(); i++) {
				if (self.value[i] != prefix.value[i])return false;
			}
			return true;
		}
		bool endWith(const String& suffix) const {
			if (suffix.length() > self.length())return false;
			for (size_t i = 1; i <= suffix.length(); i++) {
				if (self.value[self.length() - i] != suffix.value[suffix.length() - i])return false;
			}
			return true;
		}

		char chatAt(size_t index) const {
			return value[index];
		}

		size_t length() const {
			return value.size();
		}

		size_t indexOf(char ch) const {
			return value.find_first_of(ch);
		}
		size_t indexOf(const String& str) const {
			return value.find(str);
		}
		size_t lastIndexOf(char ch) const {
			return value.find_last_of(ch);
		}
		size_t lastIndexOf(const String& str) const {
			return value.rfind(str);
		}

		String toUpperCase() const {
			std::string res = value;
			for (auto i = res.begin(); i != res.end(); i++) {
				*i = toupper(*i);
			}
			return res;
		}
		String toLowerCase() const {
			std::string res = value;
			for (auto i = res.begin(); i != res.end(); i++) {
				*i = tolower(*i);
			}
			return res;
		}

		String substring(size_t beginIndex) const {
			return value.substr(beginIndex);
		}
		String substring(size_t beginIndex, size_t endIndex) const {
			return value.substr(beginIndex, endIndex - beginIndex + 1);
		}

		String replace(char oldChar, char newChar) const {
			std::string res = value;
			for (auto i = res.begin(); i != res.end(); i++) {
				if (*i == oldChar)*i = newChar;
			}
			return res;
		}
		String replace(const String& target, const String& replacement) const {
			return std::regex_replace(
				value, 
				std::regex(target.toString()), 
				replacement.toString());
		}
	};
}