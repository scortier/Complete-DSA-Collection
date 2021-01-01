//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

// Function to implement split function
void split(const string &s, char delimeter,
           vector<string> &words)
{
	string token;
	stringstream tokenStream(s);

	while (getline(tokenStream, token, delimeter))
		words.push_back(token);
}



int main() {

}