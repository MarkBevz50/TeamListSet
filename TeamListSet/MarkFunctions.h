#pragma once
#include "set.h"
//Task2 Mark
int digit(int n) 
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
           //main
 // int number;
//std::cout << "Enter your number: " << '\n';
//std::cin >> number;
//std::cout << "Your number contains " << digit(number) << " different digits.";


//Task1
int CountDigits(std::string str)
{
	char arr[10] = { '0', '1', '2', '3', '4', '5', '6','7', '8','9'};           // Tried using a for each loop in some functions in the project
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

//Task 3
Set<char> getFirstOccurrences(const std::string& str) {           
	Set<char> charSet;
	Set<char> firstOccurrences;
	for (char c : str) {
		if (!charSet.Contains(c)) {
			firstOccurrences.Add(c);
			charSet.Add(c);
		}
	}
	return firstOccurrences;
}
Set<char> findRepeatedCharacters(const std::string& str) {                         //usual way
	Set<char> repeatedCharacters;

	for (size_t i = 0; i < str.size(); ++i) {
		char currentChar = str[i];
		bool isRepeated = false;
		for (size_t j = i + 1; j < str.size(); ++j) {
			if (str[j] == currentChar) {
				isRepeated = true;
				break;
			}
		}
		if (isRepeated) {
			repeatedCharacters.Add(currentChar);
		}
	}

	return repeatedCharacters;
}
//Set<char> findRepeatedCharacters(const std::string& str) {                       // Tried to write using STL
//	Set<char> repeatedCharacters;
//
//	for (size_t i = 0; i < str.size(); ++i) {
//		char currentChar = str[i];
//		if (std::count(str.begin() + i + 1, str.end(), currentChar) > 0) {
//			repeatedCharacters.Add(currentChar);
//		}
//	}
//
//	return repeatedCharacters;
//}

Set<char> getNonRepeatedCharacters(const std::string& str) {
	Set<char> firstOccurrences = getFirstOccurrences(str);
	Set<char> repeatedCharacters = findRepeatedCharacters(str);
	return firstOccurrences.Difference(repeatedCharacters);
}
           //main
//std::string str = "abracadabra";
//Set<char> firstOccurrences = getFirstOccurrences(str);
//std::cout << "First occurrence of each letter: ";
//firstOccurrences.Print();
//
//Set<char> repeatedCharacters = findRepeatedCharacters(str);
//std::cout << "Repeated characters: ";
//repeatedCharacters.Print();
//
//Set<char> nonRepeatedCharacters = getNonRepeatedCharacters(str);
//std::cout << "Non-repeated characters: ";
//nonRepeatedCharacters.Print();

//In our implementation of the set, the elements during addition are placed in ascending order, so when printing, the order will be "abcdr".
//To make it like yours, you should change the add method so that it doesn't take into account the order of the elements, here's how


//template<typename T>
//inline void Set<T>::Add(const T& value)
//{
//	Node<T>* newNode = new Node<T>(value);
//	newNode->next = nullptr;  
//
//	if (head == nullptr) {
//		head = newNode;
//	}
//	else {
//		Node<T>* current = head;
//		while (current->next != nullptr) {
//			current = current->next;
//		}
//		current->next = newNode;
//	}
//	++size; 
//}