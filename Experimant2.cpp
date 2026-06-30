#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isKeyword(char str[])
{
    char keyword[][10]={"int","float","char","double","if",
                        "else","while","for","return","void"};

    for(int i=0;i<10;i++)
    {
        if(strcmp(str,keyword[i])==0)
            return true;
    }
    return false;
}

bool isIdentifier(char str[])
{
    if(!(isalpha(str[0]) || str[0]=='_'))
        return false;

    for(int i=1;str[i]!='\0';i++)
    {
        if(!isalnum(str[i]) && str[i]!='_')
            return false;
    }

    return true;
}

bool isConstant(char str[])
{
    int dot=0;

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='.')
            dot++;

        else if(!isdigit(str[i]))
            return false;
    }

    if(dot>1)
        return false;

    return true;
}

bool isOperator(char str[])
{
    if(strcmp(str,"+")==0 ||
       strcmp(str,"-")==0 ||
       strcmp(str,"*")==0 ||
       strcmp(str,"/")==0 ||
       strcmp(str,"%")==0 ||
       strcmp(str,"=")==0 ||
       strcmp(str,"==")==0 ||
       strcmp(str,"!=")==0 ||
       strcmp(str,"<")==0 ||
       strcmp(str,">")==0 ||
       strcmp(str,"<=")==0 ||
       strcmp(str,">=")==0)
        return true;

    return false;
}

bool isSpecialSymbol(char str[])
{
    if(strcmp(str,";")==0 ||
       strcmp(str,",")==0 ||
       strcmp(str,"(")==0 ||
       strcmp(str,")")==0 ||
       strcmp(str,"{")==0 ||
       strcmp(str,"}")==0)
        return true;

    return false;
}

void identify(char token[])
{
    if(isKeyword(token))
        cout<<token<<" = Keyword"<<endl;

    else if(isOperator(token))
        cout<<token<<" = Operator"<<endl;

    else if(isSpecialSymbol(token))
        cout<<token<<" = Punctuation"<<endl;

    else if(isIdentifier(token))
        cout<<token<<" = Identifier"<<endl;

    else if(isConstant(token))
        cout<<token<<" = Constant"<<endl;

    else
        cout<<token<<" = Invalid Token"<<endl;
}

int main()
{
    char str[100], token[50];

    cout<<"Enter Statement: ";
    cin.getline(str,100);

    char *start=str;
    char *forward=str;

    while(true)
    {
        if(*forward==' ' || *forward=='\0')
        {
            int i=0;
            char *temp=start;

            while(temp<forward)
            {
                token[i]=*temp;
                temp++;
                i++;
            }

            token[i]='\0';

            if(strlen(token)>0)
                identify(token);

            if(*forward=='\0')
                break;

            forward++;
            start=forward;
        }
        else
        {
            forward++;
        }
    }

    return 0;
}
