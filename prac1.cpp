#include <iostream>
using namespace std;
struct studentInfo
{
    string name;
    int roll;
    float sgpa;
};

// Get student information
void getStudentInfo(struct studentInfo s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << (i + 1) << endl;
        cout << "Enter Name: ";
        cin >> s[i].name;
        cout << "Enter Roll No: ";
        cin >> s[i].roll;
        cout << "Enter SGPA: ";
        cin >> s[i].sgpa;
        cout << endl;
    }
}

// Display all students
void displayInfo(struct studentInfo s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Name: " << s[i].name << endl;
        cout << "Roll No: " << s[i].roll << endl;
        cout << "SGPA: " << s[i].sgpa << endl;
        cout << endl;
    }
}

// Bubble Sort for Roll Numbers
void bubbleSortForRollNum(struct studentInfo s[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (s[j].roll > s[j + 1].roll)
            {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

// Insertion Sort for Names
void insertionSortForNames(struct studentInfo s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        studentInfo key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].name > key.name)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

// Quick Sort for SGPA
int partition(struct studentInfo s[], int low, int high)
{
    float pivot = s[high].sgpa;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (s[j].sgpa > pivot)
        {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return i + 1;
}

void quickSortForSGPA(struct studentInfo s[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(s, low, high);
        quickSortForSGPA(s, low, pi - 1);
        quickSortForSGPA(s, pi + 1, high);
    }
}

void displayTop10(struct studentInfo s[], int n)
{
    int limit = min(n, 10);
    cout << "Top " << limit << " Students According to SGPA:\n\n";
    for (int i = 0; i < limit; i++)
    {
        cout << "Rank: " << (i + 1) << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Roll No: " << s[i].roll << endl;
        cout << "SGPA: " << s[i].sgpa << endl;
        cout << endl;
    }
}

// Search by SGPA
void searchStudentwrtSGPA(struct studentInfo s[], int n, float key)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i].sgpa == key)
        {
            cout << "Name: " << s[i].name << endl;
            cout << "Roll No: " << s[i].roll << endl;
            cout << "SGPA: " << s[i].sgpa << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No student found with SGPA: " << key << endl;
}

// Binary Search for Name
void searchStudentwrtName(struct studentInfo s[], string key, int n)
{
    int start = 0;
    int end = n - 1;
    bool found = false;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (s[mid].name == key)
        {
            found = true;
            cout << "Name: " << s[mid].name << endl;
            cout << "Roll No: " << s[mid].roll << endl;
            cout << "SGPA: " << s[mid].sgpa << endl;
            cout << endl;
            
            // Check nearby for duplicates
            int left = mid - 1;
            while (left >= 0 && s[left].name == key)
            {
                cout << "Name: " << s[left].name << endl;
                cout << "Roll No: " << s[left].roll << endl;
                cout << "SGPA: " << s[left].sgpa << endl;
                cout << endl;
                left--;
            }

            int right = mid + 1;
            while (right < n && s[right].name == key)
            {
                cout << "Name: " << s[right].name << endl;
                cout << "Roll No: " << s[right].roll << endl;
                cout << "SGPA: " << s[right].sgpa << endl;
                cout << endl;
                right++;
            }
            break;
        }
        else if (s[mid].name < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (!found)
        cout << "No student found with name: " << key << endl;
}

int main()
{
    cout << "Student Information System.\n\n";
    int n;
    cout << "Enter Number of Students: ";
    cin >> n;

    struct studentInfo s[n];
    getStudentInfo(s, n);

    while (true)
    {
        cout << "Enter:\n";
        cout << "1. Arrange List by Roll Numbers (Bubble Sort)\n";
        cout << "2. Arrange List Alphabetically (Insertion Sort)\n";
        cout << "3. Display Top 10 Toppers (Quick Sort)\n";
        cout << "4. Search by SGPA\n";
        cout << "5. Search by Name (Binary Search)\n";
        cout << "6. Exit\n\n";

        int choice;
        string nameKey;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            bubbleSortForRollNum(s, n);
            displayInfo(s, n);
            break;

        case 2:
            insertionSortForNames(s, n);
            displayInfo(s, n);
            break;

        case 3:
            quickSortForSGPA(s, 0, n - 1);
            displayTop10(s, n);
            break;

        case 4:
            float sgpaKey;
            cout << "Enter SGPA to Search: ";
            cin >> sgpaKey;
            searchStudentwrtSGPA(s, n, sgpaKey);
            break;

        case 5:
            insertionSortForNames(s, n); // Ensure names are sorted for binary search
            
            cout << "Enter Name to Search: ";
            cin >> nameKey;
            searchStudentwrtName(s, nameKey, n);
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid Choice. Please try again.\n";
        }
    }
    return 0;
}
