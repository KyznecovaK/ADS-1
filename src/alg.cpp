// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>
#include <vector>


bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value <= 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
    
  for (uint64_t divisor = 5; divisor * divisor <= value; divisor += 6) {
    if (value % divisor == 0 || value % (divisor + 2) == 0) return false;
   
}
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
    if (n == 1) return 2;
    
    uint64_t primeCount = 1;      
    uint64_t currentNumber = 3;  
    
    while (primeCount < n) {
        if (isPrime(currentNumber)) {
            primeCount++;
            if (primeCount == n) return currentNumber;
        }
        currentNumber += 2; 
    }

  return 2;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t candidate = value + 1;
    if (candidate <= 2) return 2;
    
    if (candidate % 2 == 0) candidate++;  
    
    while (!isPrime(candidate)) {
        candidate += 2;  
    }
    return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound <= 2) return 0;
    
    uint64_t totalSum = 2;  
    for (uint64_t number = 3; number < hbound; number += 2) {
        if (isPrime(number)) {
            totalSum += number;
        }
    }
    return totalSum;
}


uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    if (hbound <= lbound + 2) return 0;
    
    uint64_t twinCount = 0;
    uint64_t currentNumber = lbound;
    
   
    if (currentNumber % 2 == 0) currentNumber++;
    
    for (; currentNumber + 2 < hbound; currentNumber += 2) {
        if (isPrime(currentNumber) && isPrime(currentNumber + 2)) {
            twinCount++;
        }
    }
    return twinCount;
}
