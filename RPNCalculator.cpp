#include "RPNCalculator.h"

#include <string>
#include <iostream>
#include <exception>

using namespace std;

int main()
{
	cout << "Enter c to clear the stack \n";
	cout << "s to square\nn to negate\n p to pop current value\nq to quit\n\n";

	RPNCalculator<double> calc{};
	bool running = true;
	string buff{};
	while (running)
	{
		if (calc.isEmpty())
		{
			cout << "X> ";
		}
		else
		{
			cout << calc.value() << "> ";
		}
		getline(cin, buff);
		// Check the first characters only 
		switch (buff[0])
		{
		case '/': {
			calc.divide();
			break;
		}
		case '*': {
			calc.multiply();
			break;
		}
		case 'c': {
			calc.clear();
			break;
		}
		case 's': {
			calc.square();
			break;
		}
		case 'n': {
			calc.negate();
			break;
		}
		case 'p': {
			calc.pop();
			break;
		}
		case 'q': {
			running = false;
			break;
		}
		case '+':
			[[fallthrough]];
		case '-':
			// Allow for doubles to be input
			if (buff.size() == 1 || buff[1] == ' ' || buff[1] == '\n')
			{
				if (buff[0] == '-')
				{
					calc.subtract();
				}
				else
				{
					calc.add();
				}
				break;
			}

		default:
		{
			try
			{
				auto val = stod(buff);
				calc.push(val);
			}
			catch (exception)
			{
				cout << "invalid input" << endl;
			}
			break;
		}
		}
	}
	return 0; 
}