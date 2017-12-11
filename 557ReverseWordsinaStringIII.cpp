#include <iostream>
#include <string>

using namespace std;

int main(){

	string s = "Let's take LeetCode contest";

	int pos;

	string tmp;


	for(int i = 0; i < s.size(); i++){
	
		pos = s.find(" ",i);//find the space index
		if( pos > 0){

			tmp = s.substr(i,pos-i);
			// Do reverse
			for( int j = 0 ; j < tmp.length()/2; j++){
				char tmpChar = tmp[j];
				//cout << "tmpChar " << tmpChar << endl;
				tmp[j] = tmp[tmp.length()-1-j];
				tmp[tmp.length()-1-j] = tmpChar;
			}
			// replace the reverse str back
			s.replace(i,pos-i,tmp);
			i = pos;
		}else if( pos < 0){ //the last word in the str
			tmp = s.substr(i,s.size()-i);
			// Do reverse
			for( int j = 0 ; j < tmp.length()/2; j++){
				char tmpChar = tmp[j];
				tmp[j] = tmp[tmp.length()-j-1];
				tmp[tmp.length()-j-1] = tmpChar;
			}
			// replace the reverse str back
			s.replace(i,s.size()-i,tmp);
			i = s.size();
		}

		cout << tmp << endl;
	}

	cout << " s " << s << endl;

}
