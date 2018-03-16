#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#define MAX_VAL 100
#define MIN_LEN 2

using namespace std;

int my_random(void)
{
	return (int)(rand() % MAX_VAL);
}

int main(int argc, char* argv[])
{
	srand(0);
	int sz = MIN_LEN;
	if(argc >= 2){sz = max(atoi(argv[1]), MIN_LEN);}

	vector<int> a(sz);
	
	generate(a.begin(), a.end(), my_random); //stdlib
	
	cout << "Random Vector:\n";
	for(auto& ptr : a){
		cout << ptr << ", ";	
	}

	cout << "Sorted Vector:\n";
	sort(a.begin(), a.end(), [](int a, int b){return a<b;});
	
	for(auto& ptr : a){
		cout << ptr << ", ";	
	}
	cout << endl;
}
