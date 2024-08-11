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

				break;
			case '*':

				break;
			case '/':

				break; 
			case 'square':

				break; 
			case 'negate'

				break;
			case 'pop':

				break; 
			case 'clear':

				break; 
			case 'return 0':

				break;
			}
		}
	}
}