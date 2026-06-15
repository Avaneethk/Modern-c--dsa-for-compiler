#include<iostream>
#include<string>
using namespace std;

class Solution{
	public:
		string mergealternate(string word1,string word2)
		{
			string res;
			res.resize(word1.length()+word2.length());
			cout<<"Res size"<<res.size()<<endl;
			int i=0;
			int i1=0;
			int i2=0;
			while(i<res.length())
			{
				cout<<"I:"<<i<<endl;
				cout<<"Inside while"<<endl;
				if(i1<word1.length()){
					cout<<"Inside if1"<<endl;
					res[i++]=word1[i1++];}
				if(i2<word2.length()){
					cout<<"Inside if2"<<endl;
					res[i++]=word2[i2++];}
			}
			return res;
		}};
int main()
{
	Solution merge;
	string word1 = "abc";
	string word2 = "dcegh";
	string result;
	result=merge.mergealternate(word1,word2);
	cout<<"result:"<<result<<endl;
	return 0;
}

