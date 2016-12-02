#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;  // size, ind
typedef vector<ii> vi;

vi kayak,catamaran;
int ans = 0, ind = 0;
int s[100010];


int main() {
	// your code goes here

   int n,space, type,val;
   scanf("%d %d",&n,&space);

   for(int i=1;i<=n;i++)
   {
       scanf("%d",&type);
       scanf("%d",&val);

       if(type == 1)
            kayak.push_back(ii(val,i));
       else
            catamaran.push_back(ii(val,i));

   }

   sort(kayak.begin(),kayak.end());
   sort(catamaran.begin(),catamaran.end());

   int ktop = kayak.size() - 1;
   int ctop = catamaran.size() - 1;

   while(space)
   {
       if(ctop < 0 || space < 2)
       {
            if(ktop < 0)
                break;
            else
            {
                ans += kayak[ktop].first;
                s[ind] = kayak[ktop].second;
                ind++;
                ktop--;
                space--;
            }
       }
       else
       {
          if(ktop < 0)
          {
            ans += catamaran[ctop].first;
            s[ind] = catamaran[ctop].second;
            ind++;
            ctop--;
            space -= 2;
          }
          else if(ktop == 0)
          {
              if(catamaran[ctop].first > kayak[ktop].first)
              {
                ans += catamaran[ctop].first;
                s[ind] = catamaran[ctop].second;
                ind++;
                ctop--;
                space -= 2;
              }
              else
              {
                ans += kayak[ktop].first;
                s[ind] = kayak[ktop].second;
                ind++;
                ktop--;
                space--;
              }
          }
          else
          {
              if(catamaran[ctop].first > kayak[ktop].first + kayak[ktop - 1].first)
              {
                ans += catamaran[ctop].first;
                s[ind] = catamaran[ctop].second;
                ind++;
                ctop--;
                space -= 2;
              }
              else
              {
                ans = ans + kayak[ktop].first;
                s[ind] = kayak[ktop].second;
                ind++;
                ktop -= 1;
                space -= 1;
              }
          }

       }

   }

   cout<<ans<<endl;

   for(int i=0;i<ind;i++)
    printf("%d ",s[i]);

    cout<<endl;



	return 0;
}
