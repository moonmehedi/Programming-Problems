#include<bits/stdc++.h>
using namespace std;
int main()
{   /*************invered halfpyramid**************/
    // *****
    // ****
    // ***
    // **
    // *
    int n=5;
for (int i=n;i!=0;i--){
    for (int j=1;j<=i;j++)//THIS ONE IS MORE EFFICIENT AS THIS LOOP WILL RUN ACCORDING TO J
    {
        if(j<=i )
        cout<<"*";
    }cout<<endl;}


    /***************AFTER 180 ROTATION ANOTHER PIRAMID**********************/
    //     *
    //    **
    //   ***
    //  ****
    // *****
    for (int i=1;i<=n;i++){           
    for (int j=1;j<=n;j++)           
    {                           
        if(n-i>=j)           
        cout<<" ";           
        else           
        cout<<"*";           
    }cout<<endl;}     




/***********************HALF PYRAMID USING NUMBERS******************/
    for(int i=0;i<n;i++){
    for (int j=0;j<=i;j++)
    {cout<<"*";}
    cout<<endl;}
    

    /******************FLOYDS TRIANGLE************/
                 int s=0;                                                                
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)//trick in condition
        {  
            s+=1;
            printf("%d",s);
        }cout<<endl;}
                                                                        
                                                                                 
    /********************BUTTERFLY PATTERN  ***********/                                
     for(int i=1;i<=2*n;i++)

    {

      for(int j=1;j<=2*n;j++)

      {if(i<=n){

      if(j<=i||(2*n-i)<j)

       printf ("*");

       else

       printf(" ");}

       if(i>n)

       {

         if(j>=i||(2*n-i+1)>=j)

         {

           printf("*");

         }

         else

          printf (" ");

       } 

       } printf("\n");

    }
                          
                                                                                 
}