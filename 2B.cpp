#include <bits/stdc++.h>

using namespace std;

#define ll int
#define size 1005
ll n, a[size][size], fact2[size][size], fact5[size][size];

typedef struct path
{
int n2;
int n5;
char way;
} path;

map<char,char> direction;
char ansPath[2100];

path dp2[size][size], dp5[size][size] ;

int main() {
	// your code goes here

    direction['L'] = 'R';
    direction['T'] = 'D';

    cin>>n;
    bool hasZero = false;
    int zeroX, zeroY;
    // take input
    for(int i = 1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];

            if(a[i][j] == 0)
            {
                hasZero = true;
                zeroX = i;
                zeroY = j;
                a[i][j] = 10;
            }


            ll num = a[i][j];

            int n2 = 0, n5 = 0;
            while(num % 2 == 0)
            {
                n2++;
                num /= 2;
            }

            while(num % 5 == 0)
            {
                n5++;
                num /= 5;
            }

            fact2[i][j] = n2;
            fact5[i][j] = n5;
        }
    }

    // minimize no of 2

    dp2[1][1].n2 = fact2[1][1];
    dp2[1][1].n5 = fact5[1][1];

    dp5[1][1].n2 = fact2[1][1];
    dp5[1][1].n5 = fact5[1][1];

    for(int j=2;j<=n;j++)
    {
        dp2[1][j].n2 = fact2[1][j] + dp2[1][j-1].n2;
        dp2[1][j].n5 = fact5[1][j] + dp2[1][j-1].n5;
        dp2[1][j].way = 'L';


        dp5[1][j].n2 = dp2[1][j].n2;
        dp5[1][j].n5 = dp2[1][j].n5 ;
        dp5[1][j].way = 'L';

    }

    for(int i=2;i<=n;i++)
    {
        dp2[i][1].n2 = fact2[i][1] + dp2[i-1][1].n2;
        dp2[i][1].n5 = fact5[i][1] + dp2[i-1][1].n5;
        dp2[i][1].way = 'T';

        dp5[i][1].n2 = dp2[i][1].n2;
        dp5[i][1].n5 = dp2[i][1].n5;
        dp5[i][1].way = 'T';
    }


    for(int i=2;i<=n;i++)
    {
        for(int j = 2;j<=n;j++)
        {
            if(dp2[i][j-1].n2 < dp2[i-1][j].n2)
            {
                dp2[i][j].n2 = fact2[i][j] + dp2[i][j-1].n2;
                dp2[i][j].n5 = fact5[i][j] + dp2[i][j-1].n5;
                dp2[i][j].way = 'L';
            }
            else
            {
                dp2[i][j].n2 = fact2[i][j] + dp2[i-1][j].n2;
                dp2[i][j].n5 = fact5[i][j] + dp2[i-1][j].n5;
                dp2[i][j].way = 'T';
            }

            if(dp5[i][j-1].n5 < dp5[i-1][j].n5)
            {
                dp5[i][j].n2 = fact2[i][j] + dp5[i][j-1].n2;
                dp5[i][j].n5 = fact5[i][j] + dp5[i][j-1].n5;
                dp5[i][j].way = 'L';
            }
            else
            {
                dp5[i][j].n2 = fact2[i][j] + dp5[i-1][j].n2;
                dp5[i][j].n5 = fact5[i][j] + dp5[i-1][j].n5;
                dp5[i][j].way = 'T';
            }

        }
    }

    ll ansMinTwo = min(dp2[n][n].n2,dp2[n][n].n5);
    ll ansMinFive = min(dp5[n][n].n2,dp5[n][n].n5);
    ll ans;
    int last = 0;

    if(hasZero && ansMinFive >=1 && ansMinTwo >= 1)
    {
      ans = 1;
      ll r,c;
      r = zeroX - 1;
      c = zeroY - 1;
      for(int i=1;i<=r;i++)
        {
          ansPath[last] = 'D';
          last++;
        }
        for(int i=1;i<=c;i++)
          {
            ansPath[last] = 'R';
            last++;
          }
      r = n - zeroX;
      c = n - zeroY;
      for(int i=1;i<=r;i++)
        {
          ansPath[last] = 'D';
          last++;
        }
        for(int i=1;i<=c;i++)
          {
            ansPath[last] = 'R';
            last++;
          }
    }
    else
    {
      char revPath[2100];

      if(ansMinTwo < ansMinFive)
      {
        ans = ansMinTwo;

        ll rem = 2 * n - 2;
        ll r = n, c = n;
        char now;

        while(rem)
        {
          now = dp2[r][c].way;
          revPath[last] = direction[now];
          last++;
          if(now == 'L')
            c--;
          else
            r--;

          rem--;
        }
      }
      else
      {
        ans = ansMinFive;

        ll rem = 2 * n - 2;
        ll r = n, c = n;
        char now;

        while(rem)
        {
          now = dp5[r][c].way;
          revPath[last] = direction[now];
          last++;
          if(now == 'L')
            c--;
          else
            r--;

          rem--;
        }
      }

      for(int i=last-1,j=0;i>=0;i--,j++)
        ansPath[j] = revPath[i];

    }

    ansPath[last] = '\0';

    printf("%d\n",ans);
    printf("%s\n",ansPath );

	return 0;
}
