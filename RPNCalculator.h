#pragma once

#include <stack>
#include <fstream>

template<class T> class RPNCalculator
{
	stack<T> m_stack; // Stack containing all the numbers 

	ofstream m_logFile; // Logfile to write the results of calculations

public:
	RPNCalculator() : m_stack{}, m_logFile{"RPN.log", ios::binary | ios::trunc}
	{}

	//Destructor that gets called when RPNCalculator goes out of scope 
	~RPNCalculator()
	{
		//Close the file if it exists 
		if (m_logFile.is_open())
		{
			m_logFile.close();
		}
	}

	// Add a digit to the top of the stack 
	void push(T operand)
	{
		m_stack.push(operand);
	}

	// Add the top two values together 
	void add()
	{
		if (m_stack.empty()) return;
		auto val1 = m_stack.top();
		m_stack.pop();
		if (m_stack.empty()) return;
		auto val2 = m_stack.top();
		m_stack.pop();
		m_stack.push(val1 + val2);
		m_logFile << val1 << " + " << val2 << ' ';
	}

	// Subtract the most recent value from second most 
	void subtract()
	{
		if (m_stack.empty()) return;
		auto val1 = m_stack.top();
		m_stack.pop();
		if (m_stack.empty()) return;
		auto val2 = m_stack.top();
		m_stack.pop();
		m_stack.push(val1 - val 2);
		m_logFile << val1 << " - " << val2 << ' ';
	}

	// Multiplies the top two values by eachother
	void multiply()
	{
		if (m_stack.empty()) return;
		auto val1 = m_stack.top();
		m_stack.pop();
		if (m_stack.empty()) return;
		auto val2 = m_stack.top();
		m_stack.pop();
		m_stack.push(val1 * val2);
		m_logFile << val1 << " * " << val2 << ' ';
	}

	// Divides the second most recent value by the most recent
	void divide()
	{
		if (m_stack.empty()) return;
		auto val1 = m_stack.top();
		m_stack.pop();
		if (m_stack.empty()) return;
		auto val2 = m_stack.top();
		m_stack.pop();
		m_stack.push(val1 / val2);
		m_logFile << val1 << " / " << val2 << ' ';
	}

	// Squares the value at the top of the stack
	void square()
	{
		if (m_stack.empty()) return;
		auto val = m_stack.top();
		m_stack.pop();
		m_stack.push(val * val);
		m_logFile << val << " square " << flush;
	}

	// Negates the value at the top of the stack 
	void negate()
	{
		if (m_stack.empty()) return;
		auto val = m_stack.top();
		m_stack.pop();
		m_stack.push(val * -1);
		m_logFile << val << " negate " << flush;
	}

	// Checks if the stack is empty returns true if yes 
	bool isEmpty()
	{
		return m_stack.empty();
	}

	// Empties the stack 
	void clear()
	{
		m_logFile << " clear " << flush; 
		m_stack = {};
	}

	// Returns the top value of the stack 
	T value()
	{
		if (m_stack.empty()) return T{};
		return m_stack.top();
	}

	// Removes top value from the stack and returns it 
	T pop()
	{
		auto val = m_stack.top();
		m_stack.pop();
		return val;
	}
};

