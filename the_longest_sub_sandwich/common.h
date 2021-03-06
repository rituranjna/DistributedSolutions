#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;
 
  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);
 
  return ans;
}

string to_string( ll in)
{
  char ans[100];
  sprintf(ans , "%lld",in);
  return ans;
}

string incode_result( ll lf , ll rt)
{
  
   return to_string(lf)+" "+to_string(rt);
}



pair<ll,ll> decode_result(string in)
{
  vector<string> tp = parse( in, " ");

  assert( ((int)tp.size())==2);

  ll a = atoll( tp[0].c_str() );
  ll b = atoll( tp[1].c_str() );

  return make_pair(a,b);
}



string incode_input( vector<ll> in)
{
  //TODO: improve its complexity to O(n)
  string ans="";

  for(int i=0;i<((int)in.size());i++)
     {
       ans=ans+" "+to_string(in[i]);
     }

   return ans;
}

vector<ll> decode_input( string in)
{
  vector<string> tp = parse(in," ");

  vector<ll> ans ;

  for(int i=0;i<((int)tp.size());i++)
    ans.push_back( atoll(tp[i].c_str()) );

  return ans;
}
       
  




