// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void oneclass();//一百以内加减法
void twoClass();//1.九九乘法表 2.九九乘法表内的除法 3.混合运算
void threeClass(); //1.万位以内的加减法 2.多位数乘一位数 3.两位数乘两位数 4.简单除法
void fourClass();//1.三位数乘两位数 2.复杂除法 3.小数的加减法
void fiveClass();//1.小数乘法 2.小数除法 3.分数加法 4.分数减法
void sixClass();//1.分数乘法 2.分数除法 3.负数加减法
void InitMenu();
char signconvertchar(int sign);
int IntCalAns(int a, int b, int sign);//整数的加减乘除运算
float floatCalAns(float a, float b, int sign);//小数的加减乘除运算
void choosemode(int mode);//年级切换
void showWrongQuestion();//输出错题
int convertFraction(int a,int b);//分数约分 

int score = 0;
FILE* fp1;
int main()
{
	int  mode;
	char flag = '/';
	srand(time(NULL));

	do{
		printf("欢迎进入小学生数学题习题练习程序：\n");
		InitMenu();
		printf("输入-1退出程序\n");
		while (scanf_s("%d", &mode) != 1 && mode >= 0 && mode <= 5)
		{
			printf("请输入正确的数字\n");
		}
		choosemode(mode);
		system("cls");
		getchar();
	} while (mode!=-1);
	printf("感谢您使用我的程序~\n");
	printf("联系方式：17cliang1@stu.edu.cn\n");

	return 0;

}

void oneclass() {
	int a, b, sign, ans, temp, input = 0;
	temp = 0;
	char flag = '/';
	char symbol;
	do {
		a = rand() % 19 + 1;
		b = rand() % (20 - a) + 1;//保证相加小于20
		sign = rand() % 2;
		symbol = signconvertchar(sign);
		if (sign == 1 && (a<b))
		{
			a = temp;
			a = b;
			b = temp;
		}
		ans = IntCalAns(a, b, sign);
		printf("%d %c %d =\n", a,symbol, b);
		scanf_s("%d", &input);
		if (ans == input)
		{
			score += 10;
			printf("恭喜你答对了！");
		}
		else {
			score -= 5;
			printf("正确的答案是：%d %c %d = %d \n", a,symbol, b, ans);
			if ((fopen_s(&fp1,"falseex.txt", "a")) !=0)
			{
				printf("错题本的文件不存在\n");
				exit(0);
			}
			fprintf(fp1, "%-4d", a);
			fprintf(fp1, "%-4c", symbol);
			fprintf(fp1, "%-4d", b);
			fprintf(fp1, " = ");
			fprintf(fp1, "%-4d", ans);
			fprintf(fp1, "\n");
			fclose(fp1);
		}
		printf("Continue? Y/N\n");
		getchar();//清除回车符
		scanf_s("%c", &flag);
	} while ( flag == 'y' || flag == 'Y');




}

void twoClass()
{
	int a, b, sign, ans, temp, input,mode,c,sign1 = 0;
	temp = 0;
	char flag = '/';
	char symbol,symbol1;
	do {
		mode = rand() % 3;// 1乘法 2除法 3混合运算
		if(mode==0||mode==1)
		{
			a = rand() % 9 + 1;
			b = rand() % 9 + 1;
			sign = (mode == 0) ? 2 : 3;
			symbol = signconvertchar(sign);
			ans = IntCalAns(a, b, 2);//先算乘法 逆向得到除法（保证是整除的）
			if (sign == 3)//逆向得到除法
			{
				temp = ans;
				ans = a;
				a = temp;
			}
			printf("%d %c %d =\n", a, symbol, b);
			scanf_s("%d", &input);
			if (ans == input)
			{
				score += 10;
				printf("恭喜你答对了！");
			}
			else {
				score -= 5;
				printf("正确的答案是：%d %c %d = %d \n", a, symbol, b, ans);
				if ((fopen_s(&fp1, "falseex.txt", "a")) != 0)
				{
					printf("错题本的文件不存在\n");
					exit(0);
				}
				fprintf(fp1, "%-4d", a);
				fprintf(fp1, "%-4c", symbol);
				fprintf(fp1, "%-4d", b);
				fprintf(fp1, " = ");
				fprintf(fp1, "%-4d", ans);
				fprintf(fp1, "\n");
				fclose(fp1);
			}
		}
		if (mode == 2)
		{
			int tempans = -1;
			a = rand() % 9 + 1;
			b = rand() % 9 + 1;
			c = rand() % 9 + 1;
			sign = rand() % 2;
			sign1 = rand() % 2+2;
			symbol = signconvertchar(sign);
			symbol1 = signconvertchar(sign1);
			tempans = IntCalAns(b, c, 2);//先算乘法 逆向得到除法（保证是整除的）
			if (sign1 == 3)
			{
				temp = tempans;
				tempans = b;
				b = temp;
			}
			ans = IntCalAns(a, tempans, sign);
			printf("%d %c %d %c %d =\n", a, symbol, b,symbol1,c);
			scanf_s("%d", &input);
			if (ans == input)
			{
				score += 10;
				printf("恭喜你答对了！");
			}
			else {
				score -= 5;
				printf("正确的答案是：%d %c %d %c %d = %d \n", a, symbol, b, symbol1, c ,ans);
				if ((fopen_s(&fp1, "falseex.txt", "a")) != 0)
				{
					printf("错题本的文件不存在\n");
					exit(0);
				}
				fprintf(fp1, "%-4d", a);
				fprintf(fp1, "%-4c", symbol);
				fprintf(fp1, "%-4d", b);
				fprintf(fp1, "%-4c", symbol1);
				fprintf(fp1, "%-4d", c);
				fprintf(fp1, " = ");
				fprintf(fp1, "%-4d", ans);
				fprintf(fp1, "\n");
				fclose(fp1);
			}
		}
		printf("Continue? Y/N\n");
		getchar();
		scanf_s("%c", &flag);
	} while (flag == 'y' || flag == 'Y');
}

