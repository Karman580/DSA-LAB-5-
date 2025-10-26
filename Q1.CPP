#include <iostream>
using namespace std;
int main() {
    int arr[100], n = 0, choice, pos, val, key, i, flag;

    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter no. of elements: ";
            cin >> n;
            cout << "Enter the elements one by one:\n";
            for (i = 0; i < n; i++) cin >> arr[i];
            break;

        case 2:
            if (n == 0) cout << "Array is empty.\n";
            else {
                cout << "Array elements: ";
                for (i = 0; i < n; i++) cout << arr[i] << " ";
                cout << "\n";
            }
            break;

        case 3:
            if (n == 100) cout << "Array is full.\n";
            else {
                cout << "Enter position (1-" << n + 1 << "): ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> val;
                for (i = n; i >= pos; i--) arr[i] = arr[i - 1];
                arr[pos - 1] = val;
                n++;
            }
            break;

        case 4:
            if (n == 0) cout << "Array is empty.\n";
            else {
                cout << "Enter position (1-" << n << "): ";
                cin >> pos;
                for (i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
                n--;
            }
            break;

        case 5:
            if (n == 0) cout << "Array is empty.\n";
            else {
                cout << "Enter value to search: ";
                cin >> key;
                flag = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        cout << "Found at position " << i + 1 << "\n";
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) cout << "Not found.\n";
            }
            break;

        case 6:
            cout << "Exited\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
