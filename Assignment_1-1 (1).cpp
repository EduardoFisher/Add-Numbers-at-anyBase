/* Name       : Eduardo Fisher
* Class      : CS3A
* Prof.      : Barkeshli
* Date Due   : 3/6/2017
* Last Edited: 3/8/2017
*/

#include <iostream>

using namespace std;

void reverse(char *str);
void swap(char& a, char& b);
void add(char* num1, char* num2, char* result, int base);
void remainder(int& carry, int hold, int base, char* result);
void noRemainder(int& carry, char* str, char* result);
void Carry(int& carry, char* str, char* result);
int strlen(char* str);
int _strchr(char value);
char intChar(int remainder);
void _print(char* num1, char* num2, int base);
void TestAdd();

const int MAX = 30;

int main()
{
   TestAdd();
   return 0;
}

void reverse(char* str)
{
   char* leftSide = str + (strlen(str) - 1);
   char* rightSide = str;
   while(rightSide < leftSide)
   {
       swap(*rightSide, *leftSide);
       rightSide++;
       leftSide--;
   }
}

void add(char* num1, char* num2, char* result, int base)
{
   _print(num1, num2, base);
   char* holder = result;
   reverse(num1);
   reverse(num2);
   int carry = 0;

   while((*num1 != NULL) && (*num2 != NULL))
   {
       int hold = _strchr(*num1) + _strchr(*num2) + carry;
       if(hold >= base)
       {
           remainder(carry, hold, base, result);
           num1++;
           num2++;
           result++;
       }
       else
       {
           *result = intChar(hold);
           num1++;
           num2++;
           result++;
           carry = 0;
       }
   }
   while(*num1 != NULL)
   {
       if(carry == 1)
       {
           int hold = carry + (_strchr(*num1));
           if(hold >= base)
           {
               remainder(carry, hold, base, result);
               num1++;
               result++;
           }
           else
           {
               Carry(carry, num1, result);
               result++;
               num1++;
           }
       }
       else
       {
           noRemainder(carry, num1, result);
           result++;
           num1++;
       }
   }
   while(*num2 != NULL)
   {
       if(carry == 1)
       {
           int hold = carry + (_strchr(*num2));
           if(hold >= base)
           {
               remainder(carry,hold,base,result);
               num2++;
               result++;
           }
           else
           {
               Carry(carry, num2, result);
               result++;
               num2++;
           }
       }
       else
       {
           noRemainder(carry, num2, result);
           result++;
           num2++;
       }
   }
   if(carry == 1)
   {
       *result = '1';
       result++;
   }
   *result = NULL;
   result = holder;
   reverse(result);
}

void swap(char& a, char& b)
{
   char temp;
   temp = a;
   a = b;
   b = temp;
}

void remainder(int& carry, int hold, int base, char* result)
{
   int remainder = hold - base;
   *result = intChar(remainder);
   carry = 1;
}

void Carry(int& carry, char* str, char* result)
{
   *result = intChar((carry + (_strchr(*str))));
   carry = 0;
}

void noRemainder(int& carry, char* str, char* result)
{
   *result = *str;
   carry = 0;
}

int strlen(char* str)
{
   char* a = str;
   while(*a != NULL)
   {
       a++;
   }
   return a - str;
}


void _print(char* num1, char* num2, int base)
{
   cout << "Adding " << num1 << " with " << num2  << " :with a base of " << base
        << ": result: ";
}


int _strchr(char value)
{
   char digits[] = "0123456789ABCDEF";
   char* walker = digits;
   while(*walker != NULL)
   {
       if(*walker == value)
       {
           break;
       }
       else
       {
           walker++;
       }
   }
   return walker - digits;
}

char intChar(int remainder)
{
   char digits[] = "0123456789ABCDEF";
   char* walker = digits;
   int i = 0;
   while(remainder > i)
   {
       walker++;
       i++;
   }
   return *walker;
}

void TestAdd()
{
   char num1[MAX] = "121";
   char num2[MAX] = "198";
   char result[MAX];
   int base = 10;
   add(num1, num2, result, base);
   cout << result << endl << endl;

   char num3[MAX] = "9999";
   char num4[MAX] = "1";
   add(num3, num4, result, base);
   cout << result << endl << endl;

   base = 2;
   char num5[MAX] = "10110";
   char num6[MAX] = "0101";
   add(num5, num6, result, base);
   cout << result << endl << endl;

   char num7[MAX] = "1011";
   char num8[MAX] = "0001";
   add(num7, num8, result, base);
   cout << result << endl << endl;

   base = 10;
   char num9[MAX] = "94513";
   char num10[MAX] = "105";
   add(num9, num10, result, base);
   cout << result << endl << endl;

   char num11[MAX] = "8888888";
   char num12[MAX] = "1111111";
   add(num11, num12, result, base);
   cout << result << endl << endl;

   base = 16;
   char num13[MAX] = "15FA";
   char num14[MAX] = "15AF";
   add(num13, num14, result, base);
   cout << result << endl << endl;

   char num15[MAX] = "ABCDE6";
   char num16[MAX] = "ABFE54";
   add(num15, num16, result, base);
   cout << result << endl << endl;
}
