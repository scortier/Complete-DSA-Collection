// power of 2 contain only one set bit.
class Solution {
public:
	// A helper method which returns 1 if n is a power of 2 else returns 0.
	int isPowerOfTwo(int n)
	{
		if (n && (!(n & (n - 1))))
			return 1;
		else
			return 0;
	}
	//OR
	int isPowerOfTwo(int n)
	{
		for (int i = 0; i < 32; i++)
		{
			if (n == pow(2, i))
			{
				return true;
				break;
			}
		}
		return false;

	}

	int findPosition(int N) {

		if (!isPowerOfTwo(N))
			return -1;

		int i = 1, pos = 1;

		// Iterate through bits of n till we find a set bit
		// i&n will be non-zero only when 'i' and 'n' have a set bit
		// at same position


		while (!(i & N)) {
			// Unset current bit and set the next bit in 'i'
			i = i << 1;

			// increment position
			++pos;
		}
		//REPLACE 39 TO 44 WITH
		while (N > 0)
		{

			i = i << 1;
			pos++;
		}

		return pos;
	}
};