#define _CRT_SECURE_NO_WARNINGS
#define MAX_WORD_LENGTH 100
#include "func.h"


int main() {
    setlocale(LC_ALL, "Rus");
    FILE* filee = fopen("C:/Users/danik/Desktop/config.txt", "w");
    fclose(filee);
    int num_words = 0;
    Word* words = read_words_from_file("C:/Users/danik/Desktop/text.txt", &num_words);
    char* most_frequent_long_word;
    char* least_frequent_short_word;
    find_and_save_words(words, num_words, &most_frequent_long_word, &least_frequent_short_word);
    replace_words_in_file("C:/Users/danik/Desktop/text.txt", most_frequent_long_word, least_frequent_short_word);
    while (1) {
        int old_size = get_file_size("C:/Users/danik/Desktop/text.txt");
        find_and_save_words(words, num_words, &most_frequent_long_word, &least_frequent_short_word);
        replace_words_in_file("C:/Users/danik/Desktop/text.txt", most_frequent_long_word, least_frequent_short_word);
        int new_size = get_file_size("C:/Users/danik/Desktop/text.txt");
        if (new_size >= old_size) {
            append_config_to_file("C:/Users/danik/Desktop/text.txt");
            break;
        }
    }
    free(words);
    return 0;
}