#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <stack>
using namespace std;
void boom()
{
    float x,y;
    int z,t;        //x,y分别表示所产生的两个数，z来控制做加减乘除
    int first_num,second_num,third_num,fourth_num;
    srand(time(NULL));
    int n;
    float k;
    float d;//代表输入的答案
    float daan[100];//代表正确答案
    int zq=0;//用来表示正确答案的个数
    int cw=0;//用来表示错误答案的个数
	int f;//判断整数或者分数
//	int g;//判断打印空行
	int h;//判断括号个数
    cout<<"需要列出多少到数学题?"<<endl;
    cin>>n; 
    cout<<"********************************"<<endl;
	cout<<"请输入要生成的四则运算种类(输入1为整数，否则为真分数):"<<endl;
	cin>>f;
//	cout<<"请输入打印时每道题需要空几行(请输入整数):"<<endl;
//	cin>>g;
	//cout<<"请输入需要的括号个数，0代表不需要,最高2"<<endl;
	//cin>>h;
    for(int i=0;i<n;i++)
  {
        z=rand()%4;
        first_num=rand()%10;
        second_num=rand()%10;
        third_num=rand()%10;
        fourth_num=rand()%10;		
		if(f!=1)
		{
			if (second_num==1)
			{
				x=(float)first_num;
			}
			else if(first_num>second_num)
				{
					t=first_num;
					first_num=second_num;
					second_num=t;        
				}
				x=(float)first_num/second_num;
			if (fourth_num==1)
			{
				y=(float)third_num;
			}
			else if(third_num>fourth_num)
				{
					t=third_num;
					third_num=fourth_num;
					fourth_num=t;                
				}
				y=(float)third_num/fourth_num;
			z=rand()%4;
			switch(z)
			{
			case 0:
				cout<<i+1<<"、 "<<first_num<<"/"<<second_num<<"+"<<third_num<<"/"<<fourth_num<<"="<<"     "<<endl;
				daan[i+1]=x+y;
				break;
            
			case 1:
				cout<<i+1<<"、 "<<first_num<<"/"<<second_num<<"-"<<third_num<<"/"<<fourth_num<<"="<<"     "<<endl; 
			
				daan[i+1]=x-y;
				break;
			case 2:
				cout<<i+1<<"、 "<<first_num<<"/"<<second_num<<"*"<<third_num<<"/"<<fourth_num<<"="<<"     "<<endl;
			
				daan[i+1]=x*y;
				break;
			case 3:
				if(y!=0)
				{
				cout<<i+1<<"、 "<<first_num<<"/"<<second_num<<"÷"<<third_num<<"/"<<fourth_num<<"="<<"     "<<endl;
			
				}
				else
				{
					i=i-1;
				}
				daan[i+1]=(float)x/y;
				break;
			}
		}
			else
		{       z=rand()%4;
				first_num=rand()%10;
				x = first_num;
				second_num=rand()%10;
				y = second_num;
				switch(z)
				{
				case 0:
				cout<<i+1<<"、 "<<x<<"+"<<y<<"="<<"    "<<endl;
				daan[i+1]=x + y;
				break;
				case 1:
				cout<<i+1<<"、"<<x<<"-"<<y<<"="<<"    "<<endl;
				daan[i+1]=x - y;
				break;
				case 2:
				cout<<i+1<<"、 "<<x<<"*"<<y<<"="<<"    "<<endl;
				daan[i+1]=x * y;
				break;
				case 3:
				try
				{
				daan[i+1]=x / y;
				cout<<i+1<<"、"<<x<<"/"<<y<<"="<<"    "<<endl;
				}
				catch(...)
				{
				i--;
				}
				}
		}

        if((i+1)%3==0)
        {
            for(int c=0;c<=1;c++)
            {
                cout<<endl;
            }
        }
        if((i+1)==n)
        {
            cout<<endl;
        }
 }	
    for(i=1;i<=n;i++)
    {
        cout<<"请作答:"<<endl;
        cout<<i<<"、";
        cin>>d;
        if(d==daan[i])
        {
            cout<<"恭喜您，回答正确！"<<endl;
            cout<<endl;
            zq=zq+1;
        }
        else
        {
            cout<<"回答错误，正确答案为："<<"  "<<daan[i]<<endl;
            cout<<endl;
            cw=cw+1;
        }
    }
    k=(float)zq/n;
    cout<<"回答正确的数量为："<<" "<<zq<<"个"<<endl;
    cout<<"回答错误的数量为："<<" "<<cw<<"个"<<endl;
    cout<<"正确率为："<<" "<<k<<endl;
}

