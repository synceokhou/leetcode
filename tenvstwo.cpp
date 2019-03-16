#include <cstdio>
#include <cstring>


#ifndef MAX
#define MAX 10000
#endif

struct bigInt
{
	int data[MAX];
	int size;

	void init()
	{
		for (int i = 0; i < MAX; ++i)
		{
			data[i] = 0;
		}
		size = 0;
	}

	void set(int a)
	{
		init();
		do
		{
			data[size++] = a % 10000;
			a = a / 10000;
		} while (a != 0);
	}

	void output()
	{
		for (int i = size - 1; i >= 0; --i)
		{
			if (i != size - 1)
			{
				printf("%04d", data[i]);
				
			}
			else if (data[i] != 0)
			{
				printf("%d", data[i]);
			}
			
		}
		printf("\n");
	}

	bigInt operator * (int x) const
	{
		bigInt ret;
		ret.init();
		int carry = 0;
		for (int i = 0; i < size; ++i)
		{
			int temp = data[i] * x + carry;
			carry = temp / 10000;
			ret.data[ret.size++] = temp % 10000;
		}
		if (carry != 0)
		{
			ret.data[ret.size++] = carry;
		}
		return ret;
	}

	bigInt operator + (const bigInt &a) const
	{
		bigInt ret;
		ret.init();
		int carry = 0;
		for (int i = 0; i < a.size || i < size ; ++i)
		{
			int temp = a.data[i] + data[i] + carry;
			carry = temp / 10000;
			ret.data[ret.size++] = temp % 10000;
		}
		if (carry != 0)
		{
			ret.data[ret.size++] = carry;
		}
		return ret;
	}

	bigInt operator / (int a) const
	{
		bigInt ret;
		ret.init();
		int temp = 0;
		int carry = 0;
		for (int i = size - 1; i >= 0; --i)
		{
			temp = data[i] + carry * 10000;
			carry = temp % a;
			ret.data[i] = temp / a;
		}
		ret.size = 0;
		for (int i = 0; i < MAX; ++i)
		{
			if (ret.data[i] != 0)
			{
				ret.size = i;
			}
		}
		ret.size++;
		return ret;
	}


	int operator % (int a) const
	{
		int ret = 0;

		for (int i = size - 1; i >= 0; --i)
		{
			ret = (data[i] + ret * 10000) % a;
		}
		return ret;
	}


};





int m, n;
bigInt a;
bigInt b;
char ret[100000];
char input[1001];



int main()
{

	int temp;

	while(scanf("%s", input) != EOF)
	{

		int length = strlen(input);

		a.set(0);
		b.set(1);
		for (int i = length-1; i >= 0; --i)
		{
			temp = input[i] - '0';
			a = a + b * temp;
			b = b * 10;
		}

		int ret_length = 0;
		
		do
		{
			temp = a % 2;
			ret[ret_length++] = '0' + temp;
			a = a / 2;
		} while(a.size != 1 || a.data[0] != 0);

		a.set(0);
		b.set(1);
		for (int i = ret_length-1; i >= 0; --i)
		{
			temp = ret[i] - '0';
			a = a + b * temp;
			b = b * 2;
		}

		a.output();
	}

	return 0;
}