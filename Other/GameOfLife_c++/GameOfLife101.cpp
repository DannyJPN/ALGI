#include <iostream>
using namespace std;
void main(){bool a[10][10],b[10][10];int i,j,k,l;for(i=0;
i<10;i++)for(j=0;j<10;j++)a[i][j]=false;for(i=0;i<50;
i++){j=rand()%10;k=rand()%10;a[j][k]=true;}cout<<
"Puvodni kolonie"<<endl;for(i=0;i<10;i++){for(j=0;j<10;
j++){if(a[i][j])cout<<"X";else cout<<".";}cout<<endl
;}cout<<endl;for(i=1;i<= 10;i++){for(j=0;j<10;j++
)for(k=0;k<10;k++){l=0;if(0<=(j-1)&&(j-1)<10&&0<=
(k-1)&&(k-1)<10&&a[j-1][k-1])l+=1;if(0<=(j-1)&&(j-1)
<10&&0<= k&&k<10&&a[j-1][k])l+=1;if(0<=(j-1)&&(j-1)
<10&&0<=(k+1)&&(k+1)<10&&a[j-1][k+1])l+=1;if(0<=j
&&j<10&&0<=(k-1)&&(k-1)<10&&a[j][k-1])l+=1;if(0<=
j&&j<10&&0<=(k+1)&&(k+1)<10&&a[j][k+1])l+=1;if(0<=(
j+1)&&(j+1)<10&&0<=(k-1)&&(k-1)<10&&a[j+1][k-1])l
+=1;if(0<=(j+1)&&(j+1)<10&&0<= k&&k<10&&a[j+1][k
])l+=1;if(0<=(j+1)&&(j+1)<10&&0<=(k+1)&&(k+1)<10
&&a[j+1][k+1])l+=1;if(a[j][k]&&l==2||l == 3)b[j]
[k]=true;else b[j][k]=false;}for(j=0;j<10;j++)for
(k=0;k<10;k++)a[j][k]=b[j][k];cout<<"Generace #"
<<i<<endl;for(j=0;j<10;j++){for(k=0;k<10;k++){if(a[j]
[k])cout<<"X";else cout<<".";}cout<<endl;}cout<<endl;}}