void threeClass()
{
	int a, b, sign, ans, temp, input = 0;
	int mode = 0;//0的时候为万位加减法，1的时候多位数乘一位数 3.两位数乘两位数 4.简单除法
	temp = 0;
	char flag = '/';
	char symbol;
	do {
		mode = rand() % 4;
		if (mode == 0)
		{
			a = rand() % 100000 + 10000;
			b = rand() % 100000 + 10000;//万位数相加减
			sign = rand() % 2;//加减法
			symbol = signconvertchar(sign);
			if (sign == 1 && (a<b))
			{
				a = temp;
				a = b;
				b = temp;
			}
			ans = IntCalAns(a, b, sign);
		}
		else if (mode == 1)
		{
			a = rand() % 1000 + 10;
			b = rand() % 10;
			sign = 2;
			symbol = signconvertchar(sign);
			ans = IntCalAns(a, b, sign);
		}
		else if(mode == 2)
		{ 
			a = rand() % 100+10;
			b = rand() % 100+10;
			sign = 2;
			symbol = signconvertchar(sign);
			ans = IntCalAns(a, b, sign);
		}
		else if (mode == 3)
		{
			a = rand() % 100 + 10;
			b = rand() % 9 + 1;
			sign = 3;
			symbol = signconvertchar(sign);
			ans = IntCalAns(a, b, 2);//先算乘法 逆向得到除法（保证是整除的）
			//逆向得到除法
			{
				temp = ans;
				ans = a;
				a = temp;
			}

		}

		printf("%d %c %d =\n", a, symbol, b);
		scanf_s("%d", &input);
		if (ans == input)
		{
			score += 10;
			printf("恭喜你答对了！");
		}
		else {
			score -= 5;
			printf("正确的答案是：%d %c %d = %d \n", a, symbol, b, ans);
			if ((fopen_s(&fp1, "falseex.txt", "a")) != 0)
			{
				printf("错题本的文件不存在\n");
				exit(0);
			}
			fprintf(fp1, "%-4d", a);
			fprintf(fp1, "%-4c", symbol);
			fprintf(fp1, "%-4d", b);
			fprintf(fp1, " = ");
			fprintf(fp1, "%-4d", ans);
			fprintf(fp1, "\n");
			fclose(fp1);
		}
		printf("Continue? Y/N\n");
		getchar();//清除回车符
		scanf_s("%c", &flag);
	} while (flag == 'y' || flag == 'Y');
}

