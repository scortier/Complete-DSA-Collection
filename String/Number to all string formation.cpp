#include<bits/stdc++.h>
using namespace std;

void convTOstring(string str, string osf, char *mapping)
{
	if (str.size() == 0)
	{
		cout << osf << endl;
		return;
	}
	int first_no = str[0] - '0';
	int sec_no;
	if (str.size() >= 2)
	{
		sec_no = stoi(str.substr(0, 2));
		if (sec_no <= 26)
		{
			convTOstring(str.substr(2), osf + mapping[sec_no], mapping);

		}
		convTOstring(str.substr(1), osf + mapping[first_no], mapping);
	}
	else
	{
		convTOstring(str.substr(1), osf + mapping[first_no], mapping);
	}
}


int main() {
	string s; cin >> s;
	string osf = " ";
	char mapping[27] = {'#', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	convTOstring(s, " ", mapping);

}