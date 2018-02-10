// ----------
// Arrays.c++
// ----------

// http://en.cppreference.com/w/cpp/language/array

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl

using namespace std;

void test1 () {
    int a[] = {2, 3, 4};
    assert(*a == a[0]);
    assert(a  == &a[0]);
    assert(sizeof(a)     != sizeof(&a[0]));
    assert(sizeof(a)     == 12);
    assert(sizeof(&a[0]) == 8);
//  ++a;                                    // error: lvalue required as left operand of assignment
    ++a[1];
    ++*(a + 1);
    assert(a[1]     == 5);
    assert(*(a + 1) == 5);
//  assert(a[3]     == 0);                  // undefined
    }

void test2 () {
    int a[] = {2, 3, 4};
//  int b[] = a;                    // error: initializer fails to determine size of 'b'
    int* b  = a;
    assert(a         == b);
    assert(sizeof(a) != sizeof(b));
    assert(sizeof(a) == 12);
    assert(sizeof(b) ==  8);
    ++b[1];
    assert(a[1] == 4);
    assert(b[1] == 4);}

void test3 () {
    int a[] = {2, 3, 4};
    int b[] = {2, 3, 4};
    assert(a != b);
    assert(equal(a, a + 3, b));
    ++b[1];
    assert(a[1] == 3);
    assert(b[1] == 4);}

void f (int p[]) {
//  assert(sizeof(p) == 8); // warning: sizeof on array function parameter will return size of 'int *' instead of 'int []'
    ++p;
    ++p[0];
    ++*p;}

void test4 () {
    int a[] = {2, 3, 4};
    int b[] = {2, 5, 4};
    f(a);
    assert(equal(a, a + 3, b));}

void g (int* p) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

void test5 () {
    int a[] = {2, 3, 4};
    int b[] = {2, 5, 4};
    g(a);
    assert(equal(a, a + 3, b));}

int main () {
    cout << "Arrays.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    cout << "Done." << endl;
    return 0;}
