#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *env_path = "PATH";
    char *env_value = NULL;

    env_value = getenv(env_path);
    if (NULL == env_value)
        printf("NOT FOUND!\n");
    printf("Get Env %s:\n%s", env_path, env_value);
    return 0;
}
