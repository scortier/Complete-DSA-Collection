
// APPROACH 1
class Solution {
public:
	string multiply(string a, string b) {
		//base case
		if (a == "0" or b == "0")
			return "0";
		//array of max size
		vector<int>res(a.size() + b.size(), 0);
		int m = a.size() - 1, n = b.size() - 1;
		for (int i = m; i >= 0; i--)
		{
			for (int j = n; j >= 0; j--)
			{
				res[i + j + 1] += (a[i] - '0') * (b[j] - '0');
				res[i + j] += a[i + j + 1] / 10;
				res[i + j + 1] %= 10;
			}
		}

		//skip leading zeroes
		int i = 0;
		while (i < res.size() and res[i] == 0)
			i++;

		//transform the vector to a string
		string ans = "";
		while (i < res.size())
			ans.push_back(res[i++] + '0');

		return ans;
	}
};


/*
Approach :
MAGIC SOLUTION
let num1=(a+b) and num2=(c+d)
so num1*num2 = (a+b)*(c+d)=ac+ad+bc+bd
or 1234 * 5678
(1000+200+30+4)*(5000+600+70+8)=5000*4+600*30+70*200+8*1000;

*/
class Solution {
public:
	string multiply(string a, string b) {
		//base case
		if (a == "0" or b == "0")
			return "0";
		int m = a.size() - 1, n = b.size() - 1;
		int carry = 0;
		string product;
		for (int i = 0; i <= m + n || carry ; i++)
		{
			for (int j = max(0, i - n); j <= min(i, m); j++)
			{
				carry += (a[m - j] - '0') * (b[n - i + j] - '0');
			}
			product += carry % 10 + '0';
			carry /= 10;
		}
		reverse(product.begin(), product.end());
		return product;

	}
};
