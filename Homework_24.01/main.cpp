#include "Libraries.h"

void addColumn(vector<vector<int>>& matrix, int columnIndex, const vector<int>& newColumn) {
    if (columnIndex >= 0 && columnIndex <= matrix[0].size()) {
        for (size_t i = 0; i < matrix.size(); ++i) {
            matrix[i].insert(matrix[i].begin() + columnIndex, newColumn[i]);
        }
    }
    else {
        cout << "�������� ����� ��� ���!" << endl;
    }
}

void removeColumn(vector<vector<int>>& matrix, int columnIndex) {
    if (columnIndex >= 0 && columnIndex < matrix[0].size()) {
        for (size_t i = 0; i < matrix.size(); ++i) {
            matrix[i].erase(matrix[i].begin() + columnIndex);
        }
    }
    else {
         cout << "�������� ����� ��� ���!" << endl;
    }
}

void cyclicShift(vector<vector<int>>& matrix, int shifts, const string& direction) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (direction == "LEFT" || direction == "RIGHT") {
        // ����������� ����� ��������
        shifts = (direction == "LEFT") ? shifts : cols - shifts;
        shifts %= cols;

        for (int i = 0; i < rows; ++i) {
            rotate(matrix[i].begin(), matrix[i].begin() + shifts, matrix[i].end());
        }
    }
    else if (direction == "UP" || direction == "DOWN") {
        // ����������� ����� �����
        shifts = (direction == "UP") ? shifts : rows - shifts;
        shifts %= rows;

        rotate(matrix.begin(), matrix.begin() + shifts, matrix.end());
    }
    else {
        cout << "�����" << endl;
    }
}

int main() {
	setlocale(LC_ALL, "RU");

    //������� 1
    /*vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }

    vector<int> newColumn = { 10, 11, 12 };

    addColumn(matrix, 1, newColumn);

    cout << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }*/

    //������� 2
    /*vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }

    removeColumn(matrix, 1);

    cout << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }*/

    //������� 3
    /*vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }

    int shifts;
    string direction;

    cout << "������� ���������� �������: ";
    cin >> shifts;
    cout << "������� ����������� ������ (LEFT, RIGHT, UP, DOWN): ";
    cin >> direction;

    cyclicShift(matrix, shifts, direction);

    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }*/

	return 0;
}