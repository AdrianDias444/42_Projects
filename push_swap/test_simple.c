#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Testando malloc...\n");
    void *ptr = malloc(100);
    printf("malloc retornou: %p\n", ptr);
    free(ptr);
    return 0;
}
