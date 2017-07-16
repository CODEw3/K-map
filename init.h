/*ACCEPTS EQN IN SOP FORM AND INITIALIZES 2D ARRAY
	FIRST VERSION: MODIFICATIONS REQUIRED
	SAVE NEXT VERSION WITH v_2 AFTER NAME*/
	//NOTE:USE TILDE(~)for negation before variable
#ifndef _GLIBCXX_IOSTREAM
#include<iostream>
using namespace std;
#endif
#include<cmath>
class init
{
	private:
		char eqn[200];
		int a[200],b[200];
	protected:
		int table[5][5],no_of_var;
	public:
		//enter the equation in SOP form
		init()
		{
			cout<<"enter the equation in standard form(SOP)"<<endl;
			cin>>eqn;
		}
		void ch_no_ele()
		{
			int i=0;
			while(eqn[i]!='+')
			{
				if(eqn[i]=='\0')
					break;
				i++;
			}
			no_of_var=i;
		}
		void init_list(int no)
		{
			int t,count=0,k=0;
			int i_cnt=(no_of_var/2);
			int j_cnt=(no_of_var-i_cnt);
			i_cnt*=2;
			j_cnt*=2;
			for(int i=0;i<i_cnt;i++)
			{
				for(int j=0;j<j_cnt;j++)
				{
					for(count=0;count<=no;count++)
					{
						if(k==a[count])
						{
							table[i][j]=1;
							break;
						}
						table[i][j]=0;
					}

					k++;
				}
			}
			/*for(int i=0;i<i_cnt;i++)	//use this to check
			{
				for(int j=0;j<j_cnt;j++)
				{
					printf("%d\t",table[i][j]);
					printf("\n");
				}
			}*/
			
		}
		//plots 1 in table[] 
		void convert()
		{
			ch_no_ele();
			int no=0,k,sum,powr=(no_of_var-1);
			for(auto i=0;eqn[i]!='\0';i++)
			{
				k=1;
				if(eqn[i]=='+')
				{
					powr=no_of_var-1;
					no++;
					continue;
				}
				if(eqn[i]=='~')
				{
					k=0;
					i++;
					powr--;
					continue;
				}
				a[no]=a[no]+pow(2,powr);
				powr--;
			}
			init_list(no);
		}
		
		
};


