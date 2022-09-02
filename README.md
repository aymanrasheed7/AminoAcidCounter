# AminoAcidCounter

Task name: DNA amino acid reader

Task description:
Create a model that takes a DNA strand as input (for example, CTAGGACCG) and gives the amino acid counts as output. Please list the amino acid counts in descending order.

Solution features and limitations:
1. The model is called AminoAcidCounter. To use it create an object of this class, take the input string, take an empty list to store the output and finally call the count function of the class.
2. The solution is simply reading and mapping. The names of the amino acids are taken from: https://en.wikipedia.org/wiki/DNA_and_RNA_codon_tables
3. The solution works even if some of the letters in the input is lowercase.
4. If there are letters other than T, C, A or G in the input, the solution treats them as T.
5. If the lengh of the input is not divisible by 3, the solution ignores the last remaining 1 or 2 characters.
