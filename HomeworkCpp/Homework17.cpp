#include <iostream>
#include <vector>

using namespace std;

int check(string stroke) {
	vector<pair<char, int>> stack;
	for (int i = 0; i < stroke.length(); ++i) {
		char ch = stroke[i];

		if (ch == ';') break;

		if (ch == '(' || ch == '[' || ch == '{') {
			stack.push_back({ ch, i });
		}

		else if (ch == ')' || ch == ']' || ch == '}') {
			if (stack.empty()) return i;

			char top = stack.back().first;
			stack.pop_back();

			if ((ch == ')' && top != '(') ||
				(ch == ']' && top != '[') ||
				(ch == '}' && top != '{')) {
				return i;
			}
		}
	}

	return -1;
}



/*
int main() {
	string s1 = "({x-y-z}*[x+2y]-(z+4x));";
	string s2 = "([x-y-z}*[x+2y)-{z+4x)];";

	for (string s : {s1, s2}) {
		int errorIndex = check(s);
		if (errorIndex == -1) {
			cout << s << " — Correct" << endl;
		}
		else {
			cout << s.substr(0, errorIndex + 1) << " — Wrong" << endl;
		}
	}

	return 0;
}
*/