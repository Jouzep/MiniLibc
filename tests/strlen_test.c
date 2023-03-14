/*
** EPITECH PROJECT, 2023
** B-ASM-400-PAR-4-1-asmminilibc-joseph.yu
** File description:
** strlen_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <stdio.h>

Test(my_strlen, simple_test)
{
    void *handle;
    size_t (*my_strlen)(const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strlen = dlsym(handle, "strlen");

    char *str = "Hello";
    cr_assert_eq(my_strlen(str), strlen("Hello"));

    dlclose(handle);
}