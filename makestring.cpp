#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

// 将 argv[1], argv[2] 转换为 int 类型
int ToInt(char number[]);

// 从最小位到最大位的循环
void Boom(int a, int b, char c[], char d[]);
// 将生成的排列写入文件 
void A(char a[]);

int main(int argc, char *argv [])
{

	if (argc < 2)
	{
		cout << "Usage: makestring.exe [min] [max] [chars]\n";
		cout << "\n";
		cout << "-o Output filename\n";
		exit(1);
	}
	ofstream Fuckout;
	Fuckout.open("p.txt", ios::app);
	Fuckout << "AAAAAAAAA";
	
	int _min = ToInt(argv[1]);
	int _max = ToInt(argv[2]);
	
	for (int i = _min; i <= _max; i++)
	{
		char A[i];
		Boom(i, i, argv[3], A);	
	}

	return 0;
}

int ToInt(char number[])
{
	int D = 0;
	int pod = 0;
	int length = strlen(number);
	
	for (int i = 0; i < length; i++)
	{
		pod = int(number[i]) - 48;
		D += pod * pow(10, (length-i-1));
	}

	return D;
}

void Boom(int a, int b, char c[], char d[])
{
	if (a > 0)
	{
		for (int i = 0; i < strlen(c); i++)
		{
			d[b-a] = c[i];
			Boom(a-1, b, c, d);
		}
	}
	else
	{
		d[b] = '\0';
//		cout << d << endl;
		A(d);		
	}
}

void A(char a[])
{
	ofstream fout;
	fout.open("C:/Users/FBI/Documents/C/a.txt", ios::app);
	fout << a << endl;
}
