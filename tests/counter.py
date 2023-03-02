number_of_words = 0

with open("text_for_test3.txt") as f:
    data = f.read()
    lines = data.split()
    for word in lines:
        if not word.isnumeric():
            number_of_words += 1
print(number_of_words)



number_of_words = 0

with open("text_for_test3.txt") as f:
    with open("text_for_test31.txt", "w") as f1:
        data = f.read()
        lines = data.split()
        for word in lines:
            if not word.isnumeric():
                number_of_words += 1
                if number_of_words < 25000000:
                    f1.write(word + ' ')
                    print(number_of_words)

