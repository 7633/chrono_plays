// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <map>
#include <unordered_map>
#include <iterator>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Man
{
	string a;
	string b;
};

namespace std{
	template<>
	struct hash<Man>{
		size_t operator()(const Man &m){
			hash<string> h;
			return h(m.a) ^ h(m.b);
		}
	};

}

int _tmain(int argc, _TCHAR* argv[])
{
	/*array<int, 5> a = { 1, 2, 3 };
	for(auto x : a)
	{
		cout << x << endl;
	}
	cout << a.size();*/

	map<string, int> m; // = { { { "petro", 901 }, { "antonio", 27 } } };
	/*for (auto it : m){
		cout << it.first << " - " << it.second << endl;
	}*/

	unordered_map<string, int> um;
	
	auto t0 = system_clock::now();
	
	for (int i = 0; i <= 1000000; ++i){
		string s = "";
		int r = rand();
		s.append(to_string(r));
		m[s] = r;
	}
	
	auto t1 = system_clock::now();

	cout << duration_cast<milliseconds>(t1 - t0).count() << endl;

	t0 = system_clock::now();

	for (int i = 0; i <= 1000000; ++i){
		string s = "";
		int r = rand();
		s.append(to_string(r));
		um[s] = r;
	}

	t1 = system_clock::now();

	for (int it = 0; it <= um.bucket_count(); ++it){
		cout << um.bucket_size(it) << endl;
	}
	cout << duration_cast<milliseconds>(t1 - t0).count() << endl;

	/*multimap<string, int> m;
	m.insert(make_pair("abc", 1));
	m.insert(make_pair("abc", 2));
	m.insert(make_pair("abc", 3));

	cout << m.count("abc");

	auto it = m.equal_range("abc");
	for (auto it1 = it.first; it1 != it.second; ++it1){
		cout << it1->first << "-" << it1->second << endl;
	}*/
	
	return 0;
}

