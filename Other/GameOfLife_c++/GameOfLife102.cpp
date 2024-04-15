#include <iostream>
using namespace std;const int NumberOfRows=10;const int
NumberOfColumns=10;const int NumberOfGenerations=10;const
int NumberOfLivingCells=50;bool IsCellAlive(const bool
Colony[NumberOfRows][NumberOfColumns],const int Row,
const int Column){if(0<=Row&&Row<NumberOfRows&&0<=Column
&&Column<NumberOfColumns){return Colony[Row][Column];
}return false;}int NumberOfLivingNeighbors(const bool
Colony[NumberOfRows][NumberOfColumns],const int Row,
const int Column){int Counter=0;for(int i=Row-1;i<=Row
+1;i++){for(int j=Column-1;j<=Column+1;j++){if((i!=Row
||j!=Column)&&IsCellAlive(Colony, i, j)){Counter+=1;}}}
return Counter;}void CreateNewColony(const bool
CurrentColony[NumberOfRows][NumberOfColumns],bool
NewColony[NumberOfRows][NumberOfColumns]){for(int i=0
;i<NumberOfRows;i++){for(int j=0;j<NumberOfColumns;j++)
{int l=NumberOfLivingNeighbors(CurrentColony,i,j);NewColony
[i][j]=CurrentColony[i][j]&&l==2||l==3;}}}void
PrintColony(const bool Colony[NumberOfRows][NumberOfColumns]
){for(int i=0;i<NumberOfRows;i++){for(int j=0;j
<NumberOfColumns;j++){if(Colony[i][j])cout<<"X";else
cout<<".";}cout<<endl;}cout<<endl;}void CopyColony(const
bool SourceColony[NumberOfRows][NumberOfColumns],bool
DestinationColony[NumberOfRows][NumberOfColumns]){for(int
i=0;i<NumberOfRows;i++){for(int j=0;j<NumberOfColumns;
j++){DestinationColony[i][j]=SourceColony[i][j];}}}
void InitColony(bool Colony[NumberOfRows][NumberOfColumns]
,const int NumberOfLivingCells){for(int i=0;i<NumberOfRows;
i++){for(int j=0;j<NumberOfColumns;j++){Colony[i][j]=false;
}}for(int i=0;i<NumberOfLivingCells;i++){int r,c;do{r=rand()%
NumberOfRows;c=rand()%NumberOfColumns;}while(Colony[r][c]);
Colony[r][c]=true;}}void main(){bool CurrentColony[NumberOfRows]
[NumberOfColumns];bool NewColony[NumberOfRows]
[NumberOfColumns];InitColony(CurrentColony,
NumberOfLivingCells);cout<<"Puvodni kolonie"<<endl;
PrintColony(CurrentColony);cout<<endl;for(int i=1;
i<=NumberOfGenerations;i++){CreateNewColony(CurrentColony,
NewColony);CopyColony(NewColony,CurrentColony);
cout<<"Generace #"<<i<<endl;PrintColony(CurrentColony);}}