void fourClass()
{
	int a, b, sign, ans, temp, input = 0;
	int mode = 0;//0.三位数乘两位数 1.复杂除法 2.小数的加减法
	temp = 0;
	char flag = '/';
	char symbol;
	do {
		mode = rand()%3;
		if (mode == 0)
		{
			a = rand() % 900+100;
			b = rand() % 90 + 10;
			sign = 2;//乘法
			symbol = signconvertchar(sign);
			ans = IntCalAns(a, b, sign);
		}
		else if (mode == 1)
		{
			a = rand() % 100 +1;
			b = rand() % 90 + 10;
			sign = 3;
			symbol = signconvertchar(sign);
			ans = IntCalAns(a, b, 2);//先算乘法 逆向得到除法（保证是整除的）
									 //逆向得到除法
			{
				temp = ans;
				ans = a;
				a = temp;
			}
		}
		else if (mode == 2)
		{
			int intPart, deciPart;
			float f_a, f_b, f_ans,f_input;
			intPart = rand() % 100 + 1;
			deciPart = rand() % 9;
			f_a = intPart + deciPart / 10.0;
			intPart = rand() % 100 + 1;
			deciPart = rand() % 9;
			f_b = intPart + deciPart / 10.0;
			sign = rand() % 2;
			if (sign == 1 && (f_a<f_b))
			{
				f_a = temp;
				f_a = f_b;
				f_b = temp;
			}
			symbol = signconvertchar(sign);
			f_ans = floatCalAns(f_a,f_b, sign);

			printf("%.1f %c %.1f =\n", f_a, symbol, f_b);
			scanf_s("%f", &f_input);
			if (f_ans == f_input)
			{
				score += 10;
				printf("恭喜你答对了！");
			}
			else {
				score -= 5;
				printf("正确的答案是：%.1f %c %.1f = %.1f \n", f_a, symbol, f_b, f_ans);
				if ((fopen_s(&fp1, "falseex.txt", "a")) != 0)
				{
					printf("错题本的文件不存在\n");
					exit(0);
				}
				fprintf(fp1, "%-4.1f", f_a);
				fprintf(fp1, "%4c", symbol);
				fprintf(fp1, "%-4.1f", f_b);
				fprintf(fp1, " = ");
				fprintf(fp1, "%-4.1f", f_ans);
				fprintf(fp1, "\n");
				fclose(fp1);
			}
		}

		if(mode==0 || mode==1)
		{
			printf("%d %c %d =\n", a, symbol, b);
			scanf_s("%d", &input);
			if (ans == input)
			{
				score += 10;
				printf("恭喜你答对了！");
			}
			else {
				score -= 5;
				printf("正确的答案是：%d %c %d = %d \n", a, symbol, b, ans);
				if ((fopen_s(&fp1, "falseex.txt", "a")) != 0)
				{
					printf("错题本的文件不存在\n");
					exit(0);
				}
				fprintf(fp1, "%-4d", a);
				fprintf(fp1, "%4c", symbol);
				fprintf(fp1, "%-4d", b);
				fprintf(fp1, " = ");
				fprintf(fp1, "%-4d", ans);
				fprintf(fp1, "\n");
				fclose(fp1);
			}
		}

		printf("Continue? Y/N\n");
		getchar();//清除回车符
		scanf_s("%c", &flag);
	} while (flag == 'y' || flag == 'Y');
}

