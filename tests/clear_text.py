import string

fname = "Tolkien The Lord of the Rings.txt"
with open("text.txt", "w") as f:
    with open(fname) as f1:
        for line in f1:
            s = line
            s = s.translate(dict.fromkeys(map(ord, string.punctuation))).lower()
            f.write(s)
