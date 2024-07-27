#pragma once

#include <vector>

template <class T> class RPNCalculator
{
	private
		vector<T> m_stack;
	size_t m_stackSize; 
public:
	RPNCalculator() : m_stack{}, m_stackSize{ 0 }
	{}

	//pushes a new operand onto the stack 
	void push(T operand) {
		m_stack.emplace_back(operand);
		m_stackSize++;
	}
	
	//binary operators: 
	void add() {

	}

	void subtract() {

	}

	void multiply() {

	}

	void divide() {

	}
};

