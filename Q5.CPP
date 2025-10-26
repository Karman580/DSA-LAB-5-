
int main() {
    int a[10][10], m, n, i, j, s;

    cout << "Enter rows and cols: ";
    cin >> m >> n;

    cout << "Enter elements:\n";
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin >> a[i][j];

    for(i=0;i<m;i++) {
        s=0;
        for(j=0;j<n;j++) s+=a[i][j];
        cout << "Row " << i+1 << " sum = " << s << endl;
    }

    for(j=0;j<n;j++) {
        s=0;
        for(i=0;i<m;i++) s+=a[i][j];
        cout << "Col " << j+1 << " sum = " << s << endl;
    }
}