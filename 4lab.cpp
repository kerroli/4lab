#include <iostream>
#include <ctime>

void swap_int(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rand_mas(int mas[]) {
    for (int i = 0; i < 30; i++) {
        mas[i] = std::rand() % 201 - 100;
    }
}

void print_mas(int mas[]) {
    for (int i = 0; i < 30; i++) {
        std::cout << mas[i] << ' ';
    }
    std::cout << std::endl;
}

int cocktail_sort(int mas[], int n) {
    int start = 0;
    int end = n - 1;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = start; i < end; i++) {
            if (mas[i] > mas[i + 1]) {
                swap_int(&mas[i], &mas[i + 1]);
                flag = true;
            }
        }
        end--;
        for (int i = end - 1; i >= start; i--) {
            if (mas[i] > mas[i + 1]) {
                swap_int(&mas[i], &mas[i + 1]);
                flag = true;
            }
        }
        if (!flag) break;
        start++;
    }
    return 0;
}

int merge_sort_halves(int mas[], int mid, int left, int right) {
    int temp_left, temp_mid, iter, mas_new[right+1];
    temp_left = left;
    iter = temp_left;
    temp_mid = mid + 1;
    while ((temp_left <= mid) && (temp_mid <= right)) {
        if (mas[temp_left] < mas[temp_mid]) {
            mas_new[iter] = mas[temp_left];
            iter++;
            temp_left++;
        }
        else {
            mas_new[iter] = mas[temp_mid];
            iter++;
            temp_mid++;
        }
    }
    while (temp_left <= mid) {
        mas_new[iter] = mas[temp_left];
        iter++;
        temp_left++;
    }
    while (temp_mid <= right) {
        mas_new[iter] = mas[temp_mid];
        iter++;
        temp_mid++;
    }
    for (int i = left; i < iter; i++)
        mas[i] = mas_new[i];
    return 0;
}

int merge_sort(int mas[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(mas, left, mid);
        merge_sort(mas, mid + 1, right);
        merge_sort_halves(mas, mid, left, right);
    }
    return 0;
}

int shell_sort(int mas[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = mas[i];
            int j;
            for (j = i; j >= gap && mas[j - gap] > temp; j -= gap)
                mas[j] = mas[j - gap];
            mas[j] = temp;
        }
    }
    return 0;
}

int main() {
    std::srand(std::time(nullptr));
    int mas[30];
    //
    rand_mas(mas);
    cocktail_sort(mas, 30);
    print_mas(mas);
    //
    rand_mas(mas);
    merge_sort(mas, 0, 29);
    print_mas(mas);
    //
    rand_mas(mas);
    shell_sort(mas, 30);
    print_mas(mas);
    //
    return 0;
}
