
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

#define NUM_TEST_CASES 5

using namespace std;

int solution(int X)
{
	string str_X = to_string(X);
	int strlen_X = str_X.length();
	vector<int> mask(strlen_X, 0);
	string new_str;

	for(int i = strlen_X - 1; i > 0; i--){
		if(str_X.at(i-1) == str_X.at(i)){ //if we find a duplicate
			if(i < strlen_X - 1 && (str_X.at(i+1) > str_X.at(i))){
				mask[i] = 3; //duplicate RV is greater (ideal candidate)
			}
			else if(i < strlen_X - 1 && (str_X.at(i+1) == str_X.at(i))){
				mask[i] = 2; //duplicate RV is equal
			}
			else {	 //duplicate RV is smaller			
				mask[i] = 1;
			}
		}
	}
	int max_val = *(max_element(mask.begin(), mask.end()));
	int maxpos;
	if(max_val > 2){ //if we have an ideal candidate pick the first pair element
		maxpos = 0;
		while(mask[maxpos] != max_val) {
			maxpos++;
		}
	}
	else { //otherwise remove the last pair element
		maxpos = strlen_X -1;
		while(mask[maxpos] != max_val) {
			maxpos--;
		} 
	}

	for(int i = 0, j = 0; i < strlen_X; i++){ //create new string
		if(i != maxpos){
			new_str.insert(j,str_X, i, 1);
			j++;
		}

	}
	return stoi(new_str.c_str());
} //solution

int main(int argc, char* argv[]){

	int test_arr[NUM_TEST_CASES];
	test_arr[0] = 122334455;
	test_arr[1] = 443221100;
	test_arr[2] = 1234566;
	test_arr[3] = 633111443;
	test_arr[4] = 882345999;

	int sol = 0;
	for(int i = 0; i < NUM_TEST_CASES; i++){
		sol = solution(test_arr[i]);
		cout << test_arr[i] << " ==> " << sol << endl;
	}
}