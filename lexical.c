#include<stdio.h>
#include<stdlib.h>
int lengthOfString(char *str);
int compareString(char *str1,char *str2);
char * substring(char *sourceStr,int left,int right);
int Operator(char operator);
int delameter(char ch);
int Identifier(char *str);
int Keywoard(char *str);
int Inteder(char *str);
int realNumber(char *str);
int tokenizer(char *str);


int main(void){
    char code []= "int sum = x + y";
    tokenizer(code);
    return 0;

}


int lengthOfString(char *str){
    int i=0;
    while (str[i] !='\0')
    {
        i++;
    }
    return i;
}

int compareString(char *str1,char *str2){
    if(lengthOfString(str1)==lengthOfString(str2)){
        for (int i = 0; i < lengthOfString(str1); i++)
        {
            if (str1[i]!=str2[i])
            {
                return 0;
            }
            
        }return 1;
    }
    return 0;
}    

char * substring(char *sourceStr,int left,int right){
    int len=right-left+1;
    char *destintaionString=(char*)malloc(sizeof(char)*(len+1));
    for (int  i = 0; i <=right && sourceStr[i]!='\0' ; i++)
    {
        *destintaionString=sourceStr[i];
        destintaionString++;
    }
    
    *destintaionString='\0';
    return destintaionString-len;
}

int Operator(char operator){
    if(operator=='+'|| operator=='-' ||operator=='*' ||
       operator=='/'|| operator=='>' ||operator=='<' ||operator=='=')
       return 1;
    return 0;   
}

int delameter(char ch){
    if (ch=='+' || ch=='-'|| ch=='*' ||
        ch=='/' || ch=='>'|| ch=='<' ||ch=='='||
        ch=='(' ||ch==')' || ch=='{' ||ch=='}'||
        ch=='[' ||ch==']' || ch=='{' ||ch=='}'||
        ch==',' ||ch==';' ||ch==' ')
        return 1;
    return 0;    
}

int Identifier(char *str){
    if (str[0]=='0' ||str[0]=='1' ||str[0]=='2'|| str[0]=='3' ||
    str[0]=='4' ||str[0]=='5' ||str[0]=='6'|| str[0]=='7' ||
    str[0]=='8' ||str[0]=='9' || Operator(str[0]==1)|| delameter(str[0]==1))
    return 0;
return 1;        
}

int Keywoard(char *str){
    if (compareString(str,"if")||compareString(str,"else")||
        compareString(str,"while")||compareString(str,"do")||
        compareString(str,"break")||compareString(str,"for")||
        compareString(str,"continue")||compareString(str,"int")||
        compareString(str,"float")||compareString(str,"double")||
        compareString(str,"return")||compareString(str,"char")||
        compareString(str,"sizeof")||compareString(str,"long")||
        compareString(str,"short")||compareString(str,"tybedef")||
        compareString(str,"switch")||compareString(str,"unsigned")||
        compareString(str,"void")||compareString(str,"static")||
        compareString(str,"struct")||compareString(str,"goto")||
        compareString(str,"print")||compareString(str,"printf"))
        return 1;
    return 0;        
}

int Inteder(char *str){
    if (lengthOfString(str)==0)
        return 0;
    for (int i = 0; i < lengthOfString(str); i++)
    {
        if (str[i]!='0'&& str[i]!='1'&& str[i]!='2'&&
            str[i]!='3'&& str[i]!='4'&& str[i]!='5'&&
            str[i]!='6'&& str[i]!='7'&& str[i]!='8'&&
            str[i]!='9'||(str[i]!='-' && i> 0))
            return 0;    
    }
    return 1;    
}
int realNumber(char *str){
    int dynamicFlag=0;
    if (lengthOfString(str)==0)
        return 0;
    for (int i = 0; i < lengthOfString(str); i++)
    {
        if (str[i]!='0'&& str[i]!='1'&& str[i]!='2'&&
            str[i]!='3'&& str[i]!='4'&& str[i]!='5'&&
            str[i]!='6'&& str[i]!='7'&& str[i]!='8'&&
            str[i]!='9'&& str[i]!='.'||(str[i]!='-' && i> 0))
            return 0; 
        if(str[i]=='.')   
          dynamicFlag=1;    
    }
    return dynamicFlag;    
}
int tokenizer(char *str){
    int left=0,right=0;
    int len=lengthOfString(str);
    while (right<=len && left<=right)
    {
        if(delameter(str[right])==0)
            right ++;
        if (delameter(str[right])==1 && left==right)
        {
            if(Operator(str[right])==1 && left==right)
                printf("'%c' is operator\n",str[right]);
            
            right ++;
            left=right;
        }
        else if (delameter(str[right])==1 && left!=right||(right==len&&left!=right))
        {
            char* substr= substring(str,left,right-1);
            if(Keywoard(substr)==1)
               printf("'%s' is keywoard\n",substr);

            else if (Inteder(substr)==1)
                printf("'%s' is integrer\n",substr);

            else if (realNumber(substr)==1)
                printf("'%s' is realNumber\n",substr);  

            else if (Identifier(substr)==1 && delameter(str[right-1])==0)
                printf("'%s' is Identifier\n",substr); 

            else if (Identifier(substr)==0 && delameter(str[right-1])==0)
                printf("'%s' is not Identifier\n",substr);      
            left=right;               
        }
             
    }
    return 0;
}


    




