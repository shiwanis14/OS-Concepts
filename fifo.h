#ifndef FIFO_H
#define FIFO_H
  #include<iostream>
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
     
    using namespace std;
     
    int foundlru(int x,int *l,int max)
    {
            for(int i=0;i<max;i++)
                    if(l[i]==x){return(i);}
            return(-1);
    }
     
    void fifoalgorithm()
    {
            cout<<"\n\nEnter the maximum number of frames in the main memory:\t";
            int max;
            cin>>max;
            int *l=new int[max];
            for(int i=0;i<max;i++)l[i]=-1;
            int a,x;
            int k=0,c=0,res;
            cout<<"\n\nEnter the sequence of page requests(enter -1 to stop):\t";
            while(1)
            {
                    cin>>x;
                    if(x==-1) {cout<<"\n\n";break;}
                    else{
                   
                    if(k<max)
                    {
                            if((res=foundlru(x,l,max))!=-1) {cout<<"\n\npage "<<x<<" already exists in frame "<<res<<" in MM";
                                    cout<<"\n\nNext page:\t";}
                            else
                            {
                                    cout<<"\n\npage "<<x<<" has been allocated a frame "<<k<<" in MM.";
                                    l[k++]=x;
                                    cout<<"\n\nNext page:\t";
                            }
                    }
                    else
                    {
                            if((res=foundlru(x,l,max))!=-1) {cout<<"\n\npage "<<x<<" already exists in frame "<<res<<" in MM";
                                    cout<<"\n\nNext page:\t";}
                            else{
                           
                            cout<<"\n\npage fault has occured";
                            cout<<"\n\npage "<<x<<" has been allocated frame "<<c<<" in MM by replacing page "<<l[c];
                            l[c]=x;
                            c=(c+1)%max;
                            cout<<"\n\nNext page:\t";
                            }
                    }
                    }
                           
            }
           
            delete[] l;
    }
#endif
