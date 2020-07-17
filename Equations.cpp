#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <sstream>
using namespace std;

class equations
{
	string equation;
public:
	void setequation(string s)
	{
		equation=s;
	}
	string getequation()
	{
		return equation;
	}

	string proper_equation()
	{
		string s=getequation();
	string str[100],var[100],coff[100],cons[100],eq[100],equ[100],variable[100],coffcient[100],equation[100];
	string prop_equation;
	int j=0,i=0;
	int l=s.length();

	for(i=1;i<l;i++)
	{
		if(s.at(i)=='+'||s.at(i)=='-'||s.at(i)=='=')
		{
			str[j]=s.substr(0,i);
			

			s=s.erase(0,i);
			j++;
			l=s.length();
			i=1;
			



		}
	
	}
		str[j]=s;
		

	for (int k=0;k<=j;k++)
	{
		int l=str[k].length();
		for(int m=0;m<l;m++)
		
			{
				float a=str[k].at(m);
		if(a>=65&&a<=90)
			{
				a+=32;
		str[k].at(m)=a;
		}
	
		


		}
		

		}
	int f=0;
	for(int y=0;y<=j;y++)
	{
		if(str[y].at(0)=='=')
		{
			f=y;
			int n=str[y].length();
		
		for (int m=0;m<n;m++)
		{
			float b=str[y].at(1);
			float a=str[y].at(m);
			if(a>=97&&a<=122)
			{
				if(b>=48&&b<=57||b>=97&&b<=122)
					str[y].at(0)='-';
				if(str[y].at(1)=='-')
					str[y].at(1)='+';
				
				break;

			}
		} 
		}
		
		
	}
	for(int d=0;d<f;d++)
	{
		int p=0;
		int n=str[d].length();
		for (int m=0;m<n;m++)
		{
			float a=str[d].at(m);
			if(a>=97&&a<=122)
				{
					
					 p=1;
					 break;

		}
		
					

		}
		if(p!=1)
		{
				if(str[d].at(0)=='+')
					str[d].at(0)='-';
				else if(str[d].at(0)=='-')
					str[d].at(0)='+';
				else
					str[d]='-'+str[d];
				
		}
	}
	for(int d=f+1;d<=j;d++)
	{
		int n=str[d].length();
		for (int m=0;m<n;m++)
		{
			float a=str[d].at(m);
			if(a>=97&&a<=122)
			{
				if(str[d].at(0)=='+')
					str[d].at(0)='-';
				else
					str[d].at(0)='+';
				break;
			}
		}
	}
	for(int k=0;k<=j;k++)
	{
		if(str[k].at(0)=='=')
			str[k]=str[k].substr(1);
	}
	int c=0,v=0,g=0;
	for(int k=0;k<=j;k++)
	{
		int o=0;
		int a=str[k].length();
		for(int m=0;m<a;m++)
		{
			float b=str[k].at(m);
			if(b>=97&&b<=122)
			{
				if(m==0)
				{
					coff[c]='1';
					var[v]=str[k];
					c++;
					v++;
					o=1;
					break;
				}
				else
				{

				int s=m;
				coff[c]=str[k].substr(0,s);
				var[v]=str[k].substr(s);
				c++;
				v++;
				o=1;
				break;
				}
			}

		}
		if(o!=1)
		{
			cons[g]=str[k];
			g++;
		}
	}
	int con=g-1;
	int var1=v-1;
	int coff1=c-1;
	for(int k=0;k<=coff1;k++)
	{
		if(coff[k]=="-")
			coff[k]="-1";
		if(coff[k]=="+")
			coff[k]="+1";

	}
	
	
	float sum=0;
	for(int k=0;k<=con;k++)
	{
		float v;
		v=atof(cons[k].c_str());
		sum+=v;


	}
	float q=sum;
	string constant;
	ostringstream ss;
	ss<<q;
	constant=ss.str();
	eq[0]=constant;

	int z=1,y=0;
	for(int k=0;k<=var1;k++)
	{
		for(int e=k+1;e<=var1;e++)
		{
			if(var[k]=="")
				{
					break;
				}
			
			if(var[k]==var[e])
			{
				
				
				
				

				string s1=coff[k];
				string s2=coff[e];
				float coff2= atof(s1.c_str());
				float coff3=atof(s2.c_str());
				float coff4=coff2+coff3;
				ostringstream ss;
				ss<<coff4;
				coff[k]=ss.str();
				var[e].clear();
				coff[e].clear();
				}
				
			
				
			}
		if(coff[k]!=""&&var[k]!="")
		{
		eq[z]=coff[k]+var[k];
		z++;
		}
			
		}	
	for(int k=0;k<z;k++)
	{
		if (eq[k].at(0)=='+')
			eq[k]=eq[k].substr(1);
	}
	for(int k=1;k<z;k++)
	{
		if (eq[k].at(0)=='0'&&eq[k].at(1)!='.')
			eq[k].clear();
	}
	
	int r=0;
	for(int k=0;k<z;k++)
	{
		if(eq[k]!="")
		{
			equ[r]=eq[k];
			r++;
		}
	}
	
	

	string equa[100];
	for(int h=1;h<r;h++)
	{
			int a=equ[h].length();
		for(int m=0;m<a;m++)
		{
			float b=equ[h].at(m);
			if (b>=97&&b<=122)
			{
				equa[h]=equ[h].substr(m);
				coffcient[h]=equ[h].substr(0,m);
				break;
			}
		}
	}

	for(int h=1;h<r;h++)
	{
		for(int g=h+1;g<r;g++)
		{
			if(equa[g]<equa[h])
			{
				string temp=equa[h];
				equa[h]=equa[g];
				equa[g]=temp;
				string temp2=coffcient[h];
				coffcient[h]=coffcient[g];
				coffcient[g]=temp2;
			}
		}
	}


	
	equation[0]=eq[0];
	for(int k=1;k<r;k++)
	{
		equation[k]=coffcient[k]+equa[k];

	}
	for(int k=1;k<r;k++)
	{
		float a=equation[k].at(0);
		if(a>=97&&a<=122||a>=48&&a<=57)
		{
			equation[k]="+"+equation[k];
		}
	}
	prop_equation=equation[1];
	for(int k=2;k<r;k++)
	{
		prop_equation=prop_equation+equation[k];
	}
	prop_equation=prop_equation+"="+equation[0];
	if(prop_equation.at(0)=='+')
		prop_equation=prop_equation.substr(1);

	return prop_equation;

	}
	
