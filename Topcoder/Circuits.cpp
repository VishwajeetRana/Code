#include <bits/stdc++.h>
using namespace std;

#define sz 60

class Circuits
{
private:

		int dp[sz][sz];



		public:

		int howLong(vector <string> connects, vector <string> costs)
		{
            string val,buf;

			for(int i=0;i<sz;i++)
				for(int j=0;j<sz;j++)
				{
					if(i == j)
						dp[i][j] = 0;
					else
						dp[i][j] = -1;
				}

			int n = connects.size();

			for(int i=0;i<n;i++)
			{
					stringstream ss(connects[i]); // Insert the string into a stream
					stringstream cc(costs[i]);

					while (ss >> buf)
					{
							cc >> val;
		        	dp[i][stoi(buf)] = stoi(val);
					}

			}

			int ans = -1;

			for(int k=0;k<n;k++)
			{
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						 if(dp[i][k] > -1 && dp[k][j] > -1)
						 	dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);

							if(k == n-1)
								ans = max(ans, dp[i][j]);
					}
				}
			}

			return ans;



		}
};



int main()
{
    Circuits obj;

    string a[] = 	{"", "42", "46", "23 39 40 21 4 5 6", "", "", "", "27 35 28 34", "", "", "42 29 47 32", "1 27", "49 40 39 7 31 10 48", "27 47 33 41 39", "46 11 21 13", "6 20 47 2 17 33 21 14 29", "", "13 36 31 6 37 7", "5 7 37 31 34 40 26", "", "", "", "", "", "", "38 43 22 42 1 26", "", "", "39 10", "", "32 43 14 18 47 20 45", "48 40 10 27 4", "", "", "", "", "", "", "16", "", "", "4 28 25 12 31 43 18 20 27", "", "", "", "29 7 21 8 24 40", "29 36 37 0 10", "", "2 33 47 9 45 22", ""};
     string b[] = {"", "70", "77", "33 33 71 79 75 51 31", "", "", "", "26 24 18 29", "", "", "55 37 22 43", "60 50", "90 98 11 64 44 8 22", "92 92 32 42 48", "50 30 16 86", "96 83 26 70 75 77 79 99 4", "", "26 83 37 77 52 9", "21 43 82 56 31 60 2", "", "", "", "", "", "", "13 43 83 3 66 72", "", "", "17 47", "", "21 6 77 53 95 34 75", "86 76 80 37 4", "", "", "", "", "", "", "1", "", "", "74 7 96 82 54 85 28 96 28", "", "", "", "70 83 22 63 94 78", "68 65 31 49 2", "", "86 29 73 1 55 78", ""};
  //  int n = sizeof(a) / sizeof(int);
    int n = sizeof(a) / sizeof(a[0]);
  //  vi a,b;
	vector<string> x,y;
    for(int i=0;i<n;i++)
    {
        x.push_back(a[i]);
				y.push_back(b[i]);
    }

    //cout<<tree.longestZigZag(a);
		cout<<obj.howLong(x,y);
    return 0;
}
