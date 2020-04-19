#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
void* compute_prime(void* arg)
{
    int *p_candidate = (int*)malloc(sizeof(int));
    *p_candidate = 2;
    int n = *((int*)arg);
    while (1)
    {
        int factor;
        int is_prime = 1;
        for (factor = 2; factor < (*p_candidate); ++factor)
            if (*p_candidate % factor == 0)
            {
                is_prime = 0;
                break;
            }
        if (is_prime)
        {
            if (--n == 0)
                return (void*)p_candidate;
        }
        ++(*p_candidate);
    }
    return p_candidate;
    return NULL;
}
int main()
{
    pthread_t thread;
    int which_prime = 5000;
    int *prime = NULL;
    pthread_create(&thread, NULL, &compute_prime, &which_prime);
    pthread_join(thread, (void*)&prime);
    if (prime != NULL)
    {
        printf("The %dth prime number is %d\n", which_prime, *prime);
        free (prime);
    }
    else
    {
        printf ("error");
    }
    return 0;
}