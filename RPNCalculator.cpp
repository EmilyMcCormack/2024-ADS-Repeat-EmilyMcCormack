#include "RPNCalculator.h"

#include <string>
#include <iostream>
using namespace std;

int main() {
	RPNCalculator<double> calculator{};

	string buff;
	cout << "X>";
	while (getline(cin, buff)) {
		if (buff.size() == 1) {
			switch (buff[0]) {
			case '+':
				calculator.add();
				break;
			case '-':
				calculator.subtract();
				break;
			case '*':
				calculator.multiply();
				break;
			case '/':
				calculator.divide();
				break;
			case 'square':
				calculator.square();
				break;
			case 'negate':
				calculator.negate();
				break;
			case 'pop':
				calculator.pop();
				break;
			case 'clear':
				calculator.clear();
				break;
			case 'return 0':
				return 0;
			default:
				auto val = stod(buff);
				calculator.push(val);
				break;
			}
		}
		else {
			auto val = stod(buff);
			calculator.push(val);
		}
		cout << (calculator.isEmpty()) ? "X" : calculator.value() << "> ";
	}
	return 0; 
}