	string cofficent(string s1)
	{
		string s=proper_equation();
		

	string s3,str[100],coff[100],var[100],cons[100];
	int j=0,i=0;
	int l=s.length();

	for(i=1;i<l;i++)
	{
		if(s.at(i)=='+'||s.at(i)=='-'||s.at(i)=='=')
		{
			str[j]=s.substr(0,i);
			

			s=s.erase(0,i);
			j++;
			l=s.length();
			i=1;
			



		}
	
	}
		str[j]=s;
		
			int c=0,v=0,g=0;
	for(int k=0;k<=j;k++)
	{
		int o=0;
		int a=str[k].length();
		for(int m=0;m<a;m++)
		{
			float b=str[k].at(m);
			if(b>=97&&b<=122)
			{
				if(m==0)
				{
					coff[c]='1';
					var[v]=str[k];
					c++;
					v++;
					o=1;
					break;
				}
				else
				{

				int s=m;
				coff[c]=str[k].substr(0,s);
				var[v]=str[k].substr(s);
				c++;
				v++;
				o=1;
				break;
				}
			}

		}
		if(o!=1)
		{
			cons[g]=str[k];
			g++;
		}
	}
	int con=g-1;
	int var1=v-1;
	int coff1=c-1;
	for(int k=0;k<=coff1;k++)
	{
		if(coff[k]=="-")
			coff[k]="-1";
		if(coff[k]=="+")
			coff[k]="+1";

	}
	int h=0;
	for(int k=0;k<=var1;k++)
	{
		if(s1==var[k])
		{
			s3=coff[k];
			h=1;

		}
		
	}
	if(h!=1)
		s3="0";

	return s3;


	}

