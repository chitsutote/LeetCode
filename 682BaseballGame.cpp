#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main(){

	vector<string> ops = {"5","-2","4","C","D","9","+","+"};

	int sum = 0;

	vector<int> round;

	for(int i = 0 ;i < ops.size();i++){
	
		if(ops[i] == "C"){
			
			sum -=round.back();
			
			round.pop_back();

		}else if(ops[i] == "D"){
			int score = 2*round.back();
			sum += score;
			round.push_back(score);

		}else if(ops[i] == "+"){
			int tmp = round[round.size()-1] + round[round.size()-2];
			sum+= tmp;
			round.push_back(tmp);
		}else{
			sum += stoi(ops[i]);
			round.push_back(stoi(ops[i]));
		}
	}
	
	cout << sum << endl;
}
