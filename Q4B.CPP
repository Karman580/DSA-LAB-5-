
int main() {
    int a[10][10], b[10][10], c[10][10];
    int i, j, k, m, n, p, q;

    cin >> m >> n;
    cin >> p >> q;

    if(n != p) {
        cout << "Not possible";
        return 0;
    }

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin >> a[i][j];

    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            cin >> b[i][j];

    for(i=0;i<m;i++)
        for(j=0;j<q;j++) {
            c[i][j]=0;
            for(k=0;k<n;k++)
                c[i][j]+=a[i][k]*b[k][j];
        }

    for(i=0;i<m;i++) {
        for(j=0;j<q;j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}