	string add(string s2)
	{
		string s1=proper_equation();
		
	string str[100],coff[100],var[100],coff1[100],var1[100],str1[100],summ[100],cons[1],cons1[1];
	int j=0,i=0;
	int l=s1.length();

	for(i=1;i<l;i++)
	{
		if(s1.at(i)=='+'||s1.at(i)=='-'||s1.at(i)=='=')
		{
			str[j]=s1.substr(0,i);
			

			s1=s1.erase(0,i);
			j++;
			l=s1.length();
			i=1;
			



		}
	
	}
		str[j]=s1;
		int c=0,v=0,g=0;
	for(int k=0;k<=j;k++)
	{
		int o=0;
		int a=str[k].length();
		for(int m=0;m<a;m++)
		{
			float b=str[k].at(m);
			if(b>=97&&b<=122)
			{
				if(m==0)
				{
					coff[c]='1';
					var[v]=str[k];
					c++;
					v++;
					o=1;
					break;
				}
				else
				{

				int s=m;
				coff[c]=str[k].substr(0,s);
				var[v]=str[k].substr(s);
				c++;
				v++;
				o=1;
				break;
				}
			}
		}
		if(o!=1)
		{
			cons[g]=str[k];
			g++;
		}
	}
			for(int k=0;k<c;k++)
	{
		if(coff[k]=="-")
			coff[k]="-1";
		if(coff[k]=="+")
			coff[k]="+1";

	}
	
	
	int d=0,f=0;
	int p=s2.length();

	for(f=1;f<p;f++)
	{
		if(s2.at(f)=='+'||s2.at(f)=='-'||s2.at(f)=='=')
		{
			str1[d]=s2.substr(0,f);
			

			s2=s2.erase(0,f);
			d++;
			p=s2.length();
		f=1;
			



		}
	
	}
		str1[d]=s2;
		int c1=0,v1=0,g1=0;
	for(int k=0;k<=d;k++)
	{
		int o=0;
		int a=str1[k].length();
		for(int m=0;m<a;m++)
		{
			float b=str1[k].at(m);
			if(b>=97&&b<=122)
			{
				if(m==0)
				{
					coff1[c1]='1';
					var1[v1]=str1[k];
					c1++;
					v1++;
					o=1;
					break;
				}
				else
				{

				int s=m;
				coff1[c1]=str1[k].substr(0,s);
				var1[v1]=str1[k].substr(s);
				c1++;
				v1++;
				o=1;
				break;
				}
			}
		}
		if(o!=1)
		{
			cons1[g1]=str1[k];
			g1++;
		}
	}
		for(int k=0;k<c1;k++)
	{
		if(coff1[k]=="-")
			coff1[k]="-1";
		if(coff1[k]=="+")
			coff1[k]="+1";

	}
	

	int b=0;
	for(int k=0;k<v;k++)
	{
		int t=0;
		float sum=0;
		for(int y=0;y<v1;y++)
		{
			if(var[k]==var1[y])
			{
				sum=atof(coff[k].c_str())+atof(coff1[y].c_str());
				ostringstream ss;
				ss<<sum;
				coff1[y]=ss.str();
				summ[b]=coff1[y]+var1[y];
				var1[y].clear();
				b++;
			    t=1;


			}
		}
		if(t!=1)
		{
			summ[b]=coff[k]+var[k];
			b++;
		}

	}
	for(int k=0;k<v1;k++)
	{
		if(var1[k]!="")
		{
			summ[b]=coff1[k]+var1[k];
			b++;
		}

	}
	cons[0]=cons[0].substr(1);
	cons1[0]=cons1[0].substr(1);
	float constant=atof(cons[0].c_str())+atof(cons1[0].c_str());
	ostringstream ss;
	ss<<constant;
	summ[b]=ss.str();
	
	string equa[100],coffcient[100];
	for(int h=0;h<b;h++)
	{
			int a=summ[h].length();
		for(int m=0;m<a;m++)
		{
			float b=summ[h].at(m);
			if (b>=97&&b<=122)
			{
				equa[h]=summ[h].substr(m);
				coffcient[h]=summ[h].substr(0,m);
				break;
			}
		}
	}

	for(int h=0;h<b;h++)
	{
		for(int g=h+1;g<b;g++)
		{
			if(equa[g]<equa[h])
			{
				string temp=equa[h];
				equa[h]=equa[g];
				equa[g]=temp;
				string temp2=coffcient[h];
				coffcient[h]=coffcient[g];
				coffcient[g]=temp2;
			}
		}
	}
	for(int k=0;k<b;k++)
	{
		summ[k]=coffcient[k]+equa[k];

	}
	

	string summation;
	for(int k=0;k<b;k++)
	{
		if(summ[k].at(0)=='-'||summ[k].at(0)=='+')
			summ[k]=summ[k];
		else
			summ[k]="+"+summ[k];
		if(summ[k].at(1)=='0')
			summ[k].clear();
		summation=summation+summ[k];
		
	}
	summation=summation+"="+summ[b];
	if(summation.at(0)=='+')
		summation=summation.substr(1);
	
		return summation;

	}

