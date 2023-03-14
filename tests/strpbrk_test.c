#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>

Test(my_strpbrk, simple_occurence_test)
{
    void *handle;
    char *(*my_strpbrk)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str[] = "Hello";
    char c[] = "es";
    char *a = my_strpbrk(str, c);
    char *b = strpbrk(str, c);
    cr_assert_eq(a, b, "Expected: %s\tBut Got: %s", b, a);

    dlclose(handle);
}

Test(my_strpbrk, strpbrk_test_0)
{
    void *handle;
    char *(*my_strpbrk)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str[] = "Hello Man";
    char *a = my_strpbrk(str, "H");
    char *b = strpbrk(str, "H");
    cr_assert_eq(a, b, "Expected: %s\tBut Got: %s", b, a);
    cr_assert_str_eq(my_strpbrk(str, "l"), strpbrk(str, "l"), "Test 1 failed");
    cr_assert_str_eq(my_strpbrk(str, "M"), strpbrk(str, "M"), "Test 2 failed");
    cr_assert_str_eq(my_strpbrk(str, "n"), strpbrk(str, "n"), "Test 4 failed");
    dlclose(handle);
}

Test(my_strpbrk, strpbrk_test_s)
{
    void *handle;
    char *(*my_strpbrk)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str[] = "Hello Man";
    char *a = my_strpbrk(str, "H");
    char *b = strpbrk(str, "H");
    cr_assert_eq(a, b, "Expected: %s\tBut Got: %s", b, a);
    cr_assert_str_eq(my_strpbrk(str, "l"), strpbrk(str, "l"), "Test 1 failed");
    cr_assert_str_eq(my_strpbrk(str, "M"), strpbrk(str, "M"), "Test 2 failed");
    cr_assert_str_eq(my_strpbrk(str, "n"), strpbrk(str, "n"), "Test 4 failed");
    dlclose(handle);
}

Test(my_strpbrk, strpbrk_test_1)
{
    void *handle;
    char *(*my_strpbrk)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str[] = "Salut";
    char *a = my_strpbrk(str, "H");
    char *b = strpbrk(str, "H");
    cr_assert_eq(a, b, "Expected: %s\tBut Got: %s", b, a);
    dlclose(handle);
}

Test(my_strpbrk, strpbrk_test_2)
{
    void *handle;
    char *(*my_strpbrk)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str[] = "CouCOu Cou";
    char *a = my_strpbrk(str, "coucou");
    char *b = strpbrk(str, "coucou");
    cr_assert_eq(a, b, "Expected: %s\tBut Got: %s", b, a);
    dlclose(handle);
}