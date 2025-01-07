#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string>

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

String^ NumberToText(int number)
{
	if (number == 0)
		return "nol";

	if (number < 0)
		return "minus " + NumberToText(-number);

	array<String^>^ numbers1 = gcnew array<String^>
		{ "nol", "bir", "ikki", "uch", "to'rt",
			"besh", "olti", "yetti", "sakkiz", "to'qqiz" };
	array<String^>^ numbers10 = gcnew array<String^>
		{ "o'n", "yigirma", "o'ttiz", "qirq",
			"ellik", "oltmish", "yetmish", "sakson", "to'qson" };

	String^ result = "";

	if ((number / 1000000) > 0)
	{
		result += NumberToText(number / 1000000) + " million ";
		number %= 1000000;
	}

	if ((number / 1000) > 0)
	{
		result += NumberToText(number / 1000) + " ming ";
		number %= 1000;
	}

	if ((number / 100) > 0)
	{
		result += NumberToText(number / 100) + " yuz ";
		number %= 100;
	}

	if ((number / 10) > 0)
	{
		result += numbers10[number / 10 - 1] + " ";
		number %= 10;
	}

	if (number > 0)
	{
		result += numbers1[number] + " ";
	}

	return result->Trim();
}

int main(array<System::String^>^ args)
{
	double a = rand() % 10;
	double b = rand() % 10;

	// Find the minimum of two numbers
	Double^ c = std::min(a, b);
	Console::WriteLine("Min: {0}", c);

	// Calculate the power of a number
	double result = Math::Pow(a, b);
	Console::WriteLine("{0} ning {1}-darajasi: {2}", a, b, result);

	// Write the string to a file
	String^ s = "Hello, World!";
	File::WriteAllText("test.txt", s);

	// Read the file into a std::string
	std::ifstream file("test.txt");
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string s2 = buffer.str();
	std::cout << s2 << std::endl;

	// Create a dictionary with random numbers and their text representation
	Dictionary<String^, int>^ dict = gcnew Dictionary<String^, int>();
	Random^ r = gcnew Random();
	for (int i = 0; i < 10; i++)
	{
	start: int randNumber = r->Next(0, 100);
		String^ randNumberString = NumberToText(randNumber);
		if (!dict->ContainsKey(randNumberString))
		{
			dict->Add(randNumberString, randNumber);
		}
		else {
			goto start;
		}
	}
	// Print the dictionary
	for each (auto item in dict)
	{
		Console::WriteLine("{0} = {1}", item.Key, item.Value);
	}
	return 0;
}