#include<iostream>
#include<vector>

using std::vector;

vector<int> bubble_sort(vector<int> v) {
    int v_size = v.size();
    for (int i = 0; i < v_size; i++) {
        for (int j = 0; j < (v_size-i)-1; j++) {
            if (v[j] > v[j+1]) std::swap(v[j], v[j+1]);
        }
    }
    return v;
}

vector<int> unique(vector<int> v) {
    v = bubble_sort(v);
    for (int i = 0; i < v.size()-1; i++) {
        if (v[i] == v[i+1]) v.erase(v.begin() + i);
    }
    return v;
}

int main() {
    int n;
    std::cout << "n=";
    std::cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cout << "v[" << i << "]=";
        std::cin >> v[i];
    }

    vector<int> erg = unique(v);
    for (int i = 0; i < erg.size(); i++) {
        std::cout << erg[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}