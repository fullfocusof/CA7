#include "DPTInteraction.h"

void printQuit()
{
	cout << endl << endl << "Backspace - возврат в меню";

	int answ = _getch();
	bool press = false;

	while (!press)
	{
		if (answ == 8)
		{
			press = true;
			break;
		}
		else answ = _getch();
	}

	system("cls");
}

unsigned long long factorial(int value)
{
	unsigned long long result = 1;
	for (int i = 2; i <= value; ++i) 
	{
		result *= i;
	}
	return result;
}

unsigned long long lucasNum(int value)
{
	if (value == 0) return 2;
	if (value == 1) return 1;

	unsigned long long a = 2, b = 1, c;
	for (int i = 2; i <= value; ++i) 
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long mod)
{
	unsigned long long result = 1;
	base = base % mod;
	while (exp > 0) 
	{
		if (exp % 2 == 1) result = (result * base) % mod;
		exp = exp >> 1;
		base = (base * base) % mod;
	}
	return result;
}

vector<int> getFactors(int value)
{
	vector<int> result;

	if (value % 2 == 0)
	{
		result.push_back(2);
		while (value % 2 == 0) value /= 2;
	}

	for (int i = 3; i * i <= value; i += 2)
	{
		if (value % i == 0)
		{
			result.push_back(i);
			while (value % i == 0) value /= i;
		}
	}

	if (value > 2) result.push_back(value);

	return result;
}

void DPTInteraction::sieveOfEratosthenes()
{
	int limit;
	cout << "Введите число: ";
	cin >> limit;

	if (limit < 2) throw exception("Неверный ввод данных");

	vector<bool> nums(limit + 1, true);
	nums[0] = nums[1] = false;

	for (int i = 2; i * i <= limit; i++) 
	{
		if (nums[i])
		{
			for (int j = i * i; j <= limit; j += i)
			{
				nums[j] = false;
			}
		}
	}

	cout << "Полученные числа: ";
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i]) cout << i << " ";
	}
}

bool DPTInteraction::trialDivs(int value)
{
	if (value <= 1) return false;
	if (value <= 3) return true;
	if (value % 2 == 0 || value % 3 == 0) return false;

	for (int i = 5; i * i <= value; i += 6) 
	{
		if (value % i == 0 || value % (i + 2) == 0) return false;
	}
	return true;
}

bool DPTInteraction::testWilson(int value)
{
	if (value <= 1) return false;
	if (value <= 3) return true;

	unsigned long long fact = factorial(value - 1) + 1;
	return (fact % value == 0);
}

bool DPTInteraction::testLucas(int value, int k)
{
	if (value <= 1) return false;
	if (value <= 3) return true;
	if (value % 2 == 0) return false;

	int value_minus_1 = value - 1;
	vector<int> factors = getFactors(value_minus_1);

	for (int i = 0; i < k; ++i) 
	{
		int a = 2 + rand() % (value_minus_1 - 2 + 1);

		if (modExp(a, value_minus_1, value) != 1) cout << i << ": Число " << value << " не является простым" << endl;

		for (int q : factors) 
		{
			if (modExp(a, value_minus_1 / q, value) == 1) break;
			if (q == factors.back()) cout << i << ": Число " << value << " является простым" << endl;
		}
	}
	return false;
}