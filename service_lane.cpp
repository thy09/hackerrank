#include <stdio.h>
#define MAX_WIDTH 3

int width[300000];
int prepare(int length);
int solve(int depth,int left,int right,int base);
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    int depth = prepare(n);
    int left,right;
    unsigned total = (1<<depth);
		while (t--)
    {
			scanf("%d%d",&left,&right);
			printf("%d\n",solve(depth,left+total,right+1+total,total));
		}
    return 0;
}
int prepare(int length)
{
    int depth = 0,total = 1;
    while (length>total)
    {
        depth++;
        total <<= 1;
    }
    for (int i=0;i<length;i++)
        scanf("%d",&width[total+i]);
    for (int i=length;i<total;i++)
        width[total+i] = MAX_WIDTH;
    for (int i=total-1;i>0;i--)
        if (width[(i<<1)]>width[(i<<1)+1])
            width[i] = width[(i<<1)+1];
        else width[i] = width[(i<<1)];
    //for (int i=1;i<total*2;i++)
    //printf("%d:%d\n",i,width[i]);
    return depth;
}
int solve(int depth,int left,int right,int base)
{
	//printf("solving %d,%d,%d,%d\n",depth,left,right,base);
	int tail = base + (1<<depth);
	if (left == base && tail == right)
		return width[base >> depth];
	int mid = base + (1<<(depth-1));
	//printf("%d:%d:%d\n",base,mid,tail);
	if (left >= mid)
		return solve(depth-1,left,right,mid);
	if (mid >= right)
		return solve(depth-1,left,right,base);
	int lv = solve(depth-1,left,mid,base);
	int rv = solve(depth-1,mid,right,mid);
	return lv<rv?lv:rv;
}
