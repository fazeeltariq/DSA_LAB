#include <iostream>
using namespace std;
#include <string>
bool ispalindrome(string n)
{
    int count = n.length();
    int j = count - 1;
    bool found = true;
    if(n.length()!=5) return false;
    for (int i = 0; i < count; i++)
    {
        if (n[i] != n[j])
        {
            found = false;
            break;
        }
        j--;
    }
    if (found == true)
    {
        cout << "palindorme" << endl;
        cout<<n<<endl;
        return true;
    }
    else
    {
        return false;
    }
}
bool issafe(string arr[5][5],int i,int j,int n,int visited[5][5])
{
    if(i<0 || j<0 || i>=n || j>=n || visited[i][j]==1)
    {
        return false;
    }
    return true;
}
void back(string arr[5][5], int i, int j, int n, string chk,int visited[5][5])
{
    if (i >= 4 || j >= 4 || chk.length()==5)
    {
        ispalindrome(chk);
        return;
    }
    if(issafe(arr,i,j,n,visited))
    {
        visited[i][j]=1;
        chk=chk+arr[i][j];
        back(arr,i+1,j,n,chk,visited);
         back(arr,i,j+1,n,chk,visited);
          back(arr,i-1,j,n,chk,visited);
           back(arr,i,j-1,n,chk,visited);

           visited[i][j]=0;
    }

}

int main()
{
    string arr[5][5] = {{"G", "R", "O", "O", "T"},
                        {"B", "A", "R", "R", "O"},
                        {"W", "R", "D", "B", "S"},
                        {"R", "A", "D", "A", "R"},
                        {"W", "E", "S", "T", "G"}};
    int count = 5;
    int visited[5][5]={0};
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < count; i++)
    {
    for (int j = 0; j < count; j++)
    {
       back(arr,i,j,5,"",visited);
    }
    
    }
    
    

    return 0;
}