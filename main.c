#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 50

void Sort_Int(int *metric,int *nums,int numbers)
{
    int temp,i,j;
    i=1;
    while (i<size)
    {
        j=i+1;
        while (j<size)
        {
            if (metric[i]<metric[j])
            {
                temp=metric[i];
                metric[i]=metric[j];
                metric[j]=temp;
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
            if (metric[i]==metric[j] && nums[i]>nums[j])
            {
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
            j++;
        }
        i++;
    }
    i=1;
    while (i<=numbers)
    {
        printf("%d ",nums[i]);
        i++;
    }
}

void Sort_Double(double *metric,int *nums,int numbers)
{
    double temp1;
    int temp2,i,j;
    i=1;
    while (i<size)
    {
        j=i+1;
        while (j<size)
        {
            if (metric[i]<metric[j])
            {
                temp1=metric[i];
                metric[i]=metric[j];
                metric[j]=temp1;
                temp2=nums[i];
                nums[i]=nums[j];
                nums[j]=temp2;
            }
            if (metric[i]==metric[j] && nums[i]>nums[j])
            {
                temp2=nums[i];
                nums[i]=nums[j];
                nums[j]=temp2;
            }
            j++;
        }
        i++;
    }
    i=1;
    while (i<=numbers)
    {
        printf("%d ",nums[i]);
        i++;
    }
}

int main()
{
    int numbers,metric,size_of_nums,num[size];
    char *file;
    int **nums;
    int i,j,k,a;
    scanf("%d %d ",&numbers,&metric);
    file=malloc(50*sizeof(char));
    fgets(file,100,stdin);
    file[strcspn(file,"\n")]='\0';
    if (numbers<=0 || numbers>=50)
    {
        printf("Wrong Input!");
        return 1;
    }
    if (metric<=-1 || metric>=4)
    {
    	printf("Wrong Input!");
    	return 1;
    }
    FILE *input;
    input=fopen(file,"r");
    if (input==NULL)
    {
        printf("File Error!");
        return 1;
    }
    i=0;
    while (i<size)
    {
    	num[i]=i;
    	i++;
    }
    int temp=0;
    nums=malloc(900*sizeof(int**));
    while (!feof(input))
    {
    	nums[temp]=malloc(8*sizeof(int*));
    	j=0;
    	while (j<7)
    	{
    		fscanf(input,"%d",&nums[temp][j]);
    		j++;
    	}
    	temp++;
    }
    if (strcmp(file,"big.txt")==0)
    {
    	size_of_nums=temp-1;
    }
    else
    {
        size_of_nums=temp;
    }
    int *metric0;
    metric0=calloc(50,sizeof(int*));
    i=0;
    while (i<size)
    {
        j=0;
    	while (j<size_of_nums)
    	{
    	    k=0;
    		while (k<7)
    		{
    			if (num[i]==nums[j][k])
    			{
    				metric0[i]+=1;
    			}
    			k++;
    		}
    		j++;
    	}
    	i++;
    }
    int *metric1;
    metric1=calloc(50,sizeof(int*));
    j=0;
    while (j<size)
    {
        k=0;
    	while (k<size_of_nums)
    	{
    		temp=0;
    		a=0;
    		while (a<7)
    		{
    			if (num[j]==nums[k][a])
    			{
    				temp=1;
    			}
    			a++;
    		}
    		if (temp==1)
    		{
    			metric1[j]=k;
    			break;
    		}
    		k++;
    	}
    	if(temp==0)
    	{
    		metric1[j]=10;
    	}
    	j++;
    }
    int *metric2;
    metric2=calloc(50,sizeof(int*));
    i=0;
    while (i<size)
    {
    	metric2[i]=metric0[i]+metric1[i];
    	i++;
    }
    double *metric3;
    metric3=calloc(50,sizeof(double));
    i=0;
    while (i<size)
    {
    	if (metric0[i]==0)
        {
    		metric3[i]=0;
    	}
    	else
        {
    		metric3[i]=metric1[i]-(size_of_nums/(double)metric0[i]);
    	}
    	i++;
    }
    if (metric==0)
    {
    	Sort_Int(metric0,num,numbers);
    }
    else if (metric==1)
    {
    	Sort_Int(metric1,num,numbers);
    }
    else if (metric==2)
    {
    	Sort_Int(metric2,num,numbers);
    }
    else if (metric==3)
    {
    	Sort_Double(metric3,num,numbers);
    }
    return 0;
}
