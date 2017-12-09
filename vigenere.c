#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // return 1 and error message if less or more than 1 argument
    if (argc != 2)
    {
        printf("Error: Please input one and only one argument.\n");
        return 1;
    }

    // iterates through key and convert to array of integers
    int klength = strlen(argv[1]);
    int key[klength];
    for (int h = 0; h < klength; h++)
    {
        if (argv[1][h] >= 65 && argv[1][h] <= 90)
            key[h] = argv[1][h] % 65;
        else
            key[h] = argv[1][h] % 97;
    }
    
    // return 1 and error message if argument contains non-alphabetical characters
    for (int i = 0; i < klength; i++)
    {
        if (argv[1][i] < 65 || argv[1][i] > 122 ||
            (argv[1][i] > 90 && argv[1][i] < 97))
        {
            printf("Error: Input alphabetical characters only.\n");
            return 1;
        }
    }

    // prompts user for plaintext
    printf("plaintext: ");
    string ptext = get_string();

    // initiate plaintext length and ciphertext string
    int plength = strlen(ptext);
    char ctext[plength];

    // iterates through plaintext and encrypt using key
    int flag = 0;
    for (int j = 0; j < plength; j++)
    {
        int addkey = key[flag % klength];
        if (ptext[j] >= 65 && ptext[j] <= 90)
        {
            ctext[j] = (65 + (((ptext[j] % 65) + addkey) % 26));
            flag += 1;
        }
        else if (ptext[j] >= 97 && ptext[j] <= 122)
        {
            ctext[j] = (97 + (((ptext[j] % 97) + addkey) % 26));
            flag += 1;
        }
        else
            ctext[j] = ptext[j];
    }
    
    // iterates through and print ciphertext
    printf("ciphertext: ");
    for (int l = 0; l < plength; l++)
        printf("%c", ctext[l]);
    
    printf("\n");
    return 0;
}