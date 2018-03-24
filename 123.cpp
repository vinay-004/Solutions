#include<iostream>
#include<string>
#include<map>
#include<set>
#include<iterator>
#include<cstdio>
#include<cctype>

using namespace std;

int main() 
{
	set<string> ignore;
	multimap<string, string> output;
	string str;
	while (getline(cin,str) )
	{
		if (str == "::")break;
		ignore.insert(str);
	}
	string sentence;
	while (getline(cin,sentence))
	{
		string t;
		
		for (size_t i = 0; i < sentence.length(); i++)
		{
			sentence[i] = tolower(sentence[i]);
		}
		
		int j = sentence.length();
		for (size_t i = 0; i < sentence.length(); ++i)
		{
			j--;
			if (!isspace(sentence[i]))
			{
				t += sentence[i];
			}
			if (isspace(sentence[i]))
			{
				
				if(!ignore.count(t))
				{
					string t2(t);
					for (int k = 0; k != t.length(); k++)
					{
						t2[k] = toupper(t[k]);
					}

					string t3(sentence);
					t3.replace(i-t2.size(), t2.size(), t2);
					//cout << t3 << endl;
					output.insert(pair<string,string>(t2, t3));
					
				}
				t.clear();
			}
			if(j == 0)
			{
				if (!ignore.count(t))
				{
					string t2(t);
					for (int k = 0; k != t.length(); k++)
					{
						t2[k] = toupper(t[k]);
					}

					string t3(sentence);
					t3.replace(i - t2.size()+1, t2.size(), t2);
					//cout << t3 << endl;
					output.insert(pair<string, string>(t2, t3));
				}
				t.clear();
			}
			
			
		}
		
	}

	map<string, string>::iterator it;
	for (it = output.begin(); it != output.end(); ++it)
		std::cout <<it->second <<endl;
	

	return 0;
}