#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct Exponent {
    int base;
    int power;
};

void answer_1();
void answer_2();
void answer_3();
void answer_4();
void answer_5();
void answer_6();
void answer_7();
void answer_8();
void answer_9();
void answer_10();
void answer_11();
void answer_12();
void answer_13();
void answer_14();
void answer_15();
void answer_16();
void answer_17();
void answer_18();

//helper function
bool is_prime(long long n);
long long next_prime(int n);
bool is_palindrome(long long n);
vector<Exponent> prime_decomposition(long long n);
int count_devisors(int n);
#endif
