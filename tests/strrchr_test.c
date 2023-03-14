#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <stdio.h>

Test(my_strrchr, simple_occurence_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "Hello";
    cr_assert_eq(my_strrchr(str, 'e'), strrchr(str, 'e'));

    dlclose(handle);
}

Test(my_strrchr, no_occurence_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "Hello";
    cr_assert_eq(my_strrchr(str, 'p'), strrchr(str, 'p'));

    dlclose(handle);
}

Test(my_strrchr, multiple_occurence_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "Hello lo lo";
    cr_assert_eq(my_strrchr(str, 'l'), strrchr(str, 'l'));

    dlclose(handle);
}

Test(my_strrchr, occurence_at_first_index_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "Hello lo lo";
    cr_assert_eq(my_strrchr(str, 'H'), strrchr(str, 'H'));

    dlclose(handle);
}

Test(my_strrchr, occurence_at_last_index_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "Hello lo lo.";
    cr_assert_eq(my_strrchr(str, '.'), strrchr(str, '.'));

    dlclose(handle);
}

Test(my_strrchr, null_occurence_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "Hello lo lo.";
    cr_assert_eq(my_strrchr(str, '\0'), strrchr(str, '\0'), "me(%s)|(%s)standard", my_strrchr(str, '\0'), strrchr(str, '\0'));

    dlclose(handle);
}