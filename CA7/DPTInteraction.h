#pragma once
#include <iostream>
#include <sstream>

#include <cmath>
#include <algorithm>

#include <Windows.h>
#include <conio.h>

#include <string>
#include <vector>

using namespace std;

class DPTInteraction
{

public:

	void sieveOfEratosthenes();
	bool trialDivs(int value);
	bool testWilson(int value);
	bool testLucas(int value, int k);
};

void printQuit();
unsigned long long factorial(int value);
unsigned long long lucasNum(int value);
unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long mod);
vector<int> getFactors(int value);