#include <bits/stdc++.h>
using namespace std;

#define sz 60
#define ii pair<int,int>
#define vi vector<int>

class ZigZag
{
private:

	int n;
	ii dp[sz];  // val, prob



		public:

		int longestZigZag(vector <int> sequence)
		{
		    n = sequence.size();
				for(int i=0;i<n;i++)
				{
					dp[i].first = 1;
					dp[i].second = 1;
				}

				int ans = 1;

				for(int i=1;i<n;i++)
				{
						 int addF = 0, addS = 0;
						 for(int j=0;j<i;j++)
						 {
								  if(sequence[j] < sequence[i])
									{
										 addF = max(addF, dp[j].second);
									}
									else if(sequence[j] > sequence[i])
									{
										 addS = max(addS, dp[j].first);
									}
						 }
						 dp[i].first += addF;
						 dp[i].second += addS;
						 ans = max(ans, dp[i].first);
						 ans = max(ans, dp[i].second);
				}


				return ans;

		}
};



int main()
{
    ZigZag tree;
    int values[] = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };


    int n = sizeof(values) / sizeof(int);

    vi a,b;
    for(int i=0;i<n;i++)
    {
        a.push_back(values[i]);
    }

    cout<<tree.longestZigZag(a);
    return 0;
}
