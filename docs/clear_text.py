import string

fname = "master_i_margarita.txt"

with open(fname) as f:
    for line in f:
        s = line
        output = s.translate(str.maketrans('', '', string.punctuation))
        print(output)

