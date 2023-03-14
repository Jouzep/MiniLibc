#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <stdio.h>

Test(my_strchr, simple_occurence_test)
{
    void *handle;
    size_t (*my_strchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");

    char *str = "Hello";
    cr_assert_eq(my_strchr(str, 'e'), strchr(str, 'e'));

    dlclose(handle);
}

Test(my_strchr, no_occurence_test)
{
    void *handle;
    size_t (*my_strchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");

    char *str = "Hello";
    cr_assert_eq(my_strchr(str, 'p'), strchr(str, 'p'));

    dlclose(handle);
}

Test(my_strchr, multiple_occurence_test)
{
    void *handle;
    size_t (*my_strchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");

    char *str = "Hello lo lo";
    cr_assert_eq(my_strchr(str, 'l'), strchr(str, 'l'));

    dlclose(handle);
}

Test(my_strchr, occurence_at_first_index_test)
{
    void *handle;
    size_t (*my_strchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");

    char *str = "Hello lo lo";
    cr_assert_eq(my_strchr(str, 'H'), strchr(str, 'H'));

    dlclose(handle);
}

Test(my_strchr, occurence_at_last_index_test)
{
    void *handle;
    size_t (*my_strchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");

    char *str = "Hello lo lo.";
    cr_assert_eq(my_strchr(str, '.'), strchr(str, '.'));

    dlclose(handle);
}

Test(my_strchr, null_occurence_test)
{
    void *handle;
    size_t (*my_strchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");

    char *str = "Hello lo lo.";
    cr_assert_eq(my_strchr(str, '\0'), strchr(str, '\0'));

    dlclose(handle);
}