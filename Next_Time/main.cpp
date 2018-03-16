

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

#define ASCII_OFFSET 48
#define TIME_DIGITS	 4
#define MAX_HOURS 24


#define NUM_TEST_CASES 8

using namespace std;

int ConvertToMins(vector<int> time)
{
	int mins = (time[0]*10 + time[1])*60 + time[2]*10 + time[3];
	return mins;
}
string ConvertToTime(int mins)
{
	string result;
	int hours = (mins/60)%24;
	int minutes = mins%60;

	result.insert(0, to_string(minutes));
	if(minutes < 10){
		result.insert(0, "0");
	}
	result.insert(0, ":");
	result.insert(0, to_string(hours));
	if(hours < 10){
		result.insert(0, "0");
	}
	return result;
}

int DiffAvoidOverflow(int basetime, int futuretime){
	int diff = 0;
	if(basetime > futuretime){
		diff = (MAX_HOURS*60)-basetime + futuretime;
	}
	else{
		diff = futuretime - basetime;
	}
	return diff;
}

string solution(string& S)
{
	vector<int> digits(TIME_DIGITS);
	digits[0] = (int)(S.at(0) - ASCII_OFFSET);
	digits[1] = (int)(S.at(1) - ASCII_OFFSET);
	digits[2] = (int)(S.at(3) - ASCII_OFFSET);
	digits[3] = (int)(S.at(4) - ASCII_OFFSET);

	int orig_time = ConvertToMins(digits);
	vector<int> minute_permutations;
	sort(digits.begin(), digits.end());
	do{
		int mins = ConvertToMins(digits);
		if(mins < MAX_HOURS*60) { //only valid permutations
			minute_permutations.push_back(mins);
		}
	}
	while(next_permutation(digits.begin(), digits.end()));

	int diff = 0, min = 100000000;
	for(int i = 0; i < (int)minute_permutations.size(); i++){	
		diff = DiffAvoidOverflow(orig_time, minute_permutations[i]); //compare against self so diff must be > 0
		if(diff > 0 && diff < min){
			min = diff;
		}
	}
	if(min == 100000000){ //exactly 24 hrs
		min = 0;
	}
	string result = ConvertToTime(min+orig_time);
	return result;
}

int main(int argc, char* argv[])
{
	vector<string> times(NUM_TEST_CASES);
	times[0] = "01:12";
	times[1] = "12:12";
	times[2] = "23:59";
	times[3] = "11:11";
	times[4] = "03:20";
	times[5] = "02:40";
	times[6] = "23:50";
	times[7] = "22:42";

	for(int i = 0; i < NUM_TEST_CASES; i++){
		string sol = solution(times[i]);
		cout << "Next time after " << times[i] << " is: " << sol << endl;
	}
	return 0;
}


