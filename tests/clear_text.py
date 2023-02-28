import re

fname = "doyle_the_adventures.txt"
with open("text4.txt", "w") as f:
    with open(fname) as f1:
        for line in f1:
            s = line
            s = re.sub(r'[.,"“”\'-?:!;—‘’]', '', s).lower()
            f.write(s)