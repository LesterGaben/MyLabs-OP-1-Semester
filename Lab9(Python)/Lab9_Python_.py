def delete_words_what_ending_in_symbols(line, symbols):
    leng_of_symbols = len(symbols)
    words = line.split()
    num_of_delete_words = 0
    for i in range(0,len(words)):
      for word in words:
        end_of_word = str(word[len(word) - leng_of_symbols::])
        if symbols == end_of_word:
            words.remove(word)
    new_string = ' '.join(words)
    return new_string

def amount_of_delete_words(line, new_line):
    return len(line.split()) - len(new_line.split())

string = input("Input string: ")
symbols = input("Input group of symbols: ")
new_string = delete_words_what_ending_in_symbols(string, symbols)
num_of_delete_words = amount_of_delete_words(string, new_string)
print("New string:", new_string)
print("Number of word deletions:", num_of_delete_words)
