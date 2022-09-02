class AminoAcidCounter:

    def __init__(self):
        self.nTypes = 23
        self.indexMap = [
            0, 0, 1, 1, 5, 5, 5, 5, 9, 9, 10, 11, 18, 18, 19, 20, 1, 1, 1, 1,
            6, 6, 6, 6, 12, 12, 13, 13, 21, 21, 21, 21, 2, 2, 2, 3, 7, 7, 7, 7,
            14, 14, 15, 15, 5, 5, 21, 21, 4, 4, 4, 4, 8, 8, 8, 8, 16, 16, 17,
            17, 22, 22, 22, 22
        ]
        self.aminoAcids = [
            '(Phe/F) Phenylalanine', '(Leu/L) Leucine', '(Ile/I) Isoleucine',
            '(Met/M) Methionine', '(Val/V) Valine', '(Ser/S) Serine',
            '(Pro/P) Proline', '(Thr/T) Threonine', '(Ala/A) Alanine',
            '(Tyr/Y) Tyrosine', 'Stop (Ochre)', 'Stop (Amber)',
            '(His/H) Histidine', '(Gln/Q) Glutamine', '(Asn/N) Asparagine',
            '(Lys/K) Lysine', '(Asp/D) Aspartic acid', '(Glu/E) Glutamic acid',
            '(Cys/C) Cysteine', 'Stop (Opal)', '(Trp/W) Tryptophan',
            '(Arg/R) Arginine', '(Gly/G) Glycine'
        ]

    def charMap(self, c):
        if c == 'G' or c == 'g':
            return 3
        if c == 'A' or c == 'a':
            return 2
        if c == 'C' or c == 'c':
            return 1
        return 0

    def count(self, input, output):
        for i in range(self.nTypes):
            output.append([0, self.aminoAcids[i]])
        for i in range(0, len(input), 3):
            output[self.indexMap[self.charMap(input[i]) << 4
                                 | self.charMap(input[i + 1]) << 2
                                 | self.charMap(input[i + 2])]][0] += 1
        output.sort(reverse=True)


output = []
input = input()
model = AminoAcidCounter()
model.count(input, output)
for i in range(len(output)):
    if output[i][0] != 0:
        print(output[i][0], output[i][1])
