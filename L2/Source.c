#define _CRT_SECURE_NO_WARNINGS
#define MAX_WORD_LENGTH 100
#include "func.h"


int main() {
    setlocale(LC_ALL, "Rus");
    int num_words = 0;
    Word* words = read_words_from_file("C:/Users/danik/Desktop/text.txt", &num_words);
    Word* most_frequent_long_word;
    Word* least_frequent_short_word;
    int max_pairs = num_words / 2;
    char** pairs = malloc(max_pairs * sizeof(char*));
    for (int i = 0; i < max_pairs; i++) {
        pairs[i] = malloc(MAX_WORD_LENGTH * 2 + 1);
        pairs[i][0] = '\0';
    }
    int pair_count = 0;
    while (1) {
        find_and_save_words(words, num_words, &most_frequent_long_word, &least_frequent_short_word);
        int old_size = find_old_size(most_frequent_long_word, least_frequent_short_word);
        printf("\nOLD:%d", old_size);
        int new_size = find_new_size(most_frequent_long_word, least_frequent_short_word);
        printf("\nNew:%d", new_size);
        if (new_size >= old_size) {
            break;
        }
        replace_words_in_file("C:/Users/danik/Desktop/text.txt", most_frequent_long_word, least_frequent_short_word);
        if (pair_count < max_pairs) {
            sprintf(pairs[pair_count], "%s %s", most_frequent_long_word->word, least_frequent_short_word->word);
            pair_count++;
        }
        else {
        }
    }
    FILE* file = fopen("C:/Users/danik/Desktop/text.txt", "a");
    fprintf(file, " --- ");
    for (int i = 0; i < pair_count; i++) {
        fprintf(file, "%s\n", pairs[i]);
    }
    fclose(file);
    for (int i = 0; i < max_pairs; i++) {
        free(pairs[i]);
    }
    free(pairs);
    free(words);
    return 0;
}