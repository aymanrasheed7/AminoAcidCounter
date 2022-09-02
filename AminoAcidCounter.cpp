#include<bits/extc++.h>
using namespace std;
struct AminoAcidCounter {
    AminoAcidCounter() {}
    int nTypes = 23, indexMap[64] = {
         0,  0,  1,  1,  5,  5,  5,  5,
         9,  9, 10, 11, 18, 18, 19, 20,
         1,  1,  1,  1,  6,  6,  6,  6,
        12, 12, 13, 13, 21, 21, 21, 21,
         2,  2,  2,  3,  7,  7,  7,  7,
        14, 14, 15, 15,  5,  5, 21, 21,
         4,  4,  4,  4,  8,  8,  8,  8,
        16, 16, 17, 17, 22, 22, 22, 22 };
    string aminoAcids[23] = {
        "(Phe/F) Phenylalanine", "(Leu/L) Leucine",
        "(Ile/I) Isoleucine", "(Met/M) Methionine", "(Val/V) Valine",
        "(Ser/S) Serine", "(Pro/P) Proline",
        "(Thr/T) Threonine", "(Ala/A) Alanine",
        "(Tyr/Y) Tyrosine", "Stop (Ochre)", "Stop (Amber)",
        "(His/H) Histidine", "(Gln/Q) Glutamine",
        "(Asn/N) Asparagine", "(Lys/K) Lysine",
        "(Asp/D) Aspartic acid", "(Glu/E) Glutamic acid",
        "(Cys/C) Cysteine", "Stop (Opal)", "(Trp/W) Tryptophan",
        "(Arg/R) Arginine", "(Gly/G) Glycine" };
    int charMap(char c) {
        if (c == 'G' || c == 'g') return 3;
        if (c == 'A' || c == 'a') return 2;
        if (c == 'C' || c == 'c') return 1;
        return 0;
    }
    void count(string& input, vector<pair<int, string>>& output) {
        for (int i = 0; i != nTypes; output.emplace_back(0, aminoAcids[i++]));
        for (int i = 0; i + 2 < input.size(); ++output[indexMap[
            charMap(input[i]) << 4 | charMap(input[i + 1]) << 2
                | charMap(input[i + 2])]].first, i += 3);
        sort(output.begin(), output.end(), greater<pair<int, string>>());
    }
};
int main() {
    string input;
    vector<pair<int, string>> output;
    ios::sync_with_stdio(0), cin.tie(0), cin >> input;
    AminoAcidCounter model = AminoAcidCounter();
    output.clear(), model.count(input, output);
    for (int i = 0; i != output.size(); ++i) if (output[i].first)
        cout << output[i].first << ' ' << output[i].second << '\n';
    exit(0);
}
