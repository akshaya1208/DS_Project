#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

char back[5][10];
char forward[5][10];
int top=-1;
int ftop=-1;

void push(char url[])
{
    if ((top+1)==N)
    {
        printf("Stack Full\n");
    }
    else
    {
        top=top+1;
        strcpy(back[top], "");
        strcpy(back[top],url);
        printf("Navigating to %s\n",url);
    }
}

void pop()
{
    if (top==-1)
    {
        printf("Cannot go Back\n");
    }
    else
    {
        ftop=ftop+1;
        strcpy(forward[ftop],back[top]);
        top=top-1;
        if (top==-1)
        {
            printf("Going back to Homepage\n");
            return;
        }
        printf("Going back to %s\n", back[top]);
    }
}

void goForward()
{
    if (ftop==-1)
    {
        return;
    }
    printf("Forwarding to %s\n", forward[ftop]);
    push(forward[ftop]);
    ftop=ftop-1;
}

void displayCurrent()
{
    if (top!=-1)
    {
        printf("You are Currently Viewing %s\n", back[top]);
    }
    else
    {
        printf("Currently Viewing the HomePage\n");
    }
}

int displayMenu()
{
    int ch;
    char url[25];
    printf("1.Go to a Website:\n");
    if (top!=-1)
    {
        printf("2.Undo\n");
    }
    if (ftop!=-1)
    {
        printf("3.Forward\n");
    }
    printf("Enter a Choice: ");
    scanf("%d", &ch);
    if (ch==1)
    {
        printf("3.Enter an URL To Visit: ");
        scanf("%s",url);
        push(url);
    }
    else if (ch==2)
    {
        pop();
    }
    else if (ch==3)
    {
        goForward();
    }

    printf("Press 0 to Exit and 5 to Continue... ");
    scanf("%d",&ch);
    if (ch==0)
    {
        printf("Exiting....\n");
        return 0;
    }
}

void displayAll()
{
    int i;
    for (i=top;i>=0;i--)
    {
        printf("%d.%s\n",i,back[i]);
    }
}

void main()
{
    int ch;
    printf("*******************************\n");
    printf("        Web Browser            \n");
    printf("*******************************\n");
    printf("Opened the Browser\n");
    while (displayMenu())
    {
        displayCurrent();
    }
}