void fiveClass()
{
	int a, b, c,d,sign, ans, temp, input = 0;
	int s_ans[2];
	int s_input[2];
	int intPart, deciPart;
	float f_a, f_b, f_ans, f_input;
	int mode = 0;//1.小数乘法 2.小数除法 3.分数加法 4.分数减法
	temp = 0;
	char flag = '/';
	char symbol;
	do {
		mode = rand()%3;
		if (mode == 0)
		{
			intPart = rand() % 100 + 1;
			deciPart = rand() % 9;
			f_a = intPart + deciPart / 10.0;
			intPart = rand() % 100 + 1;
			deciPart = rand() % 9;
			f_b = intPart + deciPart / 10.0;
			sign = 2;
			symbol = signconvertchar(sign);
			f_ans = floatCalAns(f_a, f_b, sign);
		}
		else if (mode == 1)
		{
			intPart = rand() % 100 + 1;
			deciPart = rand() % 9;
			f_a = intPart + deciPart / 10.0;
			intPart = rand() % 100 + 1;
			deciPart = rand() % 9;
			f_b = intPart + deciPart / 10.0;
			sign = 3;
			symbol = signconvertchar(sign);
			f_ans = floatCalAns(f_a, f_b, 2);//先算乘法 逆向得到除法（保证是整除的）
									 //逆向得到除法
			{
				temp = f_ans;
				f_ans = f_a;
				f_a = temp;
			}
		}
		else if (mode == 2)
		{
			a = rand() % 50 + 1;
			b = rand() % 50 + 1;
			c = rand() % 50 + 1;
			d = rand() % 50 + 1;
			int n = convertFraction(a, b);
			a /= n;
			b /= n;
			n = convertFraction(c, d);
			c /= n;
			d /= n;
			if (a*d - b*c < 0)
			{
				temp = a;
				a = b;
				b = temp;
				temp = d;
				d = c;
				c = temp;
				
			}
			sign = rand() % 2;
			symbol = signconvertchar(sign);
			switch (sign)
			{
			case 0:s_ans[0] = a*d + b*c; break;
			case 1:s_ans[0] = a*d - b*c; break;				
			}
			s_ans[1] = b*c;
			n = convertFraction(s_ans[0], s_ans[1]);
			s_ans[0] /= n;
			s_ans[1] /= n;
		}
		if (mode == 0 || mode == 1)
		{
			printf("%.1f %c %.1f =\n", f_a, symbol, f_b);
			scanf_s("%f", &f_input);
			if (f_ans == f_input)
			{
				score += 10;
				printf("恭喜你答对了！");
			}
			else {
				score -= 5;
				printf("正确的答案是：%.1f %c %.1f = %.1f \n", f_a, symbol, f_b, f_ans);
				if ((fopen_s(&fp1, "falseex.txt", "a")) != 0)
				{
					printf("错题本的文件不存在\n");
					exit(0);
				}
				fprintf(fp1, "%-4.1f", f_a);
				fprintf(fp1, "%-4c", symbol);
				fprintf(fp1, "%-4.1f", f_b);
				fprintf(fp1, " = ");
				fprintf(fp1, "%-4.1f", f_ans);
				fprintf(fp1, "\n");
				fclose(fp1);
			}
		}
		if (mode == 2)
		{
			printf("%d/%d %c %d/%d = \n",a,b,symbol,c,d);
			scanf_s("%d/%d", &s_input[0],&s_input[1]);
			if(s_ans[0]==s_input[0]&&s_ans[1]==s_input[1])
			{
				printf("恭喜你答对了！");
				score += 10;
			}
			else {
				score -= 5;
				printf("正确的答案是：%d/%d %c %d/%d =%d/%d \n", a, b, symbol, c, d,s_ans[0],s_ans[1]);
				if ((fopen_s(&fp1, "falseex.txt", "a")) != 0)
				{
					printf("错题本的文件不存在\n");
					exit(0);
				}
				fprintf(fp1, "%4d", a);
				fprintf(fp1, "/");
				fprintf(fp1, "%-4d",b);
				fprintf(fp1, " %c ",symbol);
				fprintf(fp1, "%4d", c);
				fprintf(fp1, "/");
				fprintf(fp1, "%-4d", d);
				fprintf(fp1, "=");
				fprintf(fp1, "%4d", s_ans[0]);
				fprintf(fp1, "/");
				fprintf(fp1, "%d", s_ans[1]);
				fprintf(fp1, "\n");
				fclose(fp1);
			}
		}
		printf("Continue? Y/N\n");
		getchar();//清除回车符
		scanf_s("%c", &flag);
	} while (flag == 'y' || flag == 'Y');
}

