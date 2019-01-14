#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int fact(int n)
{
    if(n==1 || n==0) return 1;
    else
        return n*fact(n-1);
}
int series(int n)
{
      int c;
      c=fact(n)/(2*(fact(n-2)));
      return c;
}
int series2(int n)
{
        int c;
        c=fact(n)/(6*(fact(n-3)));
        return c;
}
int row=0,col=0;
int main()
{
    //string filename;
    //cout<<"enter name of the file"<<endl;
    //cin>>filename;
    int i,n,j,k,minn,diff;
    cout<<"enter the minimum support count\n";
    cin>>minn;
    freopen("abc.csv","r",stdin);
    string s;
    int a[500][500];
    int x;
    while(cin>>s)
    {
        stringstream ss(s);
        col=0;
        int ndw=1;
        while (ss >> x)
        {
            a[row][col++]=x;
            if(ss.peek()==',')
                ss.ignore();
        }
        row++;
    }
    int c[row];
    for(i=0;i<row;i++)
        c[i]=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            for(k=0;k<j;k++)
            {
                if(a[i][j]==a[i][k])
                {
                    break;
                }
            }
            if(j==k)
                c[i]++;
        }
        //cout<<c[i]<<" ";
    }
    diff=c[0];
    for(i=1;i<row;i++)
    {
        if(c[i]>diff)
            diff=c[i];
    }
    /*cout<<"the original data is :\n\n";
    for(int l=0;l<row;l++)
    {
        for(int m=0;m<col;m++)
            cout<<a[l][m]<<" ";
            cout<<endl;
    }
    cout<<"the no of rows in the data are : "<<row;
    cout<<"\nand the no of columns in the data are : "<<col;

    cout<<"enter the no of transactions\n";
    cin>>n;
    int a[n][5];
    for(i=0;i<n;i++)
    {
        cout<<"enter items for transaction "<<i+1<<"\n";
        for(j=0;j<5;j++)
        {
            cin>>a[i][j];
        }
    }*/
    cout<<"the data we have of transactions and items is as follows :\n\n";
    cout<<"TRANSACTIONS\t\t\t\t\tITEMS\n";
    for(i=0;i<row;i++)
    {
        cout<<"\t"<<"T"<<i+1<<"\t\t\t\t";
        for(j=0;j<col;j++)
        {
            cout<<"I"<<a[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<"\nthe no of rows in the data are : "<<row;
    cout<<"\nand the no of columns in the data are : "<<col;
    cout<<"\nthe minimum support count is "<<minn;
    cout<<"\nthe number of different items are : "<<diff;
    int c1[diff];
    for(i=0;i<diff;i++)
    {
        int t1=0;
        for(j=0;j<row;j++)
        {
            for(k=0;k<col;k++)
            {
                if(a[j][k]==i+1)
                    t1++;
            }
        }
        c1[i]=t1;
    }
    cout<<"\n\n\nC1 for the data is \n\n";
    cout<<"\tItem"<<"\t\tCount\n";
    for(i=0;i<diff;i++)
    {
        cout<<"\tI"<<i+1<<"\t\t"<<c1[i]<<"\n";
    }
    //cout<<minn<<endl;
    int l1[diff];
    int count1=0;
    for(i=0,j=0;i<diff;i++)
    {
        if(c1[i]>=minn)
        {
            l1[j]=i;
            count1++;
            j++;
        }
    }
    //cout<<j<<endl;
    //cout<<count1<<endl;
    /*for(i=0;i<row;i++)
        cout<<l1[i]<<"\n";*/
    cout<<"\n\n\nL1 for the data is \n\n";
    cout<<"\tItem"<<"\t\tCount\n";
    for(i=0;i<count1;i++)
    {
        cout<<"\tI"<<l1[i]+1<<"\t\t"<<c1[l1[i]]<<endl;
    }
    //int y=series(count1);
    //cout<<y;
    int n1=series(count1);
    int c2[n1][3];
    int c2t1; //will hold first item for join
    int c2t2; //will hold second item for join
    int v=0;
    //cout<<"\n"<<count1<<endl;
    for(i=0;i<count1;i++)
    {
        //cout<<"outer pass "<<i<<endl;
        for(j=i+1;j<count1;j++,v++)
        {
            //cout<<"inner pass "<<j<<endl;
            c2t1=l1[i];
            c2t2=l1[j];
            c2[v][0]=c2t1;
            c2[v][1]=c2t2;
            int t2=0;
            int k,l;
            //int h,g;
            //cout<<"c2t1 "<<c2t1<<endl;
            //cout<<"c2t2 "<<c2t2<<endl;
            /*for(h=0;h<j;h++)
            {
                for(g=0;g<2;g++)
                {
                    cout<<c2[h][g]<<endl;
                }
            }*/
            for(k=0;k<row;k++)
            {
                int f1=0;
                int f2=0; //resetting flag
                //scan a purcahse
                for(l=0;l<col;l++)
                {
                    if(c2t1+1==a[k][l])
                    {
                    //one of the element found
                        f1=1;
                    }
                    if(c2t2+1==a[k][l])
                    {
                        //second elements also found
                        f2=1;
                    }
                }
                //one purchase scanned
                if(f1==1 && f2==1) //both items are present in
                //purchase
                {
                    t2++;
                }
            }
            //assign count
            //cout<<i<<"    "<<t2<<endl;
            c2[v][2]=t2;
        }

    }
    /*cout<<"first"<<c2[0][2]<<"\n";
    cout<<"second"<<c2[1][2]<<"\n";
    cout<<"third"<<c2[2][2]<<"\n";
    cout<<"fourth"<<c2[3][2]<<"\n";
    cout<<"fifth"<<c2[4][2]<<"\n";
    cout<<"sixth"<<c2[5][2]<<"\n";
    cout<<"seventh"<<c2[6][2]<<"\n";
    cout<<"eighth"<<c2[7][2]<<"\n";
    cout<<"ninth"<<c2[8][2]<<"\n";
    cout<<"tenth"<<c2[9][2];
    for(int h=0;h<10;h++)
    {
            cout<<c2[h][2]<<endl;
    }*/
    //Printing second pass
    cout<<"\n\nGenerating C2\n";
    cout<<"\tItem"<<"\t\tCount\n";
    for(i=0;i<series(count1);i++)
    {
        cout<<"\t{I"<<c2[i][0]+1<<",I"<<c2[i][1]+1<<"}\t\t"<<c2[i][2]<<endl;
    }

    int l2[series(count1)];
    int count2=0;
    cout<<"\n\nGenerating L2\n";
    cout<<"\tItem"<<"\t\tCount\n";
    for(i=0;i<series(count1);i++)
    {
        if(c2[i][2]>=minn)
        {
            cout<<"\t{I"<<c2[i][0]+1<<",I"<<c2[i][1]+1<<"}\t\t"<<c2[i][2]<<endl;
            count2++;
        }
    }
cout<<count2;
    int c3[count2];
    int visited[diff];
    int l=0;
    for(i=0;i<count2;i++)
        c3[i]=0;
    for(j=0;j<diff;j++)
        visited[j]=0;
    //for(i=0;i<count2;i++)
        //cout<<c3[i];
    cout<<endl;
    for(k=0;k<count2;)
    {
        for(i=0;i<series(count1);i++)
        {
            if(c2[i][2]>=minn)
            {
                for(j=0;j<2;j++)
                {
                    if(visited[c2[i][j]]!=1)
                    {
                        if(c3[k]==c2[i][j])
                        {
                            //visited[c2[i][j]]=1;
                            k++;
                        }
                        else
                        {
                            c3[k]=c2[i][j];
                            //visited[c2[i][j]]=1;
                            k++;
                        }
                        visited[c2[i][j]]=1;
                    }
                }
            }
         }
    }
    for(i=0;i<count2;i++)
       cout<<c3[i];
    cout<<endl;
    /*for(j=0;j<diff;j++)
        cout<<visited[j];*/
    //cout<<count2;
    //int n2=series2(count2);
    //cout<<endl;
    //cout<<n2;
    int l3[series2(count2)][4];
    /*for(i=0;i<3;i++)
    {
        l3[i][0]=0;
    }
    for(i=0;i<3;i++)
    {
        cout<<endl;
        cout<<l3[i][0];
    }
    */
    int c3t1,c3t2,c3t3;
    int z,v1=0;
    for(i=0;i<count2;i++)
    {
        for(j=i+1;j<count2;j++)
        {
            for(z=j+1;z<count2;z++,v1++)
            {
                c3t1=c3[i];
                c3t2=c3[j];
                c3t3=c3[z];
                //cout<<c3t3;
                l3[v1][0]=c3t1;
                l3[v1][1]=c3t2;
                l3[v1][2]=c3t3;
                int t3=0;
                int k,l;
                for(k=0;k<row;k++)
                {
                    int f1=0;
                    int f2=0;
                    int f3=0;
                    for(l=0;l<col;l++)
                    {
                        if(c3t1+1==a[k][l])
                        {
                            f1=1;
                        }
                        if(c3t2+1==a[k][l])
                        {
                            f2=1;
                        }
                        if(c3t3+1==a[k][l])
                        {
                            f3=1;
                        }
                    }
                    if(f1==1 && f2==1 && f3==1)
                    {
                        t3++;
                    }
                }
                l3[v1][3]=t3;
            }
        }
    }
    int count3=0;
    //for(i=0;i<series2(count2);i++)
    //{
        //for(j=0;j<4;j++)
            //cout<<l3[i][j]<<endl;
    //}
    cout<<"\n\nGenerating C3\n";
    cout<<"\tItem"<<"\t\t\tCount\n";
    for(i=0;i<series2(count2);i++)
    {
        cout<<"\t{I"<<l3[i][0]+1<<",I"<<l3[i][1]+1<<",I"<<l3[i][2]+1<<"}\t\t"<<l3[i][3]<<endl;
    }
    cout<<"\n\nGenerating L3\n";
    cout<<"\tItem"<<"\t\t\tCount\n";
    for(i=0;i<series2(count2);i++)
    {
        if(l3[i][3]>=minn)
        {
            cout<<"\t{I"<<l3[i][0]+1<<",I"<<l3[i][1]+1<<",I"<<l3[i][2]+1<<"}\t\t"<<l3[i][3]<<endl;
            count3++;
        }
      }
    //cout<<count3;
    //Generating Rules
    /*for(i=0;i<series(count1);i++)
        cout<<c2[i][2];
    cout<<endl;
    for(i=0;i<diff;i++)
        cout<<c1[i];*/
    float confidence[count3][6];
    for(i=0;i<count3;i++)
    {
        for(l=0;l<6;)
        {
            for(j=0;j<series(count1);j++)
            {
                if(c2[j][2]>=minn)
                {
                    //cout<<c2[j][2]<<endl;
                    confidence[i][l]=5.0/(c2[j][2]);
                    l++;
                    if(l==3)
                        break;
                }
            }
            for(k=2;k>=0;k--)
            {
                cout<<c3[k]<<" "<<c1[c3[k]]<<endl;
                confidence[i][l]=5.0/(c1[c3[k]]);
                l++;
                if(l==6)
                    break;
            }
            if(l==6)
                break;
        }
    }
    for(i=0;i<count3;i++)
    {
        for(j=0;j<6;j++)
            cout<<confidence[i][j];
    }
    /*for(i=0;i<count3;i++)
    {
        if(count3==1)
        {
            cout<<"the rule with most confidence for your dataset is "
        }
    }
    /*
    //Third pass
    int p3pcount=0;
    int p3items[5]={-1,-1,-1,-1,-1};
    int p3pos=0;
    for(i=0;i<n;i++)
    {
        if(l2[i][2]>=min)
        {
            f=0;
            for(j=0;j<5;j++)
            {
                if(p3items[j]==l2[i][0])
                {
                    f=1;
                }
            }
            if(f!=1)
            {
            p3items[p3pos]=l2[i][0];
            p3pos++;
            p3pcount++;
            }
            f=0;
            for(j=0;j<5;j++)
            {
                if(p3items[j]==l2[i][1])
                {
                f=1;
                }
            }
            if(f!=1)
            {
                p3items[p3pos]=l2[i][1];
                p3pos++;
                p3pcount++;
            }
        }
    }
    //Joining
    int l3[5][4];
    int l3ocount=0; //occurance counter
    int l3jcount=0; //join counter
    for(i=0;i<p3pcount;i++)
    {
        for(j=i+1;j<p3pcount;j++)
        {
            for(k=j+1;k<p3pcount;k++)
            {
                l3[i][0]=p3items[i];
                l3[i][1]=p3items[j];
                l3[i][2]=p3items[k];
                l3jcount++;
                //count occurances
                l3ocount=0; //reset counter
                for(k=0;k<5;k++)
                {
                    f1=f2=f3=0; //resetting flag
                    //scan a purcahse
                    for(l=0;l<5;l++)
                    {
                        if(l3[i][0]==a[k][l])
                        {
                        //one of the element found
                            f1=1;
                        }
                        if(l3[i][1]==a[k][l])
                        {
                        //second elements also found
                            f2=1;
                        }
                        if(l3[i][2]==a[k][l])
                        {
                        //third element also found
                            f3=1;
                        }
                    }
                    //one purchase scanned
                    if(f1==1&&f2==1&&f3==1) //all items are present
                    //in purchase
                    {
                        l3ocount++;
                    }
                }
                //assign count
                l3[i][3]=l3ocount;
            }
        }
    }
    //Printing second pass
    cout<<"\n\nGenerating L3\n";
    for(i=0;i<l3jcount;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<l3[i][j]<<"\t";
        }
        cout<<"\n";
    }
    */
    getch();
    return 0;
}

