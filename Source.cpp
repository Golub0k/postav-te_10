#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

void zhadniy(int n, int& sum, int vert, std::vector<std::vector<int>>& spisok, std::vector<int>& visited)
{

    int town = 0;
    int min = 2147483647;
    while (visited.size() != n)//посещаем все города
    {
        for (int j = 0; j < n; ++j)
        {
            bool vis = std::find(visited.begin(), visited.end(), j) != visited.end(); //проверяем, посещали ли город
            if (!vis)
            {
                if ((spisok[vert][j] != 0) && (spisok[vert][j] < min)) {
                    min = spisok[vert][j];
                    town = j;
                }
            }
        }
        sum += min;
        visited.push_back(town);
        zhadniy(n, sum, town, spisok, visited);
    }

}

void Vivod(int n, std::vector<std::vector<int>>& matrix)
{
    std::vector<std::vector<int>> itog; // вывод path
    std::vector<int> price;
    std::vector<int> chek;// посещенные города
    int summa = 0;

    for (int i = 0; i < n; ++i) //анализ городов
    {
        chek.push_back(i);
        zhadniy(n, summa, i, matrix, chek);//иду в рекурсию
        int z = chek[chek.size() - 1];
        if (matrix[z][i] != 0)
        {
            chek.push_back(i);
            summa += matrix[z][i];
        }
        price.push_back(summa);

        itog.push_back(chek);
        chek.clear();
        summa = 0;
    }

    int index_min = 0;
    int min = 2147483647;
    for (int j = 0; j < itog.size(); ++j) {
        if (itog[j][0] == itog[j][itog[j].size() - 1]) { // в начало
            if ((price[j] > 0) && (price[j] < min)) 
            {
                unsigned int x = 0;
                for (size_t i = 0; i < itog[j].size(); ++i)
                    for (size_t z = i + 1; z < itog[j].size(); ++z)
                        if (itog[j][i] == itog[j][z])
                        {
                            x += 1;
                        }
                if (x == 1) {
                    min = price[j];    //мин. цена
                    index_min = j;
                }
            }
        }
    }
    unsigned int vector_size = itog[index_min].size();

    if (min == 2147483647)
    {
        std::cout << "Lost" << std::endl;
    }
    else {
        std::cout << "Path:" << std::endl;

        for (auto el : itog[index_min]) { std::cout << el << " "; }
        std::cout << std::endl;
        std::cout << "Cost: " << min;
    }
}


int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> vse_goroda;
    int puti = 0;
    for (int i = 0; i < n; ++i)
    {
        std::vector<int> plus;
        for (int j = 0; j < n; ++j)
        {
            std::cin >> puti;
            plus.push_back(puti);
        }
        vse_goroda.push_back(plus);
        plus.clear();
    }


    Vivod(n, vse_goroda);
    return 0;
}