	string subtract(string s2)
	{
		string s1=proper_equation();
		

		string str[100],coff[100],var[100],coff1[100],var1[100],str1[100],diff[100],cons[1],cons1[1];
		
	int j=0,i=0;
	int l=s1.length();

	for(i=1;i<l;i++)
	{
		if(s1.at(i)=='+'||s1.at(i)=='-'||s1.at(i)=='=')
		{
			str[j]=s1.substr(0,i);
			

			s1=s1.erase(0,i);
			j++;
			l=s1.length();
			i=1;
			



		}
	
	}
		str[j]=s1;
		int c=0,v=0,g=0;
	for(int k=0;k<=j;k++)
	{
		int o=0;
		int a=str[k].length();
		for(int m=0;m<a;m++)
		{
			float b=str[k].at(m);
			if(b>=97&&b<=122)
			{
				if(m==0)
				{
					coff[c]='1';
					var[v]=str[k];
					c++;
					v++;
					o=1;
					break;
				}
				else
				{

				int s=m;
				coff[c]=str[k].substr(0,s);
				var[v]=str[k].substr(s);
				c++;
				v++;
				o=1;
				break;
				}
			}
		}
		if(o!=1)
		{
			cons[g]=str[k];
			g++;
		}
	}
			for(int k=0;k<c;k++)
	{
		if(coff[k]=="-")
			coff[k]="-1";
		if(coff[k]=="+")
			coff[k]="+1";

	}
	
	
	int d=0,f=0;
	int p=s2.length();

	for(f=1;f<p;f++)
	{
		if(s2.at(f)=='+'||s2.at(f)=='-'||s2.at(f)=='=')
		{
			str1[d]=s2.substr(0,f);
			

			s2=s2.erase(0,f);
			d++;
			p=s2.length();
		f=1;
			



		}
	
	}
		str1[d]=s2;
		int c1=0,v1=0,g1=0;
	for(int k=0;k<=d;k++)
	{
		int o=0;
		int a=str1[k].length();
		for(int m=0;m<a;m++)
		{
			float b=str1[k].at(m);
			if(b>=97&&b<=122)
			{
				if(m==0)
				{
					coff1[c1]='1';
					var1[v1]=str1[k];
					c1++;
					v1++;
					o=1;
					break;
				}
				else
				{

				int s=m;
				coff1[c1]=str1[k].substr(0,s);
				var1[v1]=str1[k].substr(s);
				c1++;
				v1++;
				o=1;
				break;
				}
			}
		}
		if(o!=1)
		{
			cons1[g1]=str1[k];
			g1++;
		}
	}
		for(int k=0;k<c1;k++)
	{
		if(coff1[k]=="-")
			coff1[k]="-1";
		if(coff1[k]=="+")
			coff1[k]="+1";

	}
	

	int b=0;
	for(int k=0;k<v;k++)
	{
		int t=0;
		float dif=0;
		for(int y=0;y<v1;y++)
		{
			if(var[k]==var1[y])
			{
				dif=atof(coff[k].c_str())-atof(coff1[y].c_str());
				ostringstream ss;
				ss<<dif;
				coff1[y]=ss.str();
				diff[b]=coff1[y]+var1[y];
				var1[y].clear();
				b++;
			    t=1;


			}
		}
		if(t!=1)
		{
			diff[b]=coff[k]+var[k];
			b++;
		}

	}
	for(int k=0;k<v1;k++)
	{
		if(var1[k]!="")
		{
				if(coff1[k].at(0)=='-')
				coff1[k].at(0)='+';
			else
				coff1[k].at(0)='-';

			diff[b]=coff1[k]+var1[k];
			b++;
		}

	}
	cons[0]=cons[0].substr(1);
	cons1[0]=cons1[0].substr(1);
	float constant=atof(cons[0].c_str())-atof(cons1[0].c_str());
	ostringstream ss;
	ss<<constant;
	diff[b]=ss.str();
	
	string equa[100],coffcient[100];
	for(int h=0;h<b;h++)
	{
			int a=diff[h].length();
		for(int m=0;m<a;m++)
		{
			float b=diff[h].at(m);
			if (b>=97&&b<=122)
			{
				equa[h]=diff[h].substr(m);
				coffcient[h]=diff[h].substr(0,m);
				break;
			}
		}
	}

	for(int h=0;h<b;h++)
	{
		for(int g=h+1;g<b;g++)
		{
			if(equa[g]<equa[h])
			{
				string temp=equa[h];
				equa[h]=equa[g];
				equa[g]=temp;
				string temp2=coffcient[h];
				coffcient[h]=coffcient[g];
				coffcient[g]=temp2;
			}
		}
	}
	for(int k=0;k<b;k++)
	{
		diff[k]=coffcient[k]+equa[k];

	}
	

	string differance;
	for(int k=0;k<b;k++)
	{
		if(diff[k].at(0)=='-'||diff[k].at(0)=='+')
			diff[k]=diff[k];
		else
			diff[k]="+"+diff[k];
		if(diff[k].at(1)=='0')
			diff[k].clear();
		differance=differance+diff[k];
		
	}
	differance=differance+"="+diff[b];
	if(differance.at(0)=='+')
		differance=differance.substr(1);
	
	
	
	return differance;

		
	}
	string substitute(string s1,string vari)
	{
		string s=proper_equation();
		
	string str1[100],str[100],var[100],coff[100],cons,var1[100],cons1,coff1[100];
	
	int j=0,i=0;
	int l=s.length();

	for(i=1;i<l;i++)
	{
		if(s.at(i)=='+'||s.at(i)=='-'||s.at(i)=='=')
		{
			str[j]=s.substr(0,i);
			

			s=s.erase(0,i);
			j++;
			l=s.length();
			i=1;
			



		}
	
	}
		str[j]=s;
		for(int k=0;k<=j;k++)
	{
		if(str[k].at(0)=='=')
			str[k]=str[k].substr(1);
	}
	int c=0,v=0;
	for(int k=0;k<=j;k++)
	{
		int o=0;
		int a=str[k].length();
		for(int m=0;m<a;m++)
		{
			float b=str[k].at(m);
			if(b>=97&&b<=122)
			{
				if(m==0)
				{
					coff[c]='+1';
					var[v]=str[k];
					c++;
					v++;
					o=1;
					break;
				}
				else
				{

				int s=m;
				coff[c]=str[k].substr(0,s);
				var[v]=str[k].substr(s);
				c++;
				v++;
				o=1;
				break;
				}
			}

		}
		if(o!=1)
		{
			cons=str[k];
			
		}
	}
	
	for(int k=0;k<c;k++)
	{
		if(coff[k]=="-")
			coff[k]="-1";
		if(coff[k]=="+")
			coff[k]="+1";

	}
	string sub;
	
	for(int k=0;k<v;k++)
	{
		if(var[k]==vari)
		{
			sub=coff[k];
			var[k].clear();
			coff[k].clear();

			
		}
		else
		{
			if(coff[k].at(0)=='-')
				coff[k].at(0)='+';
			else 
				coff[k].at(0)='-';

		}

	}
	
int g=0,h=0;
int f=s1.length();
	for(h=1;h<f;h++)
	{
		if(s1.at(h)=='+'||s1.at(h)=='-'||s1.at(h)=='=')
		{
			str1[g]=s1.substr(0,h);
			

			s1=s1.erase(0,h);
			g++;
			f=s1.length();
			h=1;
			



		}
	
	}
		str1[g]=s1;
		for(int k=0;k<=g;k++)
	{
		if(str1[k].at(0)=='=')
			str1[k]=str1[k].substr(1);
	}
	int c3=0,v3=0;
	for(int k=0;k<=g;k++)
	{
		int o=0;
		int a=str1[k].length();
		for(int m=0;m<a;m++)
		{
			float b=str1[k].at(m);
			if(b>=97&&b<=122)
			{
				if(m==0)
				{
					coff1[c3]='+1';
					var1[v3]=str1[k];
					c3++;
					v3++;
					o=1;
					break;
				}
				else
				{

				int s=m;
				coff1[c3]=str1[k].substr(0,s);
				var1[v3]=str1[k].substr(s);
				c3++;
				v3++;
				o=1;
				break;
				}
			}

		}
		if(o!=1)
		{
			cons1=str1[k];
			
		}
	}
	
	
	for(int k=0;k<c3;k++)
	{
		if(coff1[k]=="-")
			coff1[k]="-1";
		if(coff1[k]=="+")
			coff1[k]="+1";

	}
	float z;
	for(int k=0;k<v3;k++)
	{
		if(var1[k]==vari)
		{
			z=atof(coff1[k].c_str());
			var1[k].clear();
			coff1[k].clear();
		}
	}
	if(cons1.at(0)=='-')
		cons1=cons1.substr(1);
	else
		cons1="-"+cons1;
	string eq1=cons1;
	for(int k=0;k<c3;k++)
	{
		if(coff1[k]!="")
		{
			if(coff1[k].at(0)!='+'&&coff1[k].at(0)!='-')
				coff1[k]="+"+coff1[k];
		}
	}
		for(int k=0;k<v3;k++)
		{
			if(var1[k]!="")
			{
				
				eq1=eq1+coff1[k]+var1[k];
			}
		}

	float p=atof(sub.c_str());
	float v1,m;
	for(int k=0;k<v;k++)
		{
			if(var[k]!="")
			{

			v1=atof(coff[k].c_str());
			m=(v1/p)*z;
			ostringstream ss;
			ss<<m;
			coff[k]=ss.str();

		}
	}
	float c1=atof(cons.c_str());
		float c2=(c1/p)*z;
		ostringstream ss;
		ss<<c2;
		cons=ss.str();
		string eq=cons;

		for(int k=0;k<v;k++)
		{
			if(coff[k]!="")
			{
				if(coff[k].at(0)!='-'&&coff[k].at(0)!='+')
				coff[k]="+"+coff[k];
			}
			
		}

	
		for(int k=0;k<v;k++)
		{
			if(var[k]!="")
			eq=eq+coff[k]+var[k];
		}
		string equation1;
		if(eq1.at(0)!='-'&&eq1.at(0)!='+')
			eq1="+"+eq1;
		equation1=eq+eq1+"="+"0";
		
		return equation1;
		
		


	}
	

};


