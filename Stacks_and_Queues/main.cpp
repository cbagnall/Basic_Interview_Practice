#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Container
{

private:
	stack<int> s;
	queue<int> q;
public:
	void push(int x);
	void pop(void);
	int top(void);
};

void Container::push(int x){
	cout << "push called with: " << x << endl;
}



int main(int argc, char* argv[])
{
	Container a;
	a.push(5);
	return 0;
}