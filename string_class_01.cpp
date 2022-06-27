#include<iostream>
#include<string>
using namespace std;
class String
{
private:
    int len;
    char* str;
public:
    String():len(0)
    {
        str=NULL;
    }
    String(const char* s)
    {
        len=strlen(s)+1;
        str = new char[len];
        strcpy(str, s);
    }
    String(const String& s)
    {   
        len = s.len;
        str = new char[len];
        strcpy(str, s.str);
    }
    ~String()
    {
        delete[] str;
    }
};
int main(void)
{
    String str1;
    String str2 = "I like";
    String str3 = str2;
    return 0;
}