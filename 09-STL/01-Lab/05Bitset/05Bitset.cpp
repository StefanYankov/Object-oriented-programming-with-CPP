#include <iostream>
#include <string>
#include <bitset>
#include <locale>

using namespace std;

int main()
{
	locale::global(locale("Bulgarian"));

	//initializing
	bitset<4> first(string("1001"));
	bitset<4> second(string("0011"));
	cout << "first = " << first << "\nsecond = " << second << endl;
	cout << "(" << first << "^=" << second << ") = " << (first ^= second) << endl; // 1010 (XOR,assign)
	cout << "(" << first << "&=" << second << ") = " << (first &= second) << endl; // 0010 (AND,assign)
	cout << "(" << first << "|=" << second << ") = " << (first |= second) << endl; // 0011 (OR,assign)
	cout << first << "<<=2 = " << (first <<= 2) << endl; // 1100 (SHL,assign)
	cout << first << ">>=1 = " << (first >>= 1) << endl; // 0110 (SHR,assign)
	cout << "~" << second << " = " << (~second) << endl; // 1100 (NOT)
	cout << second << "<<1" << " = " << (second << 1) << endl; // 0110 (SHL)
	cout << second << ">>1" << " = " << (second >> 1) << endl; // 0001 (SHR)
	cout << "(" << first << "==" << second << ") = " << (first == second) << endl; // false (0110==0011)
	cout << "(" << first << "!=" << second << ") = " << (first != second) << endl; // true (0110!=0011)
	cout << "(" << first << "&" << second << ") = " << (first & second) << endl; // 0010
	cout << "(" << first << "|" << second << ") = " << (first | second) << endl; // 0111
	cout << "(" << first << "^" << second << ") = " << (first ^ second) << endl; // 0101
	cout << "first.to_ulong() = " << first.to_ulong() << endl; // 6
	cout << "second.to_ulong() = " << second.to_ulong() << endl; // 3

	//initializing via long
	bitset<10> third(155);

	cout << "third = " << third.to_string() << endl; // 0010011011
	cout << "third.count() = " << third.count() << endl; // number of 1
	cout << "third.size() - third.count() = " << third.size() - third.count() << endl; // number of 0
	cout << "Обръщане на бит на позиция 2 = " << third.flip(2) << endl; // 0010011111
	cout << "Всички 1 стават 0, а всички 0 стават 1 = " << third.flip() << endl; // 1101100000
	cout << "Конвертиране до unsigned long integer = " << third.to_ulong() << endl;
	
	//all bits become 0
	third.reset();
	cout << "third = " << third.to_string() << endl; // 0000000000
	
	//all bits become 1
	cout << "third = " << third.set() << endl; // 1111111111

	//задава как да се смени бита на указаната позиция (първи параметър позиция, втори стойност на бит).
	//Ако няма втори параметър, се подразбира 1 
	cout << "third.set(2,0) = " << third.set(2, 0) << endl; // 1111111011
	cout << third.set(2) << endl; // 1111111111
	return 0;
}
