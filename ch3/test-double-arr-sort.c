int is_sorted(double a[], int len) {
    int ret = 1;
    
    for (int i = 0; i < len - 1; i++) {
            if (a[i] > a[i + 1])
                    return 0;
    }
    return ret;
}