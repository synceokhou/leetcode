#include <cstdio>
#include <cstring>


#ifndef MAX
#define MAX 100
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
		int i = size - 1;
		printf("%d", data[i]);
		for (i = size - 2; i >= 0; --i)
		{
			printf("%04d", data[i]);
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
char ret[10000];
char input[10000];



int main()
{
	
	int temp;

	while(scanf("%d %d", &m, &n) != EOF)
	{

		scanf("%s", input);
		int length = strlen(input);

		a.set(0);
		b.set(1);
		for (int i = length-1; i >= 0; --i)
		{
			if ('0' <= input[i] && input[i] <= '9')
			{
				temp = input[i] - '0';
			}
			else
			{
				temp = input[i] - 'A' + 10;
			}
			a = a + b * temp;
			b = b * m;
		}



		int ret_length = 0;
		
		do
		{
			temp = a % n;
			if ( 36 >= temp && temp >= 10)
			{
				ret[ret_length++] = 'a' + temp - 10;
			}
			else
			{
				ret[ret_length++] = '0' + temp;
			}
			a = a / n;
		} while(a.size != 1 || a.data[0] != 0);

		for (int i = ret_length-1; i >=0 ; --i)
		{
			printf("%c", ret[i]);
		}
		printf("\n");
	}

	return 0;
}