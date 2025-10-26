
int main() {
    int arr[100], n, i;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int end = n - 1;
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    cout << "Reversed array:\n";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
