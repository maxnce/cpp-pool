/*
** EPITECH PROJECT, 2022
** day05
** File description:
** string
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void string_init_c_funcs(string_t *this)
{
    this->assign_c = &assign_c;
    this->append_c = &append_c;
    this->compare_c = &compare_c;
    this->c_str = &c_str;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->split_c = &split_c;
}

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->string_init = &string_init;
    this->string_destroy = &string_destroy;
    this->assign_s = &assign_s;
    this->append_s = &append_s;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->copy = &copy;
    this->empty = &empty;
    this->find_s = &find_s;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
    this->split_s = &split_s;
    this->print = &print;
    string_init_c_funcs(this);
}

void string_destroy_c_funcs(string_t *this)
{
    this->assign_c = NULL;
    this->compare_c = NULL;
    this->append_c = NULL;
    this->c_str = NULL;
    this->find_c = NULL;
    this->insert_c = NULL;
    this->split_c = NULL;
}

void string_destroy(string_t *this)
{
    if (this->str != NULL)
        free(this->str);
    this->string_init = NULL;
    this->string_destroy = NULL;
    this->assign_s = NULL;
    this->append_s = NULL;
    this->at = NULL;
    this->clear = NULL;
    this->length = NULL;
    this->compare_s = NULL;
    this->copy = NULL;
    this->empty = NULL;
    this->find_s = NULL;
    this->insert_s = NULL;
    this->to_int = NULL;
    this->split_s = NULL;
    this->print = NULL;
    string_destroy_c_funcs(this);
}
