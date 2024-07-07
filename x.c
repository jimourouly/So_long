int char_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0'; 
    }

    return -1;
}
