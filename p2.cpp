#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  int i,pmax,lmax,pm,lm,n;
  unsigned char c;

  getline(cin,s);
  s += " "; // dodajemy wartownika
  n = s.length();
  pmax = -1; lmax = lm = 0;
  for(i = 0; i < n; i++)
  {
    c = s[i];
    if(((c >= '0') && (c <= '9')) ||
        (c == '_') || (c == '-')  ||
       ((c >= 'A') && (c <= 'Z')) ||
       ((c >= 'a') && (c <= 'z')) ||
        (c == 164) || (c == 165)  ||
        (c == 227) || (c == 228)  ||
        (c == 224) || (c == 162)  ||
        (c == 151) || (c == 152)  ||
        (c == 141) || (c == 171)  ||
        (c == 189) || (c == 190))
    {
      if(!lm) pm = i;
      lm++;
    }
    else
    {
      if(lm > lmax)
      {
        lmax = lm; pmax = pm;
      }
      lm = 0;
    }
  }
  if(pmax == -1) cout << "BRAK\n";
  else cout << "[" << s.substr(pmax,lmax) << "] : " << lmax << endl;
  cout << endl;
  return 0;
}
