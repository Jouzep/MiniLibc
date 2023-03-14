#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <stdio.h>

Test(my_strncmp, simple_occurence_test)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "e";
    int a = my_strncmp(str, c, strlen(c));
    int b = strncmp(str, c, strlen(c));
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, same_string_test)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "Hello";
    int a = my_strncmp(str, c, strlen(c));
    int b = strncmp(str, c, strlen(c));
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, null_test)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "\n";
    int a = my_strncmp(str, c, strlen(c));
    int b = strncmp(str, c, strlen(c));
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, first_string_lower_test)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "Hellobg";
    int a = my_strncmp(str, c, strlen(c));
    int b = strncmp(str, c, strlen(c));
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, same_length_but_inequal_test)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "KIKIK";
    int a = my_strncmp(str, c, strlen(c));
    int b = strncmp(str, c, strlen(c));
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, simple_occurence_test_with_diff_length)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "e";
    int a = my_strncmp(str, c, 4);
    int b = strncmp(str, c, 4);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, same_string_test_with_diff_length)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "Hello";
    int a = my_strncmp(str, c, 4);
    int b = strncmp(str, c, 4);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, null_test_with_diff_length)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "\n";
    int a = my_strncmp(str, c, 4);
    int b = strncmp(str, c, 4);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, first_string_lower_test_with_diff_length)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "Hellobg";
    int a = my_strncmp(str, c, 4);
    int b = strncmp(str, c, 4);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, same_length_but_inequal_test_with_diff_length)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "KIKIK";
    int a = my_strncmp(str, c, 4);
    int b = strncmp(str, c, 4);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, occurence_at_start_test)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "ello";
    char c[] = "ell";
    int a = my_strncmp(str, c, strlen(c));
    int b = strncmp(str, c, strlen(c));
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, occurence_at_mid_test)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "ello";
    int a = my_strncmp(str, c, strlen(c));
    int b = strncmp(str, c, strlen(c));
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, occurence_at_end_test)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "lo";
    int a = my_strncmp(str, c, strlen(c));
    int b = strncmp(str, c, strlen(c));
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strncmp, occurence_at_end_tesst)
{
    void *handle;
    size_t (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");

    char str[] = "Hello";
    char c[] = "lo";
    int a = my_strncmp(str, c, strlen(c));
    int b = strncmp(str, c, strlen(c));
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}