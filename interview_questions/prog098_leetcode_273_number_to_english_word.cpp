#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string threeDigitsToString(int num) {
	vector<string> tens{ "", "","Twenty","Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	vector<string> unit_order{ "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
	vector<string> below20 = { "Ten","Eleven","Twelve","Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	string s = "";
	int hundredOrder = num / 100;
	num = num % 100;
	if (hundredOrder > 0) {
		s += unit_order[hundredOrder] + " Hundred";
	}
	if (num >= 20) {
		int tetnsOrder = num / 10;
		num = num % 10;
		if (hundredOrder > 0)
			s += " ";
		s += tens[tetnsOrder];
		if (num > 0)
			s += " " + unit_order[num];
	}
	else if (num >= 10) {
		if (hundredOrder > 0)
			s += " ";
		s += below20[num - 10];
	}
	else {
		if (num > 0)
			if (hundredOrder > 0)
				s += " ";
		s += unit_order[num];
	}
	return s;
}


string numberToWords(int num) {
	vector<string> unit_order{ "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
	vector<string> orders{ "", "Thousand", "Million", "Billion" };
	if (num < 10) {
		return unit_order[num];
	}
	int numDigits = static_cast<int>(floor(log10(num))) + 1;
	int order = ceil(static_cast<float> (numDigits) / 3.0f) - 1;
	string answer = "";

	for (int i = order; i >= 0; i--) {
		if (num != 0) {
			int unit = static_cast<int>(pow(1000, i));
			int value = num / unit;
			num = num % unit;
			if (value != 0) {
				string s_value = threeDigitsToString(value);
				answer += s_value + " " + orders[i];
				if (num != 0)
					answer += " ";
			}
		}
	}
	if (answer[answer.size() - 1] == ' ')
		return answer.substr(0, answer.size() - 1);
	else
		return answer;

}

int main() {
	std::cout << numberToWords(110) << std::endl;
	std::cout << numberToWords(119) << std::endl;
	std::cout << numberToWords(12345) << std::endl;
	std::cout << numberToWords(1234567) << std::endl;
	std::cout << numberToWords(1000) << std::endl;
	std::cout << numberToWords(10000) << std::endl;
	std::cout << numberToWords(1000000) << std::endl;
	std::cout << numberToWords(1000010) << std::endl;
	std::cout << numberToWords(1000010) << std::endl;
	std::cout << numberToWords(1000000000) << std::endl;
	std::cout << numberToWords(1000000010) << std::endl;
	return 0;
}