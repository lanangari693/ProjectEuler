#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<vector>
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

//helper function
bool is_prime(long long n);
long long next_prime(int n);
bool is_palindrome(long long n);
vector<Exponent> prime_decomposition(long long n);

#endif
