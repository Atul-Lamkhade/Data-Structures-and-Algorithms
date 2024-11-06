/*Analyze complexity of loops and recursive algorithms */

int main()
{
int i,j,n;
int a=0,b=0;                    
for(i=0;i<n;i++){     //for this function O(n)
    a=a+rand();
}
for(j=0;j<n;j++){    //for this function O(n)
    b=b+rand();
}
}  /*Overall time complexity for this function O(n)+O(n) 
                                               =2 O(n)
                                               =O(n)       constant value is not considered.
  */



int main()
{
 int i,j,k,n;
int a=0,b=0;
for(i=0;i<n;i++)
{                            //for outer for loop  O(n)
    for(j=0;j<n;j++){        //for inner for loop  O(n)    
     a=a+j;
    }
}
for(k=0;k<n;k++){           //for this loop O(n)
     b=b+k;
}
}
/*Overall time complexity for this function O(n) * O(n) +O(n) 
                                               =O(n^2) +O(n)
                                               =O(n^2)     
  */



int main()
{
 int i,j,n;
int a=0;
for(i=0;i<n;i++)     //for outer for loop  O(n)
{
    for(j=n;j>i;j--){    //for inner for loop  O(n)
     a=a+j;
    }
}
}
/*Overall time complexity for this function O(n) * O(n)  
                                               =O(n^2) 
                                                    
  */