int main()
{   
	equations equation [100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string eq;
		cin>>eq;
		equation[i].setequation(eq);
	}
	while(int w=1)
		
	{
		string comm;
		getline(cin,comm);
		if(comm=="quit")
			return 0;
		else
		{
				string arr[4];
				int u=0;
				int first=0;
				int second=0;
				int x=2;
				while(comm.find(" ",first)!=-1)
				{
					second=comm.find(" ",first);
					arr[u]=comm.substr(first,second-first);
					first=second+1;
						u++;
						x=1;
				}
				if(x==1)
				arr[u]=comm.substr(first);
				if(x==2)
					arr[0]=comm;
				if(arr[0]=="num_vars")
				{
					string s1=equation[0].proper_equation();
					for(int k=1;k<n;k++)
					{
						s1=s1+equation[k].proper_equation();
					}
					
	

	
		string str[100],var[100];
		
		
		
	int j=0,i=0;
	int l=s1.length();

	for(i=1;i<l;i++)
	{
		if(s1.at(i)=='+'||s1.at(i)=='-'||s1.at(i)=='=')
		{
			str[j]=s1.substr(0,i);
			

			s1=s1.erase(0,i);
			j++;
			l=s1.length();
			i=1;
			



		}
	
	}
		str[j]=s1;
		int c=0,v=0,g=0;
	for(int k=0;k<=j;k++)
	{
		int o=0;
		int a=str[k].length();
		for(int m=0;m<a;m++)
		{
			float b=str[k].at(m);
			if(b>=97&&b<=122)
			{
				if(m==0)
				{
					var[v]=str[k];
					v++;
					break;
				}
				else
				{

				int s=m;
				var[v]=str[k].substr(s);
				
				v++;
			
				break;
				}
			}
		}
	
	}

	
	
	
		
		for(int k=0;k<v;k++)
		{
			for(int h=k+1;h<v;h++)
			{
				if(var[k]==var[h])
					var[h].clear();
				
			}
		}
		int variable=0;
		for(int k=0;k<v;k++)
		{
			if(var[k]!="")
				variable++;
		}
			
	cout<<variable;





	}
				if(arr[0]=="equation")
				{
					int v;
					v=atof(arr[1].c_str());
					string s3=equation[v-1].proper_equation();
					if(s3.at(0)=='+')
						s3=s3.substr(1);
					cout<<s3;
				}
				if(arr[0]=="column")
				{

					int o=arr[1].length();
		           for(int m=0;m<o;m++)
		
			   {
				float a=arr[1].at(m);
		         if(a>=65&&a<=90)
			{
				a+=32;
		      arr[1].at(m)=a;
		}
				   }
	
					for(int k=0;k<n;k++)
					{

						string s3=equation[k].cofficent(arr[1]);
							if(s3.at(0)=='+')
								s3=s3.substr(1);
						cout<<s3<<endl;
					}
				}
				if(arr[0]=="add")
				{
					int v1=atof(arr[1].c_str());
					int v2=atof(arr[2].c_str());
					string s3=equation[v2-1].proper_equation();
					string s4=equation[v1-1].add(s3);
					cout<<s4;
					
				}
				if(arr[0]=="subtract")
				{
					int v1=atof(arr[1].c_str());
					int v2=atof(arr[2].c_str());
					string s3=equation[v2-1].proper_equation();
					string s4=equation[v1-1].subtract(s3);
					cout<<s4;
				}
				if(arr[0]=="substitute")
				{
					int v1=atof(arr[2].c_str());
					int v2=atof(arr[3].c_str());
					equations s4;
					string s3=equation[v2-1].substitute(equation[v1-1].proper_equation(),arr[1]);
					s4.setequation(s3);
					cout<<s4.proper_equation();




				}
			}
		

	}
	

	system("pause");
	return 0;


}
