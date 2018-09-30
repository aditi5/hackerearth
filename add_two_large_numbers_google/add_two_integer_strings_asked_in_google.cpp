#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;


// This function will add zeros at the end of the shorter string to match the length of both strings
string add_trailing_zeros(int difference)
	{
		string trailing_zeros = "";
		for(int i = 0 ; i < difference ; i++)
		{
			trailing_zeros += "0";
		}
		return trailing_zeros;
	}

//This function will add the two strings in reverse order and push the output in the a stack 	
string add_two_numbers(string str_num1, string str_num2)
	{
		// ostringstream ss;
		string sum = "";
		// stack<char> sum;
		int carry = 0; 
		for(int i = 0 ; i < str_num2.length() ; i++ )
		{
			int add =  (str_num1[i]-48) + (str_num2[i]-48) + carry;
			int rem = add % 10;
			carry = add/10;
		    if(i == (str_num2.length()-1) && carry != 0)
			{
				sum.push_back(rem+48);
				sum.push_back(carry+48);

			}
			else {
				sum.push_back(rem+48);
			}

		}
		return sum;
	}

int main()
{
	int is_negative = 0;
	string str_num1, str_num2;
	cin>>str_num1;
	cin>>str_num2;
	if (str_num1.find('-') != string::npos && str_num2.find('-') != string::npos)
		{
			str_num1.replace(str_num1.find('-'), 1, "0");
			str_num2.replace(str_num2.find('-'), 1, "0");
		    is_negative = 2;
		}
	// reverse both the strings to start the addition from the first character of both the strings
	reverse(str_num1.begin(), str_num1.end()); 
	reverse(str_num2.begin(), str_num2.end()); 

	int diff = str_num1.size() - str_num2.size();
    if( diff > 0 )
    	{
			str_num2 += add_trailing_zeros(diff);           
		}		
	else {
			str_num1 += add_trailing_zeros(-diff);
	}	
	
	string sum = add_two_numbers(str_num1, str_num2);

	reverse(sum.begin(), sum.end());
	if(is_negative == 2)
	 	{
	 		sum[0] ='-'; 
	 	}	
	cout<<"The sum of the two large numbers is : "<<sum<<endl;	
	
	}