/*combination
1d dp
isme ek coin lo aur usko har target valu 0 to last tk fin dkaro ki is particular target ko sirf 2=is coin coin se kitne tarike se bna sakte hai.

fir second itr m next coin lao aur pehle coin se fomr hue combination ki madad lete jao autr combn bantae jao


permutation
1d dp
isme har target val ko ek hi itr m saare coin se dekho ki form ho skta hai toh kon kon se ways hai
visualize - by making src to destn tree where src = target and dest=0 and saare coins se path bnao

target sum
2d dp
isme dp coinsay boolean banegi as koi bhi coin ko ek hi baar use kar skte haai
vahi cricket game wala funda lagao
maanlo curr coin nhi khel rha toh kya baaki coin n vo target achieve kar rkha hai toh badiya agr nhi toh dekho ag rcoin bat karega toh kya target achieve ho oaega
agr ek bhi case m true aagya toh shi hus cell p true return hojaega

*/

//combination code
//coin change - inf coins but not permutation

int dp[amt + 1];
dp[0] = 1;	//1 ko pay ka tarika humesha hota hai ki kuch len den na karega

for (int i = 0; i < coins.size(); i++) //coins ka loop
{
	for (int j = coins[i]; j < dp.size(); j++) //5 ka loop 5 target se aur usse aage hi chalega
	{
		dp[j] += dp[j - coins[i]];
	}
}


//permutation
int dp[amt + 1];

dp[0] = 1;

for (int i = 1; i < dp.size(); i++)
{
	for (int j = 0; j < coins.size(); j++)
	{
		if (coins[j] <= i)
			dp[j] += dp[i - coins[j]];
	}
}


//permutation
