#include <iostream>
#include <ctime>
#include <vector>

void veccopy(std::vector<int>& vecMain, std::vector<int>& vecWork);
void swap(int& a, int& b);
void printvec(std::vector<int>& vec);
int cocktailsort(std::vector<int>& vec);
int mergesort(std::vector<int>& vec);
int shellsort(std::vector<int>& vec);


int main() {
    int m;
    std::cout << "Amount of digits:" << std::endl;
    std::cin >> m;
    std::vector<int> vecForCocktailsort(m);
    std::vector<int> vecForMergesort(m);
    std::vector<int> vecForShellsort(m);
    std::vector<int> vec(m);
    std::srand(std::time(nullptr));
    std::cout << "Random digits:" << std::endl;
    for ( int i=0; i<m; i++){
        vec[i] = std::rand()%201-100;
    }
    printvec(vec);
    veccopy(vec, vecForCocktailsort);
    cocktailsort(vecForCocktailsort);
    std::cout << "Cocktail sort:" << std::endl;
    printvec(vecForCocktailsort);
    veccopy(vec, vecForMergesort);
    mergesort(vecForMergesort);
    std::cout << "Merge sort sort:" << std::endl;
    printvec(vecForMergesort);
    veccopy(vec, vecForShellsort);
    shellsort(vecForShellsort);
    std::cout << "Shell sort:" << std::endl;
    printvec(vecForShellsort);
    return 0;
}

void veccopy(std::vector<int>& vecMain, std::vector<int>& vecWork){
    for ( int i=0; i<vecMain.size(); i++){
        vecWork[i] = vecMain[i];
    }
}

void swap (int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

void printvec(std::vector<int>& vec){
    for ( int i=0; i<vec.size(); i++)
        std::cout << vec[i] << ' ';
    std::cout << std::endl;
}

int cocktailsort(std::vector<int>& vec){
    for (int i = 0; i < vec.size() / 2; i++)
    {
        bool point = true;
        for (int x = i+1; x < vec.size()-i; x++)
        {
            if (vec[x] > vec[x + 1])
            {
                swap(vec[x], vec[x + 1]);
                point = false;
            }
        }
        for (int x = vec.size()-i-2; x > i; x--)
        {
            if (vec[x - 1] > vec[x])
            {
                swap(vec[x - 1], vec[x]);
                point = false;
            }
        }
        if (point)
        {
            break;
        }
    }
    return 0;
}

int mergesort(std::vector<int>& vec){
    return 0;
}

int shellsort(std::vector<int>& vec){
    int a = vec.size() / 2;
    while (a >= 1)
    {
        for (int i = a; i < vec.size(); i++)
        {
            int x = i;
            while ((x >= a) && (vec[x-a] > vec[x]))
            {
                swap(vec[x], vec[x-a]);
                x -= a;
            }
        }

        a /= 2;
    }
    return 0;
}
