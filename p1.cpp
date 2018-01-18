// Pot�gowanie du�ej liczby przez ma��
// Data: 24.10.2012
// (C)2012 mgr Jerzy Wa�aszek
//---------------------------------------

#include <iostream>
#include <string>

using namespace std;

// Oblicza sum� podanych liczb
//----------------------------
string dodaj(string & x, string & y)
{
  string z;
  int p,w,i,j,k,n;

  i = x.length();
  j = y.length();

  n = i; if(j < i) n = j;

  p = 0;

  z = "";

  for(k = 1; k <= n; k++)
  {
    w  = (int)(x[--i]) + (int)(y[--j]) + p - 96;
    p  = w / 10;
    z = (char)((w % 10) + 48) + z;
  }

  while(i)
  {
    w  = x[--i] + p - 48;
    p  = w / 10;
    z = (char)((w % 10) + 48) + z;
  }

  while(j)
  {
    w  = y[--j] + p - 48;
    p  = w / 10;
    z = (char)((w % 10) + 48) + z;
  }

  if(p) z = (char)(p + 48) + z;

  if(z == "") z = "0";

  return z;  // zwracamy wynik dodawania
}

// Mno�y du�� liczb� a przez ma�� b
//---------------------------------
string mnoz_ab(string a, unsigned int b)
{
  string w;

  w = "0";           // zerujemy �a�cuch wyj�ciowy

  while(true)        // wykonujemy mno�enie
  {
    if(b & 1)   w = dodaj(w,a);
    if(b >>= 1) a = dodaj(a,a); else break;
  }

  return w;          // zwracamy wynik mno�enia
}
