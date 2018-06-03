#include "iostream"
#include "string"
#include "stack"
#include "algorithm"
using  namespace std;
class Solution {
public:
	bool backspaceCompare(string S, string T) {
		if (S.empty() && T.empty()) return true;
		if (S.empty() || T.empty())return false;
		stack<char> q1, q2;
		//q1.push(*S.begin());
		for (char ch : S)
		{
			q1.push(ch);
			if (ch == '#')
			{
				q1.pop(); 
				if (!q1.empty())
					q1.pop();
			}
			
		}
		for (char ch : T)
		{
			q2.push(ch);
			if (ch == '#')
			{
				q2.pop();
				if (!q2.empty())
					q2.pop();
			}
			
		}
		if (q1.size() == q2.size())
		{
			char ch1, ch2;
			for (unsigned int i = 0; i < q1.size(); i++)
			{
				ch1 = q1.top();
				q1.pop();
				ch2 = q2.top();
				q2.pop();
				if (ch1 == ch2)
					continue;
				return false;
			}
			return true;
		}
		return false;
	}
};

void main()
{
	Solution s1;
	//string s = "ab#d";
	//string t = "ac#d";
	//string s = "ab##";
	//string t = "c#d#";
	string s = "a#c";
	string t = "b";
	//string s = "a##c";
	//string t = "#a#c";
	bool out = s1.backspaceCompare(s, t);
	if (out) printf("true");
	else printf("false");
	system("pause");
}