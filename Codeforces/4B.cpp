#include <bits/stdc++.h>

using namespace std;



int main() {
	// your code goes here

    int d, sum, minTime[35], maxTime[35];

    scanf("%d %d",&d,&sum);
    int nMin = 0, nMax = 0;
    int ans[35], res[35];

    for(int i=1;i<=d;i++)
    {
        scanf("%d %d",minTime + i, maxTime + i);
        nMin += minTime[i];

        nMax += maxTime[i];
        ans[i] = minTime[i];
        res[i] = maxTime[i] - minTime[i];
    }
    if(nMin > sum || nMax < sum)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    int left = sum - nMin;

    int ind = 1;

    while(left > 0)
    {
        ans[ind] += min(left,res[ind]);
        left -= res[ind];
        ind++;
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=d;i++)
        printf("%d ",ans[i]);

    cout<<endl;




	return 0;
}
