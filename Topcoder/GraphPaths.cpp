#include <bits/stdc++.h>
using namespace std;

#define sz 55
#define bits 31
#define ll long long

class GraphPaths
{
private:

		ll dp[sz][sz], path[bits][sz][sz], tmp[sz][sz];



		public:

		ll howMany(vector<string> graph, int start, int destination, int dist)
		{
            string buf;

						int n = graph.size();

						for(int i=0;i<n;i++)
							for(int j=0;j<n;j++)
							{
								path[0][i][j] = 0;

								if(i == j)
									dp[i][j] = 1;
								else
									dp[i][j] = 0;

							}

						for(int i=0;i<n;i++)
						{
							stringstream ss(graph[i]);

							while(ss >> buf)
							{
								path[0][i][stoi(buf)] = 1;
							}

						}

						for(int k=1;k<bits;k++)
						{
								for(int i=0;i<n;i++)
								{
										for(int j=0;j<n;j++)
										{
												ll val = 0;

												for(int p=0;p<n;p++)
												{
														ll a = path[k-1][i][p];
														ll b = path[k-1][p][j];

														if(a == 0 || b == 0)
														{
															// no path between i and j via p
															continue;
														}

														if(a == -1 || b == -1)
														{
																val = -1;
																break;
														}



														if(b > LLONG_MAX /  a  )
														{
															// overflow
															val = -1;
															break;
														}
														ll x = a * b;

														if(val > LLONG_MAX - x )
														{
															// overflow
															val = -1;
															break;
														}

														val = val + x;
												}

												path[k][i][j] = val;

										}
								}
						}




						for(int ind = 0;dist;ind++, dist = dist >> 1)
						{
									if(dist & 1)
									{
											for(int i=0;i<n;i++)
											{
													 for(int j=0;j<n;j++)
													 {
														 		ll val = 0;

																for(int p=0;p<n;p++)
																{

																		ll a = path[ind][i][p];
																		ll b = dp[p][j];

																		if(a == 0 || b == 0)
																		{
																			// no path between i and j via p
																			continue;
																		}

																		if(a == -1 || b == -1)
																		{
																				val = -1;
																				break;
																		}



																		if(b > LLONG_MAX /  a )
																		{
																			// overflow
																			val = -1;
																			break;
																		}

																		ll x = a * b;

																		if(val > LLONG_MAX - x )
																		{
																			// overflow
																			val = -1;
																			break;
																		}

																	  val = val + x;
																}

																tmp[i][j] = val;
													 }
											}

											swap(dp,tmp);



									}
						}

						return dp[start][destination];


		}
};



int main()
{
    GraphPaths obj;

    string a[] = 		{"1 2 3",
 "0 1 2",
 "0",
 "1 2"};
     //string b[] = {"","30 50","19 6 40","12 10","35 23","8","11 20",""};
    int n = sizeof(a) / sizeof(a[0]);
	//int n = 8;
  //  vi a,b;
	vector<string> x,y;
    for(int i=0;i<n;i++)
    {
        x.push_back(a[i]);
				// y.push_back(b[i]);
    }

    //cout<<tree.longestZigZag(a);
		cout<<obj.howMany(x,0,1,2);
    return 0;
}
