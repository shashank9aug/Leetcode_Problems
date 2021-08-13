/*
    Given mat[i][j]  of n*m
    we have to find if their is any mat[i][j]==0
    make ith row and jth column completly zero 

Enter row and col : 3 4
0 1 2 0  
3 4 5 2
1 3 1 5
--------
0 0 0 0
0 4 5 0
0 3 1 0

*/

#include <iostream>
#include <vector>
using namespace std;

void setMatZero(vector<vector<int>> &mat, int n, int m)
{
    //create pair of coordinates of zero.
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                p.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < p.size(); i++)
    {
        // cout << p[i].first << " " << p[i].second << endl;

        for(int j=0;j<p[i].first;j++){
            mat[p[i].first][j]=0;
        }
        for(int j=0;j<p[i].second;j++){
            mat[j][p[i].second]=0;
        }
    }
}


//Solution : 
void setZero(vector<vector<int>>&mat){
    int row=mat.size();
    int col=mat[0].size();

    //flag for index of zero
    vector<int>rowidx(row,1);
    vector<int>colidx(col,1);

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==0){
                rowidx[i]=0;
                colidx[j]=0;
            }
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(rowidx[i]==0 or colidx[j]==0){
                mat[i][j]=0;
            }
        }
    }
}


int main()
{
    int n, m;
    cout << "Enter row and col : ";
    cin >> n >> m;
    vector<vector<int>> mat;
    int val;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            cin >> val;
            temp.push_back(val);
        }
        mat.push_back(temp);
        temp.clear();
    }

    setZero(mat);
    cout<<"--------"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}