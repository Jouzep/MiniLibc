#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <stdio.h>

Test(my_strcspn, simple_occurence_test)
{
    void *handle;
    size_t (*my_strcspn)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcspn = dlsym(handle, "strcspn");

    char str[] = "Hello";
    char c[] = "e";
    int a = my_strcspn(str, c);
    int b = strcspn(str, c);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strcspn, null_test)
{
    void *handle;
    size_t (*my_strcspn)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcspn = dlsym(handle, "strcspn");

    char str[] = "Hello";
    char c[] = "\0lle";
    int a = my_strcspn(str, c);
    int b = strcspn(str, c);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strcspn, multiple_end_test)
{
    void *handle;
    size_t (*my_strcspn)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcspn = dlsym(handle, "strcspn");

    char str[] = "Hello";
    char c[] = "dqzdqzdo";
    int a = my_strcspn(str, c);
    int b = strcspn(str, c);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strcspn, null_testv2)
{
    void *handle;
    size_t (*my_strcspn)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcspn = dlsym(handle, "strcspn");

    char str[] = "Hello";
    char c[] = "";
    int a = my_strcspn(str, c);
    int b = strcspn(str, c);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}

Test(my_strcspn, no_occurence_test)
{
    void *handle;
    size_t (*my_strcspn)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcspn = dlsym(handle, "strcspn");

    char str[] = "Hello";
    char c[] = "kijn";
    int a = my_strcspn(str, c);
    int b = strcspn(str, c);
    cr_assert_eq(a, b, "Expected: %d\tBut Got: %d", b, a);

    dlclose(handle);
}