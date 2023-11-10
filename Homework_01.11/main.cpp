#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n, k;
    cout << "Ввод: " << endl;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    multiset<int> s;
    for (int i = 0; i < k; i++) {
        s.insert(nums[i]);
    }

    cout << "Вывод: " << endl;
    cout << *s.begin() << endl;
    for (int i = k; i < n; i++) {
        s.erase(s.find(nums[i - k]));
        s.insert(nums[i]);
        cout << *s.begin() << endl;
    }

    return 0;
}