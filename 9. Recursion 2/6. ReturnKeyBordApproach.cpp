#include<iostream>
using namespace std;

string getString(int d)
{
    if(d == 2) return "abc";
    if(d == 3) return "def";
    if(d == 4) return "ghi";
    if(d == 5) return "jkl";
    if(d == 6) return "mno";
    if(d == 7) return "pqrs";
    if(d == 8) return "tuv";
    if(d == 9) return "wxyz";
    return "";
}

int keyBoard(int input, string* output)
{
    if(input == 0)
    {
        output[0] = "";
        return 1;
    }
    int lastDigit = input%10;
    int smallNumber = input/10;
    int smallOutput = keyBoard(smallNumber, output);
    string options = getString(lastDigit);
    for(int i=0; i<options.length()-1; i++)
    {
        for(int j=0; j<smallOutput; j++)
        {
            output[j+(i+1)*smallOutput] = output[j];
        }
    }
    int k=0;
    for(int i=0; i<options.length(); i++)
    {
        for(int j=0; j<smallOutput; j++)
        {
            output[k] = output[k] + options[i];
            k++;
        }
    }
    return smallOutput*options.length();
}

int main()
{
    int s ;
    cin>>s;
    string* output = new string[2000];
    int count = keyBoard(s, output);
    cout<<"KeyBoard: "<<count<<endl;
    for(int i=0; i<count; i++)
        cout<<output[i]<<endl;
    delete [] output;
    return 0;
}