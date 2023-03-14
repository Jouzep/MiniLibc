#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <stdio.h>

Test(my_strstr, simple_occurence_test)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello";
    cr_assert_eq(my_strstr(str, "e"), strstr(str, "e"));

    dlclose(handle);
}

Test(my_strstr, no_occurence_test)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello";
    cr_assert_eq(my_strstr(str, "p"), strstr(str, "p"));

    dlclose(handle);
}

Test(my_strstr, multiple_occurence_test)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello lo lo";
    cr_assert_eq(my_strstr(str, "l"), strstr(str, "l"));

    dlclose(handle);
}

Test(my_strstr, occurence_at_first_index_test)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello lo lo";
    cr_assert_eq(my_strstr(str, "H"), strstr(str, "H"));

    dlclose(handle);
}

Test(my_strstr, occurence_at_last_index_test)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello lo lo.";
    cr_assert_eq(my_strstr(str, "."), strstr(str, "."));

    dlclose(handle);
}

Test(my_strstr, null_occurence_test)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello lo lo.";
    cr_assert_eq(my_strstr(str, "l\0"), strstr(str, "l\0"));

    dlclose(handle);
}

Test(my_strstr, simple_occurence_test_with_string)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello";
    cr_assert_eq(my_strstr(str, "el"), strstr(str, "el"));

    dlclose(handle);
}

Test(my_strstr, no_occurence_test_with_string)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello";
    cr_assert_eq(my_strstr(str, "pe"), strstr(str, "pe"));

    dlclose(handle);
}

Test(my_strstr, multiple_occurence_test_with_string)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello lo lo";
    cr_assert_eq(my_strstr(str, "lo"), strstr(str, "lo"));

    dlclose(handle);
}

Test(my_strstr, occurence_at_first_index_test_with_string)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello lo lo";
    cr_assert_eq(my_strstr(str, "He"), strstr(str, "He"));

    dlclose(handle);
}

Test(my_strstr, occurence_at_last_index_test_with_string)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello lo lo..";
    cr_assert_eq(my_strstr(str, ".."), strstr(str, ".."));

    dlclose(handle);
}

Test(my_strstr, null_occurence_test_with_string)
{
    void *handle;
    size_t (*my_strstr)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char *str = "Hello lo lo.";
    cr_assert_eq(my_strstr(str, ".\0"), strstr(str, ".\0"));

    dlclose(handle);
}