double calculate(string s)
{
    stack<double> num;
    stack<char> op;
    string temp = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            temp += s[i];
        }
        if((s[i] < '0' || s[i] > '9') && temp != "")
        {
            num.push(atoi(temp.c_str()));
            temp = "";
        }
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            op.push(s[i]);
        }
        if(s[i] == '*' || s[i] == '/')
        {
            if(!op.empty())
            {
                char lastop = op.top();
                if(lastop == '/')
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    num.push(firstnum*1.0/secondnum);
                    op.pop();
                }
            }
            op.push(s[i]);
        }
        if(s[i] == '+' || s[i] == '-')
        {
            if(i == 0 || s[i-1] == '(' || s[i-1] == '[' || s[i-1] == '{')
            {
                num.push(0);
            }
            if(!op.empty())
            {
                char lastop = op.top();
                while(!op.empty() && (lastop == '*' || lastop == '/'))
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    if(lastop == '*')
                        num.push(firstnum*secondnum);
                    else if(lastop == '/')
                        num.push(firstnum*1.0/secondnum);
                    op.pop();
                    if(!op.empty())
                        lastop = op.top();
                }
                if(lastop == '-')
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    num.push(firstnum-secondnum);
                    op.pop();
                }
            }
            op.push(s[i]);
        }
        if(s[i] == ')')
        {
            if(!op.empty())
            {
                char lastop = op.top();
                while(!op.empty() && lastop != '(')
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    switch(lastop)
                    {
                        case '+':
                            num.push(firstnum+secondnum);
                            break;
                        case '-':
                            num.push(firstnum-secondnum);
                            break;
                        case '*':
                            num.push(firstnum*secondnum);
                            break;
                        case '/':
                            num.push(firstnum*1.0/secondnum);
                            break;
                    }
                    op.pop();
                    if(!op.empty())
                        lastop = op.top();
                }
                if(lastop == '(')
                    op.pop();
            }
        }
        if(s[i] == ']')
        {
            if(!op.empty())
            {
                char lastop = op.top();
                while(!op.empty() && lastop != '[')
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    switch(lastop)
                    {
                        case '+':
                            num.push(firstnum+secondnum);
                            break;
                        case '-':
                            num.push(firstnum-secondnum);
                            break;
                        case '*':
                            num.push(firstnum*secondnum);
                            break;
                        case '/':
                            num.push(firstnum*1.0/secondnum);
                            break;
                    }
                    op.pop();
                    if(!op.empty())
                        lastop = op.top();
                }
                if(lastop == '[')
                    op.pop();
            }
        }
        if(s[i] == '}')
        {
            if(!op.empty())
            {
                char lastop = op.top();
                while(!op.empty() && lastop != '{')
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    switch(lastop)
                    {
                        case '+':
                            num.push(firstnum+secondnum);
                            break;
                        case '-':
                            num.push(firstnum-secondnum);
                            break;
                        case '*':
                            num.push(firstnum*secondnum);
                            break;
                        case '/':
                            num.push(firstnum*1.0/secondnum);
                            break;
                    }
                    op.pop();
                    if(!op.empty())
                        lastop = op.top();
                }
                if(lastop == '{')
                    op.pop();
            }
        }
    }
    if(temp != "")
        num.push(atoi(temp.c_str()));
    while(!op.empty())
    {
         char lastop = op.top();
         double secondnum = num.top();
         num.pop();
         double firstnum = num.top();
         num.pop();
         switch(lastop)
         {
             case '+':
                 num.push(firstnum+secondnum);
                 break;
             case '-':
                 num.push(firstnum-secondnum);
                 break;
             case '*':
                 num.push(firstnum*secondnum);
                 break;
             case '/':
                 num.push(firstnum*1.0/secondnum);
                 break;
         }
         op.pop();
    }
    if(num.empty())
        return 0;
    double value = num.top();
    num.pop();
    return value;
}
void zidingyi()
{
	string s;
	cout<<"请输入自定义的四则表达式，注意括号匹配"<<endl;
	cin>>s;
	cout << calculate(s) << endl;
	
}
int main()
{
	int h;//括号个数
	string s;
	cout<<"请输入是否需要括号括号，0代表不需要，其他代表自定义"<<endl;
	cin>>h;
    if(h==0)
	{
		boom(); 
	}
	else{
		zidingyi();
		}   
    int c;//c代表输入是否继续的数字
    cout<<"要继续答题吗？（0：继续  1：退出）"<<endl;
    cin>>c;
    if(c==0)
    {
        cout<<endl;
        main();
    }
    else
    {
        cout<<endl;
        return 0;
    }
    
    return 0;
}