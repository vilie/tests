#include <iostream>
#include <string>
#include <vector>
#define DIM 30
using namespace std;
int main()
{
	int32_t numOf;
	cin>>numOf;
	vector<int> a;
	int temp;
	for(int i = 0; i < numOf; i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	for(auto w:a)
		cout<<w<<endl;
	
	return 0;
}
