void preorder(NODE root)
{
    NODE cur, s[20];
    int top=-1;
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    cur=root;
    for(;;)
    {
        while(cur!=NULL)
        {
            printf("%d",cur->info);
            s[++top]=cur;
            cur=cur->llink;
        }
        if(top!=-1)
        {
            cur=s[top--];
            cur=cur->rlink;
        }
        else
            return;
    }
}
//-----------------------------------------
void postorder(NODE root)
{
    struct stack
    {
        NODE address;
        int flag;
    };
    NODE cur;
    struct stack s[20];
    int top=-1;
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    cur=root;
    for(;;)
    {
        while(cur!=NULL)
        {
            top++;
            s[top].address=cur;
            s[top].flag=1;
            cur=cur->llink;
        }
        while(s[top].flag < 0)
        {
            cur=s[top].address;
            top--;
            printf("%d",cur->info);
            if(top==-1)
            return;
        }
        cur=s[top].address;
        cur=cur->rlink;
        s[top].flag=-1;
    }
}