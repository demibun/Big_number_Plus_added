#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct numbers
{
	char buf[31];
	char strnum[31];
	
};
void plus(struct numbers nums[])
{
	int i,j, sum, real_sum=0,carry = 0;
	char result[32]="";
	sprintf(nums[0].strnum, "%030s", nums->buf);
	sprintf(nums[1].strnum, "%030s", nums->buf);

	for (i = 29; i >= 0; i--)
	{
		sum = (nums[0].strnum[i] - '0') + (nums[1].strnum[i] - '0') + carry;
		carry = sum / 10;
		sum = sum % 10;
		result[i + 1] = sum + '0';
	}
	result[0] = carry + '0';

	for (i = 0; result[i] == '0'; i++);
	printf("%s\n", result + i);
	printf("\n");
}
int mult_ten(int n)
{
	int i, result = 1;
	for (i = 0; i < n - 1; i++)
	{
		result *= 10;
	}
	return result;
}
int power(int a, int b)
{
	int i, result = 1;
	for (i = 0; i < b; i++)
	{
		result = a * result;
	}
	return result;
}
void put(int count[], char getf[], struct numbers nums[])
{
	int i, j, sum = 0, count_rep = 0, k = 0;
	for (j = 0; j < 2; j++)
	{
		for (i = 0; i < count[j]; i++)
		{
			k = 0;
			for (i = 0; i < count[j]; i++)
			{
				nums[j].buf[k++] = getf[i];
				nums[j].buf[k] = '\0';
				
			}
			
			
		}
		
	}

}
int main(void)
{
	char geti[100] /* 공백 포함 입력 */, getf[100] = { 0 }; /* 공백 제거 */
	int num[100] = { 0 }, i, j = 0, num_len = 0, len = 0, lenf = 0,
		count[100] = { 0 } /* 자릿수 */, index = 0, oper[10] = { 0 }, sum = 0, oper_index = 0, result = 0, numIdx;
	struct numbers numbs[10];
	printf("사용법: 숫자와 연산자를 입력하고 엔터를 누르세요.\nex) 32 * 532 / 2 - 7 + 8\n\n");
	scanf(" %[^\n]", geti);

	len = strlen(geti);

	for (i = 0; i < len; i++)
	{
		if (geti[i] != ' ')
		{
			getf[j] = geti[i];
			j++;
		}

	}
	lenf = strlen(getf);

	for (i = 0; i < lenf; i++) // 모든 숫자와 연산자 확인
	{
		if ((getf[i] == '+') || (getf[i] == '-') || (getf[i] == '*') || (getf[i] == '/') || getf[i + 1] == '\0')
		{
			count[index] = num_len;
			index++;
			num_len = 0;
			count[i + 1] = count[i] * 10;
			oper[oper_index] = getf[i];
			oper_index++;
		}
		else
		{
			num_len++;
		}
	}
	count[index - 1]++;

	put(count, getf, numbs);
	

	numIdx = oper_index + 1;
	for (i = 0; i < oper_index; i++)

	{

		if (oper[i] == '*')

		{

			num[i] = num[i] * num[i + 1];

			for (j = i + 1; j < numIdx; j++)

				num[j] = num[j + 1];

			numIdx -= 1;

			for (j = i; j < oper_index; j++)

				oper[j] = oper[j + 1];

			oper_index -= 1;

			i -= 1;

		}

		else if (oper[i] == '/')

		{

			num[i] = num[i] / num[i + 1];

			for (j = i + 1; j < numIdx; j++)

				num[j] = num[j + 1];

			numIdx -= 1;

			for (j = i; j <oper_index; j++)

				oper[j] = oper[j + 1];

			oper_index -= 1;

			i -= 1;

		}

	}

	result = num[0];

	for (i = 0; i < oper_index; i++)

	{

		if (oper[i] == '+')

			plus(numbs);

		else if (oper[i] == '-')

			result -= num[i + 1];

	}
	

}