void sixClass()
{
	int a, b, c, d, sign, ans, temp, input = 0;
	int s_ans[2];
	int s_input[2];
	int mode = 0;//1.分数乘法 2.分数除法 3.负数加减法
	temp = 0;
	char flag = '/';
	char symbol;
	do {
		mode = rand() % 3;
		if (mode == 0 || mode == 1)
		{
			a = rand() % 50 + 1;
			b = rand() % 50 + 1;
			c = rand() % 50 + 1;
			d = rand() % 50 + 1;
			int n = convertFraction(a, b);
			a /= n;
			b /= n;
			n = convertFraction(c, d);
			c /= n;
			d /= n;

			sign = rand() % 2 + 2;
			symbol = signconvertchar(sign);
			switch (sign)
			{
			case 2:s_ans[0] = a*c; s_ans[1] = b*d; break;
			case 3:s_ans[0] = a*d; s_ans[1] = b*c; break;
			}
			n = convertFraction(s_ans[0], s_ans[1]);
			s_ans[0] /= n;
			s_ans[1] /= n;
		}
		else if (mode == 2)
		{
			a = rand() % 100 - 100;
			b = rand() % 100 - 100;
			sign = rand() % 2;
			symbol = signconvertchar(sign);
			ans = IntCalAns(a, b, sign);
			printf("%d %c %d =\n", a, symbol, b);
			scanf_s("%d", &input);
			if (ans == input)
			{
				score += 10;
				printf("恭喜你答对了！");
			}
		}
		if (mode == 0 || mode == 1)
		{
			printf("%d/%d %c %d/%d = \n", a, b, symbol, c, d);
			scanf_s("%d/%d", &s_input[0], &s_input[1]);
			if (s_ans[0] == s_input[0] && s_ans[1] == s_input[1])
			{
				printf("恭喜你答对了！");
				score += 10;
			}
			else {
				score -= 5;
				printf("正确的答案是：%d/%d %c %d/%d =%d/%d \n", a, b, symbol, c, d, s_ans[0], s_ans[1]);
				if ((fopen_s(&fp1, "falseex.txt", "a")) != 0)
				{
					printf("错题本的文件不存在\n");
					exit(0);
				}
				fprintf(fp1, "%-4d", a);
				fprintf(fp1, "/");
				fprintf(fp1, "%-4d", b);
				fprintf(fp1, " %-4c ", symbol);
				fprintf(fp1, "%4d", c);
				fprintf(fp1, "/");
				fprintf(fp1, "%-4d", d);
				fprintf(fp1, "=");
				fprintf(fp1, "%4d", s_ans[0]);
				fprintf(fp1, "/");
				fprintf(fp1, "%d", s_ans[1]);
				fprintf(fp1, "\n");
				fclose(fp1);
			}

			if (mode == 2)
			{
				printf("%d %c %d =\n", a, symbol, b);
				scanf_s("%d", &input);
				if (ans == input)
				{
					score += 10;
					printf("恭喜你答对了！");
				}
				else {
					score -= 5;
					printf("正确的答案是：%d %c %d = %d \n", a, symbol, b, ans);
					if ((fopen_s(&fp1, "falseex.txt", "a")) != 0)
					{
						printf("错题本的文件不存在\n");
						exit(0);
					}
					fprintf(fp1, "%-4d", a);
					fprintf(fp1, "%-4c", symbol);
					fprintf(fp1, "%-4d", b);
					fprintf(fp1, " = ");
					fprintf(fp1, "%-4d", ans);
					fprintf(fp1, "\n");
					fclose(fp1);
				}

			}
			printf("Continue? Y/N\n");
			getchar();//清除回车符
			scanf_s("%c", &flag);
		} 
	}while (flag == 'y' || flag == 'Y');
}

int IntCalAns(int a, int b, int sign)
{
	int ans;
	switch (sign) {
	case 0:
		ans = a + b; break;
	case 1:
		ans = a - b; break;
	case 2:
		ans = a*b; break;
	case 3:
		ans = a / b; break;//记得判断a%b是否等于0
	}
	return ans;
}
float floatCalAns(float a, float b, int sign)
{
	float ans;
	switch (sign) {
	case 0:
		ans = a + b; break;
	case 1:
		ans = a - b; break;
	case 2:
		ans = a*b; break;
	case 3:
		ans = a / b; break;
	}
	return ans;
}
void InitMenu()
{
	printf("输入0进入错题本\n");
	printf("输入1进入一年级的题目：100以内的加减法\n");
	printf("输入2进入二年级的题目：1.九九乘法表 2.九九乘法表内的除法 3.混合运算\n");
	printf("输入3进入三年级的题目：1.万位以内的加减法 2.多位数乘一位数 3.两位数乘两位数 4.简单除法\n");
	printf("输入4进入四年级的题目：1.三位数乘两位数 2.复杂除法 3.小数的加减法\n");
	printf("输入5进入五年级的题目：1.小数乘法 2.小数除法 3.分数加法 4.分数减法\n");
	printf("输入6进入六年级的题目：1.分数乘法 2.分数除法 3.负数加减法\n");
}
void choosemode(int mode)
{
	switch (mode) {
	case 0:showWrongQuestion(); break;
	case 1:oneclass(); break;
	case 2:twoClass(); break;
	case 3:threeClass(); break;
	case 4:fourClass(); break;
	case 5:fiveClass(); break;
	case 6:sixClass(); break;
	}

}
void showWrongQuestion()
{
	char ch = ' ';
	int flag;
	if ((fopen_s(&fp1, "falseex.txt", "r")) != 0)
	{
		printf("错题本的文件不存在\n");
		exit(0);
	}
	printf("你的错题如下：\n");
	ch = fgetc(fp1);
	while (ch!=EOF)
	{
		putchar(ch);
		ch = fgetc(fp1);
	}
	getchar();
	printf("输入1回到主界面\n");
	while (scanf_s("%d", &flag) != 1 && flag==1)
	{
		printf("请输入正确的数字\n");
	}
	system("cls");
}
int convertFraction(int a, int b)
{
	int temp;
	while (a%b != 0) {
		temp = a%b;
		a = b;
		b = temp;
	}
	return b;
}
char signconvertchar(int sign)
{
	switch (sign) {
	case 0: return '+';
	case 1: return '-';
	case 2: return '*';
	case 3: return '/';
	}

}

