#include <bits/stdc++.h>
using namespace std;

#define sz 60
#define ii pair<int,int>
#define vi vector<int>

class SkewTree
{
private:

	int n,dp[sz][sz],sum[sz];
	ii val[sz];  // val, prob

		int getSum(int l, int r)
		{
			if(r < l)
				return 0;

			return sum[r] - sum[l-1];
		}

		public:

		int bestScore(vi values, vi probs) {
			// your code goes here

			//int n = sizeof(values) / sizeof(int);
            int n = values.size();

			for(int i = 0;i<n; i++)
			{
				val[i+1].first = values[i];
				val[i+1].second = probs[i];

			}

			sort(val+1,val+1+n);

			sum[0] = 0;

			for(int i=1;i<=n;i++)
			 	sum[i] = sum[i-1] + val[i].second;

			for(int i=0;i<sz;i++)
				for(int j=0;j<=sz;j++)
					dp[i][j] = 0;

			for(int i=1;i<=n;i++)
				dp[i][i] = val[i].second;
			for(int t = 1;t<n;t++)
			{
				for(int i=1,j=i+t;j<=n;j++,i++)
				{
					int minVal = val[i].second + dp[i][i-1] + getSum(i,i-1) + dp[i+1][j] + getSum(i+1,j);
						for(int m = i + 1;m<=j;m++)
						{
							minVal = min(minVal, val[m].second + dp[i][m-1] + getSum(i,m-1) + dp[m+1][j] + getSum(m+1,j));
							//cout<<i<<" "<<minVal<<"\n";
						}

						dp[i][j] = minVal;
				}
			}




			return dp[1][n];
		}
};
