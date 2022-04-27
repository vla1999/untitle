#include <iostream>

#include <stddef.h>
#include <stdlib.h>

#include <aerospike/aerospike.h>
#include <aerospike/as_string.h>


int main() {


    std::string s = "ddsd";
    char* c;
    str= "948505";
    as_string_s* AS;
    AS = as_string_new(c, true);
    int i = as_string_len(AS);
    std::cout << i << std::endl;

    return 0;

}
