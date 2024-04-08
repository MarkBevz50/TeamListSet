#pragma once
#include "set.h"
#include <vector>
//Task2
int digit(int n) // Mark
{
	Set<int> Test;
	while (n > 0)
	{
		int digit = n % 10;
		Test.Add(digit);
		n /= 10;
	}
	return Test.Size();
}
//Task1
int CountDigits(std::string str)
{
	char arr[10] = { '0', '1', '2', '3', '4', '5', '6','7', '8','9'};
	Set<char> digits(arr, 10);
	int countDigit = 0;
	for (char c : str)
	{
		if (digits.Contains(c))
		{
			++countDigit;
		}
	}
	return countDigit;
}
int CountOperators(std::string str)
{
	char arr[6] = { '+', '-', '*', '/', '(', ')'};
	Set <char> operators(arr, 6);
	int countOp = 0;
	for (char c : str)
	{
		if (operators.Contains(c))
		{
			++countOp;
		}
	}
	return countOp;
}
int CountOpenBrackets(const std::string& str) {
	Set<char> openBrackets('(');
	int countOpenBrackets = 0;
	for (char c : str) {
		if (openBrackets.Contains(c)) {
			++countOpenBrackets;
		}
	}
	return countOpenBrackets;
}

// Функція для обчислення кількості закритих дужок у рядку
int CountCloseBrackets(const std::string& str) {
	Set<char> closeBrackets(')');
	int countCloseBrackets = 0;
	for (char c : str) {
		if (closeBrackets.Contains(c)) {
			++countCloseBrackets;
		}
	}
	return countCloseBrackets;
}

// Функція для перевірки балансу дужок у рядку
bool BalancedBrackets(const std::string& str) {
	int openCount = 0;
	int closeCount = 0;
	for (char c : str) {
		if (c == '(') {
			++openCount;
		}
		else if (c == ')') {
			++closeCount;
		}
	}
	return openCount == closeCount;
}
//main
//std::string expression = "27 + 19 - (21 * 4 - 15) + (2 - 1)";
//int digitCount = CountDigits(expression);
//int operatorCount = CountOperators(expression);
//int openBracketCount = CountOpenBrackets(expression);
//int closeBracketCount = CountCloseBrackets(expression);
//bool bracketsAreBalanced = BalancedBrackets(expression);
//std::cout << "Amount of digits: " << digitCount << std::endl;
//std::cout << "Amount of operators: " << operatorCount << std::endl;
//std::cout << "Amount of opened brackets: " << openBracketCount << std::endl;
//std::cout << "Amount of closed brackets: " << closeBracketCount << std::endl;
//std::cout << "Brackets " << (bracketsAreBalanced ? "" : "not ") << "Balanced." << std::endl;

//Task 5
enum class Product { Bread, Butter, Milk, Cheese, Meat, Fish, Salt, Sugar, Tea, Coffee, Water };
