//
//  main.cpp
//  AllocationG
//
//  Created by adeeb mohammed on 01/11/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>
// find the maximum no of houses that can be buy
const int houseMaxPrice = 1001;


int getMaxHouse(std::vector<int> housePrices,
                int moneyWithUs){
    int noHouse = 0;
    int currentSum = 0;
    std::vector<int> sortArray(houseMaxPrice);
    // storing the max prices
    for (auto price : housePrices) {
        sortArray[price] += 1;
    }
    
    for(int housePrice = 0; housePrice < houseMaxPrice; housePrice++){
        int currentNoOfHouse = sortArray[housePrice];
        for (int i = 0; i < currentNoOfHouse; i++) {
            currentSum += housePrice;
            if (currentSum <= moneyWithUs) {
                noHouse++;
            }else{
                return noHouse;
            }
        }
    }
    
    return noHouse;
}

int main(int argc, const char * argv[]) {
    int T = 0;
    int N = 0;
    int P = 0;
    int M = 0;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::vector<int> housePrices;
        std::cin>> N;
        std::cin >> M;
        for (int j = 0; j < N; j++) {
            std::cin >> P;
            housePrices.push_back(P);
        }
        std::cout << "Case #"<<i+1<<": "<<getMaxHouse(housePrices, M) << std::endl;
    }
    
    return 0;
}
