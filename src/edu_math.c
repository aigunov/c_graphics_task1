#include "edu_math.h"

#include <stdio.h>
#include <stdlib.h>

#define UNIMPLEMENTED \
    do { \
        fprintf(stderr, "[ERROR] function %s is unimplemented\n", func); \
        abort(); \
    } while (0)

#define UNUSED(x) (void)(x)

int edu_add(int a, int b) {
    return a + b;
}

int edu_sub(int a, int b) {
    return a-b;
}

int edu_mult(int a, int b) {
    return a*b;
}

int edu_div(int a, int b) {
    if (b==0){
        fprintf(stderr, "ERROR: Division by zero: %d", b);
        abort();
    }
    return a/b;
}

int edu_mod(int a, int b) {
    return a % b;
}

int edu_pow(int a, int b) {
    int result = 1;
    int base = a;
    int exp = b;
    if (exp<0){
        return 0;
    }
    while (exp > 0){
        if (exp % 2 == 1){
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

int edu_abs(int a) {
    return abs(a);
}

int edu_gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int edu_lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int gcd = edu_gcd(a, b);
    return (a / gcd) * b;  
}

int edu_int_sqrt(int a) {
    if (a < 0) {
        fprintf(stderr, "ERROR: negative input %d",a);
        abort();
    }
    int left = 0, right = a, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((long long)mid * mid <= a) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int edu_sgn(int a) {
    if (a> 0) return 1;
    if (a<0) return -1;
    return 0;
}

int edu_fact(int a) {
    if (a < 0) {
        fprintf(stderr, "ERROR: negative input %d", a);
        abort();
    }
    int result = 1;
    for (int i = 2; i <= a; i++) {
        result *= i;
    }
    return result;
}