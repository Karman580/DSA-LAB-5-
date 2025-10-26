
int main() {
    int a[10][10], t[10][10];
    int m,n,i,j;

    cin >> m >> n;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin >> a[i][j];

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            t[j][i]=a[i][j];

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
}

