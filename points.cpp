#include <iostream>
#include <vector>
#include <random>
#include <array>
#include <cmath>
#include <fstream>
#include <string>

double euclDist(const std::vector<double>& a, const std::vector<double>& b)
{
    double dist = 0.0;
    for (int i = 0; i < a.size(); i++)
    {
        auto x = a[i] - b[i];
        dist += x * x;
    }
    return std::sqrt(dist);
}

std::vector<std::vector<double>> genPoints(int d)
{
    std::vector<std::vector<double>> points(100, std::vector<double>(d));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < d; j++)
        {
            points[i][j] = dis(gen);
        }
    }
    return points;
}

std::vector<double> calculateDist(const std::vector<std::vector<double>>& points)
{
    std::vector<double> dists;
    for (int i = 0; i < points.size() - 1; i++)
    {
        for (int j = i+1; j < points.size(); j++)
        {
            dists.push_back(euclDist(points[i], points[j]));
            //std::cout << i << ' ' << j << '\n';
        }
    }
    return dists;
}

int main()
{
    int dims[5] = {10, 50, 100, 500, 1000};
    std::vector<double> dists[5];
    for (int i = 0; i < 5; i++)
    {
        auto p = genPoints(dims[i]);
        dists[i] = calculateDist(p);
        std::cout << i  << ' ' << dims[i] << ' ' << p.size() << ' ' << dists[i].size() << '\n';
    }
    std::ofstream f("distances.csv");
    for (int i = 0; i < 4; i++)
    {
        f << dims[i] << ',';
    }
    f << dims[4] << '\n';
    for (int j = 0; j < dists[0].size(); j++)
    {   
        int i = 0;
        for (; i < 4; i++)
        {
            f << dists[i][j] << ',';
        }
        f << dists[i][j] << '\n';
    }
    return 0;
}