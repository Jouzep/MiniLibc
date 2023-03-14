#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <stdio.h>

Test(my_strcmp, simple_occurence_test)
{
    void *handle;
    size_t (*my_strcmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcmp = dlsym(handle, "strcmp");

    char str[] = "Hello";
    char c[] = "e";
    int a = my_strcmp(str, c);
    int b = strcmp(str, c);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strcmp, same_string_test)
{
    void *handle;
    size_t (*my_strcmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcmp = dlsym(handle, "strcmp");

    char str[] = "Hello";
    char c[] = "Hello";
    int a = my_strcmp(str, c);
    int b = strcmp(str, c);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strcmp, null_test)
{
    void *handle;
    size_t (*my_strcmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcmp = dlsym(handle, "strcmp");

    char str[] = "Hello";
    char c[] = "\n";
    int a = my_strcmp(str, c);
    int b = strcmp(str, c);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strcmp, first_string_lower_test)
{
    void *handle;
    size_t (*my_strcmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcmp = dlsym(handle, "strcmp");

    char str[] = "Hello";
    char c[] = "Hellobg";
    int a = my_strcmp(str, c);
    int b = strcmp(str, c);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strcmp, same_length_but_inequal_test)
{
    void *handle;
    size_t (*my_strcmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcmp = dlsym(handle, "strcmp");

    char str[] = "Hello";
    char c[] = "KIKIK";
    int a = my_strcmp(str, c);
    int b = strcmp(str, c);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}