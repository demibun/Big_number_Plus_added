/* for (i = max - 2; i >= 0; i--)
{
	sum = (nums[0].numstr[i] - '0') - (nums[1].numstr[i] - '0') + carry;

	if (sum >= 0)
	{
		carry = -(sum / 10);
		sum = sum % 10;
	}
	else
	{
		sum = 10 - (nums[1].numstr[i] - '0') + (nums[0].numstr[i] - '0') + carry;
		carry = -1;
	}

	result[i + 1] = sum + '0';
	result[0] = -carry + '0';
}

for (i = 0; result[i] == '0'; i++);
printf("%s\n", result + i);
printf("\n");
*/